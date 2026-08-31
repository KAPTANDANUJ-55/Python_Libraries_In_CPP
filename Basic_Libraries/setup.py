from setuptools import setup, Extension

class get_pybind_include:
    def __str__(self):
        import pybind11
        return pybind11.get_include()

ext_modules = [
    Extension(
        "danujeasyhelper",
        ["esyHelper.cpp"],
        include_dirs=[get_pybind_include()],
        language="c++",
        extra_compile_args=["-std=c++17"] if not __import__("sys").platform.startswith("win") else ["/std:c++17"],
    ),
]

setup(
    name="kaptandanuj-easyhelper",
    version="0.0.2",
    description="Beginner friendly helper library powered by C++",
    ext_modules=ext_modules,
    setup_requires=["pybind11>=2.10.0"],
    install_requires=[],
)