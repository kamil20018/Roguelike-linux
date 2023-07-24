add_library(Utils)

target_sources(Utils
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/json.hpp
)

target_include_directories(Utils
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)