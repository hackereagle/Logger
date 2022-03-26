cmake_minimum_required(VERSION 3.10.0)
set(PROJECT_NAME LoggerTesting)
aux_source_directory(. DIR_SRC)

# if(MSVC)
# 	message(STATUS "lib path: ${CMAKE_BINARY_DIR}")
# 	set(myLib ${CMAKE_BINARY_DIR}/lib/Debug/Logger.lib)
# else()
# 	add_library(myLib SHARED IMPORTED)
# 	set_target_properties(myLib PROPERTIES IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/lib/libLogger.so)
# endif(MSVC)
set(myLib ${CMAKE_BINARY_DIR}/lib/libLogger.so)
include_directories(${CMAKE_SOURCE_DIR}/logResp/src/Logger)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${DIR_SRC})
target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} ${myLib} Threads::Threads)

