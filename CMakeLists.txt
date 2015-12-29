CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

IF (COMMAND CMAKE_POLICY)
	CMAKE_POLICY(SET CMP0003 NEW)
	CMAKE_POLICY(SET CMP0005 OLD)
ENDIF (COMMAND CMAKE_POLICY)   

# add FindAtomSpace.cmake to cmake's module path.
SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

#Compiler setting
IF (CMAKE_COMPILER_IS_GNUCXX)
	# 1) -Wno-variadic-macros is to avoid warnings regarding using
	# variadic in macro OC_ASSERT (the warning warns that this is only
	# available from C99, lol!)
	#
	# 2) -fopenmp for multithreading support
	#
	# 3) -std=gnu++0x for C++0x and GNU extensions support
	SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wno-variadic-macros -fopenmp -std=gnu++0x")
ENDIF (CMAKE_COMPILER_IS_GNUCXX)

# Check if dependencies are installed.                                                                                                                                                                     
FIND_PACKAGE(AtomSpace REQUIRED)                                                                                                                                          
IF (ATOMSPACE_FOUND)                                                                                                                                                            
	MESSAGE(STATUS "Great!, You're Ready to go with atomspace tutorials.")   
ELSE (ATOMSPACE_FOUND)                                                                                                                                                          
	MESSAGE(FATAL_ERROR "AtomSpace missing: Please make sure that you have
	installed atomspace before proceeding to this tutorial.")                                                                                                  
ENDIF (ATOMSPACE_FOUND)      

#Compile
ADD_EXECUTABLE(crudexample
	CRUDExample
	)
TARGET_LINK_LIBRARIES(crudexample
	${ATOMSPACE_LIBRARIES}
	)
