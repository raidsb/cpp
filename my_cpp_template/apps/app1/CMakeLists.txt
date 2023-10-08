# Boost library.
set(BOOST_USE_STATIC_LIBS ON)
find_package(Boost 1.73.0 REQUIRED COMPONENTS program_options)

if (BOOST_FOUND)
	include_directories(${Boost_INVLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)

	# Build app.
	add_executable(
		name_of_app
		source_file1.cpp 
		source_file2.cpp 
	)

	# Link app.
	target_link_directories(
		name_of_app
		module_lib1
		module_lib2
		${Boost_LIBRARIES}
	)
endif()