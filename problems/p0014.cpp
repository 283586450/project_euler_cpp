#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

namespace {

std::uint32_t collatz_length(std::uint64_t start, std::vector<std::uint32_t> &cache) {
  std::vector<std::uint64_t> path;
  std::uint64_t value = start;

  while (value >= cache.size() || cache[static_cast<std::size_t>(value)] == 0) {
    path.push_back(value);
    value = ((value % 2) == 0) ? (value / 2) : ((3 * value) + 1);
  }

  std::uint32_t length = cache[static_cast<std::size_t>(value)];
  while (!path.empty()) {
    ++length;
    const std::uint64_t current = path.back();
    path.pop_back();

    if (current < cache.size()) {
      cache[static_cast<std::size_t>(current)] = length;
    }
  }

  return length;
}

std::uint64_t longest_collatz_start(std::uint64_t limit) {
  std::vector<std::uint32_t> cache(static_cast<std::size_t>(limit) + 1, 0);
  cache[1] = 1;

  std::uint64_t best_start = 1;
  std::uint32_t best_length = 1;

  for (std::uint64_t start = 2; start < limit; ++start) {
    const std::uint32_t length = collatz_length(start, cache);
    if (length > best_length) {
      best_length = length;
      best_start = start;
    }
  }

  return best_start;
}

} // namespace

int main() {
  constexpr std::uint64_t limit = 1'000'000;
  std::cout << longest_collatz_start(limit) << '\n';
  return 0;
}
