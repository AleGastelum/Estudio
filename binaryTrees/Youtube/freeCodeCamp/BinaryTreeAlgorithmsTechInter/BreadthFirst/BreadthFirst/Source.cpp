#include <iostream>
#include <string>
#include <queue>
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

void printVector(std::vector<std::string>& vector)
{
	for (auto value : vector)
	{
		std::cout << "Value: " << value << std::endl;
	}
}

std::vector<std::string> breadthFirstIterative(Node* root)
{
	if (root == nullptr)
	{
		return {};
	}

	std::queue<Node*> queue;
	queue.push(root);

	std::vector<std::string> results;

	while (queue.size() > 0)
	{
		Node* currentNode = queue.front();
		queue.pop();
		results.push_back(currentNode->mVal);

		if (currentNode->mLeft != nullptr)
		{
			queue.push(currentNode->mLeft);
		}

		if (currentNode->mRight != nullptr)
		{
			queue.push(currentNode->mRight);
		}
	}

	return results;
}

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

	std::cout << std::endl;

	std::vector<std::string> results = breadthFirstIterative(a);

	printVector(results);

	return 0;
}