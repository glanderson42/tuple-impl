#ifndef TUPLE_HPP
#define TUPLE_HPP

#include <cstddef>

namespace tpl {

	template<class First, class... Rest>
	struct tuple : public tuple<Rest...> {
		First first;
		
		tuple(First first, Rest... rest)
			: tuple<Rest...>(rest...)
			, first(first)
		{}
	};

	template<class First>
	struct tuple<First> {
		First first;

		tuple(First first)
			: first(first)
		{}
	};

	template<std::size_t Index, class First, class... Rest>
	struct impl {
		static auto value(const tuple<First, Rest...>* tpl) 
			-> decltype(impl<Index - 1, Rest...>::value(tpl)) {
			return impl<Index - 1, Rest...>::value(tpl);
		}
	};

	template<class First, class... Rest>
	struct impl<0, First, Rest...> {
		static First value(const tuple<First, Rest...>* tpl) {
			return tpl->first;
		}
	};

	template<std::size_t Index, class First, class... Rest>
	auto get(const tuple<First, Rest...>& tpl)
		-> decltype(impl<Index, First, Rest...>::value(&tpl)) {
		return impl<Index, First, Rest...>::value(&tpl);
	}
}

#endif // TUPLE_HPP