#ifndef FILE_OPERATIONS_HPP
# define FILE_OPERATIONS_HPP

#include <iostream>
#include <fstream>
#include <string>

class	FileOperations
{
public:
	static int	readInputFile(const char *filename, std::string &fileContent);
	static std::string	generateOutputFileName(const std::string &inputFilename);
	static int	writeOutputFile(const std::string &filename, const std::string &content);
};

#endif
