#include <cstdint>
#include <iostream>

namespace {

constexpr std::uint64_t sum_of_squares(std::uint64_t value) noexcept {
  return value * (value + 1) * (2 * value + 1) / 6;
}

constexpr std::uint64_t square_of_sum(std::uint64_t value) noexcept {
  const std::uint64_t sum = value * (value + 1) / 2;
  return sum * sum;
}

} // namespace

int main() {
  constexpr std::uint64_t limit = 100;
  const std::uint64_t answer = square_of_sum(limit) - sum_of_squares(limit);

  std::cout << answer << '\n';
  return 0;
}
