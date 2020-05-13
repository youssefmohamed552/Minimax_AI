cmake_minimum_required( VERSION 2.8 )
project(minimax_ai)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)


set(minimax_ai_VERSION 1.0.0)

include(GenerateExportHeader)

include_directories(include)

add_definitions("-std=c++11")


add_library(player SHARED src/player.cpp)
generate_export_header(player)

add_library(state SHARED src/state.cpp)
generate_export_header(state)

add_library(game SHARED src/game.cpp)
generate_export_header(game)

add_library(action SHARED src/action.cpp)
generate_export_header(action)

# set(INCLUDE_INSTALL_DIR include/ ... CACHE )

target_link_libraries(player state)



install(
  TARGETS player state action game
  EXPORT minimax_ai_targets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  INCLUDES DESTINATION include
)


install(
  FILES
    player.hpp
    "${CMAKE_CURRENT_BINARY_DIR}/player_export.h"
    state.hpp
    "${CMAKE_CURRENT_BINARY_DIR}/state_export.h"
    game.hpp
    "${CMAKE_CURRENT_BINARY_DIR}/game_export.h"
    action.hpp
    "${CMAKE_CURRENT_BINARY_DIR}/action_export.h"
  DESTINATION
    include
  COMPONENT
    Devel
)


include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/MinimaxAI/minimax_aiConfigVersion.cmake"
  VERSION ${minimax_ai_VERSION}
  COMPATIBILITY AnyNewerVersion
)

export(
  EXPORT minimax_ai_targets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/MinimaxAI/minimax_ai_targets.cmake"
  NAMESPACE MinimaxAI::
)


configure_file(
  config_file/minimax_ai-config.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/MinimaxAI/minimax_ai-config.cmake"
  COPYONLY
)



