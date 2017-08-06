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

TEST(TestAddition, multiplication01)
{
    BigNumber a{"11"};
    BigNumber b{"120"};
    BigNumber c = a * b;
    ASSERT_TRUE(c.getmValue() == "1320");

    a *= b;
    ASSERT_TRUE(a.getmValue() == "1320");
}

TEST(TestAddition, multiplication02)
{
    BigNumber a{"12345"};
    BigNumber b{"6789"};
    BigNumber c = a * b;
    ASSERT_TRUE(c.getmValue() == "83810205");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
