add_library(production ${CMAKE_CURRENT_LIST_DIR})
set_target_properties(production PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(production PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/../containers/"
        "${CMAKE_CURRENT_LIST_DIR}/../graph/")

target_link_libraries(production graph)