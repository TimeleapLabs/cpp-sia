// README.md

# Sia C++ Serialization Library

This is a modern C++17+ port of the original Go-based `sia` serialization library. It provides a compact, efficient API for serializing and deserializing primitive types, strings, byte arrays, big integers, and custom arrays.

## 📦 Features

- Simple, chainable interface
- Support for fixed and variable-length strings and byte arrays
- Optional support for arbitrary precision integers via Boost
- Templated array serialization for generic types
- Easy to embed into projects as a static library

## 🔧 Building

This project uses CMake. You can add it to your project or build standalone.

### 🔗 Add to your CMake project

```cmake
add_subdirectory(path/to/sia-cpp)
target_link_libraries(your_target PRIVATE sia)
```

### 🛠 Build standalone

```bash
git clone https://github.com/your-org/sia-cpp.git
cd sia-cpp
mkdir build && cd build
cmake ..
make
```

### 🔄 Optional: Enable Boost support

To use `boost::multiprecision::cpp_int` for BigInt support:

```bash
cmake -DSIA_USE_BOOST=ON ..
```

Or in CMake:

```cmake
target_compile_definitions(sia PUBLIC SIA_USE_BOOST)
```

## ✍️ Example

### Primitive values

```cpp
#include <sia/sia.hpp>

auto s = sia::New();
s->AddUInt64(42)
 ->AddString8("hello");

auto data = s->Bytes();

auto reader = sia::NewFromBytes(data);
uint64_t num = reader->ReadUInt64();
std::string str = reader->ReadString8();
```

### Arrays

```cpp
#include <sia/sia.hpp>
#include <sia/array.hpp>

// Serialize an array of integers
std::vector<int> numbers = {1, 2, 3, 4};
auto arraySia = sia::NewArray<int>();
arraySia->AddArray8(numbers, [](auto s, int item) {
  s->AddInt32(item);
});

std::vector<uint8_t> bytes = arraySia->Bytes();

// Deserialize
auto reader = sia::NewArrayFromBytes<int>(bytes);
auto decoded = reader->ReadArray8([](auto s) {
  return s->ReadInt32();
});
```

## 🧪 Supported Types

- `uint8_t`, `uint16_t`, `uint32_t`, `uint64_t`
- `int8_t`, `int16_t`, `int32_t`, `int64_t`
- `bool`
- `std::string` (fixed, 8/16/32/64-bit length-prefixed)
- `std::vector<uint8_t>` (same)
- `BigInt` (optional with Boost)
- `std::vector<T>` using `Array<T>` with `std::function` callbacks

## 🧩 License

MIT
