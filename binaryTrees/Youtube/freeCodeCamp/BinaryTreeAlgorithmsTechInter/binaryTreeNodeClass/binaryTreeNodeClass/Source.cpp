#include <iostream>
#include <string>
#include <stack>
#include <vector>

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
	Node* f = new Node("f");

	a->mLeft = b;
	a->mRight = c;

	b->mLeft = d;
	b->mRight = e;

	c->mRight = f;

	return 0;
}