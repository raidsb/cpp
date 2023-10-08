# This option tells Doxygen to extract documentation from all source files, including those 
# without special Doxygen comments. It ensures that all code elements are included in the 
# generated documentation.
set(DOXYGEN_EXTRACT_ALL YES) 

# This option enables built-in support for documenting C++ Standard Library (STL) classes and 
# functions, so that Doxygen can generate documentation for STL elements in your code.
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

# List the dirs/files.
# is a CMake function provided by the Doxygen module in CMake. It is used to trigger the generation 
# of Doxygen documentation.
# docs: This is a user-defined name for the documentation target. It can be used later to specify dependencies or other build rules.
# WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/include"This specifies the working directory where Doxygen will look for source code and generate documentation. In this case, it's set to the include directory within your project's source directory 
doxygen_add_docs(
	docs
	WORKING_DIRECTORY
	"${PROJECT_SOURCE_DIR}/include"
)