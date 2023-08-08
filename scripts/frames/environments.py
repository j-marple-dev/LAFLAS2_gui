"""Module for environment frame.

-Author: Haneol Kim
-Contact: hekim@jmarple.ai
"""
# pylint: disable=duplicate-code

from ast import literal_eval
from typing import TYPE_CHECKING, Any, Optional, Union

from scripts.frames.common_frames import LabelWithComboBox, LaflasFrameBase
from scripts.utils.constants import ENV_ATTRIBUTES

if TYPE_CHECKING:
    from customtkinter import CTk, CTkBaseClass
    from customtkinter.windows.widgets.scaling import CTkScalingBaseClass

    from scripts.app.laflas_app import LaflasApp
    from scripts.frames.laflas_frames import MainScrollable


class EnvironmentScrollable(LaflasFrameBase):
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
        """Initialize EnvironmentScrollable class."""
        super().__init__(
            master, header_name, pad_x, pad_y, sticky, show_label, **kwargs
        )

        self.environment_frame: EnvironmentFrame
        self.create_environment_frame()

    def create_environment_frame(self) -> None:
        """Create environment frame."""
        frame = EnvironmentFrame(self, "Environment")
        frame.grid(row=1, column=0, padx=10, pady=10)
        self.environment_frame = frame

    def parse(self) -> dict:
        """Parse data."""
        result = {"IENVI": self.environment_frame.parse()}
        return result


class EnvironmentFrame(LaflasFrameBase):
    """Frame for fixed masses."""

    def __init__(
        self,
        master: Union["CTk", "CTkBaseClass", "EnvironmentScrollable"],
        header_name: str = "Initial Condition",
        **kwargs: Any,
    ) -> None:
        """Initialize EnvironmentFrame class.

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
        for i, attr in enumerate(ENV_ATTRIBUTES):
            if i == 0:
                frame = LabelWithComboBox(self, frame_id=attr, postfix="", combo_box=['0', '1', '2'])
            else:
                frame = LabelWithComboBox(self, frame_id=attr, combo_box=['0', '1'])
            frame.grid(row=(i // 2) + 1, column=i % 2, padx=10, pady=10)
            self.entries.update({attr: frame})


    def parse(self) -> dict:
        """Parse data."""
        result = {}
        for key, value in self.entries.items():
            data = literal_eval(value.parse())
            result.update({key: data})

        return result
