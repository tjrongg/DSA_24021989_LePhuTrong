#include <bits/stdc++.h>
using namespace std;

struct Node{
int data;
Node* next;
};
Node* createNode(int x){
  Node*p = new Node;
p-> data=x;
p-> next=nullptr;
return p;
}

//chendau
void insertFrist( Node*& head, int x){
  Node *p= createNode(x);
p->next=head;
head=p;
}

//chen cuoi
void insertLast(Node *&head, int x)
{
    Node* p= createNode(x);
    if(head==nullptr)
    {
        head= p;
        return;
    }
    
    Node* cur =head;
    while(cur->next != nullptr)
    {
        cur=cur->next;
    }
    cur->next = p;
}

//chen vi tri thu i
void insertValue(Node*& head, int x, int k)
{
    if (k <= 0 || head == nullptr)
    {
        insertFirst(head, x);
        return;
    }

    Node* cur = head;
    int cnt = 0;

    // Đưa cur đến node đứng ngay trước vị trí k
    while (cnt < k - 1 && cur->next != nullptr)
    {
        cur = cur->next;
        cnt++;
    }

    Node* p = createNode(x);

    p->next = cur->next;
    cur->next = p;
}

//xoa phan tu dau
void DeleteFisrt( Node *&head)
{
    if(head == nullptr) return;
    Node *cur =head;
    head =head->next;
    delete cur;
}
void DeleteLast(Node *&head)
{
    if( head == nullptr) return;
    if(head->next == nullptr)
    {
        delete head;
        head =nullptr;
        return;
    }
    Node *cur =head;
    while(cur->next->next != nullptr) cur =cur->next;
    delete cur->next;
    cur->next =nullptr;
}
void Deletevalue(Node *&head, int k)
{
    if( k<0 || head == nullptr) return;
    if( k==0)
    {
        DeleteFisrt(head);
        return;
    }
    Node *cur = head;
    for(int i=0; i<k-1 && cur->next != nullptr; i++)
    {
        cur = cur->next;
    }
    if(cur->next == nullptr) return;
    Node *temp = cur->next;
    cur->next = temp->next;
    delete temp;
    
}
 int indexOf(Node* head, int x) 
 { 
    int index = 0;
    while(head != nullptr) {
        if (head->data == x) return index;
        head = head->next;
        index++;
    }
    return -1;
}

void printList(Node* head) 
{
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printReverse(Node* head) 
{
    if(head == nullptr) return;
    printReverse(head->next);
    cout << head->data << " ";
}

int main() {
    Node* head = nullptr; 
    cout<<"Tao chuoi node"<<endl;
    insertFirst(head, 10);
    insertLast(head, 20);
    insertLast(head, 30);
    insertLast(head, 40);
    printList(head); 

    cout<<"chen vao vi tri thu 2"<<endl;
    InsertValue(head, 15, 1);
    printList(head); 

    cout<<"Xoa vi tri dau"<<endl;
    DeleteFisrt(head);
    printList(head); 
    
    cout<<"Xoa vi tri cuoi:"<<endl;
    DeleteLast(head);
    printList(head); 
    cout<<"Xoa vi tri thu 2"<<endl;
    Deletevalue(head,1);
    printList(head);
    cout<<"Duyet nguoc :"<<endl;
    printReverse(head);

    return 0;
}




