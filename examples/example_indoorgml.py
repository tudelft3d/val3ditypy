import val3ditypy


f = open("FZK-Haus_full.gml", "r")
ig = f.read()

if val3ditypy.is_valid_indoorgml(ig) == True:
  print("valid!")
else:
  print("oh no invalid :(")

report = val3ditypy.validate_indoorgml(ig)
print(report["validity"])

# print(report)