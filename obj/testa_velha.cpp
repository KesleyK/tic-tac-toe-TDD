#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/velha.hpp"

TEST_CASE("Check undefined games") {
  WHEN("No marks was added") {
    THEN("It must return -1") {
      REQUIRE(checkGameStatus() == -1);
    }
  }
  
  WHEN("We add just two or less marks of one type on the game") {
    pushX('a', 'd');
    pushX('a', 'e');
    pushO('b', 'd');

    THEN("It must return -1") {
      REQUIRE(checkGameStatus() == -1);
    }
  }
}