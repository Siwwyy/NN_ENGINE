#ifndef DEFINES_ASSERT_HPP_INCLUDED
#define DEFINES_ASSERT_HPP_INCLUDED



/*
	For assertion, bug reporting etc.
 */
#if HAS_ASSERTION == 1

#define report(str_msg) std::cout << "Error at line: " << __LINE__ << " In file: " << __FILE__  << " Message: " << str_msg << '\n';

#else

#define report(x) 

#endif /* ASSERTION */

#endif /* DEFINES_ASSERT_HPP_INCLUDED */