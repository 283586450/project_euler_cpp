#include <cstdint>
#include <iostream>

#include "project_euler/math.hpp"

namespace {

bool check(bool condition, const char* message) {
  if (!condition) {
    std::cerr << message << '\n';
    return false;
  }
  return true;
}

}  // namespace

int main() {
  using project_euler::math::digit_count;
  using project_euler::math::digit_sum;
  using project_euler::math::is_even;

  bool ok = true;
  ok &= check(is_even(0), "0 should be even");
  ok &= check(is_even(42), "42 should be even");
  ok &= check(!is_even(7), "7 should be odd");
  ok &= check(digit_count(0) == 1, "digit_count(0) should be 1");
  ok &= check(digit_count(7) == 1, "digit_count(7) should be 1");
  ok &= check(digit_count(42) == 2, "digit_count(42) should be 2");
  ok &= check(digit_count(1000) == 4, "digit_count(1000) should be 4");
  ok &= check(digit_sum(0) == 0, "digit_sum(0) should be 0");
  ok &= check(digit_sum(12345) == 15, "digit_sum(12345) should be 15");

  return ok ? 0 : 1;
}

