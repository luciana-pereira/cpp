#include "../include/FileOperations.hpp"
#include "../include/StringOperations.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string inputFilename = argv[1];
	std::string searchString = argv[2];
	std::string replacementString = argv[3];
	std::string fileContent;
	if (FileOperations::readInputFile(inputFilename.c_str(), fileContent) != 0)
	{
		return (1);
	}
	std::string modifiedContent;
	if (!StringOperations::replaceOccurrences(fileContent, searchString, replacementString, modifiedContent)) {
		std::cerr << "Error: String '" << searchString << "' not found in the file." << std::endl;
		return (1);
	}
	std::string outputFilename = FileOperations::generateOutputFileName(inputFilename);
	if (FileOperations::writeOutputFile(outputFilename, modifiedContent) != 0)
	{
		return (1);
	}
	std::cout << "Replacement successful. Output written to: " << outputFilename << std::endl;
	return (0);
}
