project(Rtiow)
add_executable(Rtiow main.cpp)
add_executable(Rtiow hittable.cpp)
add_executable(Rtiow sphere.cpp)

add_compile_options(
    "$<$<CONFIG:DEBUG>:-g>"
    )
add_compile_options(
    "$<$<CONFIG:RELEASE>:-O1"
    )
