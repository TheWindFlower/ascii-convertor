cmake_minimum_required(VERSION 3.25)
project( ascii )
find_package( OpenCV REQUIRED )
find_package( Threads REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories(${CMAKE_SOURCE_DIR}/include)
set(SOURCES
    src/main.cpp
    # Add other source files here if you have more
)
add_executable( ascii.app src/mina.cpp )
target_link_libraries( ascii.app ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})