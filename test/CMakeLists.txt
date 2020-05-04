cmake_minimum_required( VERSION 3.3 )

project( ProjectTemplate.AllTests )

enable_testing()

include( CommonTestTargets.cmake )

#
# Include all the subdirectories with your test modules
#
add_subdirectory( ExamplePrivateClass )
add_subdirectory( ExamplePublicClass )
