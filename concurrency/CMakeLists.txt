cmake_minimum_required(VERSION 2.8)
project(concurancy_ostep C)
set(CMAKE_CXX_FLAGS "-g -Wall")
find_package(Threads REQUIRED)
add_executable(t0 t0.c)
install(TARGETS t0 DESTINATION bin)
target_link_libraries(t0 ${CMAKE_THREAD_LIBS_INIT})
add_executable(tapi tapi.c)
target_link_libraries(tapi ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS tapi DESTINATION bin)
