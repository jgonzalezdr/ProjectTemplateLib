cmake_minimum_required( VERSION 3.3 )

project( ProjectTemplate.Test.ExamplePrivateClass )

#
# Test configuration
#

set( PROD_DIR ${CMAKE_SOURCE_DIR}/prod )
set( MOCKS_DIR ${CMAKE_SOURCE_DIR}/test/Mocks )

include_directories(
    ${PROD_DIR}/sources
    ${PROD_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${MOCKS_DIR}
)

#
# Add your production source files to the following list
#
set( PROD_SRC_FILES
     ${PROD_DIR}/sources/ExamplePrivateClass.cpp
)

#
# Add your test source files to the following list
#
set( TEST_SRC_FILES
     ExamplePrivateClass_test.cpp
)

# Generate test target
include( ../GenerateTest.cmake )
