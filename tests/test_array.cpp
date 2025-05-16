#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <sia/array.hpp>
#include <sia/sia.hpp>
#include <string>

TEST_CASE("Sia: Array<int> round-trip", "[array][int]") {
  auto s = sia::New();
  std::vector<int> data = {10, 20, 30, 40};

  sia::AddArray8<int>(s, data,
                      [](auto self, const int& x) { self->AddInt8(x); });

  auto r = sia::NewFromBytes(s->Bytes());
  auto out = sia::ReadArray8<int>(
      r, [](auto self) -> int { return self->ReadInt8(); });

  REQUIRE(out == data);
}

TEST_CASE("Sia: Array<string> round-trip", "[array][string]") {
  auto s = sia::New();
  std::vector<std::string> data = {"foo", "bar", "baz"};

  sia::AddArray8<std::string>(s, data, [](auto self, const std::string& str) {
    self->AddString8(str);
  });

  auto r = sia::NewFromBytes(s->Bytes());
  auto out = sia::ReadArray8<std::string>(
      r, [](auto self) -> std::string { return self->ReadString8(); });

  REQUIRE(out == data);
}
