#include <algorithm>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <string_view>
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

  std::string_view view(content);
  if (!view.empty() && view.front() == '"') {
    view.remove_prefix(1);
  }
  if (!view.empty() && view.back() == '"') {
    view.remove_suffix(1);
  }

  while (!view.empty()) {
    const std::size_t separator = view.find("\",\"");
    if (separator == std::string_view::npos) {
      names.emplace_back(view);
      break;
    }

    names.emplace_back(view.substr(0, separator));
    view.remove_prefix(separator + 3);
  }

  std::sort(names.begin(), names.end());

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
