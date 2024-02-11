#ifndef STRING_OPERATIONS_HPP
# define STRING_OPERATIONS_HPP

#include <string>

class	StringOperations
{
public:
	static bool replaceOccurrences(const std::string &original, const std::string &search,
								const std::string &replace, std::string &result);
};

#endif
