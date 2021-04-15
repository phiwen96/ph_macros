#pragma once
using namespace std;

#define fwd(x) std::forward <decltype (x)> (x)

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

#define EVAL(...)  EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL1(...) EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL2(...) EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL3(...) EVAL4(EVAL4(EVAL4(__VA_ARGS__)))
#define EVAL4(...) EVAL5(EVAL5(EVAL5(__VA_ARGS__)))

#define EVAL5(...) __VA_ARGS__
#define PH_$defer(...) __VA_ARGS__ PH_$empty ()

#define EAT(...)
#define EXPAND(...) __VA_ARGS__
#define EMPTY()
#define CHECK_N(x, n, ...) n
#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
#define COMPL(b) PRIMITIVE_CAT(COMPL_, b)
#define COMPL_0 1
#define COMPL_1 0
#ifdef CHECK
#undef CHECK
#endif
#define CHECK(...) CHECK_N(__VA_ARGS__, 0,)
#define PROBE(x) x, 1,
#define NOT(x) CHECK(PRIMITIVE_CAT(NOT_, x))
#define NOT_0 PROBE(~)
#define BOOL(x) COMPL(NOT(x))

#define If(...) PRIMITIVE_CAT (IF_, __VA_ARGS__)
#define IF_0(...) EXPAND
#define IF_1(...) __VA_ARGS__ EAT

//#define IF(...) IIF(BOOL(__VA_ARGS__))




#define IFF_0(...) EXPAND
#define IFF_1(...) __VA_ARGS__ EAT
#define IF_ELSE(x) BOOST_PP_EXPAND (BOOST_PP_CAT (IFF_, x))//IFF_ ## x

//#define IFF_0(...) EXPAND
//#define IFF_1(...) __VA_ARGS__ EAT
#define IF_ELSE2(x, y) EXPAND (DEFER (BOOST_PP_CAT) (IFF_, TOKEN_IS_STRING (x, y)))

//#define IF_0(...)
//#define IF_1(...) __VA_ARGS__
//#define IF(cond) IF_ ## cond



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


#define TOKEN_IS_STRING(x, y) __builtin_choose_expr (same_strings (BOOST_PP_STRINGIZE (x), y), 1, 0)
#define IF_ELSE_TOKEN_IS_STRING(token, string)  EVAL ( BOOST_PP_CAT (DEFER (IFF_), EVAL (__builtin_choose_expr (same_strings (BOOST_PP_STRINGIZE (token), string), 1, 0))))
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





namespace {
#define KK(arg, ...) cout << BOOST_PP_STRINGIZE (arg) << endl; //cout << "yoyoyo" << endl;


#define X1(r, func, arg) \
BOOST_PP_EXPAND (func BOOST_PP_SEQ_TO_TUPLE (arg))

#define INVOKE(func, seq) \
BOOST_PP_SEQ_FOR_EACH (X1, func, seq)

/**
 example
 
 INVOKE( KK,
   ((number_t) (int))
    ((plus_t) (int))
    ((minus_t) (int))
    ((multi_t) (int))
    ((divi_t) (int))
    ((ph::number_t) (int))
    ((ph::lparen_t) (int))
    ((ph::rparen_t) (int))
 )
 */
}




#define DECL(z, n, func) \
func (n)

#define FOR(j, func) \
    BOOST_PP_REPEAT (j, DECL, func)


#define DECL2(z, n, k) \
case n: \
if constexpr (requires {value.template get <k> ().value = other.value.template get <n> ().value;}) \
{ \
cout << "tju" << endl; \
value.template get <k> ().value = other.value.template get <n> ().value; \
} \
break;
//{X1 (k, n)} \



#define SWITCH_CASE_2(func, cases, arg) \
    BOOST_PP_REPEAT (cases, func, arg)


#include <boost/preprocessor/seq/pop_back.hpp>
#include <boost/preprocessor/seq/pop_front.hpp>


//BOOST_PP_SEQ_TO_TUPLE


#define lol(n, seq) \
n, BOOST_PP_EXPAND (BOOST_PP_SEQ_TO_TUPLE BOOST_PP_SEQ_POP_FRONT (seq))

#define DECLx(z, n, func) \
BOOST_PP_EXPAND (func )

#define lol3()

#define lol2(...) \
    BOOST_PP_VARIADIC_TO_SEQ (__VA_ARGS__)


#define FORx(j, ...) \
    BOOST_PP_EXPAND (BOOST_PP_REPEAT a, DECLx, lol2 (j, __VA_ARGS__))
