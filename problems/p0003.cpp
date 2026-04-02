#include <cstdint>
#include <iostream>

namespace {

std::uint64_t largest_prime_factor(std::uint64_t value) {
  std::uint64_t largest = 1;

  while ((value % 2) == 0) {
    largest = 2;
    value /= 2;
  }

  for (std::uint64_t factor = 3; factor <= value / factor; factor += 2) {
    while ((value % factor) == 0) {
      largest = factor;
      value /= factor;
    }
  }

  if (value > 1) {
    largest = value;
  }

  return largest;
}

} // namespace

int main() {
  constexpr std::uint64_t target = 600851475143ULL;
  std::cout << largest_prime_factor(target) << '\n';
  return 0;
}
