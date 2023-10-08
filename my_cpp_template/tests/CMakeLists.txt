add_subdirectory(test_cases_of_app1)

# Tests to run.
if (BUILD_TESTING)
	set (
		test_files 

		test_file1
		test_file2
		/path/to/test_file3
		..
	)

	# running test for app1
	foreach(TEST ${test_files})
		add_test(
			NAME ${TEST}_app1
			COMMAND app1 --switch ${APP1_TESTCASES_DIR}/${TEST}
		)
	endforeach()

	# running test for app2 another example
	add_test(
		NAME test_name
		COMMAND APP2 --switch1 --switch2 ${CMAKE_SOURCE_DIR}/tests/test_cases_for_app1/some_folder/some_file 
		--swith3_for_output ${CMAKE_BINARY_DIR}/tests/test_cases_for_app1/some_folder/some_file_name
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
	)

	add_test(
		NAME test_case_name 
		COMMAND diff something 
	)

	#FIXTURES_REQUIRED propert makes sure the FIXTURES_SETUP test is run
	set_tests_properties(test_case_name PROPERTIES FIXTURES_SETUP something_run)
	set_tests_properties(test_case_name PROPERTIES FIXTURES_SETUP something_run)

	set_property(
		TEST test_case_name
		PROPERTY WILL_FAIL TRUE
	)
endif()