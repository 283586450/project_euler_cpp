#include <cstdint>
#include <iostream>

namespace {

std::uint64_t find_pythagorean_triplet_product(std::uint64_t sum) {
  for (std::uint64_t a = 1; a < sum / 3; ++a) {
    for (std::uint64_t b = a + 1; b < sum / 2; ++b) {
      const std::uint64_t c = sum - a - b;
      if ((a * a) + (b * b) == (c * c)) {
        return a * b * c;
      }
    }
  }

  return 0;
}

} // namespace

int main() {
  constexpr std::uint64_t sum = 1000;
  std::cout << find_pythagorean_triplet_product(sum) << '\n';
  return 0;
}
