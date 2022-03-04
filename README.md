# val3ditypy


## to install:

1. Clone the repository:

```bash
git clone https://github.com/tudelft3d/val3ditypy
git submodule init
git submodule update
```

2. Install [all the dependencies of val3dity](https://github.com/tudelft3d/val3dity#installation-of-the-command-line-tool) and make sure you can compile it

3. Compile the bindings and install the Python package: `python setup.py install`


## how to use it

```python
import val3ditypy
import json

mycity = json.load(open("/home/elvis/delft.city.json"))

if val3ditypy.is_valid_cityjson(mycity) == True:
  print("valid!")
else:
  print("oh no invalid :(")

report = val3ditypy.validate_cityjson(mycity)
print(report["validity"])
```

## input accepted

1. one [CityJSON object](https://www.cityjson.org/specs/1.0.3/#cityjson-object)
2. one [tu3djson object](https://github.com/tudelft3d/tu3djson#tu3djson-object)
3. [one geometry of a tu3djson object](https://github.com/tudelft3d/tu3djson#geometry-object)


## functions

bool is_valid_onegeom(json mydata)
json validate_onegeom(json mydata)

list(bool) is_valid_tu3djson(json mydata)
json validate_tu3djson(json mydata)

bool is_valid_cityjson(json mydata)
json validate_cityjson(json mydata)
