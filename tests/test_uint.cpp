#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <sia/sia.hpp>

TEST_CASE("Sia: Unsigned integers", "[uint]") {
  auto s = sia::New();
  s->AddUInt8(255)
      ->AddUInt16(65000)
      ->AddUInt32(4294960000U)
      ->AddUInt64(18446744073709551600ULL);
  auto r = sia::NewFromBytes(s->Bytes());

  REQUIRE(r->ReadUInt8() == 255);
  REQUIRE(r->ReadUInt16() == 65000);
  REQUIRE(r->ReadUInt32() == 4294960000U);
  REQUIRE(r->ReadUInt64() == 18446744073709551600ULL);
}
