cmake_minimum_required(VERSION 2.8)
project( ascii )
find_package( OpenCV REQUIRED )
find_package( Threads REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( ascii.app mina.cpp )
target_link_libraries( ascii.app ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})