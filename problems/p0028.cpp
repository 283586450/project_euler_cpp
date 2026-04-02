#include <cstdint>
#include <iostream>

namespace {

std::uint64_t spiral_diagonal_sum(std::uint32_t size) noexcept {
  std::uint64_t total = 1;
  for (std::uint32_t layer = 1; layer <= (size - 1) / 2; ++layer) {
    const std::uint64_t side = (2U * layer) + 1U;
    total += 4 * side * side - 6 * (side - 1);
  }
  return total;
}

} // namespace

int main() {
  std::cout << spiral_diagonal_sum(1001) << '\n';
  return 0;
}
