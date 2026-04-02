#pragma once

#include <cstdint>

namespace project_euler::math {

[[nodiscard]] constexpr bool is_even(std::int64_t value) noexcept {
  return (value % 2) == 0;
}

[[nodiscard]] unsigned digit_count(std::uint64_t value) noexcept;

[[nodiscard]] std::uint64_t digit_sum(std::uint64_t value) noexcept;

} // namespace project_euler::math
