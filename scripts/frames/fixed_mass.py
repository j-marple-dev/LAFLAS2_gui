"""Fixed mass frame module.

-Author: Haneol Kim
-Contact: hekim@jmarple.ai
"""

# pylint: disable=duplicate-code

from ast import literal_eval
from typing import TYPE_CHECKING, Any, List, Optional, Union

from customtkinter import CTkButton

from scripts.frames.common_frames import (LabelWithEntry, LaflasFrameBase,
                                          LaflasScrollableFrameBase)
from scripts.utils.constants import FIXED_MASS_ATTRIBUTES

if TYPE_CHECKING:
    from customtkinter import CTk, CTkBaseClass
    from customtkinter.windows.widgets.scaling import CTkScalingBaseClass

    from scripts.app.laflas_app import LaflasApp
    from scripts.frames.laflas_frames import MainScrollable


class FixedMassScrollable(LaflasScrollableFrameBase):
    """Fixed mass scrollable frame class."""

    def __init__(
        self,
        master: Union[
            "LaflasApp", "CTkBaseClass", "CTk", "CTkScalingBaseClass", "MainScrollable"
        ],
        header_name: str = "",
        pad_x: int = 0,
        pad_y: int = 0,
        sticky: Optional[str] = "NSEW",
        show_label: bool = False,
        **kwargs: Any,
    ) -> None:
        """Initialize FixedMassScrollable class."""
        super().__init__(
            master, header_name, pad_x, pad_y, sticky, show_label, **kwargs
        )

        self.fixed_mass_frames: List[FixedMassFrame] = []
        for _ in range(1):
            self.create_fixed_mass_frame()

    def create_fixed_mass_frame(self) -> None:
        """Create fixed mass frame."""
        frame = FixedMassFrame(
            self, "Fixed Mass #" + str(len(self.fixed_mass_frames) + 1)
        )
        frame.grid(
            row=(len(self.fixed_mass_frames) // 2) + 1,
            column=(len(self.fixed_mass_frames) % 2),
            padx=10,
            pady=10,
        )
        self.fixed_mass_frames.append(frame)

    def parse(self) -> dict:
        """Parse data."""
        result = {}
        datas = []
        for frame in self.fixed_mass_frames:
            datas.append(frame.parse())

        result.update({"IFIXM": datas})
        return result


class FixedMassFrame(LaflasFrameBase):
    """Frame for fixed masses."""

    def __init__(
        self,
        master: Union["CTk", "CTkBaseClass", "FixedMassScrollable"],
        header_name: str = "Fixed Mass",
        **kwargs: Any,
    ) -> None:
        """Initialize FixedMassFrame class.

        Args:
            master: master of the frame.
            header_name: header name of frame.
        """
        # initialize ancestor class
        super().__init__(master, header_name, **kwargs)

        self.entries: dict = {}
        self.create_entries()

    def create_entries(self) -> None:
        """Create entries."""
        for i, attr in enumerate(FIXED_MASS_ATTRIBUTES):
            frame = LabelWithEntry(self, frame_id=attr, postfix="")
            frame.grid(row=1, column=i, padx=10, pady=10)
            self.entries.update({attr: frame})

    def parse(self) -> dict:
        """Parse data."""
        result = {}
        for key, value in self.entries:
            if key == "ID":
                data = value.parse()
            else:
                data = literal_eval(value.parse())
            result.update({key: data})

        return result


class FixedMass(LaflasFrameBase):
    """Fixed mass class."""

    def __init__(
        self, master: "MainScrollable", header_name: str = "Fixed mass", **kwargs: Any
    ) -> None:
        """Initialize fixed mass class."""
        super().__init__(master, header_name, **kwargs)

        self.add_fixed_mass = CTkButton(
            self, text="Add Fixed Mass", command=self.create_fixed_mass
        )
        self.add_fixed_mass.grid(row=1, column=0, padx=10, pady=10, sticky="NW")

        self.frame = FixedMassScrollable(self, width=1500)
        self.frame.grid(row=2, column=0, padx=10, pady=10)

    def create_fixed_mass(self) -> None:
        """Create fixed mass frame."""
        self.frame.create_fixed_mass_frame()

    def parse(self) -> dict:
        """Parse data."""
        return self.frame.parse()
