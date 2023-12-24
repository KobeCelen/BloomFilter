//
// Created by Kobe Celen on 29/11/2023.
//

#include <iostream>
#include "catch2/catch.hpp"
#include "bloom/bloomfilter.hpp"
#include "bloom/hasher.hpp"

using namespace std;

TEST_CASE("Main")
{

    vector<size_t> hashConstants = {0xDEADBEEF, 0xC0FFEE, 0xABCDEF};
    BloomFilter<std::string> bloomFilter(1000, hashConstants);

    bloomFilter.insert("hello");
    bloomFilter.insert("world");
    bloomFilter.insert("test1");
    bloomFilter.insert("test2");
    bloomFilter.insert("test4");
    bloomFilter.insert("test6");
    bloomFilter.insert("test8");


    std::cout << "Query 'hello': " << bloomFilter.query("hello") << std::endl;  // Should print true
    std::cout << "Query 'foo': " << bloomFilter.query("foo") << std::endl;      // Should print false

}

TEST_CASE("Hasher values" , "[vector]")
{
    vector<size_t> hashConstants = {3, 4, 5};

    vector<std::size_t> expected_hashValue = {3138, 3107, 3076};

    vector<std::size_t> actual_hashValue;

    for (size_t hasherConst : hashConstants) {
        Hasher<string> hasher(hasherConst);
        actual_hashValue.insert(actual_hashValue.end(),hasher("hello"));

        //cout << "Actual hashvalue: " << actual_hashValue << endl;
    }

    REQUIRE(expected_hashValue == actual_hashValue);
}


TEST_CASE("")
{

}