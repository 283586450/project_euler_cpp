#include <algorithm>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

std::uint64_t name_scores_sum() {
  const std::filesystem::path file_path = std::filesystem::path(PROJECT_EULER_0022_NAMES_FILE);
  std::ifstream file(file_path);
  if (!file) {
    throw std::runtime_error("failed to open problem 22 names file");
  }

  const std::string content{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
  std::vector<std::string> names;

  std::string current;
  bool in_name = false;
  for (const char ch : content) {
    if (ch == '"') {
      if (in_name) {
        names.push_back(current);
        current.clear();
      }
      in_name = !in_name;
      continue;
    }

    if (in_name) {
      current.push_back(ch);
    }
  }

  std::ranges::sort(names);

  std::uint64_t total = 0;
  for (std::size_t index = 0; index < names.size(); ++index) {
    std::uint64_t value = 0;
    for (const char ch : names[index]) {
      value += static_cast<std::uint64_t>(ch - 'A' + 1);
    }
    total += static_cast<std::uint64_t>(index + 1) * value;
  }

  return total;
}

} // namespace

int main() {
  try {
    std::cout << name_scores_sum() << '\n';
  } catch (const std::exception &ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }
  return 0;
}
