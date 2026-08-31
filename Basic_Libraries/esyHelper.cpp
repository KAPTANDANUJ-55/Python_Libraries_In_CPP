#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>
#include <vector>
#include <unordered_set>

namespace py = pybind11;

template <typename T>
std::vector<T> remove_duplicates(const std::vector<T>& items) {
    std::vector<T> result;
    std::unordered_set<T> seen;

    result.reserve(items.size()); // reallocation avoid karne ke liye

    for (const auto& item : items) {
        // Agar pehle nahi dekha
        if (seen.find(item) == seen.end()) {
            seen.insert(item);
            result.push_back(item);
        }
    }
    return result;
}

PYBIND11_MODULE(danujeasyhelper, m) {
    m.doc() = "A basic helper function which removes duplicate from list";

    // Integers Bind
    m.def("unique", &remove_duplicates<int>, 
          "Remove duplicates from integer list while preserving order", 
          py::arg("items"));

    // Strings Bind
    m.def("unique", &remove_duplicates<std::string>, 
          "Remove duplicates from string list while preserving order", 
          py::arg("items"));

    // Floats Bind
    m.def("unique", &remove_duplicates<double>, 
          "Remove duplicates from float list while preserving order", 
          py::arg("items"));
}