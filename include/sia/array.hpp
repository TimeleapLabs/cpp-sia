#pragma once

#include <functional>
#include <memory>
#include <vector>
#include "sia.hpp"

namespace sia {

template <typename T>
std::shared_ptr<Sia> AddArray8(
    const std::shared_ptr<Sia>& stream,
    const std::vector<T>& vec,
    const std::function<void(const std::shared_ptr<Sia>&, const T&)>& encoder) {
  stream->AddUInt8(static_cast<uint8_t>(vec.size()));
  for (const auto& v : vec)
    encoder(stream, v);
  return stream;
}

template <typename T>
std::vector<T> ReadArray8(
    const std::shared_ptr<Sia>& stream,
    const std::function<T(const std::shared_ptr<Sia>&)>& decoder) {
  uint8_t size = stream->ReadUInt8();
  std::vector<T> vec;
  vec.reserve(size);
  for (uint8_t i = 0; i < size; ++i) {
    vec.push_back(decoder(stream));
  }
  return vec;
}

template <typename T>
std::shared_ptr<Sia> AddArray16(
    const std::shared_ptr<Sia>& stream,
    const std::vector<T>& vec,
    const std::function<void(const std::shared_ptr<Sia>&, const T&)>& encoder) {
  stream->AddUInt16(static_cast<uint16_t>(vec.size()));
  for (const auto& v : vec)
    encoder(stream, v);
  return stream;
}

template <typename T>
std::vector<T> ReadArray16(
    const std::shared_ptr<Sia>& stream,
    const std::function<T(const std::shared_ptr<Sia>&)>& decoder) {
  uint16_t size = stream->ReadUInt16();
  std::vector<T> vec;
  vec.reserve(size);
  for (uint16_t i = 0; i < size; ++i) {
    vec.push_back(decoder(stream));
  }
  return vec;
}

template <typename T>
std::shared_ptr<Sia> AddArray32(
    const std::shared_ptr<Sia>& stream,
    const std::vector<T>& vec,
    const std::function<void(const std::shared_ptr<Sia>&, const T&)>& encoder) {
  stream->AddUInt32(static_cast<uint32_t>(vec.size()));
  for (const auto& v : vec)
    encoder(stream, v);
  return stream;
}

template <typename T>
std::vector<T> ReadArray32(
    const std::shared_ptr<Sia>& stream,
    const std::function<T(const std::shared_ptr<Sia>&)>& decoder) {
  uint32_t size = stream->ReadUInt32();
  std::vector<T> vec;
  vec.reserve(size);
  for (uint32_t i = 0; i < size; ++i) {
    vec.push_back(decoder(stream));
  }
  return vec;
}

template <typename T>
std::shared_ptr<Sia> AddArray64(
    const std::shared_ptr<Sia>& stream,
    const std::vector<T>& vec,
    const std::function<void(const std::shared_ptr<Sia>&, const T&)>& encoder) {
  stream->AddUInt64(static_cast<uint64_t>(vec.size()));
  for (const auto& v : vec)
    encoder(stream, v);
  return stream;
}

template <typename T>
std::vector<T> ReadArray64(
    const std::shared_ptr<Sia>& stream,
    const std::function<T(const std::shared_ptr<Sia>&)>& decoder) {
  uint64_t size = stream->ReadUInt64();
  std::vector<T> vec;
  vec.reserve(size);
  for (uint64_t i = 0; i < size; ++i) {
    vec.push_back(decoder(stream));
  }
  return vec;
}

}  // namespace sia
