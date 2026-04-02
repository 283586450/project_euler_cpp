#include <cstdint>
#include <algorithm>
#include <iostream>
#include <string>

namespace {

std::string add_big_integers(const std::string &lhs, const std::string &rhs) {
  std::string result;
  const std::size_t max_size = std::max(lhs.size(), rhs.size());
  result.reserve(max_size + 1);

  int carry = 0;
  for (std::size_t offset = 0; offset < max_size; ++offset) {
    int digit = carry;
    if (offset < lhs.size()) {
      digit += lhs[lhs.size() - 1 - offset] - '0';
    }
    if (offset < rhs.size()) {
      digit += rhs[rhs.size() - 1 - offset] - '0';
    }
    result.push_back(static_cast<char>('0' + (digit % 10)));
    carry = digit / 10;
  }
  while (carry > 0) {
    result.push_back(static_cast<char>('0' + (carry % 10)));
    carry /= 10;
  }

  std::reverse(result.begin(), result.end());
  return result;
}

std::uint32_t first_fibonacci_with_digits(std::size_t digits) {
  std::string previous = "1";
  std::string current = "1";
  std::uint32_t index = 2;

  while (current.size() < digits) {
    const std::string next = add_big_integers(previous, current);
    previous = current;
    current = next;
    ++index;
  }

  return index;
}

} // namespace

int main() {
  std::cout << first_fibonacci_with_digits(1000) << '\n';
  return 0;
}
