 /**
 * @file
 * @brief      Example public class implementation
 * @project    Project Template
 * @authors    Jesus Gonzalez <jgonzalez@gdr-sistemas.com>
 * @copyright  Copyright (c) 2020 Jesus Gonzalez. All rights reserved.
 * @license    See LICENSE.txt
 */

#include "ExamplePublicClass.hpp"
#include "ExamplePrivateClass.hpp"

int ExamplePublicClass::f1(int a, int b)
{
    ExamplePrivateClass c;

    return 2 * c.f2( a, b );
}
