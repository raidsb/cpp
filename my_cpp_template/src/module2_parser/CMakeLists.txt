# PThread
# It configures the use of the POSIX threads (pthread) library for multi-threading support in the project.
# the two variables below are not used directly by Threads package--->? 
set (CMAKE_THREAD_PREFER_PTHREAD TRUE)
set (THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

# FLEX/BISON.
find_package(BISON 3.6 REQUIRED)
find_package(FLEX 2.6 REQUIRED)

# Generate grammar.
if (BISON_FOUND) 
	add_custom_command(
		OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/SOME_YACC.CPP ${CMAKE_CURRENT_BINARY_DIR}/SOME_YACC.h
		COMMAND ${BISON} -d -o y.tab.some_header.c ${PROJECT_SOURCE_DIR}/src/module_parser/some_yacc.y
		COMMAND sed s/yy/some_header_yy/g y.tab.some_header.c > ${CMAKE_CURRENT_BINARY_DIR}/some_header_yacc.cpp
		COMMAND sed s/yy/some_header_yy/g y.tab.some_header.h > ${CMAKE_CURRENT_BINARY_DIR}/some_header_yacc.h
		COMMAND rm -f y.tab.some_header.h
		COMMAND rm -f y.tab.some_header.c
		COMMENT "Generating some_header_yacc.cpp"
	)

	# Do that command for all other yacc files
endif()

# Generate lexer
if (FLEX_FOUND)
	add_custom_command(
		OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/some_header_lex.cpp
		COMMAND ${FLEX_EXECUTABLE} -o lex.yy.some_header.c > ${CMAKE_CURRENT_BINARY_DIR}/some_header_lex.cpp
		COMMAND sed s/yy/some_header_yy/g lex.yy.some_header.c > ${CMAKE_CURRENT_BINARY_DIR}/some_header_lex.cpp
		COMMAND rm -f lex.yy.some_header.c 
		COMMENT "Generating some_header_lex.cpp"
		DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/some_header_yacc.cpp
	)

	# add for all other lex files
endif()

# Library name.
set(lib_name module2_parse)

# Library sources.
set(
	lib_srcs
	some_header_lex.cpp
	some_header_yacc.cpp
	# the rest of files
)

# Library header files.
# ${CMAKE_BINARY_DIR} is a built-in variable, represents the top-level binary directory where CMake generates 
# build artifacts, such as compiled object files, libraries, and executables. This directory is typically set 
# by the user when configuring the CMake project using the CMake command-line tools. It is the location where 
# the build system for your project is generated, and it's separate from the source directory.
file(GLOB lib_incs "${CMAKE_BINARY_DIR}/${lib_name}/*.h") # --> does it generate header files in the bin dir of the project?

# Include dirs.
# is a built-in variable and represents the current binary directory for the current CMake source file being 
# processed. This is often used to refer to the binary directory where a specific CMakeLists.txt file is located. 
# It allows you to specify paths relative to the directory where the current CMakeLists.txt file resides.
include_directories(
	${CMAKE_CURRENT_BINARY_DIR}
)

# Build library.
add_library(${lib_name} STATIC ${lib_srcs})
set_target_properties(${lib_name} PROPERTIES PUBLIC_HEADER "${lib_incs}")

# Link library.
# The target_link_libraries() command is used to specify the libraries that should be linked with a particular
# CMake target. ${lib_name} is the name of the target you want to link with other libraries. In this case, it's 
# the module2_parse library.
target_link_libraries(
	${lib_name}
	lib_used_by_this_module # This means that module2_parse depends on lib_used_by_this_module, and its code will be linked with module2_parse.
	Threads::Threads # The Threads package is commonly used in CMake projects to ensure that multi-threaded code is properly linked and configured.
)