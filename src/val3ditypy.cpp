#include <val3dity.h>
#include "nlohmann-json/json.hpp"
using json = nlohmann::json;
#include <fstream>

#include <pybind11/pybind11.h>
#include "pybind11_json.hpp"
#include <pybind11/stl.h>
namespace py = pybind11;

//validate_onegeom
bool 
is_valid_onegeom(py::dict obj,
                 double tol_snap=0.001,
                 double planarity_d2p_tol=0.01,
                 double planarity_n_tol=20.0,
                 double overlap_tol=-1.0){
  json j = obj;
  return val3dity::is_valid_onegeom(j, tol_snap,planarity_d2p_tol, planarity_n_tol, overlap_tol);
}

py::dict
validate_onegeom(py::dict obj,
                 double tol_snap=0.001,
                 double planarity_d2p_tol=0.01,
                 double planarity_n_tol=20.0,
                 double overlap_tol=-1.0){
  json j = obj;
  json jre = val3dity::validate_onegeom(j, tol_snap, planarity_d2p_tol, planarity_n_tol, overlap_tol);
  py::object result = jre;
  return result;
}


//validate_tu3djson
std::vector<bool> 
is_valid_tu3djson(py::dict obj,
                  double tol_snap=0.001,
                  double planarity_d2p_tol=0.01,
                  double planarity_n_tol=20.0,
                  double overlap_tol=-1.0){
  json j = obj; 
  return val3dity::is_valid_tu3djson(j, tol_snap, planarity_d2p_tol, planarity_n_tol, overlap_tol);
}

py::dict
validate_tu3djson(py::dict obj, 
                  double tol_snap=0.001,
                  double planarity_d2p_tol=0.01,
                  double planarity_n_tol=20.0,
                  double overlap_tol=-1.0){
    json j = obj;
    json jre = val3dity::validate_tu3djson(j, tol_snap, planarity_d2p_tol, planarity_n_tol, overlap_tol);
    py::object result = jre;
    return result;
}


//validate_cityjson
bool 
is_valid_cityjson(py::dict obj,
                  double tol_snap=0.001,
                  double planarity_d2p_tol=0.01,
                  double planarity_n_tol=20.0,
                  double overlap_tol=-1.0){
    json j = obj; 
    return val3dity::is_valid_cityjson(j, tol_snap,planarity_d2p_tol, planarity_n_tol, overlap_tol);
}

py::dict 
validate_cityjson(py::dict obj, 
                  double tol_snap=0.001,
                  double planarity_d2p_tol=0.01,
                  double planarity_n_tol=20.0,
                  double overlap_tol=-1.0){
    json j = obj;
    json jre = val3dity::validate_cityjson(j, tol_snap, planarity_d2p_tol, planarity_n_tol, overlap_tol);
    py::object result = jre;
    return result;
}

//validate_indoorgml
bool 
is_valid_indoorgml(const char* s,
                  double tol_snap=0.001,
                  double planarity_d2p_tol=0.01,
                  double planarity_n_tol=20.0,
                  double overlap_tol=-1.0){
    // std::cout << s << std::endl;

    return val3dity::is_valid_indoorgml(s, tol_snap,planarity_d2p_tol, planarity_n_tol, overlap_tol);
}

py::dict 
validate_indoorgml(const char* s, 
                  double tol_snap=0.001,
                  double planarity_d2p_tol=0.01,
                  double planarity_n_tol=20.0,
                  double overlap_tol=-1.0){
    json jre = val3dity::validate_indoorgml(s, tol_snap, planarity_d2p_tol, planarity_n_tol, overlap_tol);
    py::object result = jre;
    return result;
}


PYBIND11_MODULE(val3ditypy, m) {
    m.doc() = R"pbdoc(
        val3ditypy
        -----------------------

        .. currentmodule:: val3ditypy

        .. autosummary::
           :toctree: _generate

           
           is_valid_onegeom
           validate_onegeom
           is_valid_tu3djson
           validate_tu3djson
           is_valid_cityjson
           validate_cityjson
           is_valid_indoorgml
    )pbdoc";

    //-- validate_onegeom
    m.def("is_valid_onegeom", 
      &is_valid_onegeom, 
      "Return true/false for one geometry",
      py::arg("geometry"),  
      py::arg("tol_snap")=0.001,
      py::arg("planarity_d2p_tol")=0.01,
      py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0
    );

    m.def("validate_onegeom", 
      &validate_onegeom, 
      "Return validation report for one geometry",
      py::arg("geometry"),  
      py::arg("tol_snap")=0.001,
      py::arg("planarity_d2p_tol")=0.01,
      py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0
    );


    //-- validate_tu3djson
    m.def("is_valid_tu3djson", 
      &is_valid_tu3djson, 
      "A function to validate tu3djson",
      py::arg("tu3djson"),  
      py::arg("tol_snap")=0.001,
      py::arg("planarity_d2p_tol")=0.01,
      py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0
    );

    m.def("validate_tu3djson", 
      &validate_tu3djson, 
      "A function to validate tu3djson return with report",
      py::arg("geometry"),  
      py::arg("tol_snap")=0.001,
      py::arg("planarity_d2p_tol")=0.01,
      py::arg("planarity_n_tol")=20.0,
      py::arg("overlap_tol")=-1.0
    );


    //validate_cityjson
    m.def("is_valid_cityjson", 
      &is_valid_cityjson, 
      "A function to validate cityjson",
      py::arg("cityjson"),  
      py::arg("tol_snap")=0.001,
      py::arg("planarity_d2p_tol")=0.01,
      py::arg("planarity_n_tol")=20.0,
      py::arg("overlap_tol")=-1.0
    );

    m.def("validate_cityjson", 
      &validate_cityjson, 
      "A function to validate cityjson file return with report",
      py::arg("cityjson"), 
      py::arg("tol_snap")=0.001,
      py::arg("planarity_d2p_tol")=0.01,
      py::arg("planarity_n_tol")=20.0,
      py::arg("overlap_tol")=-1.0)
    ;

    //validate_indoorgml
    m.def("is_valid_indoorgml", 
      &is_valid_indoorgml, 
      "A function to validate indoorgml",
      py::arg("indoorgml string"),  
      py::arg("tol_snap")=0.001,
      py::arg("planarity_d2p_tol")=0.01,
      py::arg("planarity_n_tol")=20.0,
      py::arg("overlap_tol")=-1.0
    );

    m.def("validate_indoorgml", 
      &validate_indoorgml, 
      "A function to validate indoorgml file return with report",
      py::arg("indoorgml string"), 
      py::arg("tol_snap")=0.001,
      py::arg("planarity_d2p_tol")=0.01,
      py::arg("planarity_n_tol")=20.0,
      py::arg("overlap_tol")=-1.0)
    ;

}