"""File utility.

-Author: Haneol Kim
-Contact: hekim@jmarple.ai
"""

# pylint: disable=consider-using-f-string, unspecified-encoding

import yaml

from scripts.utils.constants import FIXED_MASS_ATTRIBUTES


def dump_yaml(filepath: str, data: dict) -> None:
    """Dump data to yaml file."""
    with open(filepath, "w") as file:
        yaml.dump(data, file)


def dump_dat(filename: str, data: dict) -> None:
    """Dump data to dat file."""
    with open(filename, "w") as file:
        # Fixed mass
        file.write("F\r\n")
        file.write(f"{len(data['IFIXM'])}\r\n")
        for fixm in data["IFIXM"]:
            for k in FIXED_MASS_ATTRIBUTES:
                file.write(f"{fixm[k]}\r\n")

        file.write("#\r\n")

        # Variable mass
        file.write("V\r\n")
        file.write(f"{len(data['IVARM'])}\r\n")
        for varm in data["IVARM"]:
            file.write(f"{varm['ID']}\r\n")
            file.write("%d\r\n" % varm["Quan"])
            file.write("%10.2f\r\n" % varm["mass_s"])
            file.write("%10.2f\r\n" % varm["mass_p"])
            file.write("%.2f\r\n" % varm["isp"])
            file.write(" %.4f\r\n" % varm["aEx"])
            file.write(f"{varm['nTime']}")
            file.write(f"{varm['iType']}")
            for i in range(varm["nTime"]):
                file.write(
                    "%10.4f %10.4f\r\n"
                    % (varm["tVSthr"][2 * i], varm["tVSthr"][2 * i + 1])
                )
        file.write("#\r\n")

        # Aerodynamics
        file.write("A\r\n")
        file.write(f"{len(data['IAERO'])}\r\n")

        for aero in data["IAERO"]:
            file.write(f"{aero['ID']}\r\n")
            file.write("%10.6f\r\n" % aero["eRef"])

            for i in range(aero["nMCA"]):
                file.write(f"{aero['nMCA']}\r\n")
                file.write(
                    "%6.2f %6.2f\r\n" % (aero["tMCA"][2 * i], aero["tMCA"][2 * i + 1])
                )
            for i in range(aero["nMCN"]):
                file.write(f"{aero['nMCN']}\r\n")
                file.write(
                    "%6.2f %6.2f\r\n" % (aero["tMCN"][2 * i], aero["tMCN"][2 * i + 1])
                )
            for i in range(aero["nMCY"]):
                file.write(f"{aero['nMCY']}\r\n")
                file.write(
                    "%6.2f %6.2f\r\n" % (aero["tMCY"][2 * i], aero["tMCY"][2 * i + 1])
                )

        file.write("#\r\n")

        # Phase elements
        file.write("P\r\n")
        file.write(
            "%d %d\r\n%s\r\n" % (len(data["IPHAS"]), len(data["IPHAS"]) - 1, "R")
        )
        for phase in data["IPHAS"]:
            file.write(f"{phase['ID']}\r\n")
            file.write("%10.4f" % phase["Time end"])
            file.write(f"{phase['iAero'] - 1}")
            for i in range(len(data["IFIXM"]) - 1):
                file.write("%d " % phase["attFix"][i])
            file.write("%d\r\n" % phase["attFix"][i + 1])  # type: ignore
            for i in range(len(data["IVARM"]) - 1):
                file.write("%d " % phase["attVar"][i])
            file.write("%d\r\n" % phase["attVar"][i + 1])  # type: ignore
            for i in range(len(data["IVARM"]) - 1):
                file.write("%d " % phase["actVar"][i])
            file.write("%d\r\n" % phase["actVar"][i + 1])  # type: ignore
