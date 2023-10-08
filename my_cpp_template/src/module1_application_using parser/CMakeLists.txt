# Summary 
# 1. define variables needed for building the lib (lib name, lib source files list, headers list)
# 2. create the library using the source and the headers with the name given in the variable
# 3. set library properties

# Library name.
# In CMake, variables can store various types of data, including strings, lists, and booleans. In this case, 
# lib_name is assigned a string value.
set (lib_name module1)

# Library sources.
# setting a variable with list of files
set (
	 lib_srcs 
	 source_file1.C
	 source_file2.C
	 source_file3.C
	 source_file4.C	 
)

# Library header files.
# the file(GLOB ..)  command is used to search for files matching the statement ...h and then store the list in the lib_incs
# this variable will be used later in other commands 
file(GLOB lib_incs "${PROJECT_SRC_DIR}/include/${lib_name}/*.h")

# Build library
add_library(${lib_name} STATIC ${lib_srcs}) # create a Cmake target object that has a name and information about the library
set_targer_properties(${lib_name} PROPERTIES PUBLIC_HEADER "${lib_incs}") # set the target object properties, here include dependencies

# Target include dirs.
# to easily include the library's headers using #include <lib_name/header.h> notation, assuming ${lib_name} 
# is the name of the library and header.h
Target_include_directories(
	$lib_name
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${PROJECT_SOURCE_DIR}/include/${lib_name}
)