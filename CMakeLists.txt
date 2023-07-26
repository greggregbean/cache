cmake_minimum_required (VERSION 3.0)

project (cache)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (run    source/main.cpp
                       source/cacheMethods.cpp
                       source/graphDump.cpp
                       source/lfuMethods.cpp
                       source/lruMethods.cpp
                       source/tests.cpp
                       source/cacheSetup.hpp
)

add_executable (run_belady  genious_cache/main.cpp)

if (MSVC)
    target_compile_options (
        run PRIVATE 
        /W4
    )

else ()
    target_compile_options (
        run PRIVATE
        -g -Wall -Wextra -pedantic
    )

endif ()
