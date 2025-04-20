// src/sia.cpp
#include "sia/sia.hpp"
#include "sia/sia_impl.hpp"
#include <memory>

namespace sia {

class SiaImpl : public Sia, public std::enable_shared_from_this<SiaImpl> {
public:
  std::vector<uint8_t> content;
  uint64_t index = 0;

  std::shared_ptr<Sia> Seek(uint64_t idx) override {
    index = idx;
    return shared_from_this();
  }

  std::vector<uint8_t> Bytes() const override { return content; }

  uint64_t Offset() const override { return index; }

  std::shared_ptr<Sia> EmbedSia(const std::shared_ptr<Sia> &other) override {
    auto otherBytes = other->Bytes();
    content.insert(content.end(), otherBytes.begin(), otherBytes.end());
    return shared_from_this();
  }

  std::shared_ptr<Sia> EmbedBytes(const std::vector<uint8_t> &bytes) override {
    content.insert(content.end(), bytes.begin(), bytes.end());
    return shared_from_this();
  }

  // Method stubs; full implementation in their respective files
  std::shared_ptr<Sia> AddUInt8(uint8_t n) override;
  uint8_t ReadUInt8() override;
  std::shared_ptr<Sia> AddUInt16(uint16_t n) override;
  uint16_t ReadUInt16() override;
  std::shared_ptr<Sia> AddUInt32(uint32_t n) override;
  uint32_t ReadUInt32() override;
  std::shared_ptr<Sia> AddUInt64(uint64_t n) override;
  uint64_t ReadUInt64() override;

  std::shared_ptr<Sia> AddInt8(int8_t n) override;
  int8_t ReadInt8() override;
  std::shared_ptr<Sia> AddInt16(int16_t n) override;
  int16_t ReadInt16() override;
  std::shared_ptr<Sia> AddInt32(int32_t n) override;
  int32_t ReadInt32() override;
  std::shared_ptr<Sia> AddInt64(int64_t n) override;
  int64_t ReadInt64() override;

  std::shared_ptr<Sia> AddBool(bool b) override;
  bool ReadBool() override;

  std::shared_ptr<Sia> AddStringN(const std::string &str) override;
  std::string ReadStringN(uint64_t length) override;
  std::shared_ptr<Sia> AddString8(const std::string &str) override;
  std::string ReadString8() override;
  std::shared_ptr<Sia> AddString16(const std::string &str) override;
  std::string ReadString16() override;
  std::shared_ptr<Sia> AddString32(const std::string &str) override;
  std::string ReadString32() override;
  std::shared_ptr<Sia> AddString64(const std::string &str) override;
  std::string ReadString64() override;

  std::shared_ptr<Sia>
  AddByteArrayN(const std::vector<uint8_t> &bytes) override;
  std::vector<uint8_t> ReadByteArrayN(uint64_t length) override;
  std::shared_ptr<Sia>
  AddByteArray8(const std::vector<uint8_t> &bytes) override;
  std::vector<uint8_t> ReadByteArray8() override;
  std::shared_ptr<Sia>
  AddByteArray16(const std::vector<uint8_t> &bytes) override;
  std::vector<uint8_t> ReadByteArray16() override;
  std::shared_ptr<Sia>
  AddByteArray32(const std::vector<uint8_t> &bytes) override;
  std::vector<uint8_t> ReadByteArray32() override;
  std::shared_ptr<Sia>
  AddByteArray64(const std::vector<uint8_t> &bytes) override;
  std::vector<uint8_t> ReadByteArray64() override;
};

std::shared_ptr<Sia> New() { return std::make_shared<SiaImpl>(); }

std::shared_ptr<Sia> NewFromBytes(const std::vector<uint8_t> &content) {
  auto s = std::make_shared<SiaImpl>();
  s->content = content;
  return s;
}

} // namespace sia
