add_library(core ${CMAKE_CURRENT_LIST_DIR})
target_sources(core
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/Core.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/IGameController.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/IGameModel.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/PlayerCamera.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/PlayerDisplay.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/PlayerSettings.cpp"
)

target_include_directories(core PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/../containers/"
        "${CMAKE_CURRENT_LIST_DIR}/../rendering/"
        "${CMAKE_CURRENT_LIST_DIR}/../world/")
target_link_libraries(core osal)