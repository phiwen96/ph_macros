#include "headers.hpp"


#



TEST_CASE ("test IF_TOKEN_IS_STRING (token, string, true, false)")
{
    REQUIRE (PH_MACRO_$if_token_is_string (hej, "hej", 24, 0) == 24);
    REQUIRE (PH_MACRO_$if_token_is_string (kuk, "hej", 0, 24) == 24);
    
#define TEST_PARAMS \
    X (hej, "hej", 0, 0)
    
#define X(...) REQUIRE (IF_TOKEN_IS_STRING (__VA_ARGS__) == BOOST_PP_VARIADIC_ELEM (BOOST_PP_VARIADIC_SIZE (__VA_ARGS__) - 1, __VA_ARGS__));
    

//    TEST_PARAMS
    
#undef TEST_PARAMS
#undef X
}




TEST_CASE ("test TOKEN_IS_STRING (x, y)")
{
    REQUIRE (PH_MACRO_$token_is_string (kuk, "kuk") == 1);
    REQUIRE (PH_MACRO_$token_is_string (hej, "phi") == 0);
    
//    #define TEST_TOKEN \
//        X (x) \
//        X (abs) \
//        X (hej då)
//
//    #define X(token) \
//        REQUIRE (TOKEN_IS_STRING (token, BOOST_PP_STRINGIZE (token)));
//
//    TEST_TOKEN
//
//    #undef TEST_TOKEN
//    #undef X
}



namespace ph {
namespace macro {
struct token_is_string
{
#define PH_MACRO_TOKEN_IS_STRING
};
}
}


#define TEXT1(z, n, text) BOOST_PP_COMMA_IF(n) text

#define TEXT2(z, n, text) \
BOOST_PP_COMMA_IF (n) \
      BOOST_PP_REPEAT_ ## z( \
         BOOST_PP_INC(n), \
         TEXT, text [n] \
      )
   /**/

#define TEXT3(x, n) BOOST_PP_CAT (BOOST_PP_REPEAT_, n)(n, BOOST_PP_STRINGIZE (x),  PH_MACRO_$expand(nil))
//#define TEXT4(x) TEXT3 (x, PH_MACRO_$string_size (x))

#define A0(x) x + 2
#define A1(x) x + 1

template <char...>
struct Test{};

int main( int argc, char* argv[] ) {

#define MACRO(x) IF_TOKEN_IS_STRING (x, "ph::", cout << "ph", cout << "not ph")
    
//    Test<TEXT3("hej", 3)> t1;
//    cout << A1(A2(1)) << endl;
   
    PH_$empty()
//    IF(1)(cout << "1", cout << "0");
    
    IF(1)(cout << "hi" << endl;)
    
    IF_ELSE (1)
        (cout << "1")
        (cout << "0");
    
    
    
    cout << endl;
//    cout << BOOST_TTI_NAMESPACE
    int result = Catch::Session().run( argc, argv );
    string a;
    using ty = int;
//    template <class T>
    bool has_toString = PH_MACRO_$has (c_str()) (a);
    cout << has_toString << endl;
  // global clean-up...

    return result;
}










//TEST_CASE( "Quick check", "[main]" ) {
//
//    REQUIRE( 0 == 0 );
//}


