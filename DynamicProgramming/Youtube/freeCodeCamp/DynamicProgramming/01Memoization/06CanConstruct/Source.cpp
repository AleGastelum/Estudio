#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Global variables
std::unordered_map<std::string, bool> foundConstructs;
//std::vector<std::string> stringsVector = { "ab", "abc", "cd", "def", "abcd" }; // true
//std::vector<std::string> stringsVector = { "bo", "rd", "ate", "t", "ska", "sk", "boar" }; // false
//std::vector<std::string> stringsVector = { "a", "p", "ent", "enter", "ot", "o", "t" }; // true
std::vector<std::string> stringsVector = { "e", "ee", "eee", "eeee", "eeeee", "eeeeee" }; // false

// Main functions
bool canConstruct(std::string targetWord);
//bool canConstruct(std::string targetWord, std::string currentString = "");

int main()
{
	//bool wasConstructed = canConstruct("ab");
	//bool wasConstructed = canConstruct("skateboard");
	//bool wasConstructed = canConstruct("enterapotentpot");
	bool wasConstructed = canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef");

	if (wasConstructed)
	{
		std::cout << "Word can be constructed" << std::endl;
	}
	else
	{
		std::cout << "Word can not be constructed" << std::endl;
	}

	return 0;
}

// Video solution
bool canConstruct(std::string targetWord)
{
	if (foundConstructs.count(targetWord))
	{
		return foundConstructs[targetWord];
	}

	if (targetWord == "")
	{
		return true;
	}

	for (std::string word : stringsVector)
	{
		int wordIndex = targetWord.find(word);

		if (wordIndex == 0)
		{
			std::string cutWord = targetWord.substr(word.size());

			if (canConstruct(cutWord))
			{
				foundConstructs[targetWord] = true;
				return true;
			}
		}
	}

	foundConstructs[targetWord] = false;
	return false;
}

// My solution (i think this code fails when an empty targetWord is send as an input)
// // Overall esta solucion esta medio culerona, no usarla
//bool canConstruct(std::string targetWord, std::string currentString)
//{
//	if (foundConstructs.count(currentString))
//	{
//		return foundConstructs[currentString];
//	}
//
//	if (targetWord == currentString)
//	{
//		return true;
//	}
//
//	if (targetWord.find(currentString) != 0)
//	{
//		return false;
//	}
//
//	for (std::string word : stringsVector)
//	{
//		if (canConstruct(targetWord, currentString + word))
//		{
//			foundConstructs[currentString] = true;
//			return true;
//		}
//	}
//
//	foundConstructs[currentString] = false;
//
//	return false;
//}