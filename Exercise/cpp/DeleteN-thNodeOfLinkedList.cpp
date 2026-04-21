#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

typedef struct Node node;

node *makenode(int x)
{
	node* newnode = new Node();
	newnode->data = x;
	newnode->next = nullptr;
	return newnode;
}

void scan(node *head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

void delet(node *&head, int n)
{
	if (head == nullptr) return;
	node *prev = nullptr, *end = head;
	for (int i = 0; i < n + 1; i++)
	{
		if (end == nullptr) return;
		end = end->next;
	}
	prev = head;
	while (end != nullptr)
	{
		prev = prev->next;
		end = end->next;
	}
	if (prev == head && n == 0)
	{
		node* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	node* temp = prev->next;
	prev->next = temp->next;
	delete temp;
}

void pushback(node *&head, int x) 
{
	node *temp = head;
	node *newnode = makenode(x);
	if (head == nullptr) {
		head = newnode;
		return;
	}
	while (temp->next != nullptr) 
	{
		temp = temp->next;
	}
	temp->next = newnode;
}
int main()
{
	node *head = nullptr;
	int n, x, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		pushback(head, x);
	}
	cin >> m;
	delet(head, m);
	scan(head);
	return 0;
}