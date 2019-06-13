

file(
    GLOB_RECURSE _source_list 
    LIST_DIRECTORIES false
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp*"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)


set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF)
find_package (Boost COMPONENTS date_time REQUIRED)

message("CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}")


include_directories (${CMAKE_SOURCE_DIR}/mpblib/src
                     ${Boost_INCLUDE_DIRS}
                     )				 


find_package(GTest REQUIRED)
FIND_PACKAGE ( Threads REQUIRED )
include(GoogleTest)

link_directories(${Boost_LIBRARY_DIRS})

include_directories(${GTEST_INCLUDE_DIRS})

add_executable (testrun ${_source_list})
target_link_libraries (testrun                       
  ${Boost_DATE_TIME_LIBRARY}
  ${GTEST_LIBRARIES}
  ${GTEST_MAIN_LIBRARIES}
  mpblib
  )
				   
gtest_discover_tests(testrun TEST_PREFIX new:)

foreach(_source IN ITEMS ${_source_list})
    get_filename_component(_source_path "${_source}" PATH)
    file(RELATIVE_PATH _source_path_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()
