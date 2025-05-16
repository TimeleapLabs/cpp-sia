#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <sia/sia.hpp>

TEST_CASE("Sia: Basic serialization round-trip", "[sia]") {
  auto s = sia::New();
  s->AddUInt64(42)->AddString8("hello");
  auto data = s->Bytes();

  auto r = sia::NewFromBytes(data);
  REQUIRE(r->ReadUInt64() == 42);
  REQUIRE(r->ReadString8() == "hello");
}
