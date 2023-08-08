"""Module for initial condition frame.

-Author: Haneol Kim
-Contact: hekim@jmarple.ai
"""

from ast import literal_eval
from typing import TYPE_CHECKING, Any, Optional, Union

from scripts.frames.common_frames import LabelWithEntry, LaflasFrameBase
from scripts.utils.constants import INIT_ATTRIBUTES

if TYPE_CHECKING:
    from customtkinter import CTk, CTkBaseClass
    from customtkinter.windows.widgets.scaling import CTkScalingBaseClass

    from scripts.app.laflas_app import LaflasApp
    from scripts.frames.laflas_frames import MainScrollable


class InitialConditionScrollable(LaflasFrameBase):
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

        self.initial_condition_frame: InitialConditionFrame
        self.create_initial_condition_frame()

    def create_initial_condition_frame(self) -> None:
        """Create fixed mass frame."""
        frame = InitialConditionFrame(self, "Initial Condition")
        frame.grid(row=1, column=0, padx=10, pady=10)
        self.initial_condition_frame = frame

    def parse(self) -> dict:
        """Parse data."""
        result = {"IINIT": self.initial_condition_frame.parse()}
        return result


class InitialConditionFrame(LaflasFrameBase):
    """Frame for fixed masses."""

    def __init__(
        self,
        master: Union["CTk", "CTkBaseClass", "InitialConditionScrollable"],
        header_name: str = "Initial Condition",
        **kwargs: Any,
    ) -> None:
        """Initialize InitialConditionFrame class.

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
        for i, attr in enumerate(INIT_ATTRIBUTES):
            frame = LabelWithEntry(self, frame_id=attr, postfix="")
            frame.grid(row=(i // 3) + 1, column=i % 3, padx=10, pady=10)
            self.entries.update({attr: frame})

    def parse(self) -> dict:
        """Parse data."""
        result = {}
        for key, value in self.entries:
            data = literal_eval(value.parse())
            result.update({key: data})

        return result
