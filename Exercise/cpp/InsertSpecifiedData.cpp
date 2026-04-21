#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;
};

// Hàm chèn một node vào đầu danh sách
void push(node** head_ref, int new_data)
{
    node* new_node = new node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = nullptr;
    if (*head_ref != nullptr)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

// Hàm chèn một node trước một node có giá trị cụ thể
void insertBefore(node** head_ref, node* next_node, int new_data)
{
    if (next_node == nullptr)
        return;

    node* new_node = new node();
    new_node->data = new_data;
    new_node->prev = next_node->prev;
    new_node->next = next_node;

    if (next_node->prev != nullptr)
        next_node->prev->next = new_node;
    else
        *head_ref = new_node;
    next_node->prev = new_node;
}

// Hàm in danh sách từ đầu đến cuối
void printForward(node* head)
{
    node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* getTail(node* head)
{
    if (head == nullptr)
        return nullptr;
    while (head->next != nullptr)
    {
        head = head->next;
    }
    return head;
}

// Hàm in danh sách từ cuối về đầu
void printBackward(node* tail)
{
    node* temp = getTail(tail);
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Hàm tìm node có giá trị cụ thể
node* findnode(node* head, int value)
{
    node* temp = head;
    while (temp != nullptr)
    {
        if (temp->data == value)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

int main()
{
    node* head = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        push(&head, a);
    }
    int x;
    cout << "Insert data afterL ";
    cin >> x;
    node* target_node = findnode(head, x);
    insertBefore(&head, target_node, 25);
    cout << "Insert data in reverse direction: ";
    printBackward(head);
    cout << "Insert data in correct direction: ";
    printForward(head);
}   