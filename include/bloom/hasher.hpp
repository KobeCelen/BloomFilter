//
// Created by Kobe Celen on 29/11/2023.
//

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


