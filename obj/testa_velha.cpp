#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/velha.hpp"

/* <<UNDEFINED GAMES>> */
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

/* <<'X' WAS THE WINNER. IT ALSO WORKS ON 'O' VALUE>> */
TEST_CASE("X was the winner by row") {
  SECTION("First row was the winner") {
    restartGame();
    pushX('a', 'd');
    pushX('a', 'e');
    pushX('a', 'f');
    REQUIRE(checkGameStatus() == 1);
  }

  SECTION("Second row was the winner") {
    restartGame();
    pushX('b', 'd');
    pushX('b', 'e');
    pushX('b', 'f');
    REQUIRE(checkGameStatus() == 1);
  }

  SECTION("Third row was the winner") {
    restartGame();
    pushX('b', 'd');
    pushX('b', 'e');
    pushX('b', 'f');
    REQUIRE(checkGameStatus() == 1);
  }
}

TEST_CASE("X was the winner by column") {
  SECTION("First column was the winner") {
    restartGame();
    pushX('a', 'd');
    pushX('b', 'd');
    pushX('c', 'd');
    REQUIRE(checkGameStatus() == 1);
  }

  SECTION("Second column was the winner") {
    restartGame();
    pushX('a', 'e');
    pushX('b', 'e');
    pushX('c', 'e');
    REQUIRE(checkGameStatus() == 1);
  }

  SECTION("Third column was the winner") {
    restartGame();
    pushX('a', 'f');
    pushX('b', 'f');
    pushX('c', 'f');
    REQUIRE(checkGameStatus() == 1);
  }
}

TEST_CASE("X was the winner by diagonal") {
  SECTION("First diagonal was the winner") {
    restartGame();
    pushX('a', 'd');
    pushX('b', 'e');
    pushX('c', 'f');
    REQUIRE(checkGameStatus() == 1);
  }

  SECTION("Second diagonal was the winner") {
    restartGame();
    pushX('a', 'f');
    pushX('b', 'e');
    pushX('c', 'd');
    REQUIRE(checkGameStatus() == 1);
  }
}

/* <<CHECK INVALID GAMES>> */
TEST_CASE("Game was invalid") {
  WHEN("We insert two or more of one type than the other one - case 'X'") {
    restartGame();
    pushO('a', 'e');
    pushX('a', 'd');
    pushX('b', 'd');
    pushX('c', 'd');
    REQUIRE(checkGameStatus() == -2);
  }

  WHEN("We insert two or more of one type than the other one - case 'O'") {
    restartGame();
    pushX('a', 'e');
    pushO('a', 'd');
    pushO('b', 'd');
    pushO('c', 'd');
    REQUIRE(checkGameStatus() == -2);
  }
}
