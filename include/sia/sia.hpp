#pragma once

#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#ifdef SIA_USE_BOOST
#include <boost/multiprecision/cpp_int.hpp>
#endif

#ifdef SIA_USE_BOOST
using BigInt = boost::multiprecision::cpp_int;
#else
using BigInt = std::vector<uint8_t>;  // Fallback placeholder
#endif

namespace sia {

class Sia {
 public:
  virtual ~Sia() = default;

  virtual std::shared_ptr<Sia> Seek(uint64_t index) = 0;
  virtual std::vector<uint8_t> Bytes() const = 0;
  virtual uint64_t Offset() const = 0;

  virtual std::shared_ptr<Sia> EmbedSia(const std::shared_ptr<Sia>& other) = 0;
  virtual std::shared_ptr<Sia> EmbedBytes(
      const std::vector<uint8_t>& bytes) = 0;

  virtual std::shared_ptr<Sia> AddUInt8(uint8_t n) = 0;
  virtual uint8_t ReadUInt8() = 0;
  virtual std::shared_ptr<Sia> AddUInt16(uint16_t n) = 0;
  virtual uint16_t ReadUInt16() = 0;
  virtual std::shared_ptr<Sia> AddUInt32(uint32_t n) = 0;
  virtual uint32_t ReadUInt32() = 0;
  virtual std::shared_ptr<Sia> AddUInt64(uint64_t n) = 0;
  virtual uint64_t ReadUInt64() = 0;

  virtual std::shared_ptr<Sia> AddInt8(int8_t n) = 0;
  virtual int8_t ReadInt8() = 0;
  virtual std::shared_ptr<Sia> AddInt16(int16_t n) = 0;
  virtual int16_t ReadInt16() = 0;
  virtual std::shared_ptr<Sia> AddInt32(int32_t n) = 0;
  virtual int32_t ReadInt32() = 0;
  virtual std::shared_ptr<Sia> AddInt64(int64_t n) = 0;
  virtual int64_t ReadInt64() = 0;

  virtual std::shared_ptr<Sia> AddBigInt(const BigInt& n) = 0;
  virtual BigInt ReadBigInt() = 0;

  virtual std::shared_ptr<Sia> AddBool(bool b) = 0;
  virtual bool ReadBool() = 0;

  virtual std::shared_ptr<Sia> AddStringN(const std::string& str) = 0;
  virtual std::string ReadStringN(uint64_t length) = 0;
  virtual std::shared_ptr<Sia> AddString8(const std::string& str) = 0;
  virtual std::string ReadString8() = 0;
  virtual std::shared_ptr<Sia> AddString16(const std::string& str) = 0;
  virtual std::string ReadString16() = 0;
  virtual std::shared_ptr<Sia> AddString32(const std::string& str) = 0;
  virtual std::string ReadString32() = 0;
  virtual std::shared_ptr<Sia> AddString64(const std::string& str) = 0;
  virtual std::string ReadString64() = 0;

  virtual std::shared_ptr<Sia> AddByteArrayN(
      const std::vector<uint8_t>& bytes) = 0;
  virtual std::vector<uint8_t> ReadByteArrayN(uint64_t length) = 0;
  virtual std::shared_ptr<Sia> AddByteArray8(
      const std::vector<uint8_t>& bytes) = 0;
  virtual std::vector<uint8_t> ReadByteArray8() = 0;
  virtual std::shared_ptr<Sia> AddByteArray16(
      const std::vector<uint8_t>& bytes) = 0;
  virtual std::vector<uint8_t> ReadByteArray16() = 0;
  virtual std::shared_ptr<Sia> AddByteArray32(
      const std::vector<uint8_t>& bytes) = 0;
  virtual std::vector<uint8_t> ReadByteArray32() = 0;
  virtual std::shared_ptr<Sia> AddByteArray64(
      const std::vector<uint8_t>& bytes) = 0;
  virtual std::vector<uint8_t> ReadByteArray64() = 0;
};

std::shared_ptr<Sia> New();
std::shared_ptr<Sia> NewFromBytes(const std::vector<uint8_t>& content);

}  // namespace sia
