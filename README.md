Author: Youssef Hussein


# descrition:
Minimax state space search based Aritifitial intelligence library. works well for sequential games




# build:
- mkdir build
- cmake ..
- make



# Usage:
- clone the library in the <your_project>/lib folder
- add the following the CMakeLists.txt of the game project using the library
  - set(MINIMAX_AI_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/lib/minimax/include") 
  - set(MINIMAZ_AI_CONFIG_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/minimax/build/MinimaxAI")
  - list(APPEND CMAKE_PREFIX_PATH "${MINIMAX_AI_CONFIG_PATH}")
  - find_package(minimax_ai REQUIED)
  - include_directories(<other_include_directories> ${MINIMAX_AI_INCLUDE_DIRS})
  - target_link_libraries( <target>
     <other libraries in the program>
     MinimaxAI::player
     MinimaxAI::state
     MinimaxAI::game
     MinimaxAI::action
     )
