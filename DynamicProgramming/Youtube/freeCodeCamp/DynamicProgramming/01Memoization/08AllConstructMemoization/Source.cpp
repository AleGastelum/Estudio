#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

enum RESULTS
{
	CONSTRUCT_NOT_FOUND,
	CONSTRUCT_FOUND
};

// Global variables
std::unordered_map<std::string, std::vector<std::vector<std::string>>> finishedRoutes2;
std::unordered_map<std::string, int> finishedRoutes;
std::vector<std::vector<std::string>> foundResults;
//std::vector<std::string> wordsVector = { "purp", "p", "ur", "le", "purpl" };
// [["purple", "le"], ["p", "ur", "p", "le"]

std::vector<std::string> wordsVector = { "ab", "abc", "cd", "def", "abcd", "ef", "c" };
// [["ab", "cd", "ef"], ["ab", "c", "def"], ["abc", "def"], ["abcd", "ef"]]

//std::vector<std::string> wordsVector = { "bo", "rd", "ate", "t", "ska", "sk", "boar" };
//[]

//std::vector<std::string> wordsVector = { "a", "aa", "aaa", "aaaa", "aaaaa" };
//[]

// Main functions
void printResults(std::vector<std::vector<std::string>> vector);
std::vector<std::vector<std::string>> allConstruct(std::string targetWord);
int allConstructMyAttempt(std::string targetWord, std::vector<std::string> currentConstruct = {});

int main()
{
	//allConstructMyAttempt("purple");
	//allConstructMyAttempt("abcdef");
	//allConstructMyAttempt("skateboard");
	//allConstructMyAttempt("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef");

	std::vector<std::vector<std::string>> results;
	//results = allConstruct("purple");
	results = allConstruct("abcdef");
	//results = allConstruct("skateboard");
	//results = allConstruct("aaaaaaaaaaaaaaaaaaaaaaaaaz");

	printResults(results);

	return 0;
}

void printResults(std::vector<std::vector<std::string>> vector)
{
	std::cout << "[" << std::endl;
	for (std::vector<std::string> result : vector)
	{
		std::cout << "[ ";

		for (auto element : result)
		{
			std::cout << element << ", ";
		}

		std::cout << "]" << std::endl;
	}

	std::cout << "]" << std::endl;
}

// Solucion del video
// NOTA: Ya van dos problemas donde al tratar de construir un resultado conforme voy explorando nodos de bajada
// (el currentConstruct), se complica de mas el problema. Lo mejor es llegar hasta el caso base sin estar creando
// resultados, y ya que llegues a ese caso base, de subida comenzar a guardar valores o resultados, como en el ejemplo
// del video.
std::vector<std::vector<std::string>> allConstruct(std::string targetWord)
{
	if (finishedRoutes2.count(targetWord))
	{
		return finishedRoutes2[targetWord];
	}

	if (targetWord == "")
	{
		return { {} };
	}

	std::vector<std::vector<std::string>> result = {};

	for (std::string word : wordsVector)
	{
		if (targetWord.find(word) == 0)
		{
			std::string suffix = targetWord.substr(word.size());

			std::vector<std::vector<std::string>> currentResults = allConstruct(suffix);

			for (std::vector<std::string> currentResult : currentResults)
			{
				currentResult.push_back(word);
				result.push_back(currentResult);
			}
		}
	}

	finishedRoutes2[targetWord] = result;

	return result;
}

// My attempt (funciona pero la memoizacion no es la mejor, cuando se encuentra un caso donde no se encontro respuesta, se brinca correctamente todoss esos casos, pero, si se bajo por una ruta donde se encontro un resultado, te obliga a recalcular dicho resultado
// lo ideal es que almacenara los resultados encontrados para regresar dicho valor en lugar de recalcularlo, pero pues como los casos donde no se encontro respuesta si son brincados (que son la mayoria), por eso sigue siendo capaz de resolver todos los test cases
// en este archivo)
int allConstructMyAttempt(std::string targetWord, std::vector<std::string> currentConstruct)
{
	if (finishedRoutes.count(targetWord) && finishedRoutes[targetWord] == CONSTRUCT_NOT_FOUND)
	{
		return CONSTRUCT_NOT_FOUND;
	}

	if (targetWord == "")
	{
		foundResults.push_back(currentConstruct);
		return CONSTRUCT_FOUND;
	}

	int wasResultFound = CONSTRUCT_NOT_FOUND;

	for (std::string word : wordsVector)
	{
		if (targetWord.find(word) == 0)
		{
			std::string suffix = targetWord.substr(word.length());
			currentConstruct.push_back(word);
			wasResultFound = allConstructMyAttempt(suffix, currentConstruct);
			currentConstruct.pop_back();
		}
	}

	finishedRoutes[targetWord] = wasResultFound;

	return CONSTRUCT_NOT_FOUND;
}