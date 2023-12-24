#include <iostream>
#include "bloom/bloomFilter.hpp"
#include "bloom/hasher.hpp"

template <typename ElementType>
BloomFilter<ElementType>::BloomFilter(std::size_t bit_size, std::vector<std::size_t> hash_initialization_constants)
    : bitSize(bit_size), hashInitializationConstants(hash_initialization_constants) {
    // Constructor implementation here
    bitArray.resize(bit_size, false); //all bits to zero
}

template <typename ElementType>
void BloomFilter<ElementType>::insert(const ElementType& e) {
    // Insert method implementation here
    for (std::size_t i = 0; i < hashInitializationConstants.size(); ++i) {
        //std::cout << hashInitializationConstants[i] << std::endl;
        Hasher<ElementType> hasher(hashInitializationConstants[i]);
        std::size_t hashValue = hasher(e) % bitSize;
        std::cout << "BLOOM: value in the array: " << hashValue << std::endl;
        bitArray[hashValue] = true;  // Set the corresponding bit to one
        if (is_full()){
            std::cout << "BLOOM FILTER IS FULL " << std::endl;
            break;
        }
    }

    for (bool bit : bitArray) {
        std::cout << bit << " ";
    }
    std::cout << std::endl;

}

template <typename ElementType>
bool BloomFilter<ElementType>::query(const ElementType& e) const {
    // Query method implementation here
    for (std::size_t i = 0; i < hashInitializationConstants.size(); ++i) {
        Hasher<ElementType> hasher(hashInitializationConstants[i]);
        std::size_t hashValue = hasher(e) % bitSize;
        std::cout << "BLOOM: search value in the array: " << hashValue << std::endl;
        if (!bitArray[hashValue]) {
            return false;  // If any bit is zero, the element is definitely not in the Bloom filter
        }
    }
    return true;  // All bits are one, the element might be in the Bloom filter
}

template <typename ElementType>
bool BloomFilter<ElementType>::is_full() const {
    // is_full method implementation here
    for (bool bit : bitArray) {
        if (!bit) {
            return false;  // If any bit is zero, the Bloom filter is not full
        }
    }
    return true;  // All bits are one, the Bloom filter is full
}

template class BloomFilter<std::string>;