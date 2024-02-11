#include "../include/FileOperations.hpp"

int	FileOperations::readInputFile(const char *filename, std::string &fileContent)
{
	std::ifstream inputFileStream(filename);
	if (!inputFileStream.is_open())
	{
		std::cerr << "Error: Failed to open input file!" << std::endl;
		return (1);
	}
	std::string line;
	while (std::getline(inputFileStream, line))
	{
		fileContent += line + "\n";
	}
	inputFileStream.close();
	return (0);
}

std::string	FileOperations::generateOutputFileName(const std::string &inputFilename)
{
	std::size_t dot = inputFilename.find_last_of('.');
	std::string outputFilename;
	if (dot != std::string::npos) {
		outputFilename = inputFilename.substr(0, dot);
	} else {
		outputFilename = inputFilename;
	}
	outputFilename += ".replace";
	return (outputFilename);
}

int FileOperations::writeOutputFile(const std::string &filename, const std::string &content)
{
	std::ofstream outputFileStream(filename.c_str());
	if (!outputFileStream.is_open()) {
		std::cerr << "Error: Failed to open output file!" << std::endl;
		return (1);
	}
	outputFileStream << content;
	outputFileStream.close();
	return (0);
}
