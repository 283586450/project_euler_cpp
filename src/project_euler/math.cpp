#include "project_euler/math.hpp"

namespace project_euler::math {

unsigned digit_count(std::uint64_t value) noexcept {
  unsigned count = 1;
  for (; value >= 10; value /= 10) {
    ++count;
  }
  return count;
}

std::uint64_t digit_sum(std::uint64_t value) noexcept {
  std::uint64_t sum = 0;
  do {
    sum += value % 10;
    value /= 10;
  } while (value > 0);
  return sum;
}

} // namespace project_euler::math
