#include <cstdint>
#include <iostream>

namespace {

constexpr std::uint64_t sum_of_multiples_below(std::uint64_t limit, std::uint64_t factor) {
  const std::uint64_t count = (limit - 1) / factor;
  return factor * count * (count + 1) / 2;
}

}  // namespace

int main() {
  constexpr std::uint64_t limit = 1000;
  const std::uint64_t answer = sum_of_multiples_below(limit, 3) + sum_of_multiples_below(limit, 5)
                               - sum_of_multiples_below(limit, 15);

  std::cout << answer << '\n';
  return 0;
}
