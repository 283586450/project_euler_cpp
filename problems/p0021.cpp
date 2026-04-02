#include <cstdint>
#include <iostream>

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

std::uint64_t amicable_numbers_sum(std::uint32_t limit) noexcept {
  std::uint64_t total = 0;
  for (std::uint32_t value = 2; value < limit; ++value) {
    const std::uint32_t partner = sum_proper_divisors(value);
    if (partner != value && partner < limit && sum_proper_divisors(partner) == value) {
      total += value;
    }
  }

  return total;
}

} // namespace

int main() {
  std::cout << amicable_numbers_sum(10000) << '\n';
  return 0;
}
