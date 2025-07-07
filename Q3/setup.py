# setup.py
from setuptools import setup, Extension

module = Extension("sensor_module", sources=["sensor_module.c"])

setup(
    name="sensor_module",
    version="1.0",
    description="Simulated IoT Sensor Module",
    ext_modules=[module]
)
