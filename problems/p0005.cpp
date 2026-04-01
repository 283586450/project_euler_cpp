#include <cstdint>
#include <iostream>

namespace {

constexpr std::uint64_t gcd(std::uint64_t lhs, std::uint64_t rhs) noexcept {
  while (rhs != 0) {
    const std::uint64_t remainder = lhs % rhs;
    lhs = rhs;
    rhs = remainder;
  }
  return lhs;
}

constexpr std::uint64_t lcm(std::uint64_t lhs, std::uint64_t rhs) noexcept {
  return (lhs / gcd(lhs, rhs)) * rhs;
}

}  // namespace

int main() {
  std::uint64_t result = 1;
  for (std::uint64_t value = 2; value <= 20; ++value) {
    result = lcm(result, value);
  }

  std::cout << result << '\n';
  return 0;
}
