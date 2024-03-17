add_library(graph ${CMAKE_CURRENT_LIST_DIR})
target_sources(graph
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/IGraphElement.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/IEdge.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/INode.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/IToken.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/IGraph.cpp"
)

target_include_directories(graph PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/../containers/")
target_link_libraries(graph)