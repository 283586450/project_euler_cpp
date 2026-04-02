#include <cstdint>
#include <iostream>
#include <vector>

namespace {

std::uint64_t sum_primes_below(std::size_t limit) {
  if (limit < 2) {
    return 0;
  }

  std::vector<char> is_prime(limit, 1);
  is_prime[0] = 0;
  is_prime[1] = 0;

  for (std::size_t prime = 2; prime <= limit / prime; ++prime) {
    if (!is_prime[prime]) {
      continue;
    }

    for (std::size_t multiple = prime * prime; multiple < limit; multiple += prime) {
      is_prime[multiple] = 0;
    }
  }

  std::uint64_t sum = 0;
  for (std::size_t value = 2; value < limit; ++value) {
    if (is_prime[value]) {
      sum += value;
    }
  }

  return sum;
}

} // namespace

int main() {
  constexpr std::size_t limit = 2'000'000;
  std::cout << sum_primes_below(limit) << '\n';
  return 0;
}
