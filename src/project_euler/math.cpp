#include "project_euler/math.hpp"

namespace project_euler::math {

unsigned digit_count(std::uint64_t value) noexcept {
  unsigned count = 1;
  while (value >= 10) {
    value /= 10;
    ++count;
  }
  return count;
}

std::uint64_t digit_sum(std::uint64_t value) noexcept {
  std::uint64_t sum = 0;
  while (value > 0) {
    sum += value % 10;
    value /= 10;
  }
  return sum;
}

}  // namespace project_euler::math

