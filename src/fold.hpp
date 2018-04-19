#ifndef SIBORGIUM_SFOLDL
#define SIBORGIUM_SFOLDL
#include<iterator>
#include<tuple>
#include<utility>

/*
@ namespace SFD
@ this namespace contains various folding functions
@ its name is abbreviature of SFolD (Siborgium's fold)
*/
namespace sfd {
	/*
	Left-fold function
	Required arguments:
		@ binary function, taking two arguments of type T (see below) and returning one value of type T
		* using Haskell-like notation, signature of this function is T -> T -> T
		* this function is expected to be pure (but this condition is not necessary)
		@ start value of type T
		* it is strongly recommended to avoid using start value somewhere else
		* because start value will be overwritten while function works
		@ two iterators of type Iter: begin and end
		* provide common iterators to perform a left fold
		* provide reverse iterators to perform a right fold
		*/
	template<
		typename _Callable,
		typename _T,
		typename _Iter>
		auto fold(
			_Callable &&f,
			_T &&start,
			_Iter &&begin,
			_Iter &&end)
	{
		static_assert(
			std::is_same_v<_T, typename std::iterator_traits<_Iter>::value_type>,
			"Start value should have the type same to the type of provided container");
		if (begin > end)
			std::abort();
		while (begin != end) {
				start = f(start, *begin);
				begin++;
			}
		return start;
	}
	
	/*
	 Left-fold function
	 Required arguments:
		@ binary function, taking two arguments of type T (see below) and returning one value of type T
		* using Haskell-like notation, signature of this function is T -> T -> T
		* this function is expected to be pure (but this condition is not necessary)
		@ start value of type T
		* it is strongly recommended to avoid using start value somewhere else
		* because start value will be overwritten while function works
		@ parameter pack, containing atleast 1 argument of type T (or implicitly convertible to type T)
		* every parameter in this pack is expected to have type T (but this condition is not necessary)
	 */
	template<
		typename _Callable,
		typename _T,
		typename ... _Ts>
		auto foldl(
			_Callable &&f,
			_T &&start,
			_Ts&& ... args)
	{
		static_assert(sizeof... (args) > 0, "You should provide start value and atleast one argument");
		auto argtuple = std::make_tuple(std::forward<_Ts>(args)...);
		auto write_to = [&start](auto &&arg) { start = arg; };
		std::apply(
			[&write_to, &f, &start](auto&& item, auto&&... items)
		{
			start = f(start, item);
			(write_to(f(start, items)), ...);
		}
		, std::forward<decltype(argtuple)>(argtuple));
		return start;
	}
} //namespace sfd
#endif
