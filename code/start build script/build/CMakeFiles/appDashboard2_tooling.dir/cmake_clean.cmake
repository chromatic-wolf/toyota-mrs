file(REMOVE_RECURSE
  "Dashboard2/Main.qml"
  "Dashboard2/qml.qrc"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/appDashboard2_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
