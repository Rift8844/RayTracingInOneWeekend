project(Rtiow)
add_executable(Rtiow main.cpp)

add_compile_options(
    "$<$<CONFIG:DEBUG>:-g>"
    )
add_compile_options(
    "$<$<CONFIG:RELEASE>:-O2"
    )
