#ifndef SPROUT_AUTO_CONFIG_HPP
#define SPROUT_AUTO_CONFIG_HPP

#include <boost/config.hpp>

//
// SPROUT_CONFIG_DISABLE_CONSTEXPR
//
#ifndef SPROUT_CONFIG_DISABLE_CONSTEXPR
#	ifdef BOOST_NO_CONSTEXPR
#		if !defined(__GNUC__) \
			|| defined(__GNUC__) && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 6) || !defined(__GXX_EXPERIMENTAL_CXX0X__))
#			define SPROUT_CONFIG_DISABLE_CONSTEXPR
#		endif
#	endif	// #ifdef BOOST_NO_CONSTEXPR
#endif	// #ifndef SPROUT_CONFIG_DISABLE_CONSTEXPR

//
// SPROUT_CONFIG_DISABLE_NOEXCEPT
//
#ifndef SPROUT_CONFIG_DISABLE_NOEXCEPT
#	ifdef BOOST_NO_NOEXCEPT
#		if !defined(__GNUC__) \
			|| defined(__GNUC__) && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 6) || !defined(__GXX_EXPERIMENTAL_CXX0X__))
#			define SPROUT_CONFIG_DISABLE_NOEXCEPT
#		endif
#	endif	// #ifdef BOOST_NO_NOEXCEPT
#endif	// #ifndef SPROUT_CONFIG_DISABLE_NOEXCEPT

//
// SPROUT_CONFIG_USE_SSCRISK_CEL
//

//
// SPROUT_CONFIG_SUPPORT_TEMPORARY_CONTAINER_ITERATION
//
#ifndef SPROUT_CONFIG_SUPPORT_TEMPORARY_CONTAINER_ITERATION
#	define SPROUT_CONFIG_SUPPORT_TEMPORARY_CONTAINER_ITERATION
#endif	// #ifndef SPROUT_CONFIG_SUPPORT_TEMPORARY_CONTAINER_ITERATION

#include <sprout/config.hpp>

#endif	// #ifndef SPROUT_AUTO_CONFIG_HPP
