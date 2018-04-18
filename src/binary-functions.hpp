#ifndef SIBORGIUM_SFOLDBIN
#define SIBORGIUM_SFOLDBIN

#define SFD_DECLARE_FUNCTION(name, action) struct name{\
template<typename _T>\
_T operator () (_T& a, _T& b){ return action; }\
};\

namespace sfd{
	SFD_DECLARE_FUNCTION(plus, a + b)
	SFD_DECLARE_FUNCTION(minus, a - b)
	SFD_DECLARE_FUNCTION(multiply, a * b)
	SFD_DECLARE_FUNCTION(divide, a / b)
	SFD_DECLARE_FUNCTION(module, a % b)
	SFD_DECLARE_FUNCTION(logical_and, a && b)
	SFD_DECLARE_FUNCTION(logical_or, a || b)
	SFD_DECLARE_FUNCTION(find_max, a > b ? a : b)
	SFD_DECLARE_FUNCTION(find_min , a > b ? b : a)
	SFD_DECLARE_FUNCTION(byte_and, a & b)
	SFD_DECLARE_FUNCTION(byte_or, a | b)
	SFD_DECLARE_FUNCTION(byte_lshift, a << b)
	SFD_DECLARE_FUNCTION(byte_rshift, a >> b)
	SFD_DECLARE_FUNCTION(byte_xor, a ^ b)
}

#undef SFD_DECLARE_FUNCTION

#endif