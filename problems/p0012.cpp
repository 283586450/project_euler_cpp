#include <cstdint>
#include <iostream>

namespace {

std::uint32_t divisor_count(std::uint64_t value) noexcept {
  std::uint32_t count = 1;

  for (std::uint64_t factor = 2; factor <= value / factor; ++factor) {
    if ((value % factor) != 0) {
      continue;
    }

    std::uint32_t exponent = 0;
    do {
      value /= factor;
      ++exponent;
    } while ((value % factor) == 0);

    count *= exponent + 1;
  }

  if (value > 1) {
    count *= 2;
  }

  return count;
}

std::uint64_t first_triangle_number_with_over_500_divisors() noexcept {
  for (std::uint64_t n = 1; ; ++n) {
    const std::uint64_t triangle = (n * (n + 1)) / 2;
    const std::uint32_t divisors = (n % 2 == 0) ? divisor_count(n / 2) * divisor_count(n + 1)
                                                : divisor_count(n) * divisor_count((n + 1) / 2);
    if (divisors > 500) {
      return triangle;
    }
  }
}

} // namespace

int main() {
  std::cout << first_triangle_number_with_over_500_divisors() << '\n';
  return 0;
}
