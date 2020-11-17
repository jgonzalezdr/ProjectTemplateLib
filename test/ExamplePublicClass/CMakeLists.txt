cmake_minimum_required( VERSION 3.3 )

project( ProjectTemplate.Test.ExamplePublicClass )

#
# Test configuration
#

include_directories(
     ${PROD_SOURCE_DIR}/sources
     ${PROD_SOURCE_DIR}/include
     ${PROD_BINARY_DIR}/include
     ${MOCKS_DIR}
)

#
# Production source files
#

set( PROD_SRC_FILES
     ${PROD_SOURCE_DIR}/sources/ExamplePublicClass.cpp
)

#
# Test source files
#

set( TEST_SRC_FILES
     ExamplePublicClass_test.cpp
     ${MOCKS_DIR}/ExamplePrivateClass_mock.cpp
     ${MOCKS_DIR}/ExamplePrivateClass_expect.cpp
)

#
# Generate test target
#

include( ../GenerateTest.cmake )
