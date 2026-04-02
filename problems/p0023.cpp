#include <cstdint>
#include <iostream>
#include <vector>

namespace {

std::uint32_t sum_proper_divisors(std::uint32_t value) noexcept {
  if (value <= 1) {
    return 0;
  }

  std::uint32_t sum = 1;
  for (std::uint32_t factor = 2; factor <= value / factor; ++factor) {
    if ((value % factor) != 0) {
      continue;
    }

    sum += factor;
    const std::uint32_t pair = value / factor;
    if (pair != factor) {
      sum += pair;
    }
  }

  return sum;
}

std::uint64_t non_abundant_sums(std::uint32_t limit) noexcept {
  std::vector<std::uint32_t> abundant_numbers;
  for (std::uint32_t value = 12; value <= limit; ++value) {
    if (sum_proper_divisors(value) > value) {
      abundant_numbers.push_back(value);
    }
  }

  std::vector<char> can_be_written(limit + 1, 0);
  for (std::size_t i = 0; i < abundant_numbers.size(); ++i) {
    for (std::size_t j = i; j < abundant_numbers.size(); ++j) {
      const std::uint32_t sum = abundant_numbers[i] + abundant_numbers[j];
      if (sum > limit) {
        break;
      }
      can_be_written[sum] = 1;
    }
  }

  std::uint64_t total = 0;
  for (std::uint32_t value = 1; value <= limit; ++value) {
    if (!can_be_written[value]) {
      total += value;
    }
  }

  return total;
}

} // namespace

int main() {
  std::cout << non_abundant_sums(28123) << '\n';
  return 0;
}
