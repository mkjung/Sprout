#ifndef SPROUT_RANGE_ADAPTOR_PHASE_SPECTRUM_HPP
#define SPROUT_RANGE_ADAPTOR_PHASE_SPECTRUM_HPP

#include <type_traits>
#include <sprout/config.hpp>
#include <sprout/container/traits.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/iterator/transform_iterator.hpp>
#include <sprout/iterator/phase_spectrum_iterator.hpp>
#include <sprout/range/adaptor/detail/adapted_range_default.hpp>
#include <sprout/type_traits/lvalue_reference.hpp>
#include <sprout/utility/forward.hpp>
#include <sprout/utility/lvalue_forward.hpp>
#include <sprout/numeric/dft/phase_spectrum_value.hpp>

namespace sprout {
	namespace adaptors {
		//
		// phase_spectrum_range
		//
		template<typename Range>
		class phase_spectrum_range
			: public sprout::adaptors::detail::adapted_range_default<
				Range,
				sprout::transform_iterator<
					sprout::phase_value<typename sprout::container_traits<Range>::value_type>,
					typename sprout::container_traits<Range>::iterator
				>
			>
		{
		public:
			typedef sprout::adaptors::detail::adapted_range_default<
				Range,
				sprout::transform_iterator<
					sprout::phase_value<typename sprout::container_traits<Range>::value_type>,
					typename sprout::container_traits<Range>::iterator
				>
			> base_type;
			typedef typename base_type::range_type range_type;
			typedef typename base_type::iterator iterator;
			typedef typename base_type::value_type value_type;
		public:
			phase_spectrum_range() = default;
			phase_spectrum_range(phase_spectrum_range const&) = default;
			explicit SPROUT_CONSTEXPR phase_spectrum_range(range_type& range)
				: base_type(
					iterator(sprout::begin(range), typename iterator::functor_type()),
					iterator(sprout::end(range), typename iterator::functor_type())
					)
			{}
		};

		//
		// phase_spectrum_forwarder
		//
		class phase_spectrum_forwarder {};

		//
		// phase_spectrum
		//
		namespace {
			SPROUT_STATIC_CONSTEXPR sprout::adaptors::phase_spectrum_forwarder phase_spectrum = {};
		}	// anonymous-namespace

		//
		// operator|
		//
		template<typename Range>
		inline SPROUT_CONSTEXPR sprout::adaptors::phase_spectrum_range<
			typename std::remove_reference<typename sprout::lvalue_reference<Range>::type>::type
		>
		operator|(Range&& lhs, phase_spectrum_forwarder) {
			return sprout::adaptors::phase_spectrum_range<
				typename std::remove_reference<typename sprout::lvalue_reference<Range>::type>::type
			>(
				sprout::lvalue_forward<Range>(lhs)
				);
		}
	}	// namespace adaptors

	//
	// container_construct_traits
	//
	template<typename Range>
	struct container_construct_traits<sprout::adaptors::phase_spectrum_range<Range> >
		: public sprout::container_construct_traits<typename sprout::adaptors::phase_spectrum_range<Range>::base_type>
	{};
}	// namespace sprout

#endif	// #ifndef SPROUT_RANGE_ADAPTOR_PHASE_SPECTRUM_HPP