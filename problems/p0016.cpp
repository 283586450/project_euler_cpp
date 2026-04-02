#include <cstdint>
#include <iostream>
#include <vector>

namespace {

std::uint64_t sum_digits_of_power_of_two(unsigned exponent) {
  std::vector<unsigned> digits{1};

  for (unsigned step = 0; step < exponent; ++step) {
    unsigned carry = 0;
    for (unsigned &digit : digits) {
      const unsigned value = (digit * 2U) + carry;
      digit = value % 10U;
      carry = value / 10U;
    }
    if (carry > 0) {
      digits.push_back(carry);
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
  std::cout << sum_digits_of_power_of_two(1000) << '\n';
  return 0;
}
