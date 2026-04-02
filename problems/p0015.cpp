#include <algorithm>
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

constexpr std::uint64_t binomial(std::uint64_t n, std::uint64_t k) noexcept {
  k = std::min(k, n - k);

  std::uint64_t result = 1;
  for (std::uint64_t i = 1; i <= k; ++i) {
    std::uint64_t numerator = n - k + i;
    std::uint64_t denominator = i;

    const std::uint64_t first = gcd(numerator, denominator);
    numerator /= first;
    denominator /= first;

    const std::uint64_t second = gcd(result, denominator);
    result /= second;

    result *= numerator;
  }

  return result;
}

} // namespace

int main() {
  std::cout << binomial(40, 20) << '\n';
  return 0;
}
