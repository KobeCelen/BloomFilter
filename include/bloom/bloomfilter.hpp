#pragma once

#include <cstddef>
#include <vector>

template <typename ElementType>
class BloomFilter {
public:
    BloomFilter(std::size_t bit_size, std::vector<std::size_t> hash_initialization_constants);

    void insert(const ElementType& e);

    bool query(const ElementType& e) const;

    bool is_full() const;

    std::vector<bool> bitArray;

private:
    std::size_t bitSize;
    std::vector<std::size_t> hashInitializationConstants;

};