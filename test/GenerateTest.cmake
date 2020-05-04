if( NOT DEFINED CPPUTEST_HOME )
    set( CPPUTEST_HOME $ENV{CPPUTEST_HOME} )
endif()

if( NOT DEFINED CPPUTEST_HOME )
    message(FATAL_ERROR "CPPUTEST_HOME variable must define the path of the CppUTest home directory")
endif()

if( NOT MSVC )
    set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall" )
endif()

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DUNIT_TEST" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUNIT_TEST" )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/" )

include_directories( ${CPPUTEST_HOME}/include )
link_directories( ${CPPUTEST_HOME}/lib )

if( MSVC )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc" )
endif()

add_executable( ${PROJECT_NAME} ${PROD_SRC_FILES} ${TEST_SRC_FILES} ${CMAKE_CURRENT_LIST_DIR}/TestMain.cpp )

#
# Uncomment the following commands to set an specific C++ standard
#
#set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11 )
#set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED 1 )

if( MSVC )
    target_link_libraries( ${PROJECT_NAME} debug CppUTest64d optimized CppUTest64 )
else()
    target_link_libraries( ${PROJECT_NAME} CppUTest64 CppUTestExt64 gcov pthread )
endif()

add_dependencies( build ${PROJECT_NAME} )
add_dependencies( run_tests ${PROJECT_NAME} )

if( CI_MODE )
    set( TEST_ARGS -ojunit -v )
else()
    set( TEST_ARGS -v )
endif()

add_test( ${PROJECT_NAME} ${PROJECT_NAME} ${TEST_ARGS} )
