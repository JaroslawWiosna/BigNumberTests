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

TEST(Test, fibonacci)
{
    BigNumber zero{};
    BigNumber one{1};
    constexpr int size = 10;
    std::vector<BigNumber> vec;
    vec.reserve(size);

    vec.push_back(zero);
    vec.push_back(one);

    for (int i = 2; i<size; ++i) {
        vec.push_back( vec[i-2] + vec[i-1] ); 
    }
    for (const auto& i : vec) {
        std::cout << i << std::endl;
    }
}

TEST(Test, factorial)
{
    BigNumber zero{};
    BigNumber one{1};
    BigNumber tmp{};
    constexpr int size = 50;
    std::vector<BigNumber> vec;
    vec.reserve(size);

    vec.push_back(one);

    for (int i = 1; i<size; ++i) {
	tmp = i;
        vec.push_back( tmp * vec[i-1] ); 
    }
    for (const auto& i : vec) {
        std::cout << i << std::endl;
    }

}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
