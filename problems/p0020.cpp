#include <cstdint>
#include <iostream>
#include <vector>

namespace {

std::uint64_t factorial_digit_sum(unsigned value) {
  std::vector<unsigned> digits{1};

  for (unsigned factor = 2; factor <= value; ++factor) {
    unsigned carry = 0;
    for (unsigned &digit : digits) {
      const unsigned product = (digit * factor) + carry;
      digit = product % 10U;
      carry = product / 10U;
    }
    while (carry > 0) {
      digits.push_back(carry % 10U);
      carry /= 10U;
    }
  }

  std::uint64_t sum = 0;
  for (const unsigned digit : digits) {
    sum += digit;
  }
  return sum;
}

} // namespace

int main() {
  std::cout << factorial_digit_sum(100) << '\n';
  return 0;
}
