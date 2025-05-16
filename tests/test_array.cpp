#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <sia/array.hpp>
#include <string>

//TODO:fix array instantiations

// TEST_CASE("Sia: Array<int> round-trip", "[array][int]") {
//   auto s = sia::NewArray<int>();
//   std::vector<int> data = {10, 20, 30, 40};

//   s->AddArray8(data, [](auto self, const int &x) {
//     self->AddInt(x);
//   });

//   auto r = sia::NewArrayFromBytes<int>(s->Bytes());
//   auto out = r->ReadArray8([](auto self) -> int {
//     return self->ReadInt();
//   });

//   REQUIRE(out == data);
// }

// TEST_CASE("Sia: Array<string> round-trip", "[array][string]") {
//   auto s = sia::NewArray<std::string>();
//   std::vector<std::string> data = {"foo", "bar", "baz"};

//   s->AddArray8(data, [](auto self, const std::string &str) {
//     self->AddString(str);
//   });

//   auto r = sia::NewArrayFromBytes<std::string>(s->Bytes());
//   auto out = r->ReadArray8([](auto self) -> std::string {
//     return self->ReadString();
//   });

//   REQUIRE(out == data);
// }
