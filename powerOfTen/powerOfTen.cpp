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

TEST(Test, powerOfTen01Ctor)
{
    BigNumber a{"powerOfTenTo5"};
    BigNumber b{"100000"};
    BigNumber c{100000};
#if 0
    std::cout <<"a.getmValue() = " << a.getmValue() << std::endl;
#endif
    ASSERT_TRUE(a == b);
    ASSERT_TRUE(b == c);
    ASSERT_TRUE(c == a);
    ASSERT_TRUE(a.getmValue() == "100000");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
