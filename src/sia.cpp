#include "sia/sia.hpp"
#include <memory>
#include "sia/sia_impl.hpp"

namespace sia {

std::shared_ptr<Sia> New() {
  return std::make_shared<SiaImpl>();
}

std::shared_ptr<Sia> NewFromBytes(const std::vector<uint8_t>& content) {
  auto s = std::make_shared<SiaImpl>();
  s->content = content;
  return s;
}

std::shared_ptr<Sia> SiaImpl::Seek(uint64_t idx) {
  this->index = idx;
  return shared_from_this();
}

std::vector<uint8_t> SiaImpl::Bytes() const {
  return content;
}

uint64_t SiaImpl::Offset() const {
  return index;
}

std::shared_ptr<Sia> SiaImpl::EmbedSia(const std::shared_ptr<Sia>& other) {
  auto bytes = other->Bytes();
  content.insert(content.end(), bytes.begin(), bytes.end());
  return shared_from_this();
}

std::shared_ptr<Sia> SiaImpl::EmbedBytes(const std::vector<uint8_t>& bytes) {
  content.insert(content.end(), bytes.begin(), bytes.end());
  return shared_from_this();
}

}  // namespace sia
