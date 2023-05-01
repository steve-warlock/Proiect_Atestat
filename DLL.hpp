//
//  DLL.hpp
//  Double_Linked_List
//
//  Created by Steve Warlock on 02.04.2022.
//

#pragma once


//std
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

namespace solution {

class DLL{
private:
    struct node{
        int info;
        node* prev;
        node* next;
    };
    node* head;
    node* tail;
    
    void quickSort(DLL::node* , DLL::node* , bool );
    
public:
    DLL();
    DLL(const DLL& );
    ~DLL();
    
    inline bool isEmpty(){return head == NULL;}
    
    void AddToHead(DLL& , int );
    void AddToTail(DLL& , int );
    
    
    
    void sortAscending(DLL& );
    void sortDescending(DLL& );
    
    
    void DeleteNode(DLL& , DLL::node* );
    void DeleteNodes(DLL& , int );
    
    int search(DLL& , int );
    
    void reset(DLL& );
    
    
    
    // citire/afisare standard
    friend std::istream& operator>> (std::istream& , DLL& );
    friend std::ostream& operator<< (std::ostream& , DLL& );
    
    //citire fisier
    friend std::fstream& operator>> (std::fstream& , DLL& );
    
    DLL& operator+= (const DLL&);
};
}
