#ifndef SPROUT_RANGE_ALGORITHM_FIXED_CLAMP_RANGE_COPY_HPP
#define SPROUT_RANGE_ALGORITHM_FIXED_CLAMP_RANGE_COPY_HPP

#include <sprout/config.hpp>
#include <sprout/container/traits.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/algorithm/fixed/result_of.hpp>
#include <sprout/algorithm/fixed/clamp_range_copy.hpp>

namespace sprout {
	namespace range {
		namespace fixed {
			//
			// clamp_range_copy
			//
			template<typename InputRange, typename Result, typename Compare>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Result>::type
			clamp_range_copy(
				InputRange const& rng, Result const& result,
				typename sprout::container_traits<InputRange>::value_type const& low,
				typename sprout::container_traits<InputRange>::value_type const& high,
				Compare comp
				)
			{
				return sprout::fixed::clamp_range_copy(sprout::begin(rng), sprout::end(rng), result, low, high, comp);
			}
			template<typename InputRange, typename Result>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Result>::type
			clamp_range_copy(
				InputRange const& rng, Result const& result,
				typename sprout::container_traits<InputRange>::value_type const& low,
				typename sprout::container_traits<InputRange>::value_type const& high
				)
			{
				return sprout::fixed::clamp_range_copy(sprout::begin(rng), sprout::end(rng), result, low, high);
			}

			template<typename Result, typename InputRange, typename Compare>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Result>::type
			clamp_range_copy(
				InputRange const& rng,
				typename sprout::container_traits<InputRange>::value_type const& low,
				typename sprout::container_traits<InputRange>::value_type const& high,
				Compare comp
				)
			{
				return sprout::fixed::clamp_range_copy<Result>(sprout::begin(rng), sprout::end(rng), low, high, comp);
			}
			template<typename Result, typename InputRange>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Result>::type
			clamp_range_copy(
				InputRange const& rng,
				typename sprout::container_traits<InputRange>::value_type const& low,
				typename sprout::container_traits<InputRange>::value_type const& high
				)
			{
				return sprout::fixed::clamp_range_copy<Result>(sprout::begin(rng), sprout::end(rng), low, high);
			}
		}	// namespace fixed

		using sprout::range::fixed::clamp_range_copy;
	}	// namespace range
}	// namespace sprout

#endif	// #ifndef SPROUT_RANGE_ALGORITHM_FIXED_CLAMP_RANGE_COPY_HPP
