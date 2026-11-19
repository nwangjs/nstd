#include <catch2/catch_test_macros.hpp>
#include <nstd/type_traits.hpp>
#include <type_traits>

TEST_CASE("Remove_reference strips references and preserves const") {
    STATIC_REQUIRE(std::is_same_v<nstd::remove_reference_t<int>, int>);

    STATIC_REQUIRE(std::is_same_v<nstd::remove_reference_t<int&>, int>);

    STATIC_REQUIRE(std::is_same_v<nstd::remove_reference_t<int&&>, int>);

    STATIC_REQUIRE(
        std::is_same_v<nstd::remove_reference_t<const int&>, const int>);

    STATIC_REQUIRE(
        std::is_same_v<nstd::remove_reference_t<const int&&>, const int>);
}
