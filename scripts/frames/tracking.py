"""Tracking frame module.

-Author: Haneol Kim
-Contact: hekim@jmarple.ai
"""
# pylint: disable=duplicate-code

from ast import literal_eval
from typing import TYPE_CHECKING, Any, List, Optional, Union

from customtkinter import CTkButton

from scripts.frames.common_frames import (LabelWithEntry, LaflasFrameBase,
                                          LaflasScrollableFrameBase)
from scripts.utils.constants import TRK_ATTRIBUTES

if TYPE_CHECKING:
    from customtkinter import CTk, CTkBaseClass
    from customtkinter.windows.widgets.scaling import CTkScalingBaseClass

    from scripts.app.laflas_app import LaflasApp
    from scripts.frames.laflas_frames import MainScrollable


class TrackingScrollable(LaflasScrollableFrameBase):
    """Tracking scrollable frame class."""

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
        """Initialize TrackingScrollable class."""
        super().__init__(
            master, header_name, pad_x, pad_y, sticky, show_label, **kwargs
        )

        self.tracking_frames: List[TrackingFrame] = []
        for _ in range(1):
            self.create_tracking_frame()

    def create_tracking_frame(self) -> None:
        """Create tracking frame."""
        frame = TrackingFrame(self, "Tracking #" + str(len(self.tracking_frames) + 1))
        frame.grid(
            row=(len(self.tracking_frames) // 2) + 1,
            column=(len(self.tracking_frames) % 2),
            padx=10,
            pady=10,
        )
        self.tracking_frames.append(frame)

    def parse(self) -> dict:
        """Parse data."""
        result = {}
        datas = []
        for frame in self.tracking_frames:
            datas.append(frame.parse())

        result.update({"ITRAK": datas})
        return result


class TrackingFrame(LaflasFrameBase):
    """Frame for tracking."""

    def __init__(
        self,
        master: Union["CTk", "CTkBaseClass", "TrackingScrollable"],
        header_name: str = "Track",
        **kwargs: Any,
    ) -> None:
        """Initialize TrackingFrame class.

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
        for i, attr in enumerate(TRK_ATTRIBUTES):
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


class Track(LaflasFrameBase):
    """Track class."""

    def __init__(
        self, master: "MainScrollable", header_name: str = "Track", **kwargs: Any
    ) -> None:
        """Initialize track class."""
        super().__init__(master, header_name, **kwargs)

        self.add_track = CTkButton(self, text="Add Track", command=self.create_track)
        self.add_track.grid(row=1, column=0, padx=10, pady=10, sticky="NW")

        self.frame = TrackingScrollable(self, width=1500)
        self.frame.grid(row=2, column=0, padx=10, pady=10)

    def create_track(self) -> None:
        """Create tracking frame."""
        self.frame.create_tracking_frame()

    def parse(self) -> dict:
        """Parse data."""
        return self.frame.parse()
