#include <cstdio>

struct Node {
    int value;
    Node* next;
};

int main() {
    int n, m;
    if (std::scanf("%d%d", &n, &m) != 2) {
        return 0;
    }

    Node* head = new Node{1, nullptr};
    Node* tail = head;
    for (int value = 2; value <= n; ++value) {
        tail->next = new Node{value, nullptr};
        tail = tail->next;
    }
    tail->next = head;

    // previous always precedes the node where counting starts.
    Node* previous = tail;
    while (previous->next != previous) {
        for (int count = 1; count < m; ++count) {
            previous = previous->next;
        }
        Node* removed = previous->next;
        std::printf("%d\n", removed->value);
        previous->next = removed->next;
        delete removed;
    }
    std::printf("%d\n", previous->value);
    delete previous;
    return 0;
}
