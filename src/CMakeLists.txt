add_executable(game Source.cpp)
  
add_subdirectory(SfmlGui)
#add_subdirectory(Utils)

target_link_libraries(game
  PRIVATE
    SfmlGui
    #Utils
    sfml-graphics
    sfml-window
    sfml-system
  )
target_sources(game
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/AssetManager.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Chunked.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Game.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Hero.cpp
    ${CMAKE_CURRENT_LIST_DIR}/PerlinNoise.cpp
    ${CMAKE_CURRENT_LIST_DIR}/World.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ActorManager.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Enemy.cpp
    ${CMAKE_CURRENT_LIST_DIR}/EnemyChunk.cpp
    ${CMAKE_CURRENT_LIST_DIR}/EnemyGenerator.cpp
    ${CMAKE_CURRENT_LIST_DIR}/GamePlay.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MainMenu.cpp
    ${CMAKE_CURRENT_LIST_DIR}/StateManager.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Settings.cpp
    ${CMAKE_CURRENT_LIST_DIR}/UiTestState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MapParser.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/TileChunk.cpp
    ${CMAKE_CURRENT_LIST_DIR}/TileLoader.cpp
    ${CMAKE_CURRENT_LIST_DIR}/WorldGenerator.cpp
    ${CMAKE_CURRENT_LIST_DIR}/SettingsState.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/AssetManager.h
    ${CMAKE_CURRENT_LIST_DIR}/Chunked.h
    ${CMAKE_CURRENT_LIST_DIR}/Game.h
    ${CMAKE_CURRENT_LIST_DIR}/Hero.h
    ${CMAKE_CURRENT_LIST_DIR}/json.hpp
    ${CMAKE_CURRENT_LIST_DIR}/PerlinNoise.h
    ${CMAKE_CURRENT_LIST_DIR}/World.h
    ${CMAKE_CURRENT_LIST_DIR}/ActorManager.h
    ${CMAKE_CURRENT_LIST_DIR}/Enemy.h
    ${CMAKE_CURRENT_LIST_DIR}/EnemyChunk.h
    ${CMAKE_CURRENT_LIST_DIR}/EnemyGenerator.h
    ${CMAKE_CURRENT_LIST_DIR}/WorldData.h
    ${CMAKE_CURRENT_LIST_DIR}/GamePlay.h
    ${CMAKE_CURRENT_LIST_DIR}/MainMenu.h
    ${CMAKE_CURRENT_LIST_DIR}/State.h
    ${CMAKE_CURRENT_LIST_DIR}/StateManager.h
    ${CMAKE_CURRENT_LIST_DIR}/Settings.h
    ${CMAKE_CURRENT_LIST_DIR}/UiTestState.h
    ${CMAKE_CURRENT_LIST_DIR}/MapParser.h
    ${CMAKE_CURRENT_LIST_DIR}/Tile.h
    ${CMAKE_CURRENT_LIST_DIR}/TileChunk.h
    ${CMAKE_CURRENT_LIST_DIR}/TileLoader.h
    ${CMAKE_CURRENT_LIST_DIR}/WorldGenerator.h
    ${CMAKE_CURRENT_LIST_DIR}/SettingsState.h
  )
