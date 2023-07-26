add_library(SfmlGui)

target_sources(SfmlGui
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Window.cpp
    ${CMAKE_CURRENT_LIST_DIR}/TextField.cpp
    ${CMAKE_CURRENT_LIST_DIR}/TextField2.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Slider.cpp

  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Window.h
    ${CMAKE_CURRENT_LIST_DIR}/TextField.h
    ${CMAKE_CURRENT_LIST_DIR}/TextField2.h
    ${CMAKE_CURRENT_LIST_DIR}/Slider.h
)
target_include_directories(SfmlGui
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)