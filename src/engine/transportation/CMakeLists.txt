add_library(transportation ${CMAKE_CURRENT_LIST_DIR})
set_target_properties(transportation PROPERTIES LINKER_LANGUAGE CXX)

target_sources(transportation
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/ItemContainer.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/PickupArea.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/StorageArea.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/TransportationTile.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/Transporter.cpp"
        )

target_include_directories(transportation PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/../containers/"
        "${CMAKE_CURRENT_LIST_DIR}/../graph/"
        "${CMAKE_CURRENT_LIST_DIR}/../production/")
target_link_libraries(transportation graph production)
