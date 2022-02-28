#include <iostream>
#include <string>

class Node
{
public:
	Node(std::string val) :
		mVal(val),
		mLeft(nullptr),
		mRight(nullptr)
	{
	}

	std::string mVal;
	Node* mLeft;
	Node* mRight;
};

int main()
{
	Node* a = new Node("a");
	Node* b = new Node("b");
	Node* c = new Node("c");
	Node* d = new Node("d");
	Node* e = new Node("e");

	a->mLeft = b;

	std::cout << a->mLeft->mVal << std::endl;

	return 0;
}