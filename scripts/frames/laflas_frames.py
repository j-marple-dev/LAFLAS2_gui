"""Module for laflas frames.

-Author: Haneol Kim
-Contact: hekim@jmarple.ai
"""

import os
from typing import TYPE_CHECKING, Any

from scripts.frames.aero import Aero
from scripts.frames.common_frames import ButtonWithEntry  # noqa; noqa
from scripts.frames.common_frames import LaflasScrollableFrameBase
from scripts.frames.environments import EnvironmentScrollable
from scripts.frames.fixed_mass import FixedMass
from scripts.frames.initial import InitialConditionScrollable
from scripts.frames.phases import Phases
from scripts.frames.tracking import Track
from scripts.frames.variable_mass import VariableMass
from scripts.utils.file_utils import dump_yaml

if TYPE_CHECKING:
    from scripts.app.laflas_app import LaflasApp


class SaveFileFrame(ButtonWithEntry):
    """Frame for save file."""

    def __init__(  # pylint: disable=useless-parent-delegation
        self,
        master: "MainScrollable",
        frame_id: str,
        button_text: str = "Save",
        **kwargs: Any,
    ) -> None:
        """Initialize GetNumPhases class.

        Args:
            master: master of the frame.
            frame_id: id of this frame.
            ph_text: placeholder text.
        """
        super().__init__(master, frame_id, button_text, **kwargs)  # type: ignore

    def button_pressed(self) -> None:
        """Call when button pressed."""
        text = self.entry.get()
        if text.startswith("/"):
            save_dir = text
        else:
            save_dir = os.path.join(os.getcwd(), text)
        data = self.master.parse()  # type: ignore
        dump_yaml(save_dir, data)


class MainScrollable(LaflasScrollableFrameBase):
    """Main scrollable frame."""

    def __init__(
        self, master: "LaflasApp", header_name: str = "", **kwargs: Any
    ) -> None:
        """Initialize  main scrollable frame class."""
        super().__init__(master, header_name, show_label=False, **kwargs)

        # self.num_phases_frame = AddPhaseseFrame(self)
        # self.num_phases_frame.grid(row=0, column=0, padx=10, pady=10, sticky='W')

        self.init = InitialConditionScrollable(self)
        self.init.grid(row=1, column=0, padx=10, pady=10, sticky="NSEW")

        self.env = EnvironmentScrollable(self)
        self.env.grid(row=1, column=1, padx=10, pady=10, sticky="NW")

        self.track = Track(self, border_width=1)
        self.track.grid(row=2, column=0, columnspan=2, padx=10, pady=10, sticky="NSEW")

        self.aero = Aero(self, "Aero", border_width=1)
        self.aero.grid(row=3, column=0, columnspan=4, padx=10, pady=10, sticky="NSEW")

        self.fixed_mass = FixedMass(self, "Fixed Mass", border_width=1)
        self.fixed_mass.grid(
            row=4, column=0, padx=10, pady=10, sticky="NSEW", columnspan=3
        )
        self.var_mass = VariableMass(self, border_width=1)
        self.var_mass.grid(
            row=5, column=0, columnspan=3, padx=10, pady=10, sticky="NSEW"
        )
        self.phases = Phases(self, "Phases", border_width=1)
        self.phases.grid(row=6, column=0, columnspan=3, padx=10, pady=10, sticky="NSEW")

        self.save = SaveFileFrame(self, "Set save directory")
        self.save.grid(row=7, column=1, columnspan=2, padx=10, pady=10, sticky="NSEW")

    def parse(self) -> dict:
        """Parse data."""
        result = {}
        result.update(self.init.parse())
        result.update(self.env.parse())
        result.update(self.track.parse())
        result.update(self.aero.parse())
        result.update(self.fixed_mass.parse())
        result.update(self.var_mass.parse())
        result.update(self.phases.parse())

        return result
