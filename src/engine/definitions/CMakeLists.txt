add_library(definitions ${CMAKE_CURRENT_LIST_DIR})
target_sources(definitions
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/IGameDefinition.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/IDisplayableGameDefinition.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/WorldElementDefinition.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/FacilityElementDefinition.cpp"
)

target_include_directories(definitions PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
)
target_link_libraries(definitions)