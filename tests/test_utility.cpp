#include <catch2/catch_test_macros.hpp>
#include <nstd/utility.hpp>
#include <type_traits>

TEST_CASE("Move returns an rvalue reference to the same object") {
    int value = 42;
    auto&& moved = nstd::move(value);

    STATIC_REQUIRE(std::is_same_v<decltype(moved), int&&>);
    REQUIRE(&moved == &value);
}
