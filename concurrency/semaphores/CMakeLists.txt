cmake_minimum_required(VERSION 2.8)
project(concurancy_ostep_cv C)
set(CMAKE_CXX_FLAGS "-g -Wall")
find_package(Threads REQUIRED)

add_executable(sem_as_cv sem_as_cv.c)
target_link_libraries(sem_as_cv ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS sem_as_cv DESTINATION bin)
