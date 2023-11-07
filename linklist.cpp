#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node* next;

    Node(int value) : val(value), next(nullptr) {}

    void print_node()
    {
        cout << "[ ADD: " << this << ", val: " << val << ", next: " << next << " ]" << endl;
    }

    //výpis celého seznamu
    void print_LL() {
        Node* current = this;
        while (current != nullptr)
        {
            current->print_node();
            current = current->next;
        }
    }

    //přidá jeden prvek na konec seznamu
    void push_back_val(int val) {
        Node* new_node = new Node(val);
        new_node->next = nullptr;

        if (this == nullptr)
        {
            *this = *new_node;
            return;
        }

        Node* current = this;
        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = new_node;
    }

    //vloží prvek na určenou pozici v seznamu
    void insert_val(int idx, int val) {
        Node* new_node = new Node(val);

        if (idx == 0)
        {
            new_node->next = this;
            *this = *new_node;
            return;
        }

        //pokud je pozice jinde, hledáme pozici a vkládáme nový uzel    
        Node* current = this;
        int count = 0;
        while (current != nullptr)
        {
            if (count == idx - 1)
            {
                new_node->next = current->next;
                current->next = new_node;
                return;
            }
            current = current->next;
            count++;
        }
    }

    //přetížení operátoru
    Node* operator[](int index) {
        Node* current = this;
        int count = 0;
        while (current != nullptr)
        {
            if (count == index)
            {
                return current;
            }
            current = current->next;
            count++;
        }
        return nullptr;
    }

    //smazání uzlu na dané pozici
    void delete_node(int idx) {
        if (idx == 0)
        {
            Node* next_node = next;
            delete this;
            *this = *next_node;
            return;
        }

        Node* current = this;
        int count = 0;
        while (current != nullptr)
        {
            if (count == idx - 1)
            {
                Node* node_to_delete = current->next;
                current->next = node_to_delete->next;
                delete node_to_delete;
                return;
            }
            current = current->next;
            count++;
        }
    }
};

int main()
{
    Node LL(0);             //vytvoření instance seznamu s prvním prvkem 0
    //další prky na konec seznamu
    LL.push_back_val(1);
    LL.push_back_val(2);
    LL.push_back_val(3);

    //výpis seznamu
    LL.print_LL();
    LL[1]->print_node();

    //vložení prvku na určenou pozici 
    LL.insert_val(2, 4);

    //smazání prvku na určené pozici
    LL.delete_node(3);

    //výpis seznamu po úpravách
    LL.print_LL();

    return 0;
}