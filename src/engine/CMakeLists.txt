include_directories(
	${CMAKE_CURRENT_LIST_DIR}/containers
	${CMAKE_CURRENT_LIST_DIR}/definitions
	${CMAKE_CURRENT_LIST_DIR}/osal/common/rendering
	${CMAKE_CURRENT_LIST_DIR}/osal/sdl/rendering
	${CMAKE_CURRENT_LIST_DIR}/world
)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/core)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/definitions)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/graph)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/osal)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/production)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/transportation)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/world)

add_library(engine ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(engine core definitions osal graph production transportation world)

#add_library(engine)
# target_include_directories(engine
# 	PUBLIC
# 	"${CMAKE_CURRENT_LIST_DIR}/containers"
#	PUBLIC
#	"${CMAKE_CURRENT_LIST_DIR}/core"
#	PUBLIC
#	"${CMAKE_CURRENT_LIST_DIR}/graph"
#	PUBLIC
#	"${CMAKE_CURRENT_LIST_DIR}/osal"
#	PUBLIC
#	"${CMAKE_CURRENT_LIST_DIR}/osal/common"
# 	PUBLIC
# 	"${CMAKE_CURRENT_LIST_DIR}/production"
#	PUBLIC
#	"${CMAKE_CURRENT_LIST_DIR}/rendering"
# 	PUBLIC
# 	"${CMAKE_CURRENT_LIST_DIR}/transportation"
#	PUBLIC
#	"${CMAKE_CURRENT_LIST_DIR}/world"
# )

# target_sources(engine
#	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/osal/macosx/Thread.cpp"
# 	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/graph/IGraphElement.cpp"
# 	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/graph/IEdge.cpp"
# 	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/graph/INode.cpp"
#)

#target_sources(engine
#	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/osal/macosx/Thread.cpp"
#	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/graph/IGraphElement.cpp"
#	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/graph/IEdge.cpp"
#	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/graph/INode.cpp"
#	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/production/Conveyor.cpp"
# 	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/production/Item.cpp"
#	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/production/ItemProcessor.cpp"
#	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/production/ProcessStep.cpp"
#	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/production/Recipe.cpp"
# 	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/transportation/ItemContainer.cpp"
# 	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/transportation/PickupArea.cpp"
# 	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/transportation/StorageArea.cpp"
# 	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/transportation/TransportationTile.cpp"
# 	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/transportation/Transporter.cpp"
# )
