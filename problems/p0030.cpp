#include <array>
#include <cstdint>
#include <iostream>

namespace {

std::uint32_t digit_fifth_powers_sum() noexcept {
  constexpr std::array<std::uint32_t, 10> powers{
      0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049,
  };

  std::uint32_t total = 0;
  for (std::uint32_t value = 2; value <= 354294; ++value) {
    std::uint32_t sum = 0;
    std::uint32_t remaining = value;
    while (remaining > 0) {
      sum += powers[remaining % 10];
      remaining /= 10;
    }
    if (sum == value) {
      total += value;
    }
  }

  return total;
}

} // namespace

int main() {
  std::cout << digit_fifth_powers_sum() << '\n';
  return 0;
}
