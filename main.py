"""Main script for your project.

- Author: Haneol Kim
- Contact: hekim@jmarple.ai
"""


import argparse

from scripts.app.laflas_app import LaflasApp


def get_parser() -> argparse.Namespace:
    """Get argument parser.

    Modify this function as your porject needs
    """
    parser = argparse.ArgumentParser(
        formatter_class=argparse.ArgumentDefaultsHelpFormatter
    )
    parser.add_argument("--hello", type=int, default=2, help="Print 'hello' n times")
    parser.add_argument("--world", type=int, default=3, help="Print 'world' n times")

    return parser.parse_args()


if __name__ == "__main__":
    args = get_parser()

    app = LaflasApp()
    app.mainloop()
