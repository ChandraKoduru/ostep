cmake_minimum_required(VERSION 2.8)
project(concurancy_ostep_cv C)
set(CMAKE_CXX_FLAGS "-g -Wall")
find_package(Threads REQUIRED)

#add_executable(cv1 cv1.c)
#target_link_libraries(cv1 ${CMAKE_THREAD_LIBS_INIT})
#install(TARGETS cv1 DESTINATION bin)
add_executable(cv2 cv2.c)
target_link_libraries(cv2 ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS cv2 DESTINATION bin)

add_executable(posix_cv posix_cv.c)
target_link_libraries(posix_cv ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS posix_cv DESTINATION bin)

add_executable(prod_cons_final prod_cons_final.c)
target_link_libraries(prod_cons_final ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS prod_cons_final DESTINATION bin)
