add_library(Settings)

target_sources(Settings
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Settings.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Settings.h
)

target_include_directories(Settings
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)