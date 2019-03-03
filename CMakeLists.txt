project(TMA4280_project1)
cmake_minimum_required( VERSION 2.8)

#want to have an executable file for each subfolder.
find_package(MPI REQUIRED)



foreach (prog mach0 mach1 mach2)
    add_executable(${prog} ${prog}/main.cpp)
    target_include_directories(${prog} PRIVATE ${MPI_CXX_INCLUDE_DIRS})
    target_compile_options(${prog} PRIVATE ${MPI_CXX_COMPILE_OPTIONS})
    target_compile_definitions(${prog} PRIVATE ${MPI_CXX_COMPILE_DEFINITIONS})
    target_link_libraries(${prog} ${MPI_CXX_LIBRARIES} m)
    set_target_properties(${prog} PROPERTIES LINK_FLAGS ${MPI_CXX_LINK_FLAGS})
endforeach()



