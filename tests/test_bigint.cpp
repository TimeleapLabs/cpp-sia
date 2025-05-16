#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <sia/sia.hpp>

#ifdef SIA_USE_BOOST
#include <boost/multiprecision/cpp_int.hpp>
using BigInt = boost::multiprecision::cpp_int;
#else
using BigInt = std::vector<uint8_t>;
#endif

TEST_CASE("Sia: BigInt serialization", "[bigint]") {
  auto s = sia::New();

#ifdef SIA_USE_BOOST
  BigInt big = BigInt("1234567890123456789012345678901234567890");
#else
  // Fallback mode: manually construct a byte vector (little-endian)
  BigInt big = {0xD2, 0x02, 0x96, 0x49}; // Just a mock example
#endif

  s->AddBigInt(big);
  auto r = sia::NewFromBytes(s->Bytes());
  auto out = r->ReadBigInt();

#ifdef SIA_USE_BOOST
  REQUIRE(out == big);
#else
  REQUIRE(out == big); // vector<uint8_t> comparison
#endif
}
