cmake_minimum_required(VERSION 2.8)
project(concurancy_ostep_cv C)
set(CMAKE_CXX_FLAGS "-g -Wall")
find_package(Threads REQUIRED)

add_executable(sem_as_cv sem_as_cv.c)
target_link_libraries(sem_as_cv ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS sem_as_cv DESTINATION bin)

add_executable(sem_prod_cons1 sem_prod_cons1.c)
target_link_libraries(sem_prod_cons1 ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS sem_prod_cons1 DESTINATION bin)

add_executable(dining_philosophers dining_philosophers.c)
target_link_libraries(dining_philosophers ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS dining_philosophers DESTINATION bin)
