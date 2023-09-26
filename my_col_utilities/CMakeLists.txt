# minimum cmake version required is 3.15
cmake_minimum_required(VERSION 3.15)

#Project details meta data code
project(MyCppProject   
		VERSION 0.0.1 
		DESCRIPTION "My Cpp project"
		LANGUAGES CXX)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	set (MODERN_CMAKE_BUILD_TESTING ON)
	set (CMAKE_CXX_EXTENSIONS OFF)
	set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

	# Support folders in IDEs.
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif 

# Turn on warning for GCC.
if (CMAKE_COMPILER_IS_GNUCC) 
	add_compile_options(-Wall -Wextra -pedantic -Werror)
endif 

#Set prefix path to tools that we use.
set(CMAKE_PREFIX_PATH some_path)
set(BOOST_ROOT path_to_boost_lib)

#Library modules go here. so cmake will first descend into this src sub directory and process it then proceed to the rest.
add_subdirectory(src) 

#Executable apps go here.
add_subdirectory(apps)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	include(CTest)
endif()

if ((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
	set (MY_TESTCASES_DIR path_to_test_cases)
	add_subdirectory(tests)
endif()