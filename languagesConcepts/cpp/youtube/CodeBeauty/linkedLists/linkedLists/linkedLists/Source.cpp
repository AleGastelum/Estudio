#include <iostream>

class Node {
public:
	int Value;
	Node* Next;
};

void printList(Node* node)
{
	while (node != nullptr)
	{
		std::cout << node->Value << std::endl;
		node = node->Next;
	}
}

int main()
{
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->Value = 1;
	head->Next = second;

	second->Value = 2;
	second->Next = third;

	third->Value = 3;
	third->Next = nullptr;

	printList(head);

	return 0;
}