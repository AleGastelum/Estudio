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

private:
	std::string mVal;
	Node* mLeft;
	Node* mRight;
};

int main()
{
	Node a = Node("a");
	Node b = Node("b");
	Node c = Node("c");
	Node d = Node("d");
	Node e = Node("e");

	return 0;
}