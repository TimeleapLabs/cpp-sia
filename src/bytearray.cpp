#include "sia/sia_impl.hpp"

namespace sia {

std::shared_ptr<Sia> SiaImpl::AddByteArrayN(const std::vector<uint8_t>& bytes) {
  content.insert(content.end(), bytes.begin(), bytes.end());
  return shared_from_this();
}

std::vector<uint8_t> SiaImpl::ReadByteArrayN(uint64_t length) {
  if (index + length > content.size())
    return {};
  std::vector<uint8_t> out(content.begin() + index,
                           content.begin() + index + length);
  index += length;
  return out;
}

std::shared_ptr<Sia> SiaImpl::AddByteArray8(const std::vector<uint8_t>& bytes) {
  AddUInt8(static_cast<uint8_t>(bytes.size()));
  return AddByteArrayN(bytes);
}

std::vector<uint8_t> SiaImpl::ReadByteArray8() {
  return ReadByteArrayN(ReadUInt8());
}

std::shared_ptr<Sia> SiaImpl::AddByteArray16(
    const std::vector<uint8_t>& bytes) {
  AddUInt16(static_cast<uint16_t>(bytes.size()));
  return AddByteArrayN(bytes);
}

std::vector<uint8_t> SiaImpl::ReadByteArray16() {
  return ReadByteArrayN(ReadUInt16());
}

std::shared_ptr<Sia> SiaImpl::AddByteArray32(
    const std::vector<uint8_t>& bytes) {
  AddUInt32(static_cast<uint32_t>(bytes.size()));
  return AddByteArrayN(bytes);
}

std::vector<uint8_t> SiaImpl::ReadByteArray32() {
  return ReadByteArrayN(ReadUInt32());
}

std::shared_ptr<Sia> SiaImpl::AddByteArray64(
    const std::vector<uint8_t>& bytes) {
  AddUInt64(static_cast<uint64_t>(bytes.size()));
  return AddByteArrayN(bytes);
}

std::vector<uint8_t> SiaImpl::ReadByteArray64() {
  return ReadByteArrayN(ReadUInt64());
}

}  // namespace sia