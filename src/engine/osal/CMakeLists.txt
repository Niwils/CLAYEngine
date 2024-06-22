add_library(osal ${CMAKE_CURRENT_LIST_DIR})
target_sources(osal
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/common/IOsalSys.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/common/geometry/IRectangle.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/common/rendering/IRenderer.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/common/rendering/ISprite.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/common/rendering/ISpriteWindow.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/events/KeyboardEvent.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/events/MouseEvent.cpp"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/sdl/OsalSys.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/sdl/geometry/Rectangle.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/sdl/rendering/Renderer.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/sdl/rendering/Sprite.cpp"
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/sdl/rendering/SpriteWindow.cpp"
)

target_include_directories(osal PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/common/"
        "${CMAKE_CURRENT_LIST_DIR}/common/geometry/"
        "${CMAKE_CURRENT_LIST_DIR}/common/rendering/"
        "${CMAKE_CURRENT_LIST_DIR}/events/"
        "${CMAKE_CURRENT_LIST_DIR}/sdl/"
        "${CMAKE_CURRENT_LIST_DIR}/sdl/geometry/"
        "${CMAKE_CURRENT_LIST_DIR}/sdl/rendering/"
        ${SDL2_INCLUDE_DIRS})
        #${SDL2_IMAGE_INCLUDE_DIRS})

target_link_libraries(osal ${SDL2_LIBRARIES}) # ${SDL2_IMAGE_LIBRARY})