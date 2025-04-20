#include "sia/sia_impl.hpp"
#include <cstddef>
#include <cstdint>

namespace sia {

std::shared_ptr<Sia> SiaImpl::AddUInt8(uint8_t n) {
  content.push_back(n);
  return shared_from_this();
}

uint8_t SiaImpl::ReadUInt8() {
  if (index + 1 > content.size())
    return 0;
  return content[index++];
}

std::shared_ptr<Sia> SiaImpl::AddUInt16(uint16_t n) {
  content.push_back(n & 0xFF);
  content.push_back((n >> 8) & 0xFF);
  return shared_from_this();
}

uint16_t SiaImpl::ReadUInt16() {
  if (index + 2 > content.size())
    return 0;
  uint16_t n = content[index] | (content[index + 1] << 8);
  index += 2;
  return n;
}

std::shared_ptr<Sia> SiaImpl::AddUInt32(uint32_t n) {
  for (int i = 0; i < 4; ++i)
    content.push_back((n >> (i * 8)) & 0xFF);
  return shared_from_this();
}

uint32_t SiaImpl::ReadUInt32() {
  if (index + 4 > content.size())
    return 0;
  uint32_t n = 0;
  for (int i = 0; i < 4; ++i)
    n |= (static_cast<uint32_t>(content[index++]) << (i * 8));
  return n;
}

std::shared_ptr<Sia> SiaImpl::AddUInt64(uint64_t n) {
  for (int i = 0; i < 8; ++i)
    content.push_back((n >> (i * 8)) & 0xFF);
  return shared_from_this();
}

uint64_t SiaImpl::ReadUInt64() {
  if (index + 8 > content.size())
    return 0;
  uint64_t n = 0;
  for (int i = 0; i < 8; ++i)
    n |= (static_cast<uint64_t>(content[index++]) << (i * 8));
  return n;
}

} // namespace sia
