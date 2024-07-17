cmake_minimum_required(VERSION 3.5)

project(DinoSaur)
include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  option(ENABLE_BUILD_WITH_TIME_TRACE
         "Enable -ftime-trace to generate time tracing .json files on clang"
         OFF)
  if(ENABLE_BUILD_WITH_TIME_TRACE)
    target_compile_options(project_options INTERFACE -ftime-trace)
  endif()
endif()

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# allow for Sanitizers
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE Main.cpp
			Game.cpp
			Background/BackgroundSprite.cpp
			Background/DirtManager.cpp
			Core/Score.cpp
      Core/SpriteComponent.cpp
      Dino/DinoSprite.cpp
      Graphics/TextureManager.cpp
      Obstacle/ObstacleManager.cpp
      Obstacle/ObstacleSprite.cpp
      Physics/Collision.cpp
      Physics/Vector2D.cpp
      Sound/SoundManager.cpp
      Text/Text.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} Background Core Dino Graphics Obstacle Physics Sound Text)

target_link_libraries(${PROJECT_NAME}
SDL2::SDL2
SDL2_image::SDL2_image
SDL2_mixer::SDL2_mixer
SDL2_ttf::SDL2_ttf)
