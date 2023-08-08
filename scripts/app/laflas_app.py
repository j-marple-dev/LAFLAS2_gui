"""Main app module.

-Author: Haneol Kim
-Contact: hekim@jmarple.ai
"""

from typing import Any, Optional, Tuple, Union

from customtkinter import CTk

from scripts.frames.laflas_frames import MainScrollable


class LaflasApp(CTk):
    """Test app."""

    def __init__(
        self,
        fg_color: Optional[Union[str, Tuple[str, str]]] = None,
        **kwargs: Union[str, Any],
    ) -> None:
        """Initialize test app.

        Args:
            fg_color: fg color.
            kwargs: key word arguments for CTk initialization.
        """
        super().__init__(fg_color, **kwargs)
        self.columnconfigure(0, weight=1)
        self.rowconfigure(0, weight=1)

        self.geometry("1920x1080")
        self.title("test app")

        self.main_frame = MainScrollable(self)
        self.main_frame.grid(row=0, column=0, sticky="NSEW")


if __name__ == "__main__":
    app = LaflasApp()
    app.mainloop()
