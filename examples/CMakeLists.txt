option( BUILD_EXAMPLES "Enable building examples" ON )
option( INSTALL_EXAMPLES "Enable installing examples" OFF )

if( BUILD_EXAMPLES AND (BUILD_SHARED_LIB OR BUILD_STATIC_LIB) )

    #
    # Example applications
    #

    #>>> Add all the subdirectories with your examples
    add_subdirectory( Example1 )

endif()