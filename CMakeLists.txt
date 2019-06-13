cmake_minimum_required (VERSION 3.13)
project (mpb VERSION 0.0.1 LANGUAGES CXX)
ENABLE_TESTING()

message("CMAKE_SYSTEM_VERSION  : ${CMAKE_SYSTEM_VERSION}")
message("CMAKE_SYSTEM_PROCESSOR  : ${CMAKE_SYSTEM_PROCESSOR}")
message("CMAKE_HOST_SYSTEM_NAME  : ${CMAKE_HOST_SYSTEM_NAME}")


#set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build )
#message("CMAKE_BINARY_DIR  :${CMAKE_BINARY_DIR}")


message("CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  message("good")
  add_compile_options("-Wno-psabi" "-Wall" "-Wextra" "-Werror" "$<$<CONFIG:RELEASE>:-O3>")
endif()

if(MSVC)
  add_compile_options("/W4" "$<$<CONFIG:RELEASE>:/O2>")
endif()



add_subdirectory (mpblib)

include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
install(TARGETS mpblib
  ARCHIVE DESTINATION Debug/arch
        CONFIGURATIONS Debug
        RUNTIME DESTINATION Debug/bin)
install(TARGETS mpblib
  ARCHIVE DESTINATION Release/arch
        CONFIGURATIONS Release
        RUNTIME DESTINATION Release/bin)
include (CPack)
