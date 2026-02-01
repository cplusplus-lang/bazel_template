#include <iostream>
#include <format>
#include <ranges>
#include <vector>

#include "greeting.h"

int main() {
    // C++20 string_view
    std::cout << greeting::get_greeting() << '\n';

    // C++20 concepts
    std::cout << greeting::format_value(42) << '\n';
    std::cout << greeting::format_value(3.14159) << '\n';

    // C++20 ranges
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "Even numbers doubled: ";
    for (auto n : numbers 
                  | std::views::filter([](int n) { return n % 2 == 0; })
                  | std::views::transform([](int n) { return n * 2; })) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    // C++20 std::format (if available)
#if __cpp_lib_format >= 201907L
    std::cout << std::format("Formatted output: {} + {} = {}\n", 2, 3, 5);
#else
    std::cout << "std::format not available on this compiler\n";
#endif

    return 0;
}
