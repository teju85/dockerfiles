#include <pybind11/pybind11.h>
namespace py = pybind11;

extern void hello();

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 gpu example plugin";
    m.def("hello", &hello, "Hello world CUDA kernel!");
}
