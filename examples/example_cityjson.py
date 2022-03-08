import val3ditypy
import json

mycity = json.load(open("02.json"))

if val3ditypy.is_valid_cityjson(mycity) == True:
  print("valid!")
else:
  print("oh no invalid :(")

report = val3ditypy.validate_cityjson(mycity)
print(report["validity"])

# print(report)