#include <cstdint>
#include <iostream>
#include <vector>

namespace {

std::vector<std::uint32_t> primes_up_to(std::uint32_t limit) {
  std::vector<char> sieve(limit + 1, 1);
  sieve[0] = 0;
  sieve[1] = 0;

  for (std::uint32_t prime = 2; prime <= limit / prime; ++prime) {
    if (!sieve[prime]) {
      continue;
    }

    for (std::uint32_t multiple = prime * prime; multiple <= limit; multiple += prime) {
      sieve[multiple] = 0;
    }
  }

  std::vector<std::uint32_t> primes;
  for (std::uint32_t value = 2; value <= limit; ++value) {
    if (sieve[value]) {
      primes.push_back(value);
    }
  }
  return primes;
}

bool is_prime(std::int64_t value, const std::vector<std::uint32_t> &primes) {
  if (value < 2) {
    return false;
  }

  for (const std::uint32_t prime : primes) {
    const std::int64_t prime_sq = static_cast<std::int64_t>(prime) * prime;
    if (prime_sq > value) {
      break;
    }
    if ((value % prime) == 0) {
      return value == static_cast<std::int64_t>(prime);
    }
  }

  return true;
}

std::int32_t best_quadratic_primes_product() {
  const std::vector<std::uint32_t> primes = primes_up_to(2000);
  std::int32_t best_product = 0;
  std::int32_t best_length = 0;

  for (std::int32_t b = 2; b < 1000; ++b) {
    if (!is_prime(b, primes)) {
      continue;
    }

    for (std::int32_t a = -999; a < 1000; ++a) {
      std::int32_t length = 0;
      for (;; ++length) {
        const std::int64_t value = static_cast<std::int64_t>(length) * length +
                                   static_cast<std::int64_t>(a) * length + b;
        if (!is_prime(value, primes)) {
          break;
        }
      }

      const std::int32_t product = a * b;
      if (length > best_length || (length == best_length && product > best_product)) {
        best_length = length;
        best_product = product;
      }
    }
  }

  return best_product;
}

} // namespace

int main() {
  std::cout << best_quadratic_primes_product() << '\n';
  return 0;
}
