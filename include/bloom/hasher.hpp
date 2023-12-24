#pragma once

#include <cstddef>
#include <string>

template <typename ElementType>
class Hasher {
public:
    std::size_t c;

    Hasher(std::size_t c);

    std::size_t operator() (ElementType e) const;
};


