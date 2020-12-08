cmake_minimum_required(VERSION 3.19)

project(Task1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)


file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen/A)

add_custom_command( 
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/gen/A/index.h
  COMMAND python ${PROJECT_SOURCE_DIR}/A/preparing.py ${CMAKE_CURRENT_BINARY_DIR}/gen/A/index.h
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/A/preparing.py
  COMMENT "Do preparing"
)

add_custom_target( MustRunPreparing DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/gen/A/index.h COMMENT "Checking if re-generation is required" )

add_subdirectory(B)

add_executable(
  task1
  ${CMAKE_CURRENT_SOURCE_DIR}/C/main.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/gen/A/index.h
)

target_include_directories(task1 PUBLIC B ${CMAKE_CURRENT_BINARY_DIR}/gen)

target_link_libraries(task1 PRIVATE B)





