#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

#include "gravitas.h"

TEST_CASE("Basic arithmetic", "[math]") {
    REQUIRE(1 + 1 == 2);
    REQUIRE(2 * 2 == 4);
}