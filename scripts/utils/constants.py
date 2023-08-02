"""Module for constants using in LAFLAS.

-Author: Haneol Kim
-Contact: hekim@jmarple.ai
"""

CONTROL_TYPE_3DOF = {
    "a": ["alp_s", "alp_e", "bet_s", "bet_e"],
    "p": ["pit_s", "pit_e", "yaw_s", "yaw_e"],
    "q": ["pit_s", "pit_e", "yaw_s"],
    "r": ["pit_s", "yaw_s"],
    "i": ["pit_e", "yaw_e"],
    "s": ["pit_s", "yaw_s", "yaw_e"],
    "g": ["yaw_s", "yaw_e"],
}

CONTROL_TYPE_6DOF = {
    "c": ["pit_r", "yaw_r"],
    "k": ["pit_r", "yaw_r"],
    "m": ["pit_r", "yaw_r"],
    "w": ["pit_r", "yaw_r"],
    "v": ["pit_r", "yaw_r"],
    "l": ["pit_r", "yaw_r"],
    "i": ["pit_r", "yaw_e"],
}

DOF_CONTROL_TYPE = {
    "3DoF": CONTROL_TYPE_3DOF,
    "6DoF": CONTROL_TYPE_6DOF,
}

COMMON_ATTRIBUTES = [
    "ID",
    "Time end",
    "iAero",
    "attFix",
    "attVar",
    "actVar",
]

FIXED_MASS_ATTRIBUTES = [
    "ID",
    "Quan",
    "Mass",
]

VARIABLE_MASS_ATTRIBUTES = [
    "ID",
    "Quan",
    "mass_s",
    "mass_p",
    "isp",
    "aEx",
    "iType",
    "tVSthr",
]

AERO_ATTRIBUTES = [
    "ID",
    "aRef",
    "tMCA",
    "tMCN",
]

INIT_ATTRIBUTES = [
    "LAT0",
    "LON0",
    "ALT_I0",
    "AZI0",
    "PAT0",
    "VEL0",
]
