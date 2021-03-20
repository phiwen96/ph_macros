#include "headers.hpp"





TEST_CASE ("test IF_TOKEN_IS_STRING (token, string, true, false)")
{
#define TEST_PARAMS \
    X (hej, "hej", 0, 1)
    
#define X(...) REQUIRE (IF_TOKEN_IS_STRING (__VA_ARGS__) == )
    
#undef TEST_PARAMS
#undef X
}




TEST_CASE ("test SAME_TOKEN (x, y)")
{
    #define TEST_TOKEN \
        X (x) \
        X (abs) \
        X (hej då)
    
    #define X(token) \
        REQUIRE (TOKEN_IS_STRING (token, BOOST_PP_STRINGIZE (token)));
    
    TEST_TOKEN
    
    #undef TEST_TOKEN
    #undef X
}







int main( int argc, char* argv[] ) {

    cout << BOOST_TTI_NAMESPACE
    int result = Catch::Session().run( argc, argv );

  // global clean-up...

    return result;
}










//TEST_CASE( "Quick check", "[main]" ) {
//
//    REQUIRE( 0 == 0 );
//}


