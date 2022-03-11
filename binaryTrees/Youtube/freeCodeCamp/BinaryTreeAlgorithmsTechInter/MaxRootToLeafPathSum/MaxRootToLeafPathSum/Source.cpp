#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <limits>
#include <algorithm>

class Node
{
public:
	Node(int value)
		: mValue(value),
		mLeft(nullptr),
		mRight(nullptr)
	{

	}

	int mValue;
	Node* mLeft;
	Node* mRight;
};

void printVector(std::vector<int>& vector)
{
	for (auto element : vector)
	{
		std::cout << "Elemento: " << element << std::endl;
	}
}

int depthFirstRecursiveSolution(Node* root)
{
	if (root == nullptr)
	{
		return std::numeric_limits<int>::min();
	}

	if (root->mLeft == nullptr && root->mRight == nullptr)
	{
		return root->mValue;
	}

	int maxChildSum = std::max(depthFirstRecursiveSolution(root->mLeft), depthFirstRecursiveSolution(root->mRight));

	return root->mValue + maxChildSum;
}

int main()
{
	Node* a = new Node(5);
	Node* b = new Node(11);
	Node* c = new Node(3);
	Node* d = new Node(4);
	Node* e = new Node(2);
	Node* f = new Node(-1);

	a->mLeft = b;
	a->mRight = c;

	b->mLeft = d;
	b->mRight = e;

	c->mRight = f;

	int results = depthFirstRecursiveSolution(a);

	std::cout << "Max Sum: " << results;

	return 0;
}