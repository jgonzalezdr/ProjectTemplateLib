/**
 * @file
 * @brief      Unit tests for the "UnitUnderTest" class
 * @project    Project Template
 * @authors    Your Name <yourname@example.com>
 * @copyright  Copyright (c) YEAR Whatever. All rights reserved.
 * @license    See LICENSE.txt
 */

/*===========================================================================
 *                              INCLUDES
 *===========================================================================*/

#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "UnitUnderTest.hpp"

#include "OtherClass_expect.hpp"

using CppUMockGen::IgnoreParameter;

/*===========================================================================
 *                      COMMON TEST DEFINES & MACROS
 *===========================================================================*/

/*===========================================================================
 *                          TEST GROUP DEFINITION
 *===========================================================================*/

TEST_GROUP( UnitUnderTest )
{
};

/*===========================================================================
 *                    TEST CASES IMPLEMENTATION
 *===========================================================================*/

TEST( UnitUnderTest, f1 )
{
    // Prepare
    ExamplePublicClass c;
    expect::ExamplePrivateClass$::f2( IgnoreParameter::YES, 5, 9, 25 );

    // Exercise
    int ret = c.f1( 5, 9 );

    // Verify
    CHECK_EQUAL( 50, ret );

    // Cleanup
}
