cmake_minimum_required(VERSION 3.10)
project(NumberSliderPuzzle)

set(CMAKE_CXX_STANDARD 11)

set(OpenCV_DIR "E:/libs/opencv/sources/build/install/x64/mingw/lib")
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(NumberSliderPuzzle main.cpp ImageProcess.cpp MathProcess.cpp InputProcess.cpp)

target_link_libraries(NumberSliderPuzzle ${OpenCV_LIBS})

if(MINGW)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set_target_properties(NumberSliderPuzzle PROPERTIES LINK_FLAGS "-mconsole")
    else()
        set_target_properties(NumberSliderPuzzle PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()