file(GLOB SRCS *.c)
set_source_files_properties(${SRCS} PROPERTIES LANGUAGE CXX)
add_library(csolutions SHARED ${SRCS})
set_target_properties(csolutions PROPERTIES LINKER_LANGUAGE CXX)
