#list of dirs to build
# dir is a variable name as iterator over the module directories module1 and module2 
# and adds it to the cmake processing. the order of the modules in the list impacts how these folders are processed
foreach(dir module1 module2) 
	add_subdirectory(${dir})
endforeach()
