#include <catch2/catch.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include "bloomFilter.hpp"

SCENARIO( "Bloom filter hash operations.", "[bloomFilter]" ) {
    std::vector<std::string> hash_test_vals{
        "AAA",
        "BBB",
        "AA",
        "MN",
        "MNN"
    };

    GIVEN( "a bloomFilter" ) {
        bloomFilter bf = bloomFilter(hash_test_vals);

        WHEN( "queried with already stored values" ) {
            bool AAA = bf.isInTable("AAA");
            bool BBB = bf.isInTable("BBB");
            bool AA = bf.isInTable("AA");
            bool MN = bf.isInTable("MN");
            bool MNN = bf.isInTable("MNN");

            THEN( "the values are inicated as stored" ) {
                REQUIRE(AAA);
                REQUIRE(BBB);
                REQUIRE(AA);
                REQUIRE(MN);
                REQUIRE(MNN);
            }
        }

        WHEN( "queried with acceptable values" ) {
            bool F = bf.isInTable("F");

            THEN( "the values are inicated as not stored" ) {
                REQUIRE(!F);
            }
        }

        WHEN( "queried with a colliding value not entered into the table" ) {
            bool Z = bf.isInTable("Z");

            THEN( "the values are inicated as stored" ) {
                REQUIRE(Z);
            }
        }
    }
}
