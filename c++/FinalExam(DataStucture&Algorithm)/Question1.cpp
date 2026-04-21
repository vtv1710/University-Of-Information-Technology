#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    char data;
    Node* next;
};

void insert(Node*& head, char value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void printList(Node* head) {
    if (!head) {
        cout << "Empty List" << endl;
        return;
    }
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

vector<int> findKthLeastFrequent(Node* head, int k) {
    unordered_map<char, int> freq;
    vector<int> indexes;
    Node* current = head;
    int index = 0;

    while (current) {
        freq[current->data]++;
        current = current->next;
    }

    vector<pair<int, char>> freqList;
    for (auto& p : freq) {
        freqList.push_back({ p.second, p.first });
    }

    sort(freqList.begin(), freqList.end());

    int targetFreq = freqList[k - 1].first;

    current = head;
    index = 0;     
    while (current) {
        if (freq[current->data] == targetFreq) {
            indexes.push_back(index);
        }
        current = current->next;
        index++;
    }

    return indexes;
}

Node* deleteNodes(Node* head, unordered_map<char, bool>& toDelete) 
{
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (toDelete[current->data]) {
            if (prev) {
                prev->next = current->next;
            }
            else {
                head = current->next;
            }
            delete current;
            current = (prev) ? prev->next : head;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    return head;
}

int main() {
    Node* head = nullptr;
    char ch;

    while (true) {
        cin >> ch;
        if (ch == '0') break;
        insert(head, ch);
    }

    int k;
    cin >> k;

    printList(head);

    vector<int> indexes = findKthLeastFrequent(head, k);
    for (int index : indexes) {
        cout << index << " ";
    }
    cout << endl;
    unordered_map<char, bool> toDelete;
    vector<int> kthFreqIndexes = findKthLeastFrequent(head, k);
    Node* newHead = deleteNodes(head, toDelete);
    printList(newHead);
    return 0;
}

