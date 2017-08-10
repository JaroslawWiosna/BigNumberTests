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
#include <stdlib.h> // srand, rand
#include <time.h> // time

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

    ASSERT_EQ(c.getmValue(), "1043");
}

TEST(TestAddition, addition04random)
{
    constexpr std::size_t max = 100000;

    BigNumber a{0};
    BigNumber b{0};
    BigNumber c{0};
    BigNumber d{0};
    BigNumber e{0};
    const BigNumber two{"2"};
    for (std::size_t i=0; i<max; ++i) {
        a = rand()%1000000;
        c = a + b;
	EXPECT_TRUE(a.getmValue() == c.getmValue());
    }
    for (std::size_t i=0; i<max; ++i) {
        a = rand()%1000000;
        b = rand()%1000000;
        c = a + b;
	d = b + a;
	EXPECT_TRUE(c.getmValue() == d.getmValue());
    }
    for (std::size_t i=0; i<max; ++i) {
        a = rand()%1000000;
        b = rand()%1000000;
        c = two * b;
        d = a + b + b; // TODO: check if I can use multiplication to test add
        e = a + c;
	EXPECT_TRUE(d.getmValue() == e.getmValue());
    }
}

TEST(TestAddition, addition05increment)
{
    BigNumber a{"34"};
    BigNumber b{"35"};
    BigNumber c = ++a;
    ASSERT_TRUE(b == c);

    BigNumber d = a++;
    ASSERT_TRUE(b == d);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
