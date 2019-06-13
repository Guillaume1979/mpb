
file(
    GLOB_RECURSE _source_list 
    LIST_DIRECTORIES false
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

find_package (Boost COMPONENTS date_time REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})
#add_definitions (-DBOOST_TEST_DYN_LINK)

add_library (mpblib ${_source_list} )

target_include_directories (mpblib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

foreach(_source IN ITEMS ${_source_list})
    get_filename_component(_source_path "${_source}" PATH)
    file(RELATIVE_PATH _source_path_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()
