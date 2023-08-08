"""Variable mass frame module.

-Author: Haneol Kim
-Contact: hekim@jmarple.ai
"""
# pylint: disable=duplicate-code

from ast import literal_eval
from typing import TYPE_CHECKING, Any, List, Union

from customtkinter import CTkButton

from scripts.frames.common_frames import (LabelWithComboBox, LabelWithEntry,
                                          LaflasFrameBase,
                                          LaflasScrollableFrameBase)
from scripts.utils.constants import VARIABLE_MASS_ATTRIBUTES

if TYPE_CHECKING:
    from customtkinter import CTkBaseClass
    from customtkinter.windows.widgets.scaling import CTkScalingBaseClass

    from scripts.app.laflas_app import LaflasApp
    from scripts.frames.laflas_frames import MainScrollable


class VariableMassFrame(LaflasFrameBase):
    """Frame for variable mass."""

    def __init__(
        self,
        master: Union["LaflasApp", "CTkBaseClass", "CTkScalingBaseClass"],
        header_name: str = "Variable Mass",
        **kwargs: Any,
    ) -> None:
        """Initialize VariableMassFrame class."""
        super().__init__(master, header_name, **kwargs)

        self.entries: dict = {}
        self.create_entries()

    def create_entries(self) -> None:
        """Create variable mass entries."""
        for i, attr in enumerate(VARIABLE_MASS_ATTRIBUTES):
            if attr == "iType":
                frame = LabelWithComboBox(self, attr, ["T", "M"])

            else:
                frame = LabelWithEntry(self, attr)

            frame.grid(row=(i // 4) + 1, column=i % 4, padx=10, pady=10)
            self.entries.update({attr: frame})

    def parse(self) -> dict:
        """Parse data."""
        result = {}
        for key, value in self.entries.items():
            if key == "tVSthr":
                data = literal_eval(f"[{value.parse()}]")
                assert len(data) % 2 == 0, "The number of tVSthr have to be even."
                result.update({"nTime": len(data) // 2})
            elif key in ("ID", "iType"):
                data = value.parse()
            else:
                data = literal_eval(value.parse())
            result.update({key: data})
        return result


class VariableMassScrollable(LaflasScrollableFrameBase):
    """Scrollable class for variable mass."""

    def __init__(
        self,
        master: Union["LaflasApp", "CTkBaseClass", "MainScrollable"],
        header_name: str = "",
        show_label: bool = False,
        **kwargs: Any,
    ) -> None:
        """Initialize phase scrollable frame."""
        super().__init__(
            master, header_name=header_name, show_label=show_label, **kwargs
        )
        self.var_frames: List[VariableMassFrame] = []
        self.create_var_mass()

    def create_var_mass(self) -> None:
        """Create variable mass."""
        var_frame = VariableMassFrame(self, f"VMass #{len(self.var_frames) + 1}")
        var_frame.grid(row=len(self.var_frames) + 1, column=0, padx=10, pady=10)
        self.var_frames.append(var_frame)

    def parse(self) -> dict:
        """Parse data."""
        result = {}
        datas = []
        for var in self.var_frames:
            datas.append(var.parse())
        result.update({"IVARM": datas})
        return result


class VariableMass(LaflasFrameBase):
    """Variable mass class."""

    def __init__(
        self,
        master: "MainScrollable",
        header_name: str = "Variable Mass",
        **kwargs: Any,
    ) -> None:
        """Initialize variable mass class."""
        super().__init__(master, header_name, **kwargs)

        self.add_button = CTkButton(
            self, text="Add Variable Mass", command=self.create_variable_mass
        )
        self.add_button.grid(row=1, column=0, padx=10, pady=10, sticky="NW")

        self.frame = VariableMassScrollable(self, "", show_label=False, width=1500)
        self.frame.grid(row=2, column=0, padx=10, pady=10)

    def create_variable_mass(self) -> None:
        """Create variable mass."""
        self.frame.create_var_mass()

    def parse(self) -> dict:
        """Parse data."""
        return self.frame.parse()
