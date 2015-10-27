//
//  Person.cpp
//  Sparse Matrix
//
//  Created by Ian Murphy on 10/22/15.
//  Copyright © 2015 Ian Murphy. All rights reserved.
//

#include "Person.hpp"
#include <iostream>
Person::Person()
{
    
}

Person::Person( char * last,  char * first, USHORT bday, USHORT id, USHORT num):m_birthday(bday),m_id(id),m_num(num)
{
    strcpy(m_lname, last);
    strcpy(m_fname, first);
}


void Person::Set(char *, char *, USHORT, USHORT, USHORT)
{
    
}

char * Person::GetLast()
{
    return m_lname;
}

std::ostream operator<<(std::ostream& out, const Person &t)
{
    out<<t.m_lname<<"
}