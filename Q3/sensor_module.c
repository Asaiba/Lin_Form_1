// sensor_module.c
#include <Python.h>
#include <stdlib.h>
#include <time.h>

// Function that returns simulated temperature, humidity, and battery
static PyObject* get_sensor_data(PyObject* self, PyObject* args) {
    float temperature = (rand() % 400) / 10.0 + 10.0;  // 10.0°C to 50.0°C
    float humidity = (rand() % 800) / 10.0 + 20.0;     // 20% to 100%
    float battery = (rand() % 300) / 10.0 + 70.0;      // 70% to 100%

    return Py_BuildValue("(fff)", temperature, humidity, battery);
}

// Method definitions
static PyMethodDef SensorMethods[] = {
    {"get_sensor_data", get_sensor_data, METH_NOARGS, "Get simulated sensor readings."},
    {NULL, NULL, 0, NULL}
};

// Module definition
static struct PyModuleDef sensormodule = {
    PyModuleDef_HEAD_INIT,
    "sensor_module",
    "Simulated Sensor Module",
    -1,
    SensorMethods
};

// Initialization function
PyMODINIT_FUNC PyInit_sensor_module(void) {
    srand(time(NULL)); // Seed RNG
    return PyModule_Create(&sensormodule);
}
