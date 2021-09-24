# val3ditypy


## to install:

Clone the repository:

```bash
git clone https://github.com/tudelft3d/val3ditypy
git submodule init
git submodule update
```

Compile and install as a Python package:

`python setup.py install`


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

