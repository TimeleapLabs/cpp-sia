#include "sia/sia_impl.hpp"

namespace sia {

std::shared_ptr<Sia> SiaImpl::AddStringN(const std::string &str) {
  content.insert(content.end(), str.begin(), str.end());
  return shared_from_this();
}

std::string SiaImpl::ReadStringN(uint64_t length) {
  if (index + length > content.size())
    return "";
  std::string str(content.begin() + index, content.begin() + index + length);
  index += length;
  return str;
}

std::shared_ptr<Sia> SiaImpl::AddString8(const std::string &str) {
  AddUInt8(static_cast<uint8_t>(str.size()));
  content.insert(content.end(), str.begin(), str.end());
  return shared_from_this();
}

std::string SiaImpl::ReadString8() {
  uint8_t len = ReadUInt8();
  return ReadStringN(len);
}

std::shared_ptr<Sia> SiaImpl::AddString16(const std::string &str) {
  AddUInt16(static_cast<uint16_t>(str.size()));
  content.insert(content.end(), str.begin(), str.end());
  return shared_from_this();
}

std::string SiaImpl::ReadString16() {
  uint16_t len = ReadUInt16();
  return ReadStringN(len);
}

std::shared_ptr<Sia> SiaImpl::AddString32(const std::string &str) {
  AddUInt32(static_cast<uint32_t>(str.size()));
  content.insert(content.end(), str.begin(), str.end());
  return shared_from_this();
}

std::string SiaImpl::ReadString32() {
  uint32_t len = ReadUInt32();
  return ReadStringN(len);
}

std::shared_ptr<Sia> SiaImpl::AddString64(const std::string &str) {
  AddUInt64(static_cast<uint64_t>(str.size()));
  content.insert(content.end(), str.begin(), str.end());
  return shared_from_this();
}

std::string SiaImpl::ReadString64() {
  uint64_t len = ReadUInt64();
  return ReadStringN(len);
}

} // namespace sia