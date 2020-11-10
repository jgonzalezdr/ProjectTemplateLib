cmake_minimum_required( VERSION 3.13 )

#>>> Edit the project name (don't add any "lib" prefix or suffix!)
project( ProjectTemplate VERSION 1.0.0 )

option( BUILD_STATIC_LIB "Build static library" ON )
option( BUILD_SHARED_LIB "Build shared library" ON )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/" )

if( MSVC )
    include( VisualStudioHelper )

    generate_groups( ${CMAKE_CURRENT_SOURCE_DIR} sources )
    generate_groups( ${CMAKE_CURRENT_SOURCE_DIR} include )
endif( MSVC )

#
# Source files
#

#>>> Add your source files to the following list
set( SRC_LIST
     sources/ExamplePublicClass.cpp
     sources/ExamplePrivateClass.cpp
)

#
# Header files
#

#>>> Add your header files to the following list
set( INC_LIST
     sources/ExamplePrivateClass.hpp
     include/ExamplePublicClass.hpp
)

#
# Project information
#

if( NOT PROJECT_VERSION_BUILD )
    set( PROJECT_VERSION_BUILD ${PROJECT_VERSION_TWEAK} )
endif()

include( GenerateProductVersion )

#>>> Edit the example info to suit your project info
generate_product_version(
    PRODUCT_VERSION_FILES
    NAME ${PROJECT_NAME}
    FILE_DESCRIPTION "Example library description"
    VERSION_MAJOR ${PROJECT_VERSION_MAJOR}
    VERSION_MINOR ${PROJECT_VERSION_MINOR}
    VERSION_PATCH ${PROJECT_VERSION_PATCH}
    VERSION_BUILD ${PROJECT_VERSION_BUILD}
    VERSION_SUFFIX "${PROJECT_VERSION_SUFFIX}"
    COMPANY_NAME "www.example.com"
    COMPANY_COPYRIGHT "(C) Copyright YEAR Whatever"
    PRIVATE_BUILD "${PRIVATE_BUILD_INFO}"
    SPECIAL_BUILD "${SPECIAL_BUILD_INFO}"
    PRERELEASE "${PRERELEASE}"
    PATCHED "${PATCHED_RELEASE}"
    HOMEPAGE "http://example.com/yourproduct/"
    MAINTAINER "Your Name <yourname@example.com>"
    EXPORT_TO_PARENT_SCOPE
)

#
# Configuration file definition
#

if( BUILD_SHARED_LIB AND NOT BUILD_STATIC_LIB )
    set( CONFIG_SHARED_LIB "\n#ifndef ${PROJECT_NAME}_SHARED_LIB\n#define ${PROJECT_NAME}_SHARED_LIB 1\n#endif\n" )
endif()

configure_file( templates/Config.hpp.in include/${PROJECT_NAME}Config.hpp )

#
# Library definition
#

if( MSVC )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc" )
endif()

if ( BUILD_SHARED_LIB )
    #
    # Shared library definition
    #

    add_library( ${PROJECT_NAME} SHARED ${SRC_LIST} ${INC_LIST} ${PRODUCT_VERSION_FILES} )
    target_compile_definitions( ${PROJECT_NAME} PUBLIC "${PROJECT_NAME}_SHARED_LIB" )

    target_include_directories( ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )
    target_include_directories( ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/include )

    #>>> Uncomment and edit the following commands to add compile definitions
    #target_compile_definitions( ${PROJECT_NAME} PUBLIC "${PROJECT_NAME}_MY_DEFINITION" )

    add_dependencies( build ${PROJECT_NAME} )

    #
    # C++ standard
    #

    #>>> Uncomment and edit the following commands to set an specific C++ standard
    #set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11 )
    #set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED 1 )

    #
    # External libraries
    #

    #>>> Uncomment and edit the following commands to add external libraries
    #target_include_directories( ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/ExternalLib/include )
    #target_link_directories( ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/ExternalLib/lib )
    #target_link_libraries( ${PROJECT_NAME} ExternalLib.lib )

    #
    # Shared library properties
    #

    set_target_properties( ${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_dbg" )
    set_target_properties( ${PROJECT_NAME} PROPERTIES COVERAGE_POSTFIX "_cov" )
    set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION} )
endif()

if ( BUILD_STATIC_LIB )
    #
    # Static library definition
    #

    add_library( ${PROJECT_NAME}_static STATIC ${SRC_LIST} ${INC_LIST} ${PRODUCT_VERSION_FILES} )

    target_include_directories( ${PROJECT_NAME}_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )
    target_include_directories( ${PROJECT_NAME}_static PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/include )

    #>>> Uncomment and edit the following commands to add compile definitions
    #target_compile_definitions( ${PROJECT_NAME}_static PUBLIC "${PROJECT_NAME}_MY_DEFINITION" )

    add_dependencies( build ${PROJECT_NAME}_static )

    #
    # C++ standard
    #

    #>>> Uncomment and edit the following commands to set an specific C++ standard
    #set_property( TARGET ${PROJECT_NAME}_static PROPERTY CXX_STANDARD 11 )
    #set_property( TARGET ${PROJECT_NAME}_static PROPERTY CXX_STANDARD_REQUIRED 1 )

    #
    # External libraries
    #

    #>>> Uncomment and edit the following commands to add external libraries
    #target_include_directories( ${PROJECT_NAME}_static PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/ExternalLib/include )
    #target_link_directories( ${PROJECT_NAME}_static PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/ExternalLib/lib )
    #target_link_libraries( ${PROJECT_NAME}_static ExternalLib.lib )

    #
    # Static library properties
    #

    set_target_properties( ${PROJECT_NAME}_static PROPERTIES DEBUG_POSTFIX "_dbg" )
    set_target_properties( ${PROJECT_NAME}_static PROPERTIES COVERAGE_POSTFIX "_cov" )
    set_target_properties( ${PROJECT_NAME}_static PROPERTIES VERSION ${PROJECT_VERSION} )
endif()

#
# Install
#

include( InstallersSetup.cmake )

if ( BUILD_SHARED_LIB )
    if( WIN32 )
        install( TARGETS ${PROJECT_NAME} RUNTIME DESTINATION lib )
        install( TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION lib )
    else()
        install( TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib )
    endif()
endif()

if ( BUILD_STATIC_LIB )
    install( TARGETS ${PROJECT_NAME}_static ARCHIVE DESTINATION lib )
endif()

install( DIRECTORY include/ DESTINATION include ) 
install( DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/ DESTINATION include ) 
