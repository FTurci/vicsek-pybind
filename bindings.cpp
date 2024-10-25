#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "box.hpp"      // Ensure this header is included
#include "particle.hpp" // Ensure this header is included
#include "system.hpp"   // Ensure this header is included

namespace py = pybind11;

PYBIND11_MODULE(myvic, m) {
    // Binding for the System class
    py::class_<System>(m, "System")
        .def(py::init<int, double,double, double, double>(), 
             py::arg("nparticles"), py::arg("sidex"), py::arg("sidey"), py::arg("dt"), py::arg("noise"))
        .def_readonly("nparticles",&System::nparticles)
        .def_readwrite("noise",&System::noise)
        .def_readonly("dt",&System::dt)
        .def("random_start", &System::random_start)
        .def("update", &System::update)
        .def("print_status", &System::print_status)
        .def("gen_uniform", &System::gen_uniform, 
             py::arg("min"), py::arg("max"))
        .def("save_config", &System::save_config, 
             py::arg("filename"))
        .def("get_config", &System::get_config)
        .def("update", &System::update)
             ;
}
