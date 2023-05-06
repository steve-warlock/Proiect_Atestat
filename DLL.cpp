//
//  DLL.cpp
//  Double_Linked_List
//
//  Created by Steve Warlock on 02.04.2022.
//

#include "DLL.hpp"


namespace solution{

DLL::DLL()
{
    head = tail = nullptr;
}

DLL::DLL(const DLL& p)
{
    head = tail = nullptr;
    DLL::node* temp = p.head;
    while (temp != nullptr) {
        AddToTail(*this, temp -> info);
        temp = temp -> next;
    }
}
DLL::~DLL()
{
    DLL::node* q = head;
    while (q != nullptr) {
        head = q -> next;
        delete q;
        q = head;
    }
    tail = nullptr;
}

void DLL::AddToHead(DLL& p, int x)
{
    if (p.head == nullptr) {
        p.head = new DLL::node;
        p.head -> info = x;
        p.head -> prev = nullptr;
        p.head -> next = nullptr;
        p.tail = p.head;
    } else {
        DLL::node* q = new DLL::node;
        q -> info = x;
        q -> prev = nullptr;
        q -> next = p.head;
        p.head -> prev = q;
        p.head = q;
    }
}

void DLL::AddToTail(DLL& p, int x)
{
    DLL::node* q = new DLL::node;
    q -> info = x;
    q -> next = nullptr;
    q -> prev = nullptr;
    if (p.head == nullptr) {
        p.head = q;
        p.tail = q;
    } else {
        q -> prev = p.tail;
        p.tail -> next = q;
        p.tail = q;
    }
}

void DLL::quickSort(DLL::node* head, DLL::node* tail, bool isAscending) {
    if (head == nullptr || tail == nullptr || head == tail || head == tail -> next)
        return;
    
    DLL::node* pivot = tail;
    DLL::node* i = head -> prev;
    
    for (DLL::node* j = head; j != tail; j = j -> next) {
        if ((isAscending && j -> info <= pivot -> info) || (!isAscending && j -> info >= pivot -> info)) {
            i = (i == nullptr) ? head : i -> next;
            std::swap(i -> info, j -> info);
        }
    }
    
    i = (i == nullptr) ? head : i -> next;
    std::swap(i -> info, tail -> info);
    
    DLL::node* pivotIndex = i;
    quickSort(head, pivotIndex -> prev, isAscending);
    quickSort(pivotIndex -> next, tail, isAscending);
}


void DLL::sortAscending(DLL& p)
{
    quickSort(p.head, p.tail, true);
}

void DLL::sortDescending(DLL& p)
{
    quickSort(p.head, p.tail, false);
}


void DLL::DeleteNode(DLL& p, DLL::node* temp)
{
    if (p.head == nullptr || temp == nullptr) {
        return;
    }
    if (p.head == temp) {
        p.head = temp -> next;
    }
    if (temp -> prev != nullptr) {
        temp -> prev -> next = temp -> next;
    }
    if (temp -> next != nullptr) {
        temp -> next -> prev = temp -> prev;
    }
    delete temp;
    
}
void DLL::DeleteNodes(DLL& p, int x)
{
    if (p.head == nullptr)
        return;
    
    DLL::node* temp = p.head;
    while (temp != nullptr) {
        if (temp -> info == x) {
            DLL::node* urm = temp -> next;
            DeleteNode(p, temp);
            temp = urm;
        } else {
            temp = temp -> next;
        }
    }
}
int DLL::search(DLL& p , int x)
{
    int poz = 0;
    DLL::node *q = p.head;
    while(q != nullptr)
    {
        ++poz;
        if(q -> info == x)
            return poz;
        { q = q -> next; }
    }
    return -1;
}

void DLL::reset(DLL& p)
{
    DLL::node* q = p.head;
    while (q != nullptr) {
        DLL::node* temp = q;
        q = q -> next;
        delete temp;
    }
    p.head = p.tail = nullptr;
}

std::ostream& operator<< (std::ostream& out, DLL& p)
{
    DLL::node* q;
    for(q = p.head; q != nullptr; q = q -> next)
        out << q -> info << ' ';
    return out;
}


DLL& DLL::operator+= (const DLL& p)
{
    DLL::node* temp = p.head;
    while(temp != nullptr)
    {
        AddToTail(*this, temp -> info);
        temp = temp -> next;
    }
    return *this;
}

}
