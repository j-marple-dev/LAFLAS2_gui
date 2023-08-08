"""Common frame module.

-Author: Haneol Kim
-Contact: hekim@jmarple.ai
"""

# pylint: disable=duplicate-code

from abc import ABC, abstractmethod
from typing import TYPE_CHECKING, Any, List, Optional, Union

from customtkinter import (CTkButton, CTkComboBox, CTkEntry, CTkFont, CTkFrame,
                           CTkLabel, CTkScrollableFrame, StringVar)

if TYPE_CHECKING:
    from customtkinter import CTk, CTkBaseClass
    from customtkinter.windows.widgets.scaling import CTkScalingBaseClass

    from scripts.app.laflas_app import LaflasApp


class ButtonWithEntry(CTkFrame):
    """Frame with button and entry."""

    def __init__(
        self,
        master: Union["LaflasApp", "CTkBaseClass"],
        frame_id: str,
        button_text: str,
        **kwargs: Any,
    ) -> None:
        """Initialize ButtonWithEntry class.

        Args:
            master: master of the frame.
            frame_id: id of this frame.
            ph_text: placeholder text.
        """
        super().__init__(master, **kwargs)

        self.frame_id = frame_id
        self.button_text = button_text

        self.header = CTkLabel(self, text=self.frame_id)
        self.header.grid(row=0, column=0, padx=10, pady=10)

        self.entry_variable = StringVar(value="")

        self.entry = CTkEntry(self, textvariable=self.entry_variable)
        self.entry.grid(row=1, column=0, padx=10, pady=10)

        self.button = CTkButton(
            self, text=self.button_text, command=self.button_pressed
        )
        self.button.grid(row=1, column=1, padx=10, pady=10)

    @abstractmethod
    def button_pressed(self) -> None:
        """Call when the button pressed."""


class LabelWithEntry(CTkFrame):
    """Class which contains label and entry."""

    def __init__(
        self,
        master: Union["LaflasApp", "CTkBaseClass"],
        frame_id: str,
        postfix: str = "",
        **kwargs: Any,
    ) -> None:
        """Initialize LabelWithEntry class.

        Args:
            master: master of the frame.
            frame_id: id of this frame.
        """
        super().__init__(master, **kwargs)

        self.frame_id = frame_id
        self.postfix = postfix

        # create label
        label_text = self.frame_id + self.postfix
        self.label = CTkLabel(self, text=label_text)
        self.label.grid(row=0, column=0, padx=10, pady=10)

        # create entry
        self.entry_variable = StringVar(self, value="")
        self.entry = CTkEntry(self, textvariable=self.entry_variable)
        self.entry.grid(row=0, column=1, padx=10, pady=10)

    def parse(self) -> str:
        """Parse data."""
        return self.entry.get()


class LabelWithComboBox(CTkFrame):
    """Class which contains label and combo box."""

    def __init__(
        self,
        master: Union["LaflasApp", "CTkBaseClass"],
        frame_id: str,
        combo_box: list,
        postfix: str = "",
        **kwargs: Any,
    ) -> None:
        """Initialize LabelWithComboBox class.

        Args:
            master: master of the frame.
            frame_id: id of this frame.
            combo_box: combo box contents
        """
        assert (
            len(combo_box) >= 1
        ), "The length of list combo_box should be longer than 0."
        super().__init__(master, **kwargs)

        self.frame_id = frame_id
        self.postfix = postfix
        self.combo_box = combo_box

        # create label
        label_text = self.frame_id + self.postfix
        self.label = CTkLabel(self, text=label_text)
        self.label.grid(row=0, column=0, padx=10, pady=10)

        # create combo box
        self.data_variable = StringVar(self, value=self.combo_box[0])
        self.data: str = ""
        self.cbox = CTkComboBox(
            self,
            values=self.combo_box,
            variable=self.data_variable,
            command=self.get_combobox_data,
        )
        self.cbox.grid(row=0, column=1, padx=10, pady=10)

    def get_combobox_data(self, choice: str) -> None:
        """Get data from combo box."""
        self.data = choice
        print(self.data)

    def parse(self) -> str:
        """Parse data."""
        if self.data:
            return self.data
        return self.cbox.get()


class LabelWithMultiEntry(CTkFrame):
    """Frame for label with multi entries."""

    def __init__(
        self,
        master: Union["LaflasApp", "CTkBaseClass"],
        frame_id: str,
        n_entries: int = 4,
        postfix: str = "",
        **kwargs: Any,
    ) -> None:
        """Initialize LabelWithComboBox class.

        Args:
            master: master of the frame.
            frame_id: id of this frame.
            combo_box: combo box contents
        """
        super().__init__(master, **kwargs)

        self.frame_id = frame_id
        self.postfix = postfix
        self.n_entries = n_entries

        label_text = frame_id + postfix
        self.label = CTkLabel(self, text=label_text)
        self.label.grid(row=0, column=0, padx=10, pady=10)

        self.entry: List[CTkEntry] = []
        self.var: List[StringVar] = []

        for i in range(self.n_entries):
            var = StringVar(self)
            entry = CTkEntry(self, textvariable=var)
            entry.grid(row=(i // 2), column=1 + (i % 2), padx=10, pady=10)
            self.var.append(var)
            self.entry.append(entry)

    def parse(self) -> List[str]:
        """Parse data."""
        result = []
        for entry in self.entry:
            result.append(entry.get())

        return result


class LaflasFrameBase(CTkFrame, ABC):
    """Base class for laflas frames."""

    def __init__(
        self,
        master: Union["LaflasApp", "CTkBaseClass", "CTk", "CTkScalingBaseClass"],
        header_name: str,
        pad_x: int = 0,
        pad_y: int = 0,
        sticky: Optional[str] = "NSEW",
        show_label: bool = True,
        **kwargs: Any,
    ) -> None:
        """Initialize Laflas frame base class."""
        super().__init__(master, **kwargs)

        # set attributes
        self.header: CTkLabel
        self.header_name = header_name
        self.pad_x = pad_x
        self.pad_y = pad_y
        self.sticky = sticky
        self.show_label = show_label

        # create header
        if self.show_label:
            self.create_header()

    def create_header(self) -> None:
        """Create header label."""
        self.header = CTkLabel(self, text=self.header_name, font=CTkFont(weight="bold"))
        self.header.grid(
            row=0,
            column=0,
            padx=self.pad_x,
            pady=self.pad_y,
            sticky=self.sticky if self.sticky else None,
        )


class LaflasScrollableFrameBase(CTkScrollableFrame, ABC):
    """Base class for laflas scrollable frame base."""

    def __init__(
        self,
        master: Union["LaflasApp", "CTkBaseClass", "CTk", "CTkScalingBaseClass"],
        header_name: str,
        pad_x: int = 0,
        pad_y: int = 0,
        sticky: Optional[str] = "NSEW",
        show_label: bool = True,
        **kwargs: Any,
    ) -> None:
        """Initialize LaflasScrollableFrameBase class."""
        super().__init__(master, **kwargs)

        # set attributes
        self.header: CTkLabel
        self.header_name = header_name
        self.pad_x = pad_x
        self.pad_y = pad_y
        self.sticky = sticky
        self.show_label = show_label

        # create header
        if self.show_label:
            self.create_header()

    def create_header(self) -> None:
        """Create header label."""
        self.header = CTkLabel(self, text=self.header_name, font=CTkFont(weight="bold"))
        self.header.grid(
            row=0,
            column=0,
            padx=self.pad_x,
            pady=self.pad_y,
            sticky=self.sticky if self.sticky else None,
        )
