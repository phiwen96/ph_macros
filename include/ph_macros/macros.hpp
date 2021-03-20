#pragma once
using namespace std;

namespace {
template <size_t N, size_t M>
consteval bool same_strings (char const(&lhs)[N], char const(&rhs)[M])
{
    if (N != M)
        return false;
    
    for (int i = 0; i < N; ++i)
    {
        if (lhs[i] != rhs[i])
            return false;
    }
    
    return true;
}

template <size_t N>
consteval size_t string_size (char const(&)[N])
{
    return N;
}



#define PH_$empty()



/*
 delay the evaluation of a macro
 
 @example
    foo (x, y) x,  y
    bar () 1, 2
        
        foo (bar ())            ERROR
        defer (foo) (bar ())    foo (1, 2)
 DEFER(A)() expands to A()
 */
#define PH_$defer(...) __VA_ARGS__ PH_$empty ()

#define EAT(...)
#define EXPAND(...) __VA_ARGS__
#define EMPTY()



#define IF_0_ELSE(...) EXPAND
#define IF_1_ELSE(...) __VA_ARGS__ EAT
#define IF_ELSE(cond) IF_ ## cond ##_ELSE

#define IF_0(...)
#define IF_1(...) __VA_ARGS__
#define IF(cond) IF_ ## cond



#define PH_MACRO_$expand(...) __VA_ARGS__

#define PH_MACRO_$string_size(x) string_size (x)

#define PH_MACRO(...) __VA_ARGS__


#define TO_UPPERCASE_COUNTED(Str,Cnt)
#define TO_UPPER(Str) TO_UPPERCASE_COUNTED(Str,__COUNT__) {( \
   static char buf_##Cnt[sizeof(Str)+4]; \
   char *str_##Cnt = Str; \
   int ix_##Cnt = 0; \
   for (; *str_##Cnt; str_##Cnt++, ix_##Cnt++) \
     if (ix_##Cnt < sizeof(buf_##Cnt)-1) \
         buf_##Cnt[ix_##Cnt] = toupper(*str_##Cnt); \
   buf_##Cnt; )}



//#define TO_UPPER(x)


#define PH_MACRO_$token_is_string(x, y) __builtin_choose_expr (same_strings (BOOST_PP_STRINGIZE (x), y), 1, 0)
#define PH_MACRO_$if_token_is_string(token, string, true, false) __builtin_choose_expr (PH_MACRO_$token_is_string (token, string), true, false)
#define PH_MACRO_$has(x) \
    [] (auto a) constexpr { \
        return requires (){a.x;}; \
    }

}
namespace {
consteval auto my_function_name (char const* s = __builtin_FUNCTION ()) {
    return s;
}
#define MY_FUNCTION_NAME my_function_name ()
}
