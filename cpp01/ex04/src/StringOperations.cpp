#include "../include/StringOperations.hpp"

bool	StringOperations::replaceOccurrences(const std::string &original, const std::string &search, 
											const std::string &replace, std::string &result)
{
	std::size_t	index;
	std::size_t	foundIndex;
	bool	found;

	index = 0;
	found = false;
	while ((foundIndex = original.find(search, index)) != std::string::npos)
	{
		found = true;
		result += original.substr(index, foundIndex - index);
		result += replace;
		index = foundIndex + search.length();
	}
	result += original.substr(index);
	return (found);
}
