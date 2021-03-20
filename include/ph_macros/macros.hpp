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






#define TOKEN_IS_STRING(x, y) __builtin_choose_expr (same_strings (BOOST_PP_STRINGIZE (x), y), 1, 0)
#define IF_TOKEN_IS_STRING(token, string, true, false) __builtin_choose_expr (TOKEN_IS_STRING (token, string), true, false)
}
namespace {
consteval auto my_function_name (char const* s = __builtin_FUNCTION ()) {
    return s;
}
#define MY_FUNCTION_NAME my_function_name ()
}
