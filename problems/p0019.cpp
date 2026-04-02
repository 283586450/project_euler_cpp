#include <array>
#include <cstdint>
#include <iostream>

namespace {

constexpr bool is_leap_year(int year) noexcept {
  return ((year % 4) == 0 && (year % 100) != 0) || ((year % 400) == 0);
}

constexpr std::array<int, 12> month_lengths_common{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

std::uint64_t count_sundays_on_first() noexcept {
  int weekday = 0; // Monday = 0 for January 1, 1900.
  std::uint64_t count = 0;

  for (int year = 1900; year <= 2000; ++year) {
    for (int month = 0; month < 12; ++month) {
      if (year >= 1901 && weekday == 6) {
        ++count;
      }

      int days = month_lengths_common[month];
      if (month == 1 && is_leap_year(year)) {
        ++days;
      }
      weekday = (weekday + days) % 7;
    }
  }

  return count;
}

} // namespace

int main() {
  std::cout << count_sundays_on_first() << '\n';
  return 0;
}
