#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <sia/sia.hpp>

TEST_CASE("Sia: Signed integers", "[int]") {
  auto s = sia::New();
  s->AddInt8(-42)
      ->AddInt16(-12345)
      ->AddInt32(-987654321)
      ->AddInt64(-123456789012345LL);
  auto r = sia::NewFromBytes(s->Bytes());

  REQUIRE(r->ReadInt8() == -42);
  REQUIRE(r->ReadInt16() == -12345);
  REQUIRE(r->ReadInt32() == -987654321);
  REQUIRE(r->ReadInt64() == -123456789012345LL);
}
