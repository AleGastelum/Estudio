#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

class Node 
{
public:
	Node(int val)
		: mVal(val),
		mLeft(nullptr),
		mRight(nullptr)
	{

	}

	int mVal;
	Node* mLeft;
	Node* mRight;
};

int treeSumDepthFirstRecursive(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return root->mVal + treeSumDepthFirstRecursive(root->mLeft) + treeSumDepthFirstRecursive(root->mRight);
}

int treeSumDepthFirstIterative(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	std::stack<Node*> stack;
	stack.push(root);

	int sum = 0;

	while (stack.size() > 0)
	{
		Node* currentNode = stack.top();
		stack.pop();

		sum += currentNode->mVal;

		if (currentNode->mRight != nullptr)
		{
			stack.push(currentNode->mRight);
		}

		if (currentNode->mLeft != nullptr)
		{
			stack.push(currentNode->mLeft);
		}
	}

	return sum;
}

int treeSumBreadthFirstIterative(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	std::queue<Node*> queue;
	queue.push(root);

	int sum = 0;

	while (queue.size() > 0)
	{
		Node* currentNode = queue.front();
		queue.pop();

		sum += currentNode->mVal;

		if (currentNode->mLeft != nullptr)
		{
			queue.push(currentNode->mLeft);
		}

		if (currentNode->mRight != nullptr)
		{
			queue.push(currentNode->mRight);
		}
	}

	return sum;
}

int main()
{
	Node* a = new Node(3);
	Node* b = new Node(11);
	Node* c = new Node(4);
	Node* d = new Node(4);
	Node* e = new Node(2);
	Node* f = new Node(1);

	a->mLeft = b;
	a->mRight = c;

	b->mLeft = d;
	b->mRight = e;

	c->mRight = f;

	//int sum = treeSumDepthFirstRecursive(a);
	//int sum = treeSumDepthFirstIterative(a);
	int sum = treeSumBreadthFirstIterative(a);

	std::cout << "Sum result: " << sum << std::endl;

	return 0;
}