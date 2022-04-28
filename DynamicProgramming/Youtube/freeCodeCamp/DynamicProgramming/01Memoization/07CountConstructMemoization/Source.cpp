#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

enum RESULTS
{
	CANNOT_CONSTRUCT,
	CAN_CONSTRUCT
};

enum DEFAULTS
{
	NO_RESULTS_YET
};

// Global variables
std::unordered_map<std::string, int> foundConstructs;
std::vector<std::string> wordsVector = { "purp", "p", "ur", "le", "purpl" }; // 2
//std::vector<std::string> wordsVector = { "ab", "abc", "cd", "def", "abcd" }; // 1
//std::vector<std::string> wordsVector = { "bo", "rd", "ate", "t", "ska", "sk", "boar" }; // 0
//std::vector<std::string> wordsVector = { "a", "p", "ent", "enter", "ot", "o", "t" }; // 4
//std::vector<std::string> wordsVector = { "e", "ee", "eee", "eeee", "eeeee", "eeeeee" }; // 0

// Main functions
int canConstruct(std::string targetWord);

int main()
{
	int resultsFound = canConstruct("purple");
	//int resultsFound= canConstruct("ab");
	//int resultsFound = canConstruct("skateboard");
	//int resultsFound= canConstruct("enterapotentpot");
	//int resultsFound = canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef");

	std::cout << "Results found: " << resultsFound << std::endl;

	return 0;
}

// My attempt
int canConstruct(std::string targetWord)
{
	if (foundConstructs.count(targetWord))
	{
		return foundConstructs[targetWord];
	}

	if (targetWord == "")
	{
		return CAN_CONSTRUCT;
	}

	int solutionsFound = NO_RESULTS_YET;

	for (std::string word : wordsVector)
	{
		if (targetWord.find(word) == 0)
		{
			std::string suffix = targetWord.substr(word.size());

			solutionsFound += canConstruct(suffix);
		}
	}

	foundConstructs[targetWord] = solutionsFound;
	return solutionsFound;
}