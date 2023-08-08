"""Aero frame module.

-Author: Haneol Kim
-Contact: hekim@jmarple.ai
"""
# pylint: disable=duplicate-code

from ast import literal_eval
from typing import TYPE_CHECKING, Any, List, Optional, Union

from customtkinter import CTkButton

from scripts.frames.common_frames import (LabelWithEntry, LaflasFrameBase,
                                          LaflasScrollableFrameBase)
from scripts.utils.constants import AERO_ATTRIBUTES

if TYPE_CHECKING:
    from customtkinter import CTk, CTkBaseClass
    from customtkinter.windows.widgets.scaling import CTkScalingBaseClass

    from scripts.app.laflas_app import LaflasApp
    from scripts.frames.laflas_frames import MainScrollable


class AeroScrollable(LaflasScrollableFrameBase):
    """Aero scrollable frame class."""

    def __init__(
        self,
        master: Union[
            "LaflasApp", "CTkBaseClass", "CTk", "CTkScalingBaseClass", "MainScrollable"
        ],
        header_name: str,
        pad_x: int = 0,
        pad_y: int = 0,
        sticky: Optional[str] = "NSEW",
        show_label: bool = True,
        **kwargs: Any,
    ) -> None:
        """Initialize AeroScrollable class."""
        super().__init__(
            master, header_name, pad_x, pad_y, sticky, show_label, **kwargs
        )

        self.aero_mass_frames: List[AeroFrame] = []
        for _ in range(1):
            self.create_aero()

    def create_aero(self) -> None:
        """Create aero frame."""
        frame = AeroFrame(self, "Aero #" + str(len(self.aero_mass_frames) + 1))
        frame.grid(
            row=(len(self.aero_mass_frames) // 2) + 1,
            column=(len(self.aero_mass_frames) % 2),
            padx=10,
            pady=10,
        )
        self.aero_mass_frames.append(frame)

    def parse(self) -> dict:
        """Parse data."""
        result = {}
        datas = []
        for frame in self.aero_mass_frames:
            datas.append(frame.parse())

        result.update({"IAERO": datas})
        return result


class AeroFrame(LaflasFrameBase):
    """Frame for fixed masses."""

    def __init__(
        self,
        master: Union["CTk", "CTkBaseClass", "AeroScrollable"],
        header_name: str = "Aero",
        **kwargs: Any,
    ) -> None:
        """Initialize AeroFrame class.

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
        for i, attr in enumerate(AERO_ATTRIBUTES):
            frame = LabelWithEntry(self, frame_id=attr, postfix="")
            frame.grid(row=(i // 3) + 1, column=i % 3, padx=10, pady=10)
            self.entries.update({attr: frame})

    def parse(self) -> dict:
        """Parse data."""
        result = {}
        checker = ["tMCA", "tMCN", "tMCY"]
        for key, value in self.entries.items():
            if key in checker:
                data = literal_eval(f"[{value.parse()}]")
                print(f"{data}, {len(data)}")
                assert (
                    len(data) % 2
                ) == 0, "The length of tMCA, tMCN, tMCY should be even."
                num = "n" + key[1:]
                result.update({num: len(data) // 2})
            elif key == "ID":
                data = value.parse()
            else:
                data = literal_eval(value.parse())
            result.update({key: data})
        return result


class Aero(LaflasFrameBase):
    """Aero class."""

    def __init__(
        self, master: "MainScrollable", header_name: str = "Aero", **kwargs: Any
    ) -> None:
        """Initialize Aero class."""
        super().__init__(master, header_name, **kwargs)

        self.add_button = CTkButton(self, text="Add Aero", command=self.create_aero)
        self.add_button.grid(row=1, column=0, padx=10, pady=10, sticky="NW")

        self.frame = AeroScrollable(self, "", show_label=False, width=1500)
        self.frame.grid(row=2, column=0, padx=10, pady=10)

    def create_aero(self) -> None:
        """Create aero."""
        self.frame.create_aero()

    def parse(self) -> dict:
        """Parse data."""
        return self.frame.parse()
