cmake_minimum_required( VERSION 3.3 )

project( ProjectTemplate.Example.ExampleTemplate VERSION 1.0.0 )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/" )

if( MSVC )
    include( VisualStudioHelper )

    generate_groups( ${CMAKE_CURRENT_SOURCE_DIR} sources )
    generate_groups( ${CMAKE_CURRENT_SOURCE_DIR} include )
endif( MSVC )

#
# Source files
#

#>>> Add your example source files to the following list
set( SRC_LIST
     sources/ExampleTemplate.cpp
)

#
# Executable definition
#

if( MSVC )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc" )
endif()

add_executable( ${PROJECT_NAME} ${SRC_LIST} )

#>>> Uncomment and edit the following commands to add compile definitions
#target_compile_definitions( ${PROJECT_NAME} PUBLIC "${PROJECT_NAME}_MY_DEFINITION" )

add_dependencies( ${TARGET_NAMESPACE}build_examples ${PROJECT_NAME} )

#
# C++ standard
#

#>>> Uncomment and edit the following commands to set an specific C++ standard
#set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11 )
#set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED 1 )

#
# External libraries
#

string( REGEX REPLACE "(Lib)?.Top$" "" LIBRARY_NAME ${CMAKE_PROJECT_NAME} )

if( BUILD_STATIC_LIB )
    target_link_libraries( ${PROJECT_NAME} ${LIBRARY_NAME}_static )
elseif( BUILD_SHARED_LIB )
    target_link_libraries( ${PROJECT_NAME} ${LIBRARY_NAME} )

    add_custom_target( ${PROJECT_NAME}_CopySharedLibs ALL
                       DEPENDS ${LIBRARY_NAME}
                       COMMAND cmake -E copy "$<TARGET_FILE:${LIBRARY_NAME}>" "$<TARGET_FILE_DIR:${PROJECT_NAME}>" )
    add_dependencies( ${TARGET_NAMESPACE}build ${PROJECT_NAME}_CopySharedLibs )
endif()

#>>> Uncomment and edit the following commands to add additional external libraries
#target_include_directories( ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/ExternalLib/include )
#target_link_directories( ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/ExternalLib/lib )
#target_link_libraries( ${PROJECT_NAME} ExternalLib.lib )

#
# Executable properties
#

set_target_properties( ${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_dbg" )
set_target_properties( ${PROJECT_NAME} PROPERTIES COVERAGE_POSTFIX "_cov" )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION} )

#
# Install
#

if( INSTALL_EXAMPLES )
    install( TARGETS ${PROJECT_NAME} RUNTIME DESTINATION examples )
endif()
