//
//  Index.hpp
//  Sparse Matrix
//
//  Created by Ian Murphy on 10/22/15.
//  Copyright © 2015 Ian Murphy. All rights reserved.
//
#ifdef _WIN32
#define _CASECMP stricmp
#else
#define _CASECMP strcasecmp
#endif

#ifndef Index_hpp
#define Index_hpp



#include <fstream>
#include "Person.hpp"


const int MAX_ROW_SIZE = 10;
struct node
    {
        node * _next;
        Person * _data;
    };

class Index{
    int m_num_elements;
    node * m_head = nullptr;
    char m_index[NAME_FIELD_SIZE] = {'\0'};
    
public:
    Index();
    void Insert(node *);
    bool Delete(int);
    char * GetFirst();
    int GetSize();
    node * GetHead();
    void SetHead(node *);
    node * CreateNode(Person *);
    node * GetLast();
    void Display();
    void Display(int);
    int Search(char *);
};

#endif /* Index_hpp */
