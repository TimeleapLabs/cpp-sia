#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <sia/sia.hpp>

TEST_CASE("Sia: Byte array serialization", "[bytearray]") {
  auto s = sia::New();
  std::vector<uint8_t> b8 = {1, 2, 3};
  std::vector<uint8_t> b16 = {4, 5, 6, 7, 8};
  std::vector<uint8_t> b32(100, 0xAA);
  std::vector<uint8_t> b64(300, 0xBB);

  s->AddByteArray8(b8)
      ->AddByteArray16(b16)
      ->AddByteArray32(b32)
      ->AddByteArray64(b64);

  auto r = sia::NewFromBytes(s->Bytes());

  REQUIRE(r->ReadByteArray8() == b8);
  REQUIRE(r->ReadByteArray16() == b16);
  REQUIRE(r->ReadByteArray32() == b32);
  REQUIRE(r->ReadByteArray64() == b64);
}
