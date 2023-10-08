# Summary of the project CMAKE File
# 1. set the minimum Cmake version reguired
# 2. set project meta information. 
# 3. if the built-in project name equals the given project name by dev, then do the following 
	# set the modern built tests
	# set the cpp language extensions to off
	# set export compile commands to on 
	# set a global property to use folders in ides to on
# 4. add compile options ..mostly about warning messages
# 5. set prefix paths and boost lib 
# 6. add the src folder -> tells cmake to get into the src and process it 
# 7. add the apps folder -> tells cmale to get into the apps and process it
# 8. include ctest 
# 9. add tests folder for building

# minimum cmake version required is 3.15
cmake_minimum_required(VERSION 3.15)

#Project details meta data code
project(MyCppProject   
		VERSION 0.0.1 
		DESCRIPTION "My Cpp project"
		LANGUAGES CXX)

# CMAKE_PROJECT_NAME is a built-in variable to represent the current project being configured.
# PROJECT_NAME is a variable used by developers to specifiy the name of the current project. -----> that dev PROJECT_NAME how is it passed to the program
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) 
	# CMake will generate and build targets for running tests if there are any defined in the project.
	set (MODERN_CMAKE_BUILD_TESTING ON)
		
	# CMAKE_CXX_EXTENSIONS controls whether the compiler should enable language extensions.
	set (CMAKE_CXX_EXTENSIONS OFF)

	# Generates a compile_commands.json file used by some IDEs for code navigation and completion.
	set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

	# Support folders in IDEs. it organizes targets and source files into folders within 
	# integrated and this is set as a global property.	
	set_property(GLOBAL PROPERTY USE_FOLDERS ON) 
endif 

# Turn on warning for GCC.
if (CMAKE_COMPILER_IS_GNUCC) 
	add_compile_options(-Wall -Wextra -pedantic -Werror)
	# -Wall: Enables a set of commonly used warning flags, such as warnings about potentially problematic code constructs.
	# -Wextra: Enables additional warning flags, including warnings about non-standard or potentially error-prone code.
	# -pedantic: Requests stricter conformance to the C standard and additional warnings about non-standard language features.
	# -Werror: Treats all warnings as errors, causing the compilation to fail if any warnings are generated.
endif 

#Set prefix path to tools that we use.
# paths where CMake should look for package or CMakw configuration files.These paths are often used when you 
# are working with external libraries or dependencies that are not installed in	the default system locations, 
# and you want CMake to find and use them during the configuration process.
set(CMAKE_PREFIX_PATH some_path)
set(BOOST_ROOT path_to_boost_lib)

#Library modules go here. so cmake will first descend into this src sub directory and process it then proceed to the rest.
add_subdirectory(src) 

#Executable apps go here.
add_subdirectory(apps)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	# CTest is a CMake module that provides functionality for testing CMake-based projects. It includes commands 
	# and variables for defining and running tests, collecting test results, and generating test-related targets.
	include(CTest)   
endif()

if ((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
	set (MY_TESTCASES_DIR path_to_test_cases)
	add_subdirectory(tests)
endif()