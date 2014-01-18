/*=============================================================================
  Copyright (c) 2011-2014 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_RANDOM_RESULTS_HPP
#define SPROUT_RANDOM_RESULTS_HPP

#include <utility>
#include <sprout/config.hpp>
#include <sprout/generator/functions.hpp>
#include <sprout/utility/forward.hpp>

namespace sprout {
	namespace random {
		//
		// result
		//
		template<typename T>
		inline SPROUT_CONSTEXPR decltype(sprout::generators::generated_value(std::declval<T>()))
		result(T&& t)
			SPROUT_NOEXCEPT_EXPR(SPROUT_NOEXCEPT_EXPR(sprout::generators::generated_value(std::declval<T>())))
		{
			return sprout::generators::generated_value(sprout::forward<T>(t));
		}

		//
		// next
		//
		template<typename T>
		inline SPROUT_CONSTEXPR decltype(sprout::generators::next_generator(std::declval<T>()))
		next(T&& t)
			SPROUT_NOEXCEPT_EXPR(SPROUT_NOEXCEPT_EXPR(sprout::generators::next_generator(std::declval<T>())))
		{
			return sprout::generators::next_generator(sprout::forward<T>(t));
		}
	}	// namespace random
}	// namespace sprout

#endif	// #ifndef SPROUT_RANDOM_RESULTS_HPP