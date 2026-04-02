#include <array>
#include <cstdint>
#include <iostream>

namespace {

constexpr std::array<unsigned, 10> ones{0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
constexpr std::array<unsigned, 10> teens{3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
constexpr std::array<unsigned, 10> tens{0, 0, 6, 6, 5, 5, 5, 7, 6, 6};

constexpr unsigned letters_in_number(unsigned value) noexcept {
  if (value == 1000) {
    return 11;
  }

  unsigned total = 0;
  if (value >= 100) {
    total += ones[value / 100] + 7;
    if ((value % 100) != 0) {
      total += 3;
    }
    value %= 100;
  }

  if (value >= 20) {
    total += tens[value / 10];
    value %= 10;
  } else if (value >= 10) {
    total += teens[value - 10];
    value = 0;
  }

  if (value > 0) {
    total += ones[value];
  }

  return total;
}

} // namespace

int main() {
  std::uint64_t total = 0;
  for (unsigned value = 1; value <= 1000; ++value) {
    total += letters_in_number(value);
  }

  std::cout << total << '\n';
  return 0;
}
