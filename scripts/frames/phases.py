"""Phases frame module.

-Author: Haneol Kim
-Contact: hekim@jmarple.ai
"""

# pylint: disable=duplicate-code

from ast import literal_eval
from typing import TYPE_CHECKING, Any, List, Union

from customtkinter import CTkButton, CTkComboBox, CTkLabel, StringVar

from scripts.frames.common_frames import (LabelWithEntry, LaflasFrameBase,
                                          LaflasScrollableFrameBase)
from scripts.utils.constants import COMMON_ATTRIBUTES, DOF_CONTROL_TYPE

if TYPE_CHECKING:
    from customtkinter import CTkBaseClass
    from customtkinter.windows.widgets.scaling import CTkScalingBaseClass

    from scripts.app.laflas_app import LaflasApp
    from scripts.frames.laflas_frames import MainScrollable


class AddPhaseseFrame(LaflasFrameBase):
    """Frame for add more phases."""

    def __init__(
        self,
        master: "Phases",
        header_name: str = "Add Phases",
        **kwargs: Any,
    ) -> None:
        """Initialize add phases frame.

        Args:
            master: master of the frame.
            header_name: header name of frame.
        """
        super().__init__(master, header_name, **kwargs)

        # control model label
        self.control_label = CTkLabel(self, text="Control Type")
        self.control_label.grid(row=1, column=0, padx=10, pady=10)

        # default values
        self.dof = "3DoF"
        self.control = "i"

        # DoF type
        self.dof_value = StringVar(self, value="3DoF")
        self.dof_type = CTkComboBox(
            self,
            values=["3DoF", "6DoF"],
            variable=self.dof_value,
            command=self.dof_combobox_select,
        )
        self.dof_type.grid(row=1, column=1, padx=10, pady=10)

        # phase mode
        self.control_value = StringVar(self, value="i")
        self.control_type = CTkComboBox(
            self,
            values=list(DOF_CONTROL_TYPE[self.dof].keys()),
            variable=self.control_value,
            command=self.control_combobox_select,
        )
        self.control_type.grid(row=1, column=2, padx=10, pady=10)

        # create commit button
        self.add_button = CTkButton(self, text="Add", command=self.add_button_pressed)
        self.add_button.grid(row=2, column=2, padx=10, pady=10, sticky="NSEW")

    def add_button_pressed(self) -> None:
        """Call when add button pressed."""
        self.master.phases_frame.create_phase_frame(self.dof, self.control)  # type: ignore

    def dof_combobox_select(self, choice: Any) -> None:
        """Call when DoF combo box is selected."""
        self.dof = choice
        self.control_type.configure(values=DOF_CONTROL_TYPE[self.dof])
        print(self.dof)

    def control_combobox_select(self, choice: Any) -> None:
        """Call when control combo box is selected."""
        self.control = choice
        print(self.control)


class PhaseScrollable(LaflasScrollableFrameBase):
    """Scrollable frame for phases."""

    def __init__(
        self,
        master: Union["LaflasApp", "CTkBaseClass", "MainScrollable", "Phases"],
        **kwargs: Any,
    ) -> None:
        """Initialize phase scrollable frame."""
        super().__init__(
            master,
            header_name="",
            show_label=False,
            width=1500,
            # height=600,
            **kwargs,
        )
        self.phase_frames: List[PhaseFrame] = []

    def create_phase_frame(self, dof: str, control_mode: str) -> None:
        """Create phase frame."""
        phase_frame = PhaseFrame(
            self,
            "Phase #" + str(len(self.phase_frames) + 1),
            dof=dof,
            control_mode=control_mode,
        )
        phase_frame.grid(row=len(self.phase_frames) + 1, column=0, padx=10, pady=10)
        self.phase_frames.append(phase_frame)

    def parse(self) -> dict:
        """Parse data."""
        result = {}
        datas = []
        for frame in self.phase_frames:
            datas.append(frame.parse())
        result.update({"IPHAS": datas})
        return result


class PhaseFrame(LaflasFrameBase):
    """Frame for phase."""

    def __init__(
        self,
        master: Union["LaflasApp", "CTkBaseClass", "CTkScalingBaseClass"],
        header_name: str,
        dof: str = "3DoF",
        control_mode: str = "i",
        **kwargs: Any,
    ) -> None:
        """Initialize Phase frame class.

        Args:
            master: master of the frame.
            header_name: header name of frame.
            dof: Degree of freedom.
            control_mode: Control mode.
        """
        super().__init__(master, header_name, **kwargs)
        # create entry for phase common configuration
        # phase id
        # self.phase_id_frame = LabelWithEntry(self, "ID", ": ")
        # self.phase_id_frame.grid(row=1, column=0, padx=10, pady=10)

        self.entries: dict = {}
        self.dof = dof
        self.control_mode = control_mode
        self.create_common()
        self.create_control_frame()

    def create_common(self) -> None:
        """Create common frames."""
        for i, attr in enumerate(COMMON_ATTRIBUTES):
            frame = LabelWithEntry(self, attr)
            frame.grid(row=1, column=i, padx=10, pady=10)
            self.entries.update({attr: frame})

    def create_control_frame(self) -> None:
        """Create control frames."""
        label = CTkLabel(self, text=f"Control Type [{self.control_mode}]")
        label.grid(row=2, column=0)
        for i, attr in enumerate(DOF_CONTROL_TYPE[self.dof][self.control_mode]):
            frame = LabelWithEntry(self, attr)
            frame.grid(row=2, column=i + 1, padx=10, pady=10)
            self.entries.update({attr: frame})

    def parse(self) -> Any:
        """Parse data."""
        result = {"DoF": literal_eval(self.dof[0]), "cType": self.control_mode}
        for key, value in self.entries.items():
            if key == "ID":
                data = value.parse()
            elif key in ["attFix", "attVar", "actVar"]:
                data = literal_eval(f"[{value.parse()}]")
            else:
                data = literal_eval(value.parse())
            result.update({key: data})
        return result


class Phases(LaflasFrameBase):
    """Phases Frame."""

    def __init__(
        self, master: "MainScrollable", header_name: str, **kwargs: Any
    ) -> None:
        """Initialize phases frame."""
        super().__init__(master, header_name, **kwargs)
        self.add_phases = AddPhaseseFrame(self)
        self.add_phases.grid(row=1, column=0, padx=10, pady=10, sticky="NW")

        self.phases_frame = PhaseScrollable(self, border_width=1)
        self.phases_frame.grid(row=2, column=0, padx=10, pady=10, sticky="NSEW")

    def parse(self) -> dict:
        """Parse data."""
        return self.phases_frame.parse()
