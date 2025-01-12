file(REMOVE_RECURSE
  "simpleqml3d/IronMan.qml"
  "simpleqml3d/Main.qml"
  "simpleqml3d/RenderableEntity.qml"
  "simpleqml3d/ThreeDimensionalScene.qml"
  "simpleqml3d/qml.qrc"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/appsimpleqml3d_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
