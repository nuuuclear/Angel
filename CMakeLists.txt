cmake_minimum_required(VERSION 3.10)
project(angel_engine)

set(EXTERNAL_DIR "external")

find_package(SDL3       REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf   REQUIRED)

option(ANGEL_INSTALL "enable install rules for Angel" OFF)

####################
#     External     #
####################

add_library(miniaudio
    "${CMAKE_CURRENT_SOURCE_DIR}/${EXTERNAL_DIR}/miniaudio/miniaudio.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/${EXTERNAL_DIR}/miniaudio/miniaudio.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/${EXTERNAL_DIR}/stb_vorbis.c"
)
target_include_directories(miniaudio PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/${EXTERNAL_DIR}/miniaudio")

########################
#     Angel engine     #
########################

set(ANGEL_INCLUDE_DIR "include")
set(ANGEL_SOURCE_DIR  "src")

add_library(angel STATIC)
add_library(angel::angel ALIAS angel)
target_sources(angel PRIVATE
    "${ANGEL_INCLUDE_DIR}/Angel/Angel.h"
    "${ANGEL_SOURCE_DIR}/Engine.cpp"
    "${ANGEL_SOURCE_DIR}/Engine.h"
    "${ANGEL_SOURCE_DIR}/Window.cpp"
    "${ANGEL_SOURCE_DIR}/Window.h"
    "${ANGEL_SOURCE_DIR}/Log.cpp"
    "${ANGEL_SOURCE_DIR}/Log.h"
    "${ANGEL_SOURCE_DIR}/Render.cpp"
    "${ANGEL_SOURCE_DIR}/Render.h"
    "${ANGEL_SOURCE_DIR}/Input.cpp"
    "${ANGEL_SOURCE_DIR}/Input.h"
    "${ANGEL_SOURCE_DIR}/AssetRegistry.h" 
    "${ANGEL_SOURCE_DIR}/Sprite.cpp"
    "${ANGEL_SOURCE_DIR}/Sprite.h"        
    "${ANGEL_SOURCE_DIR}/Draw.cpp"
    "${ANGEL_SOURCE_DIR}/Draw.h"
    "${ANGEL_SOURCE_DIR}/RenderWrapper.cpp"
    "${ANGEL_SOURCE_DIR}/RenderWrapper.h" 
    "${ANGEL_SOURCE_DIR}/SpriteBatch.h"
    "${ANGEL_SOURCE_DIR}/SpriteBatch.cpp"
    "${ANGEL_SOURCE_DIR}/Camera.cpp"
    "${ANGEL_SOURCE_DIR}/Camera.h" 
    "${ANGEL_SOURCE_DIR}/TextureAtlas.cpp"
    "${ANGEL_SOURCE_DIR}/TextureAtlas.h" 
    "${ANGEL_SOURCE_DIR}/Collider.h"
    "${ANGEL_SOURCE_DIR}/Geometry/Rect.h"             
    "${ANGEL_SOURCE_DIR}/Font.cpp"
    "${ANGEL_SOURCE_DIR}/Font.h"
    "${ANGEL_SOURCE_DIR}/Text.cpp"
    "${ANGEL_SOURCE_DIR}/Text.h"
    "${ANGEL_SOURCE_DIR}/Stage.cpp"
    "${ANGEL_SOURCE_DIR}/Stage.h"
    "${ANGEL_SOURCE_DIR}/Entity.cpp"
    "${ANGEL_SOURCE_DIR}/Entity.h"
    "${ANGEL_SOURCE_DIR}/Tilemap.cpp"
    "${ANGEL_SOURCE_DIR}/Tilemap.h" 
    "${ANGEL_SOURCE_DIR}/Tileset.cpp"
    "${ANGEL_SOURCE_DIR}/Tileset.h"
    "${ANGEL_SOURCE_DIR}/AssetManager.h"
    "${ANGEL_SOURCE_DIR}/AssetManager.cpp"
    "${ANGEL_SOURCE_DIR}/CharacterModel.h"
    "${ANGEL_SOURCE_DIR}/CharacterModel.cpp"
    "${ANGEL_SOURCE_DIR}/SpriteSheet.h"
    "${ANGEL_SOURCE_DIR}/SpriteSheet.cpp"
    "${ANGEL_SOURCE_DIR}/Background.h"
    "${ANGEL_SOURCE_DIR}/Background.cpp"
    "${ANGEL_SOURCE_DIR}/ResourceLoading.h"
    "${ANGEL_SOURCE_DIR}/ResourceLoading.cpp"
    "${ANGEL_SOURCE_DIR}/StaticLoader.h"
    "${ANGEL_SOURCE_DIR}/StaticLoader.cpp"
    "${ANGEL_SOURCE_DIR}/Audio.h"
    "${ANGEL_SOURCE_DIR}/Audio.cpp"
    "${ANGEL_SOURCE_DIR}/Sound.h"
    "${ANGEL_SOURCE_DIR}/Sound.cpp"
)

target_link_libraries(angel PUBLIC
    SDL3::SDL3 
    SDL3_image::SDL3_image 
    SDL3_ttf::SDL3_ttf
    miniaudio
)

target_include_directories(angel
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# install

if(ANGEL_INSTALL)
    include(CMakePackageConfigHelpers)

    install(TARGETS angel
        EXPORT angelTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
    )

    install(DIRECTORY include/
        DESTINATION include
    )

    install(EXPORT angelTargets
        FILE angelTargets.cmake
        NAMESPACE angel::
        DESTINATION lib/cmake/angel
    )

    configure_package_config_file(
        cmake/angelConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/angelConfig.cmake
        INSTALL_DESTINATION lib/cmake/angel
    )

    install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/angelConfig.cmake
        DESTINATION lib/cmake/angel
    )
endif()