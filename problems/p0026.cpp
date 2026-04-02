#include <cstdint>
#include <iostream>
#include <vector>

namespace {

std::uint32_t recurring_cycle_length(std::uint32_t denominator) noexcept {
  std::vector<int> seen(denominator, -1);
  std::uint32_t remainder = 1 % denominator;
  std::uint32_t position = 0;

  while (remainder != 0 && seen[remainder] == -1) {
    seen[remainder] = static_cast<int>(position);
    remainder = static_cast<std::uint32_t>((remainder * 10U) % denominator);
    ++position;
  }

  return (remainder == 0) ? 0U : static_cast<std::uint32_t>(position - seen[remainder]);
}

std::uint32_t longest_reciprocal_cycle(std::uint32_t limit) noexcept {
  std::uint32_t best_denominator = 0;
  std::uint32_t best_length = 0;

  for (std::uint32_t denominator = 1; denominator < limit; ++denominator) {
    const std::uint32_t length = recurring_cycle_length(denominator);
    if (length > best_length) {
      best_length = length;
      best_denominator = denominator;
    }
  }

  return best_denominator;
}

} // namespace

int main() {
  std::cout << longest_reciprocal_cycle(1000) << '\n';
  return 0;
}
