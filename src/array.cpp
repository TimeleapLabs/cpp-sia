#include "sia/array.hpp"
#include "sia/sia_impl.hpp"

namespace sia {

template <typename T> class ArraySiaImpl : public SiaImpl, public Array<T> {
public:
  std::shared_ptr<Array<T>>
  loop(const std::vector<T> &array,
       const std::function<void(std::shared_ptr<Array<T>>, const T &)> &fn) {
    auto self = std::static_pointer_cast<ArraySiaImpl<T>>(shared_from_this());
    for (const auto &item : array)
      fn(self, item);
    return self;
  }

  std::vector<T> read(uint64_t length,
                      const std::function<T(std::shared_ptr<Array<T>>)> &fn) {
    std::vector<T> out;
    auto self =
        std::static_pointer_cast<ArraySiaImpl<T>>(this->shared_from_this());
    for (uint64_t i = 0; i < length; ++i)
      out.push_back(fn(self));
    return out;
  }

  std::shared_ptr<Array<T>>
  AddArray8(const std::vector<T> &array,
            const std::function<void(std::shared_ptr<Array<T>>, const T &)> &fn)
      override {
    AddUInt8(static_cast<uint8_t>(array.size()));
    return loop(array, fn);
  }

  std::vector<T>
  ReadArray8(const std::function<T(std::shared_ptr<Array<T>>)> &fn) override {
    uint8_t len = ReadUInt8();
    return read(len, fn);
  }

  std::shared_ptr<Array<T>>
  AddArray16(const std::vector<T> &array,
             const std::function<void(std::shared_ptr<Array<T>>, const T &)>
                 &fn) override {
    AddUInt16(static_cast<uint16_t>(array.size()));
    return loop(array, fn);
  }

  std::vector<T>
  ReadArray16(const std::function<T(std::shared_ptr<Array<T>>)> &fn) override {
    uint16_t len = ReadUInt16();
    return read(len, fn);
  }

  std::shared_ptr<Array<T>>
  AddArray32(const std::vector<T> &array,
             const std::function<void(std::shared_ptr<Array<T>>, const T &)>
                 &fn) override {
    AddUInt32(static_cast<uint32_t>(array.size()));
    return loop(array, fn);
  }

  std::vector<T>
  ReadArray32(const std::function<T(std::shared_ptr<Array<T>>)> &fn) override {
    uint32_t len = ReadUInt32();
    return read(len, fn);
  }

  std::shared_ptr<Array<T>>
  AddArray64(const std::vector<T> &array,
             const std::function<void(std::shared_ptr<Array<T>>, const T &)>
                 &fn) override {
    AddUInt64(static_cast<uint64_t>(array.size()));
    return loop(array, fn);
  }

  std::vector<T>
  ReadArray64(const std::function<T(std::shared_ptr<Array<T>>)> &fn) override {
    uint64_t len = ReadUInt64();
    return read(len, fn);
  }
};

template <typename T> std::shared_ptr<Array<T>> NewArray() {
  return std::make_shared<ArraySiaImpl<T>>();
}

template <typename T>
std::shared_ptr<Array<T>>
NewArrayFromBytes(const std::vector<uint8_t> &content) {
  auto impl = std::make_shared<ArraySiaImpl<T>>();
  impl->content = content;
  return impl;
}

// Explicit instantiations (add more if needed)
template class ArraySiaImpl<int>;
template class ArraySiaImpl<std::string>;

} // namespace sia
