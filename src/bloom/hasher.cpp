#include <iostream>
#include "bloom/hasher.hpp"

template <typename ElementType>
Hasher<ElementType>::Hasher(std::size_t c) : c(c) {}



template <typename ElementType>
std::size_t Hasher<ElementType>::operator()(ElementType e) const {
    //Your hash function implementation here
    //std::cout << "HASHER: elementType: " << e << std::endl;
    //std::cout << "HASHER: c: " << c << std::endl;

    std::size_t hashValue = 0;
    for (char ch : e) {
        //std::cout << "value ch in e " << int(ch) << std::endl;
        hashValue = hashValue * 2 + ch - c;
    }

    //std::cout << "HASHER: hashvalue: " << hashValue << std::endl;
    return hashValue;
}

template class Hasher<std::string>;



