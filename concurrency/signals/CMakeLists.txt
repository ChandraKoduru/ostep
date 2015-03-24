cmake_minimum_required(VERSION 2.8)
project(concurancy_ostep_cv C)
set(CMAKE_CXX_FLAGS "-g -Wall")
find_package(Threads REQUIRED)

add_executable(signal0 signal0.c)
target_link_libraries(signal0 ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS signal0 DESTINATION bin)
