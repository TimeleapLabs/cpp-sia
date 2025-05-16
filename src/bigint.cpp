#include <cstdint>
#include <vector>
#include "sia/sia_impl.hpp"

#ifdef SIA_USE_BOOST
#include <boost/multiprecision/cpp_int.hpp>
#endif

namespace sia {

#ifdef SIA_USE_BOOST
using BigInt = boost::multiprecision::cpp_int;
#else
using BigInt = std::vector<uint8_t>;  // Fallback placeholder
#endif

std::shared_ptr<Sia> SiaImpl::AddBigInt(const BigInt& n) {
#ifdef SIA_USE_BOOST
  std::vector<uint8_t> bytes;
  export_bits(n, std::back_inserter(bytes), 8);
#else
  const std::vector<uint8_t>& bytes = n;
#endif
  AddUInt8(static_cast<uint8_t>(bytes.size()));
  return AddByteArrayN(bytes);
}

BigInt SiaImpl::ReadBigInt() {
  uint8_t length = ReadUInt8();
  std::vector<uint8_t> bytes = ReadByteArrayN(length);
#ifdef SIA_USE_BOOST
  BigInt n;
  import_bits(n, bytes.begin(), bytes.end(), 8);
  return n;
#else
  return bytes;
#endif
}

}  // namespace sia