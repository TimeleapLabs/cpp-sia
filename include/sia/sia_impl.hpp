#pragma once
#include <memory>
#include "sia.hpp"

#ifdef SIA_USE_BOOST
#include <boost/multiprecision/cpp_int.hpp>
#endif

#ifdef SIA_USE_BOOST
using BigInt = boost::multiprecision::cpp_int;
#else
using BigInt = std::vector<uint8_t>;  // Fallback placeholder
#endif

namespace sia {

class SiaImpl : public Sia, public std::enable_shared_from_this<SiaImpl> {
 public:
  std::vector<uint8_t> content;
  uint64_t index = 0;

  std::shared_ptr<Sia> Seek(uint64_t idx) override;
  std::vector<uint8_t> Bytes() const override;
  uint64_t Offset() const override;
  std::shared_ptr<Sia> EmbedSia(const std::shared_ptr<Sia>& other) override;
  std::shared_ptr<Sia> EmbedBytes(const std::vector<uint8_t>& bytes) override;

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

  virtual std::shared_ptr<Sia> AddBigInt(const BigInt& n) override;
  virtual BigInt ReadBigInt() override;

  std::shared_ptr<Sia> AddBool(bool b) override;
  bool ReadBool() override;

  std::shared_ptr<Sia> AddStringN(const std::string& str) override;
  std::string ReadStringN(uint64_t length) override;
  std::shared_ptr<Sia> AddString8(const std::string& str) override;
  std::string ReadString8() override;
  std::shared_ptr<Sia> AddString16(const std::string& str) override;
  std::string ReadString16() override;
  std::shared_ptr<Sia> AddString32(const std::string& str) override;
  std::string ReadString32() override;
  std::shared_ptr<Sia> AddString64(const std::string& str) override;
  std::string ReadString64() override;

  std::shared_ptr<Sia> AddByteArrayN(
      const std::vector<uint8_t>& bytes) override;
  std::vector<uint8_t> ReadByteArrayN(uint64_t length) override;
  std::shared_ptr<Sia> AddByteArray8(
      const std::vector<uint8_t>& bytes) override;
  std::vector<uint8_t> ReadByteArray8() override;
  std::shared_ptr<Sia> AddByteArray16(
      const std::vector<uint8_t>& bytes) override;
  std::vector<uint8_t> ReadByteArray16() override;
  std::shared_ptr<Sia> AddByteArray32(
      const std::vector<uint8_t>& bytes) override;
  std::vector<uint8_t> ReadByteArray32() override;
  std::shared_ptr<Sia> AddByteArray64(
      const std::vector<uint8_t>& bytes) override;
  std::vector<uint8_t> ReadByteArray64() override;
};

}  // namespace sia