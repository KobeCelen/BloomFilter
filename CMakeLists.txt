cmake_minimum_required(VERSION 3.26)
project(BloomFilter)

set(CMAKE_CXX_STANDARD 17)


add_library(BloomLib STATIC
        "src/bloom/bloomfilter.cpp"
        "src/bloom/hasher.cpp"
)

target_include_directories(BloomLib PRIVATE "include/")


add_executable(TestSuite
        "test/main.cpp"
        "test/bloomfilter.cpp"
)

target_include_directories(TestSuite PRIVATE "include/")

target_link_libraries(TestSuite PRIVATE BloomLib)