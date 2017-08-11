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

TEST(Test, addition04random)
{
    constexpr std::size_t max = 1000000;

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

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
