#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <sia/sia.hpp>

TEST_CASE("Sia: String serialization", "[string]") {
  auto s = sia::New();
  std::string s8 = "hi";
  std::string s16 = "hello world";
  std::string s32 = "this is a longer string for 32";
  std::string s64 = std::string(300, 'z');

  s->AddString8(s8)->AddString16(s16)->AddString32(s32)->AddString64(s64);

  auto r = sia::NewFromBytes(s->Bytes());

  REQUIRE(r->ReadString8() == s8);
  REQUIRE(r->ReadString16() == s16);
  REQUIRE(r->ReadString32() == s32);
  REQUIRE(r->ReadString64() == s64);
}
