//
// Created by Kobe Celen on 29/11/2023.
//

#include <iostream>
#include "catch2/catch.hpp"
#include "bloom/bloomfilter.hpp"

using namespace std;

TEST_CASE("d")
{

    vector<size_t> hashConstants = {0xDEADBEEF, 0xC0FFEE};
    BloomFilter<std::string> bloomFilter(10, hashConstants);

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