from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext
import os
import sys

__version__ = "0.0.1"

# Define your compiler (gcc or clang)
compiler = "g++"  # Change this to "clang++" if you're using Clang

def get_openmp_flags():
    """Return compiler flags for OpenMP."""
    if "g++" in compiler:
        return ["-fopenmp"]  # Compiler flags for GCC
    elif "clang++" in compiler:
        return ["-fopenmp"]  # Compiler flags for Clang
    else:
        return []

def get_openmp_link_flags():
    """Return linker flags for OpenMP."""
    if "g++" in compiler:
        return ["-lgomp"]  # Linker flags for GCC
    elif "clang++" in compiler:
        return []  # Clang typically doesn't require additional linker flags
    else:
        return []

ext_modules = [
    Pybind11Extension(
        "vicsecapp",
        ["bindings.cpp"],
        define_macros=[("VERSION_INFO", __version__)],
        extra_compile_args=get_openmp_flags(),  # Add OpenMP compile flags
        extra_link_args=get_openmp_link_flags(),  # Add OpenMP link flags
    ),
]

setup(
    name="vicsecapp",
    version=__version__,
    author="Francesco Turci",
    author_email="f.turci@bristol.ac.uk",
    description="A test project using pybind11 with OpenMP",
    long_description="",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    python_requires=">=3.7",
)
