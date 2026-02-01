#include <catch2/catch_test_macros.hpp>

#include "src/greeting.h"

TEST_CASE("GetGreeting returns non-empty string with C++20", "[greeting]") {
    constexpr auto greet = greeting::get_greeting();
    REQUIRE_FALSE(greet.empty());
    REQUIRE(greet.find("C++20") != std::string_view::npos);
}

TEST_CASE("FormatValue formats integer correctly", "[greeting]") {
    auto result = greeting::format_value(42);
    REQUIRE(result == "Value: 42");
}

TEST_CASE("FormatValue formats double correctly", "[greeting]") {
    auto result = greeting::format_value(3.5);
    REQUIRE(result == "Value: 3.500000");
}

// C++20 compile-time test
static_assert(!greeting::get_greeting().empty(), "Greeting should not be empty");
