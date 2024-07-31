#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "implot.h"
#include "tinyfiledialogs.h"
#include "csv.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

struct ColumnData {
  std::string name;
  std::vector<float> data;
  bool selected;
};

std::vector<ColumnData> columns;
std::string selectedFileName;

void readCSV(const char* filename) {
  columns.clear();
  io::CSVReader<2> in(filename);
  std::string col1, col2;
  while (in.read_row(col1, col2)) {
    // Assuming the CSV has at least two columns
    columns.push_back({ col1, {}, false });
    columns.back().data.push_back(std::stof(col2));
  }
}

void openFile() {
  const char* lFilterPatterns[1] = { "*.csv" };
  const char* lTheOpenFileName = tinyfd_openFileDialog(
    "Open CSV File",
    "",
    1,
    lFilterPatterns,
    NULL,
    0
  );
  if (lTheOpenFileName) {
    selectedFileName = lTheOpenFileName;
    readCSV(lTheOpenFileName);
  }
}

int main(int, char**) {
  if (!glfwInit())
    return -1;
  const char* glsl_version = "#version 130";
  GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui Example", NULL, NULL);
  if (window == NULL)
    return -1;
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImPlot::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init(glsl_version);
  ImGui::StyleColorsDark();

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if (ImGui::BeginMainMenuBar()) {
      if (ImGui::BeginMenu("File")) {
        if (ImGui::MenuItem("Open..", "Ctrl+O")) {
          openFile();
        }
        ImGui::EndMenu();
      }
      ImGui::EndMainMenuBar();
    }

    ImGui::Begin("X-Y Column Selection", NULL, ImGuiWindowFlags_NoMove);
    ImGui::SetWindowPos(ImVec2(0, 20));
    ImGui::SetWindowSize(ImVec2(200, ImGui::GetIO().DisplaySize.y - 20));
    for (auto& col : columns) {
      ImGui::Checkbox(col.name.c_str(), &col.selected);
    }
    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(200, 20), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x - 200, ImGui::GetIO().DisplaySize.y - 20), ImGuiCond_FirstUseEver);
    ImGui::Begin("Graph Settings", NULL);
    static ImPlotLineStyle lineStyle = ImPlotLineStyle();
    static ImVec4 lineColor = ImVec4(1, 0, 0, 1);
    static float lineThickness = 1.0f;

    ImGui::ColorEdit4("Line Color", (float*)&lineColor);
    ImGui::SliderFloat("Line Thickness", &lineThickness, 1.0f, 5.0f);
    if (ImGui::BeginCombo("Line Style", lineStyle.Name)) {
      for (int n = 0; n < ImPlotLineStyle_COUNT; n++) {
        bool is_selected = (lineStyle.ID == n);
        if (ImGui::Selectable(ImPlotLineStyle_Names[n], is_selected))
          lineStyle = ImPlotLineStyle(n);
        if (is_selected)
          ImGui::SetItemDefaultFocus();
      }
      ImGui::EndCombo();
    }
    ImGui::End();

    ImGui::Begin("Plot", NULL);
    if (ImPlot::BeginPlot("XY Plot")) {
      for (auto& col : columns) {
        if (col.selected) {
          ImPlot::PushStyleVar(ImPlotStyleVar_LineWeight, lineThickness);
          ImPlot::PushStyleColor(ImPlotCol_Line, lineColor);
          ImPlot::PlotLine(col.name.c_str(), col.data.data(), col.data.size());
          ImPlot::PopStyleVar();
          ImPlot::PopStyleColor();
        }
      }
      ImPlot::EndPlot();
    }
    ImGui::End();

    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
  }

  ImPlot::DestroyContext();
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}


