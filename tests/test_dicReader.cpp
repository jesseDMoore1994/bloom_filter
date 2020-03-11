#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include "dicReader.hpp"

std::stringstream fake_cout;
std::streambuf *backup_cout;

SCENARIO( "dicReader filename operations.", "[dicReader]" ) {
    std::vector<std::string> example_dictionary_lines{
        "AAA",
        "BBB",
        "CCC",
        "DDD",
        "EEE",
        "FFF",
        "GGG",
        "HHH",
        "III",
        "JJJ"
    };
    backup_cout = std::cout.rdbuf(fake_cout.rdbuf());

    GIVEN( "a dicReader initialized with a filename" ) {
        dicReader dr = dicReader("tests/clean_dictionary.txt");

        WHEN( "the clean file is read" ) {
            std::vector<std::string> ret_lines = dr.getDictLines(); 

            THEN( "std out is empty" ) {
                REQUIRE( fake_cout.str() == "");
            }

            AND_THEN( "the lines read are the cleaned as expected" ) {
                REQUIRE( ret_lines == example_dictionary_lines );
            }
        }
    }

    GIVEN( "a dicReader initialized with a filename" ) {
        dicReader dr = dicReader("tests/dirty_dictionary.txt");

        WHEN( "the dirty file is read" ) {
            std::vector<std::string> ret_lines = dr.getDictLines();

            THEN( "std out is empty" ) {
                REQUIRE( fake_cout.str() == "Detected at least one dirty string, input was cleaned.\n");
            }

            AND_THEN( "the lines read are the cleaned as expected" ) {
                REQUIRE( ret_lines == example_dictionary_lines );
            }
        }
    }
}
