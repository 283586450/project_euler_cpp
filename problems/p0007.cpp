#include <cstdint>
#include <iostream>
#include <vector>

namespace {

std::uint32_t nth_prime(std::size_t index) {
  std::vector<std::uint32_t> primes;
  primes.reserve(index);
  primes.push_back(2);

  for (std::uint32_t candidate = 3; primes.size() < index; candidate += 2) {
    bool is_prime = true;
    for (const std::uint32_t prime : primes) {
      if (prime > candidate / prime) {
        break;
      }
      if ((candidate % prime) == 0) {
        is_prime = false;
        break;
      }
    }

    if (is_prime) {
      primes.push_back(candidate);
    }
  }

  return primes.back();
}

} // namespace

int main() {
  constexpr std::size_t target = 10001;
  std::cout << nth_prime(target) << '\n';
  return 0;
}
