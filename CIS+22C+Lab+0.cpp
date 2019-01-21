#include <iostream>

using namespace std;

template <typename T>
class Node
{ public:
    T data;
    Node* next;
    Node() { next = NULL; data = 0; }
    Node(T d) { next = NULL; data = d; }
};

template <typename T>
class LinkedList {
  public:
    Node<T>* head;
    Node<T>* tail;
    int count;
    LinkedList() {
        head = NULL;
        tail = NULL;
        count = 0;
    }
    void PrintAll() {
        Node<T>* current_node = head;
        std::cout << "There are " << count << " nodes in this list." << std::endl;
        while(current_node != NULL) {
            std::cout << current_node->data << std::endl;
            current_node = current_node->next;
        }
    }
    void ListInsertAfter(Node<T>* node, Node<T>* new_node) {
        if (count == 0) {
            head = new_node;
            tail = new_node;
        } else if (node == tail) {
            node->next = new_node;
            tail = new_node;
        } else {
            new_node->next = node->next;
            node->next = new_node;
        }
        count++;
    }
    void ListRemoveAfter(Node<T>* node) {
        if (node == NULL && head != NULL) {
            head = head->next;
            if (head == NULL) {
                tail = NULL;
            }
        } else if (node->next != NULL) {
            node->next = node->next->next;
            if (node->next == NULL) {
                tail = node;
            }
        }
        count--;
    }
};

int main() {
    Node<int> n1(1);
    Node<int> n2(2);
    Node<int> n3(3);

    LinkedList<int> int_list;

    std::cout << "Inserting " << n1.data  << " after " << "NULL" << std::endl;
    int_list.ListInsertAfter(NULL, &n1);
    std::cout << "Inserting " << n2.data  << " after " << n1.data << std::endl;
    int_list.ListInsertAfter(&n1, &n2);
    std::cout << "Inserting " << n3.data  << " after " << n2.data << std::endl;
    int_list.ListInsertAfter(&n2, &n3);
    int_list.PrintAll();

    std::cout << "Removing node after " << n1.data << std::endl;
    int_list.ListRemoveAfter(&n1);
    int_list.PrintAll();
    std::cout << "Removing node after " << n1.data << std::endl;
    int_list.ListRemoveAfter(&n1);
    int_list.PrintAll();
    std::cout << "Removing first node  "<< std::endl;
    int_list.ListRemoveAfter(NULL);
    int_list.PrintAll();


    Node<string> s1("a");
    Node<string> s2("b");

    LinkedList<string> string_list;
    std::cout << "Inserting " << s1.data  << " after " << "NULL" << std::endl;
    string_list.ListInsertAfter(NULL, &s1);
    std::cout << "Inserting " << s2.data  << " after " << s1.data << std::endl;
    string_list.ListInsertAfter(&s1, &s2);
    string_list.PrintAll();

    std::cout << "Removing node after " << s1.data << std::endl;
    string_list.ListRemoveAfter(&s1);
    string_list.PrintAll();
    std::cout << "Removing node after "<< s1.data<<std::endl;
    string_list.ListRemoveAfter(NULL);
    string_list.PrintAll();

    std::cout << "Done!";
    return 0;
}
/*
Inserting 1 after NULL
Inserting 2 after 1
Inserting 3 after 2
There are 3 nodes in this list.
1
2
3
Removing node after 1
There are 2 nodes in this list.
1
3
Removing node after 1
There are 1 nodes in this list.
1
Removing first node
There are 0 nodes in this list.
Inserting a after NULL
Inserting b after a
There are 2 nodes in this list.
a
b
Removing node after a
There are 1 nodes in this list.
a
Removing node after a
There are 0 nodes in this list.
Done!
Process returned 0 (0x0)   execution time : 0.079 s
Press any key to continue.
*/
