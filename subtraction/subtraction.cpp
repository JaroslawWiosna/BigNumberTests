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

TEST(Test, subtraction01)
{
    BigNumber a{"1082"};
    BigNumber b{"328"};
    BigNumber c = a - b;
#if 0 // TODO: leading zeros removing not yet implemented
    ASSERT_TRUE(c.getmValue() == "754");
#endif
}

TEST(Test, subtraction02)
{
    BigNumber a{"582"};
    BigNumber b{"328"};
    BigNumber c = a - b;
    std::cout << c.getmValue();
    ASSERT_TRUE(c.getmValue() == "254");
}

TEST(Test, subtraction03)
{
    BigNumber a{"582"};
    BigNumber b{"0"};
    BigNumber c = a - b;
    std::cout << c.getmValue();
    ASSERT_TRUE(c.getmValue() == "582");
}

TEST(Test, subtraction04)
{
    BigNumber a{"582"};
    BigNumber b{"1"};
    BigNumber c = a - b;
    BigNumber d = --a;
    BigNumber e = a--;
    EXPECT_TRUE(c.getmValue() == "581");
    EXPECT_TRUE(d.getmValue() == "581");
    EXPECT_TRUE(e.getmValue() == "581");
    EXPECT_TRUE(c.getmValue() == d.getmValue());
    EXPECT_TRUE(d.getmValue() == e.getmValue());
    EXPECT_TRUE(e.getmValue() == c.getmValue());

}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
