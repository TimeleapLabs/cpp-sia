#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <sia/sia.hpp>

TEST_CASE("Sia: Bool serialization", "[bool]") {
  auto s = sia::New();
  s->AddBool(true)->AddBool(false);
  auto r = sia::NewFromBytes(s->Bytes());

  REQUIRE(r->ReadBool() == true);
  REQUIRE(r->ReadBool() == false);
}
