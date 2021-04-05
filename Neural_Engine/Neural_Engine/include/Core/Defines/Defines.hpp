#ifndef DEFINES_HPP_INCLUDED
#define DEFINES_HPP_INCLUDED


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


/*
	For assertion, bug reporting etc.
 */
#if ASSERTION == 1

#define report(str_msg) std::cout << "Error at line: " << __LINE__ << " In file: " << __FILE__  << " Message: " << str_msg << '\n';

#else

#define report(x) 

#endif /* ASSERTION */


#endif /* DEFINES_HPP_INCLUDED */