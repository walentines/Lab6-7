# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Lab6_7_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Lab6_7_autogen.dir/ParseCache.txt"
  "Lab6_7_autogen"
  )
endif()
