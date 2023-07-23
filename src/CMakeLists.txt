add_executable(game Source.cpp)
  
add_subdirectory(Base)


target_link_libraries(game
  PRIVATE
    Base
    sfml-graphics
    sfml-window
    sfml-system
  )

