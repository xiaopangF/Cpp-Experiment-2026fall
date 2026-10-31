file(GLOB SOURCE "*.cpp")
list(REMOVE_ITEM SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
add_library(training ${SOURCE})
target_include_directories(training PUBLIC "${CMAKE_SOURCE_DIR}/include")
