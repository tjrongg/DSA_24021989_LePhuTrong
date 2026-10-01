#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

DNode* createDNode(int x) {
    DNode* p = new DNode;
    p->data = x;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void insertFirst(DNode *&head, int x)
{
    DNode* p = createDNode(x);
    if(head != nullptr) 
    {
        p->next = head;
        head->prev = p;
    }
    head = p;
}
void insertLast(DNode *&head, int x) 
{
    if(head == nullptr) 
    {
        insertFirst(head, x);
        return;
    }
    DNode* cur = head;
    while(cur->next != nullptr) cur = cur->next; 
    DNode* p = createDNode(x);
    cur->next = p;
    p->prev = cur;
}

void insertValue(DNode *&head, int x, int k) 
{
    if(k <= 0 || head == nullptr) 
    {
        insertFirst(head, x);
        return;
    }
    DNode* cur = head;
    for(int i = 0; i<k - 1 && cur->next != nullptr; i++) 
    {
        cur = cur->next;
    }
    DNode* p = createDNode(x);
    p->next = cur->next;
    p->prev = cur;
    if(cur->next != nullptr) cur->next->prev = p;
    cur->next = p;
}

void deleteFirst(DNode *&head) 
{
    if(head == nullptr) return;
    DNode* temp = head;
    head = head->next;
    if(head != nullptr) head->prev = nullptr;
    delete temp;
}
void deleteLast(DNode *&head)
{
    if(head == nullptr) return;
    if(head->next == nullptr) 
    {
        deleteFirst(head);
        return;
    }
    DNode* cur = head;
    while (cur->next != nullptr) cur = cur->next; 
    cur->prev->next = nullptr;
    delete cur;
}
void deleteValue(DNode *&head, int k) 
{
    if(head == nullptr || k<0) return;
    if(k == 0) {
        deleteFirst(head);
        return;
    }
    DNode* cur = head;
    for(int i = 0; i<k && cur != nullptr; i++) cur = cur->next;
    if(cur == nullptr) return; 
    if(cur->next == nullptr)
    {
        deleteLast(head);
        return;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
}
int indexOf(DNode* head, int x) 
{
    int index = 0;
    while(head != nullptr) 
    {
        if (head->data == x) return index;
        head = head->next;
        index++;
    }
    return -1;
}
void printList(DNode* head) 
{
    while(head != nullptr) 
    {
        cout<<head->data<< " ";
        head = head->next;
    }
    cout<<endl;
}
void printReverse(DNode* head) 
{
    if(head == nullptr) return;
    DNode* cur = head;
    while(cur->next != nullptr) cur = cur->next; 
    while(cur != nullptr) 
    { 
        cout<<cur->data<< " ";
        cur = cur->prev;
    }
    cout<<endl;
}

int main() {
    DNode* head = nullptr;
    cout<<"Tao node:"<<endl;
    insertFirst(head, 10);
    insertLast(head, 20);
    insertLast(head, 30);
    insertLast(head, 40);
    printList(head);

    cout<<"Chen vao vi tri thu 2"<<endl;
    insertValue(head,15,1);
    printList(head);

    cout<<"Xoa vi tri dau"<<endl;
    deleteFirst(head);
    printList(head);

    cout<<"Xoa vi tri cuoi"<<endl;
    deleteLast(head);
    printList(head);

    cout<<"Xoa vi tri thu 2"<<endl;
    deleteValue(head,1);
    printList(head);

    cout<<"In nguoc node"<<endl;
    printReverse(head); 

    return 0;
}
