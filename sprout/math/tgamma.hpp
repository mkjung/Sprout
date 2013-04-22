#ifndef SPROUT_MATH_TGAMMA_HPP
#define SPROUT_MATH_TGAMMA_HPP

#include <cstddef>
#include <limits>
#include <type_traits>
#include <sprout/config.hpp>
#include <sprout/math/detail/config.hpp>
#include <sprout/math/detail/float_compute.hpp>
#include <sprout/math/factorial.hpp>
#include <sprout/math/iround.hpp>
#include <sprout/math/trunc.hpp>
#include <sprout/algorithm/clamp.hpp>
#include <sprout/type_traits/enabler_if.hpp>
#include HDR_ALGORITHM_MIN_MAX_SSCRISK_CEL_OR_SPROUT

namespace sprout {
	namespace math {
		namespace detail {
			template<typename T>
			inline SPROUT_CONSTEXPR T
			tgamma_impl_y(T w) {
				return ((((((((((((
					-1.99542863674e-7 * w + 1.337767384067e-6) * w
					- 2.591225267689e-6) * w - 1.7545539395205e-5) * w
					+ 1.45596568617526e-4) * w - 3.60837876648255e-4) * w
					- 8.04329819255744e-4) * w + 0.008023273027855346) * w
					- 0.017645244547851414) * w - 0.024552490005641278) * w
					+ 0.19109110138763841) * w - 0.233093736421782878) * w
					- 0.422784335098466784) * w + 0.99999999999999999
					;
			}
			template<typename T>
			inline SPROUT_CONSTEXPR T
			tgamma_impl_t_pos(T x, std::size_t n, std::size_t last) {
				return last - n == 1
					? x - static_cast<T>(n)
					: sprout::math::detail::tgamma_impl_t_pos(x, n, n + (last - n) / 2)
						* sprout::math::detail::tgamma_impl_t_pos(x, n + (last - n) / 2, last)
					;
			}
			template<typename T>
			inline SPROUT_CONSTEXPR T
			tgamma_impl_t_neg(T x, std::size_t n, std::size_t last) {
				return last - n == 1
					? x + static_cast<T>(n)
					: sprout::math::detail::tgamma_impl_t_neg(x, n, n + (last - n) / 2)
						* sprout::math::detail::tgamma_impl_t_neg(x, n + (last - n) / 2, last)
					;
			}
			template<typename T>
			inline SPROUT_CONSTEXPR T
			tgamma_impl_t_pos_rec(T x, std::size_t n, std::size_t last) {
				return last - n == 1
					? T(1) / (x - static_cast<T>(n))
					: sprout::math::detail::tgamma_impl_t_pos_rec(x, n, n + (last - n) / 2)
						* sprout::math::detail::tgamma_impl_t_pos_rec(x, n + (last - n) / 2, last)
					;
			}
			template<typename T>
			inline SPROUT_CONSTEXPR T
			tgamma_impl_t_neg_rec(T x, std::size_t n, std::size_t last) {
				return last - n == 1
					? T(1) / (x + static_cast<T>(n))
					: sprout::math::detail::tgamma_impl_t_neg_rec(x, n, n + (last - n) / 2)
						* sprout::math::detail::tgamma_impl_t_neg_rec(x, n + (last - n) / 2, last)
					;
			}
			template<typename T>
			inline SPROUT_CONSTEXPR T
			tgamma_impl_2_pos(T x, T y, T t) {
				return t == 0 ? std::numeric_limits<T>::infinity()
					: (x - T(1)) / y / t
					;
			}
			template<typename T>
			inline SPROUT_CONSTEXPR T
			tgamma_impl_2_neg(T x, T y, T t) {
				return t == 0 ? T(0)
					: T(1) / y * t
					;
			}
			template<typename T>
			inline SPROUT_CONSTEXPR T
			tgamma_impl_1(T x, int n) {
				return n == 1 ? (x - T(1)) / sprout::math::detail::tgamma_impl_y(x - (n + 2))
					: n == 0 ? T(1) / sprout::math::detail::tgamma_impl_y(x - (n + 2))
					: n == static_cast<int>(sprout::math::factorial_limit<T>())
						? sprout::math::detail::tgamma_impl_2_pos(x, sprout::math::detail::tgamma_impl_y(x - (n + 2)), sprout::math::detail::tgamma_impl_t_pos_rec(x, 2, n + 1))
					: n == -static_cast<int>(sprout::math::factorial_limit<T>())
//						? sprout::math::detail::tgamma_impl_2_neg(x, sprout::math::detail::tgamma_impl_y(x - (n + 2)), sprout::math::detail::tgamma_impl_t_neg_rec(x, 0, -n))
						? T(1) / sprout::math::detail::tgamma_impl_y(x - (n + 2)) * sprout::math::detail::tgamma_impl_t_neg_rec(x, 0, -n)
					: n > 1 ? (x - T(1)) / sprout::math::detail::tgamma_impl_y(x - (n + 2)) * sprout::math::detail::tgamma_impl_t_pos(x, 2, n + 1)
					: T(1) / sprout::math::detail::tgamma_impl_y(x - (n + 2)) / sprout::math::detail::tgamma_impl_t_neg(x, 0, -n)
					;
			}
			template<typename T>
			inline SPROUT_CONSTEXPR T
			tgamma_impl(T x) {
				return sprout::math::detail::tgamma_impl_1(
					x,
					sprout::clamp(
						sprout::math::iround(x - T(2)),
						-static_cast<int>(sprout::math::factorial_limit<T>()),
						static_cast<int>(sprout::math::factorial_limit<T>())
						)
					);
			}

			template<
				typename FloatType,
				typename sprout::enabler_if<std::is_floating_point<FloatType>::value>::type = sprout::enabler
			>
			inline SPROUT_CONSTEXPR FloatType
			tgamma(FloatType x) {
				typedef typename sprout::math::detail::float_compute<FloatType>::type type;
				return x == 0 ? std::numeric_limits<FloatType>::infinity()
					: x == -std::numeric_limits<FloatType>::infinity() ? std::numeric_limits<FloatType>::quiet_NaN()
					: x == std::numeric_limits<FloatType>::infinity() ? std::numeric_limits<FloatType>::infinity()
					: x < 0 && x == std::trunc(x) ? std::numeric_limits<FloatType>::quiet_NaN()
					: static_cast<FloatType>(sprout::math::detail::tgamma_impl(static_cast<type>(x)))
					;
			}

			template<
				typename IntType,
				typename sprout::enabler_if<std::is_integral<IntType>::value>::type = sprout::enabler
			>
			inline SPROUT_CONSTEXPR double
			tgamma(IntType x) {
				return sprout::math::detail::tgamma(static_cast<double>(x));
			}
		}	// namespace detail

		using NS_SPROUT_MATH_DETAIL::tgamma;
	}	// namespace math

	using sprout::math::tgamma;
}	// namespace sprout

#endif	// #ifndef SPROUT_MATH_TGAMMA_HPP
