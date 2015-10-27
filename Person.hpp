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
typedef unsigned short int USHORT;

const USHORT NAME_FIELD_SIZE = 30;

class Person{
    friend class ostream;
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
    friend std::ostream& operator <<(std::ostream &out, const Person &t);
    virtual void Display() = 0;
};

#endif /* Person_hpp */
