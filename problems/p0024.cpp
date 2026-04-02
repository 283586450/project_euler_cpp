#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

namespace {

std::uint64_t millionth_lexicographic_permutation() {
  std::vector<unsigned> digits{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  constexpr std::array<std::uint64_t, 10> factorials{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
  std::uint64_t index = 1'000'000 - 1;
  std::uint64_t answer = 0;

  for (std::size_t remaining = digits.size(); remaining > 0; --remaining) {
    const std::uint64_t block = factorials[remaining - 1];
    const std::size_t pick = static_cast<std::size_t>(index / block);
    index %= block;
    answer = (answer * 10) + digits[pick];
    digits.erase(digits.begin() + static_cast<std::ptrdiff_t>(pick));
  }

  return answer;
}

} // namespace

int main() {
  std::cout << millionth_lexicographic_permutation() << '\n';
  return 0;
}
