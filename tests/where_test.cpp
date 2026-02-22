#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/where.hpp"

TEST_CASE( "Text='The quick brown fox' query='e' it returns 2" ) {
    REQUIRE( find("The quick brown fox",'e') == 2 );
}
TEST_CASE( "Text='The quick brown fox' query='e' string it returns 2" ) {
    REQUIRE( find("The quick brown fox","e") == 2 );
}
TEST_CASE( "Text='The quick brown fox' query=' ' it returns 3" ) {
    REQUIRE( find("The quick brown fox",' ') == 3 );
}
TEST_CASE( "Text='The quick brown fox' query='quick' it returns 4" ) {
    REQUIRE( find("The quick brown fox","quick") == 4 );
}
TEST_CASE( "Text='The quick brown fox' query='quiet' it returns -1" ) {
    REQUIRE( find("The quick brown fox","quiet") == -1 );
}
TEST_CASE( "Text='The quick brown fox' query='e' start not specified it returns 2" ) {
    REQUIRE( find("The quick brown fox",'e') == 2 );
}
TEST_CASE( "Text='The quick brown fox' query='e' start='0' it returns 2" ) {
    REQUIRE( find("The quick brown fox",'e',0) == 2 );
}
TEST_CASE( "Text='The quick brown fox' query='e' start='1' it returns 2" ) {
    REQUIRE( find("The quick brown fox",'e',1) == 2 );
}
TEST_CASE( "Text='The quick brown fox' query='e' start='2' it returns 2" ) {
    REQUIRE( find("The quick brown fox",'e',2) == 2 );
}
TEST_CASE( "Text='The quick brown fox' query='e' start='3' it returns -1" ) {
    REQUIRE( find("The quick brown fox",'e',3) == -1 );
}
TEST_CASE( "Text='The quick brown fox' query='e' start='500' it returns -1" ) {
    REQUIRE( find("The quick brown fox",'e',500) == -1 );
}
TEST_CASE( "Text='The quick brown fox' query='e' start='0' case=false it returns 2" ) {
    REQUIRE( find("The quick brown fox","E",0,false) == 2 );
}
TEST_CASE( "Text='The quick brown fox' query='e' start='0' case=true it returns -1" ) {
    REQUIRE( find("The quick brown fox","E",0,true) == -1 );
}
TEST_CASE( "Text='lamb' query='*mb' it returns 0" ) {
    REQUIRE( find("lamb","*mb") == 0 );
}
TEST_CASE( "Text='pits' query='*s' it returns 0" ) {
    REQUIRE( find("pits","*s") == 0 );
}
TEST_CASE( "Text='yellow' query='y*l' it returns 0" ) {
    REQUIRE( find("yellow","y*l") == 0 );
}
TEST_CASE( "Text='that's why I like milk' query='y*l' it returns 9" ) {
    REQUIRE( find("that's why I like milk","y*l") == 9 );
}
TEST_CASE( "Text='dumb' query='*d' it returns 0" ) {
    REQUIRE( find("dumb","*d") == 0 );
}
TEST_CASE( "Text='dumb' query='b*' it returns 3" ) {
    REQUIRE( find("dumb","b*") == 3 );
}
TEST_CASE( "Text='dumb bunnies' query='*bunnies' it returns 0" ) {
    REQUIRE( find("dumb bunnies","*bunnies") == 0 );
}
TEST_CASE( "Text='dumb bunnies' query='b*b*n' it returns 3" ) {
    REQUIRE( find("dumb bunnies","b*b*n") == 3 );
}
TEST_CASE( "Text='dumb bunnies' query='b*n*n' it returns 3" ) {
    REQUIRE( find("dumb bunnies","b*n*n") == 3 );
}
TEST_CASE( "Text='dumb bunnies' query='u*n*n' it returns 1" ) {
    REQUIRE( find("dumb bunnies","u*n*n") == 1 );
}
