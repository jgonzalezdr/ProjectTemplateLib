cmake_minimum_required( VERSION 3.3 )

option( ENABLE_TEST "Enable building tests" ON )
option( COVERAGE_VERBOSE "Coverage analysis is performed in verbose mode" OFF )

if( ENABLE_TEST )

    enable_testing()

    include( CommonTestTargets.cmake )

    set( PROD_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/../lib )
    set( PROD_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/../lib )
    set( MOCKS_DIR ${CMAKE_CURRENT_LIST_DIR}/Mocks )
    set( HELPERS_DIR ${CMAKE_CURRENT_LIST_DIR}/TestHelpers )

    #
    # Test modules
    #

    #>>> Add all the subdirectories with your test modules
    add_subdirectory( ExamplePrivateClass )
    add_subdirectory( ExamplePublicClass )

endif()
