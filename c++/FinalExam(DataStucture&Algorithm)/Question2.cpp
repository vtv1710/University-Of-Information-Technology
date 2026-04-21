#include <iostream>
#include <string>
using namespace std;

struct Request {
    string clientID;
    string apiName;
    string connectionStatus;
    Request* next;
};

struct Node {
    char data;
    Node* next;
};


class Queue {
public:
    Request* front;
    Request* rear;

    Queue() {
        front = rear = nullptr;
    }

    void enqueue(string clientID, string apiName, string connectionStatus) {
        Request* newRequest = new Request{ clientID, apiName, connectionStatus, nullptr };
        if (rear) {
            rear->next = newRequest;
            rear = newRequest;
        }
        else {
            front = rear = newRequest;
        }
    }

    void removeDisconnectedClientRequests() {
        Request* current = front;
        Request* prev = nullptr;

        while (current) {
            if (current->connectionStatus == "disconnected") {
                if (prev) {
                    prev->next = current->next;
                }
                else {
                    front = current->next;
                }
                delete current;
                current = (prev) ? prev->next : front;
            }
            else {
                prev = current;
                current = current->next;
            }
        }
    }

    void printQueue() {
        Request* current = front;
        while (current) {
            cout << current->clientID << " " << current->apiName << " " << current->connectionStatus << " -> ";
            current = current->next;
        }
        cout << "null" << '\n';
    }
};

int main() {
    Queue queue;

    queue.enqueue("C2", "fA", "poor");
    queue.enqueue("C2", "fB", "poor");
    queue.enqueue("C3", "fX", "good");
    queue.enqueue("C4", "fY", "good");
    queue.enqueue("C5", "fZ", "good");
    queue.enqueue("C2", "fC", "disconnected");
    queue.printQueue();
    queue.removeDisconnectedClientRequests();
    queue.printQueue();
    return 0;
}