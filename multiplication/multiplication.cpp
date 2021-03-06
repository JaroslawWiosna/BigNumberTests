/**
 * @file multiplication.cpp
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

TEST(Test, multiplication01)
{
    BigNumber a{"11"};
    BigNumber b{"120"};
    BigNumber c = a * b;
    ASSERT_TRUE(c.getmValue() == "1320");

    a *= b;
    ASSERT_TRUE(a.getmValue() == "1320");
}

TEST(Test, multiplication02)
{
    BigNumber a{"12345"};
    BigNumber b{"6789"};
    BigNumber c = a * b;
    ASSERT_TRUE(c.getmValue() == "83810205");
}

TEST(Test, multiplication03)
{
    BigNumber a{"123123123"};
    BigNumber b{"456456"};
    BigNumber c = a * b;
#if 0 //Temp commented
    ASSERT_TRUE(c.getmValue() == "56200288232088");
#endif
}

// TODO: move the following test to separate file
TEST(Test, operatorModulo)
{
    BigNumber a{"123123000"};
    BigNumber b{"1000"};
    BigNumber c = a % b;
    ASSERT_TRUE(c.getmValue() == "123123");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
