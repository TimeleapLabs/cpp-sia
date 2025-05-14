#include "sia/sia.hpp"
#include "sia/sia_impl.hpp"
#include <memory>

namespace sia {

std::shared_ptr<Sia> New() { return std::make_shared<SiaImpl>(); }

std::shared_ptr<Sia> NewFromBytes(const std::vector<uint8_t> &content) {
  auto s = std::make_shared<SiaImpl>();
  s->content = content;
  return s;
}

} // namespace sia
