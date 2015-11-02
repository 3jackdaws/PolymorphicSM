//
//  Person.hpp
//  Sparse Matrix
//
//  Created by Ian Murphy on 10/22/15.
//  Copyright © 2015 Ian Murphy. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>


typedef unsigned short int USHORT;

const USHORT NAME_FIELD_SIZE = 30;

class Person{
    friend class Index;
    char m_lname[NAME_FIELD_SIZE];
    char m_fname[NAME_FIELD_SIZE];
    USHORT m_birthday;
    USHORT m_id;
    USHORT m_num;
public:
    Person();
    Person(char *, char *, USHORT, USHORT, USHORT);
    char * GetLast();
    char * GetFirst();
    void Set(char *, char *, USHORT, USHORT, USHORT);
    virtual void Display();
};

#endif /* Person_hpp */
