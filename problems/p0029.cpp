#include <array>
#include <cstdint>
#include <iostream>
#include <set>
#include <string>
#include <vector>

namespace {

std::vector<std::uint32_t> primes_up_to(std::uint32_t limit) {
  std::vector<char> sieve(limit + 1, 1);
  sieve[0] = 0;
  sieve[1] = 0;

  for (std::uint32_t prime = 2; prime <= limit / prime; ++prime) {
    if (sieve[prime] == 0) {
      continue;
    }
    for (std::uint32_t multiple = prime * prime; multiple <= limit; multiple += prime) {
      sieve[multiple] = 0;
    }
  }

  std::vector<std::uint32_t> primes;
  for (std::uint32_t value = 2; value <= limit; ++value) {
    if (sieve[value] != 0) {
      primes.push_back(value);
    }
  }
  return primes;
}

std::array<std::uint32_t, 25> factor_signature(std::uint32_t base,
                                               const std::vector<std::uint32_t> &primes) {
  std::array<std::uint32_t, 25> exponents{};
  for (std::size_t index = 0; index < primes.size(); ++index) {
    const std::uint32_t prime = primes[index];
    while ((base % prime) == 0) {
      ++exponents[index];
      base /= prime;
    }
  }
  return exponents;
}

std::string signature_key(const std::array<std::uint32_t, 25> &exponents, std::uint32_t power) {
  std::string key;
  for (const std::uint32_t exponent : exponents) {
    key.append(std::to_string(exponent * power));
    key.push_back('#');
  }
  return key;
}

std::uint32_t distinct_powers_count() {
  const std::vector<std::uint32_t> primes = primes_up_to(100);
  std::set<std::string> values;

  for (std::uint32_t base = 2; base <= 100; ++base) {
    const std::array<std::uint32_t, 25> signature = factor_signature(base, primes);
    for (std::uint32_t exponent = 2; exponent <= 100; ++exponent) {
      values.insert(signature_key(signature, exponent));
    }
  }

  return static_cast<std::uint32_t>(values.size());
}

} // namespace

int main() {
  std::cout << distinct_powers_count() << '\n';
  return 0;
}
