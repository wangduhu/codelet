file(GLOB C_SRCS *.c)
set_source_files_properties(${C_SRCS} PROPERTIES LANGUAGE CXX)
add_library(csolutions SHARED ${C_SRCS})
set_target_properties(csolutions PROPERTIES LINKER_LANGUAGE CXX)
