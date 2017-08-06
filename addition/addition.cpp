/**
 * @file addition.cpp
 *
 * @author Jaroslaw Wiosna
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include <gtest/gtest.h>
#include "BigNumber.hpp"

TEST(TestAddition, addition01)
{
    BigNumber a{"123"};
    BigNumber b{"444"};
    BigNumber c = a + b;

    ASSERT_TRUE(c.getmValue() == "567");
}

TEST(TestAddition, addition02)
{
    BigNumber a{"123"};
    BigNumber b{"2"};
    BigNumber c = a + b;

    ASSERT_TRUE(c.getmValue() == "125");
    //////////////
    BigNumber d{"3"};
    BigNumber e{"123"};
    BigNumber f = d + e;

    ASSERT_TRUE(f.getmValue() == "126");
}

TEST(TestAddition, addition03withCarry)
{
    BigNumber a{"999"};
    BigNumber b{"44"};
    BigNumber c = a + b;

    ASSERT_TRUE(c.getmValue() == "1043");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
