#include <cstdint>
#include <iostream>

int main() {
  constexpr std::uint64_t limit = 4'000'000;

  std::uint64_t sum = 0;
  std::uint64_t previous = 0;
  std::uint64_t current = 2;

  while (current <= limit) {
    sum += current;

    const std::uint64_t next = 4 * current + previous;
    previous = current;
    current = next;
  }

  std::cout << sum << '\n';
  return 0;
}
