#include <cstdint>
#include <iostream>

namespace {

[[nodiscard]] constexpr bool is_palindrome(std::uint32_t value) noexcept {
  std::uint32_t reversed = 0;
  std::uint32_t original = value;

  while (original > 0) {
    reversed = reversed * 10 + (original % 10);
    original /= 10;
  }

  return value == reversed;
}

} // namespace

int main() {
  std::uint32_t best = 0;

  for (std::uint32_t a = 999; a >= 100; --a) {
    if (a * 999 <= best) {
      break;
    }

    for (std::uint32_t b = a; b >= 100; --b) {
      const std::uint32_t product = a * b;
      if (product <= best) {
        break;
      }

      if (is_palindrome(product)) {
        best = product;
      }
    }
  }

  std::cout << best << '\n';
  return 0;
}
