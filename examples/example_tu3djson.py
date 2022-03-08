import val3ditypy
import json

onecube = json.load(open("cube.json"))

if val3ditypy.is_valid_tu3djson(onecube) == True:
  print("dataset valid!")
else:
  print("oh no dataset invalid :(")

re = val3ditypy.is_valid_tu3djson_each(onecube)
for i,each in enumerate(re):
  if each is True:
    print("  - geom{}".format(i), "is valid")
  else:
    print("  - geom{}".format(i), "is invalid :(")

#-- remove the geom#1, which invalid
onecube['features'].pop()
if val3ditypy.is_valid_tu3djson(onecube) == True:
  print("dataset now valid!")
else:
  print("oh no dataset invalid :(")