/*
#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"
#include "implot.h"
#include <d3d11.h>
#include <tchar.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


static ID3D11Device*           g_pd3dDevice           = NULL;
static ID3D11DeviceContext*    g_pd3dDeviceContext    = NULL;
static IDXGISwapChain*         g_pSwapChain           = NULL;
static ID3D11RenderTargetView* g_mainRenderTargetView = NULL;


vector<vector<string>> readCSV(const string& filePath)
{
  vector<vector<string>> data;

  ifstream file(filePath);

  string line;
  while (getline(file, line)) {
    vector<string> row;

    stringstream lineStream(line);

    string cell;
    while (getline(lineStream, cell, ',')) {
      row.push_back(cell);
    }
    data.push_back(row);
  }

  return data;
}


bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();

void CreateRenderTarget();
void CleanupRenderTarget();

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


int main(int, char**)
{
  // CSV 파일 읽기
  std::string filePath = "data.csv";
  std::vector<std::vector<std::string>> data = readCSV(filePath);
  if (data.empty()) {
    std::cerr << "CSV file is empty or could not be read!" << std::endl;
    return 1;
  }
  std::vector<std::string> columns = data[0];

  // Create application window
  WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("LAFLAS-2 Plot"), NULL };
  RegisterClassEx(&wc);
  HWND hwnd = CreateWindow(wc.lpszClassName, _T("LAFLAS-2 Plot"), WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);

  // Initialize Direct3D
  if (!CreateDeviceD3D(hwnd)) {
    CleanupDeviceD3D();
    UnregisterClass(wc.lpszClassName, wc.hInstance);
    return 1;
  }

  // Show the window
  ShowWindow(hwnd, SW_SHOWDEFAULT);
  UpdateWindow(hwnd);

  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  ImGui::StyleColorsDark();

  // Initialize ImGui for DirectX and Win32
  ImGui_ImplWin32_Init(hwnd);
  ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

  // Setup ImPlot context
  ImPlot::CreateContext();

  // Main loop
  bool done = false;
  static int xColumn = 0;
  static int yColumn = 1;

  while (!done) {
    // Poll and handle messages (inputs, window resize, etc.)
    MSG msg;
    while (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
      if (msg.message == WM_QUIT)
        done = true;
    }
    if (done)
      break;

    // Start the Dear ImGui frame
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("LAFLAS-2 Plot", (bool *)0, ImGuiWindowFlags_MenuBar);
    if (ImGui::BeginMenuBar()) {
      if (ImGui::BeginMenu("File")) {
        if (ImGui::MenuItem("Open..", "Ctrl+O")) {
        }

        ImGui::EndMenu();
      }

      ImGui::EndMenuBar();
    }

    ImGui::Text("Select X and Y columns for plotting:");
    if (ImGui::BeginCombo("X Column", columns[xColumn].c_str())) {
      for (int n = 0; n < columns.size(); n++) {
        bool is_selected = (xColumn == n);
        if (ImGui::Selectable(columns[n].c_str(), is_selected))
          xColumn = n;
        if (is_selected)
          ImGui::SetItemDefaultFocus();
      }
      ImGui::EndCombo();
    }

    if (ImGui::BeginCombo("Y Column", columns[yColumn].c_str())) {
      for (int n = 0; n < columns.size(); n++) {
        bool is_selected = (yColumn == n);
        if (ImGui::Selectable(columns[n].c_str(), is_selected))
          yColumn = n;
        if (is_selected)
          ImGui::SetItemDefaultFocus();
      }
      ImGui::EndCombo();
    }
    ImGui::End();

    // Extract data for plotting
    std::vector<double> xData, yData;
    for (int i = 1; i < data.size(); i++) {
      xData.push_back(std::stod(data[i][xColumn]));
      yData.push_back(std::stod(data[i][yColumn]));
    }

    // Show plot using ImPlot
    ImGui::Begin("Plot");
    if (ImPlot::BeginPlot("My Plot")) {
      ImPlot::SetNextAxesToFit();
      ImPlot::PlotLine("Data", xData.data(), yData.data(), xData.size());
      ImPlot::EndPlot();
    }
    ImGui::End();

    // Rendering
    ImGui::Render();
    const float clear_color[4] = { 0.45f, 0.55f, 0.60f, 1.00f };
    g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
    g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color);
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    g_pSwapChain->Present(1, 0); // Present with vsync
  }

  // Cleanup
  ImPlot::DestroyContext();
  ImGui_ImplDX11_Shutdown();
  ImGui_ImplWin32_Shutdown();
  ImGui::DestroyContext();

  CleanupDeviceD3D();
  DestroyWindow(hwnd);
  UnregisterClass(wc.lpszClassName, wc.hInstance);

  return 0;
}

// Helper functions
bool CreateDeviceD3D(HWND hWnd) {
  DXGI_SWAP_CHAIN_DESC sd = {};
  sd.BufferCount = 2;
  sd.BufferDesc.Width = 1280;
  sd.BufferDesc.Height = 800;
  sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
  sd.BufferDesc.RefreshRate.Numerator = 60;
  sd.BufferDesc.RefreshRate.Denominator = 1;
  sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
  sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
  sd.OutputWindow = hWnd;
  sd.SampleDesc.Count = 1;
  sd.SampleDesc.Quality = 0;
  sd.Windowed = TRUE;
  sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

  UINT createDeviceFlags = 0;
  D3D_FEATURE_LEVEL featureLevel;
  const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
  if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2,
    D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext) != S_OK)
    return false;

  CreateRenderTarget();
  return true;
}

void CleanupDeviceD3D() {
  CleanupRenderTarget();
  if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
  if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
  if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
}

void CreateRenderTarget() {
  ID3D11Texture2D* pBackBuffer;
  g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
  g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
  pBackBuffer->Release();
}

void CleanupRenderTarget() {
  if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
    return true;

  switch (msg) {
  case WM_SIZE:
    if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED) {
      CleanupRenderTarget();
      g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
      CreateRenderTarget();
    }
    return 0;
  case WM_SYSCOMMAND:
    if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
      return 0;
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    return 0;
  }
  return DefWindowProc(hWnd, msg, wParam, lParam);
}
*/