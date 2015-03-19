cmake_minimum_required(VERSION 2.8)
project(app_project)
add_executable(myapp t0.c)
install(TARGETS myapp DESTINATION bin)
