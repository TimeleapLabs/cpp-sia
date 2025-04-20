#pragma once

#include "sia.hpp"
#include <functional>
#include <vector>

namespace sia {

template <typename T> class Array : public Sia {
public:
  virtual std::shared_ptr<Array<T>> AddArray8(
      const std::vector<T> &array,
      const std::function<void(std::shared_ptr<Array<T>>, const T &)> &fn) = 0;
  virtual std::vector<T>
  ReadArray8(const std::function<T(std::shared_ptr<Array<T>>)> &fn) = 0;

  virtual std::shared_ptr<Array<T>> AddArray16(
      const std::vector<T> &array,
      const std::function<void(std::shared_ptr<Array<T>>, const T &)> &fn) = 0;
  virtual std::vector<T>
  ReadArray16(const std::function<T(std::shared_ptr<Array<T>>)> &fn) = 0;

  virtual std::shared_ptr<Array<T>> AddArray32(
      const std::vector<T> &array,
      const std::function<void(std::shared_ptr<Array<T>>, const T &)> &fn) = 0;
  virtual std::vector<T>
  ReadArray32(const std::function<T(std::shared_ptr<Array<T>>)> &fn) = 0;

  virtual std::shared_ptr<Array<T>> AddArray64(
      const std::vector<T> &array,
      const std::function<void(std::shared_ptr<Array<T>>, const T &)> &fn) = 0;
  virtual std::vector<T>
  ReadArray64(const std::function<T(std::shared_ptr<Array<T>>)> &fn) = 0;
};

} // namespace sia