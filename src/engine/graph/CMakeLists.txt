add_library(graph ${CMAKE_CURRENT_LIST_DIR})
target_sources(graph
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/IGraphElement.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/IEdge.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/INode.cpp"
)