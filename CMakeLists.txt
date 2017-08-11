add_subdirectory( cppVersion )
add_subdirectory( addition )
add_subdirectory( subtraction )
add_subdirectory( multiplication )
add_subdirectory( division )
add_subdirectory( constructors )
add_subdirectory( powerOfTen )
add_subdirectory( equal )
add_subdirectory( operators )

if(BUILD_LONG_RUNNING_TESTS)
    add_subdirectory( LongRunningTests )
endif()

