#include <val3dity.h>
#include "nlohmann-json/json.hpp"
using json = nlohmann::json;
#include <fstream>

#include <pybind11/pybind11.h>
#include "pybind11_json.hpp"
#include <pybind11/stl.h>
namespace py = pybind11;

//validate_one_geom
bool validate_one_geom(py::dict obj,
                       double tol_snap=0.001,
                       double planarity_d2p_tol=0.01,
                       double planarity_n_tol=20.0,
                       double overlap_tol=-1.0){
    json j = obj;//create a nlohmann::json instance
    return val3dity::validate_one_geom(j,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
}

bool validate_one_geom_jr(py::dict obj, py::dict jr,
                       double tol_snap=0.001,
                       double planarity_d2p_tol=0.01,
                       double planarity_n_tol=20.0,
                       double overlap_tol=-1.0){
    json j = obj;//create a nlohmann::json instance
    json jreport = jr;
    bool re = val3dity::validate_one_geom(j,jreport,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
    std::cout << jreport << "\n";

    std::ofstream o("validate_one_geom_report.json");
    o << std::setw(4) << jreport << std::endl;

    return re;
}


//validate_tu3djson
std::vector<bool> validate_tu3djson(py::dict obj,
                       double tol_snap=0.001,
                       double planarity_d2p_tol=0.01,
                       double planarity_n_tol=20.0,
                       double overlap_tol=-1.0){
    json j = obj; //create a nlohmann::json instance
    return val3dity::validate_tu3djson(j,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
}

std::vector<bool> validate_tu3djson_jr(py::dict obj, py::dict jr,
                          double tol_snap=0.001,
                          double planarity_d2p_tol=0.01,
                          double planarity_n_tol=20.0,
                          double overlap_tol=-1.0){
    json j = obj;//create a nlohmann::json instance
    json jreport = jr;
    std::vector<bool> re = val3dity::validate_tu3djson(j,jreport,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
    std::cout << jreport << "\n";

    std::ofstream o("validate_tu3djson_report.json");
    o << std::setw(4) << jreport << std::endl;

    return re;
}


//validate_cityjson
bool validate_cityjson(py::dict obj,
                       double tol_snap=0.001,
                       double planarity_d2p_tol=0.01,
                       double planarity_n_tol=20.0,
                       double overlap_tol=-1.0){
    json j = obj; //create a nlohmann::json instance
    return val3dity::validate_cityjson(j,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
}

bool validate_cityjson_jr(py::dict obj, py::dict jr,
                          double tol_snap=0.001,
                          double planarity_d2p_tol=0.01,
                          double planarity_n_tol=20.0,
                          double overlap_tol=-1.0){
    json j = obj;//create a nlohmann::json instance
    json jreport = jr;
    bool re = val3dity::validate_cityjson(j,jreport,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
    std::cout << jreport << "\n";

    std::ofstream o("validate_cityjson_report.json");
    o << std::setw(4) << jreport << std::endl;

    return re;
}


// //validate_array
// bool validate_arrays(std::string geom, std::vector<std::vector<std::vector<int>>> boundaries,
//                      std::vector<std::vector<double>> vertices,
//                     double tol_snap=0.001,
//                     double planarity_d2p_tol=0.01,
//                     double planarity_n_tol=20.0,
//                     double overlap_tol=-1.0){
//     return val3dity::validate_arrays(geom,boundaries,vertices);
// }



PYBIND11_MODULE(val3ditypy, m) {
    m.doc() = "My awesome module";

    //validate_one_geom
    m.def("validate_one_geom", &validate_one_geom, "A function validate one geom",
          py::arg("geometry"),  py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0);

    m.def("validate_one_geom_jr", &validate_one_geom_jr, "A function validate one geom return with report",
          py::arg("geometry"),  py::arg("jreport"), py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0);


    //validate_tu3djson
    m.def("validate_tu3djson", &validate_tu3djson, "A function validate tu3djson",
          py::arg("tu3djson"),  py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0);

    m.def("validate_tu3djson_jr", &validate_tu3djson_jr, "A function validate tu3djson return with report",
          py::arg("geometry"),  py::arg("jreport"), py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0);


    //validate_cityjson
    m.def("validate_cityjson", &validate_cityjson, "A function validate cityjson",
          py::arg("cityjson"),  py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0);

    m.def("validate_cityjson_jr", &validate_cityjson_jr, "A function validate cityjson file return with report",
          py::arg("cityjson"),  py::arg("jreport"), py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0);


    // //validate_array
    // m.def("validate_arrays",&validate_arrays,"A function validate boundaries and vertices",
    //       py::arg("geom_type"),  py::arg("boundaries"), py::arg("vertices"),
    //       py::arg("tol_snap")=0.001, py::arg("planarity_d2p_tol")=0.01,
    //       py::arg("planarity_n_tol")=20.0, py::arg("overlap_tol")=-1.0);
}