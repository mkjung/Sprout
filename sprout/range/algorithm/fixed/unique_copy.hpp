#ifndef SPROUT_RANGE_ALGORITHM_FIXED_UNIQUE_COPY_HPP
#define SPROUT_RANGE_ALGORITHM_FIXED_UNIQUE_COPY_HPP

#include <sprout/config.hpp>
#include <sprout/container/traits.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/algorithm/fixed/result_of.hpp>
#include <sprout/algorithm/fixed/unique_copy.hpp>

namespace sprout {
	namespace range {
		namespace fixed {
			//
			// unique_copy
			//
			template<typename InputRange, typename Result, typename BinaryPredicate>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Result>::type
			unique_copy(InputRange const& rng, Result const& result, BinaryPredicate pred) {
				return sprout::fixed::unique_copy(sprout::begin(rng), sprout::end(rng), result, pred);
			}
			template<typename InputRange, typename Result>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Result>::type
			unique_copy(InputRange const& rng, Result const& result) {
				return sprout::fixed::unique_copy(sprout::begin(rng), sprout::end(rng), result);
			}

			template<typename Result, typename InputRange, typename BinaryPredicate>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Result>::type
			unique_copy(InputRange const& rng, BinaryPredicate pred) {
				return sprout::fixed::unique_copy<Result>(sprout::begin(rng), sprout::end(rng), pred);
			}
			template<typename Result, typename InputRange>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Result>::type
			unique_copy(InputRange const& rng) {
				return sprout::fixed::unique_copy<Result>(sprout::begin(rng), sprout::end(rng));
			}
		}	// namespace fixed

		using sprout::range::fixed::unique_copy;
	}	// namespace range
}	// namespace sprout

#endif	// #ifndef SPROUT_RANGE_ALGORITHM_FIXED_UNIQUE_COPY_HPP
