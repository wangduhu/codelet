file(GLOB SRC_LIST *.cpp)
file(GLOB HEADER_LIST *.h)

add_library(utils SHARED ${SRC_LIST})
set_target_properties(utils PROPERTIES LINKER_LANGUAGE CXX)

if (APPLE)
  set(CMAKE_INSTALL_PREFIX "/Users/wally/.local/")
else()
  set(CMAKE_INSTALL_PREFIX "/home/wally/.local/")
endif()

install(TARGETS utils
  LIBRARY DESTINATION lib
  )

install(FILES ${HEADER_LIST}
  DESTINATION include
  )
