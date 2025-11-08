#ifndef DEFINES_FUNC_ATTRIBUTES_HPP_INCLUDED
#define DEFINES_FUNC_ATTRIBUTES_HPP_INCLUDED


/*
	For availability attributes 
 */
#if HAS_ATTRIBUTES == 1

#define NODISCARD [[nodiscard]]
#define NORETURN [[noreturn]]
#define MAYBE_UNUSED [[maybe_unused]]

#if DEPRECATED_VERBOSE == 1

#define DEPRECATED(str_msg) [[deprecated(str_msg)]]

#else
#define DEPRECATED [[deprecated]]

#endif /* DEPRECATED_VERBOSE */

#else

#define NODISCARD
#define NORETURN
#define MAYBE_UNUSED

#endif /* HAS_ATTRIBUTES */

#endif /* DEFINES_FUNC_ATTRIBUTES_HPP_INCLUDED */
