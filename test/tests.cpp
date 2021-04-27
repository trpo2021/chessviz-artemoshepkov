#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <thirdparty/catch.hpp>


TEST_CASE("2+2 must be equal to 4")
{
  REQUIRE(2 + 2 == 4);
}
