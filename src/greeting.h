#pragma once

#include <string>
#include <string_view>

namespace greeting {

// C++20 constexpr string operations
[[nodiscard]] constexpr std::string_view get_greeting() noexcept {
    return "Hello from C++20 with Bazel bzlmod!";
}

// C++20 concepts example
template <typename T>
concept Printable = requires(T t) {
    { std::to_string(t) } -> std::convertible_to<std::string>;
};

template <Printable T>
std::string format_value(T value) {
    return "Value: " + std::to_string(value);
}

}  // namespace greeting
