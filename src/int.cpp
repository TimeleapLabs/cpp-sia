#include "sia/sia_impl.hpp"
#include <cstdint>

namespace sia {

std::shared_ptr<Sia> SiaImpl::AddInt8(int8_t n) {
  content.push_back(static_cast<uint8_t>(n));
  return shared_from_this();
}

int8_t SiaImpl::ReadInt8() {
  if (index + 1 > content.size())
    return 0;
  return static_cast<int8_t>(content[index++]);
}

std::shared_ptr<Sia> SiaImpl::AddInt16(int16_t n) {
  return AddUInt16(static_cast<uint16_t>(n));
}

int16_t SiaImpl::ReadInt16() { return static_cast<int16_t>(ReadUInt16()); }

std::shared_ptr<Sia> SiaImpl::AddInt32(int32_t n) {
  return AddUInt32(static_cast<uint32_t>(n));
}

int32_t SiaImpl::ReadInt32() { return static_cast<int32_t>(ReadUInt32()); }

std::shared_ptr<Sia> SiaImpl::AddInt64(int64_t n) {
  return AddUInt64(static_cast<uint64_t>(n));
}

int64_t SiaImpl::ReadInt64() { return static_cast<int64_t>(ReadUInt64()); }

} // namespace sia