#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

struct Node
{
    int data_;
    Node* next_ = nullptr;

    Node(int data) //Konstruktor
    {
        data_ = data;
    }

    ~Node() //Destruktor, frigör minne här!
    {

    }
};

struct LinkedList
{
    Node* head_ = nullptr;

    LinkedList() //Konstruktor
    {

    }

    ~LinkedList() //Destruktor, frigör minne här!
    {

    }

    void add(int index, int data)
    {
        Node* temp = new Node(data);
        if (index == 0) {
            temp->next_ = head_;
            head_ = temp;
            return;
        }

        Node* current = head_;
        Node* prev = head_;
        for (int i = 0; i < index; i++)
        {
            prev = current;
            current = current->next_;
        }
        temp->next_ = current;
        prev->next_ = temp;
    }

    void addFirst(int data)
    {
        Node* temp = new Node(data);
        temp->next_ = head_;
        head_ = temp;
    }

    void addLast(int data)
    {
        Node* temp = new Node(data);
        temp->data_ = data;
        temp->next_ = NULL;
        if (head_ == NULL) {
            head_ = temp;
        }
        else
        {
            Node* temp = head_;
            while (temp->next_ != NULL)
                temp = temp->next_;
            temp->next_ = temp;
        }
    }

    void addAfter(Node* n, int data)
    {
        //Kolla if Node är null
        if (n == NULL) {
            cout << "n kan inte vara NULL";
            return;
        }

        //förbered en ny Node
        Node* newNode = new Node(data);
        newNode->data_ = data;

        //Lägg in Node efter den tidigare
        newNode->next_ = n->next_;
        n->next_ = newNode;
    }

    void addBefore(Node* n, int data)
    {
        if (head_ == n) {
            addFirst(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* next = head_;


        while (true)
        {
            if (next == NULL || next->next_ == n) {
                break;
            }
            next = next->next_;
        }
        newNode->next_ = n;
        next->next_ = newNode;
    }

    int size()
    {
        int a = 0;

        Node* next = head_;
        while (next != nullptr)
        {
            a += 1;
            next = next->next_;
        }
        return a;
    }

    bool contains(int v)
    {
        Node* current = head_;
        while (current != NULL)
        {
            if (current->data_ == v) {
                return true;
            }
            current = current->next_;
        }
        return false;
    }

    bool remove(int v)
    {
        Node* current = head_;
        Node* prev = head_;
        
        while (current != NULL) {
            if (current->data_ = v) {
                break;
            }
            current = current->next_;
        }
        cout << current->data_;

        if (current->data_ != v || current == NULL) {
            return false;
        }

        while (prev->next_->data_ != v) {
            prev = prev->next_;
        }
        cout << prev->data_;

        /*while (next->next_ != NULL) {
            if (next == current->next_) {
                break;
            }
            next = next->next_;
        }*/

        prev->next_ = current->next_;
        cout << prev->next_->data_;
        delete current;
        return true;
    }

    int getFirst()
    {
        return head_->data_;
    }

    int getLast()
    {
        Node* current = head_;

        while (current->next_ != NULL) {
            current = current->next_;
        }
        return current->data_;
    }

    void clear()
    {
        
    }

    void print()
    {
        Node* next = head_;
        while (next != nullptr)
        {
            cout << next->data_ << " ";
            next = next->next_;
        }
    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //Debug-flaggor för att upptäcka minnesläckor

    LinkedList myLinkedList;
    myLinkedList.addFirst(10);
    myLinkedList.addFirst(20);
    myLinkedList.addFirst(60);
    myLinkedList.add(2, 70);
    myLinkedList.addFirst(30);
    myLinkedList.add(1, 50);

    myLinkedList.addBefore(myLinkedList.head_->next_, 90);
    myLinkedList.addBefore(myLinkedList.head_->next_->next_, 5);
    //Testa din länkade lista, dvs alla metoder med flera olika värden här.
    myLinkedList.print();
    cout << std::endl;
    cout << myLinkedList.size();
    cout << std::endl;
    myLinkedList.contains(10) ? cout << "contains element" : cout << "doesn't contain element";
    cout << std::endl;
    myLinkedList.contains(100) ? cout << "contains element" : cout << "doesn't contain element";
    cout << std::endl;
    cout << myLinkedList.getFirst();
    cout << std::endl;
    cout << myLinkedList.getLast();
    cout << std::endl;
    //myLinkedList.remove(5) ? cout << "har tagits bort" : cout << "fanns inte";
    //cout << std::endl;
    //myLinkedList.print();


}