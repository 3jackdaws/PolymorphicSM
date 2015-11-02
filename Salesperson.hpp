//
//  Salesperson.hpp
//  Polymorphic SM
//
//  Created by Ian Murphy on 10/26/15.
//  Copyright © 2015 Ian Murphy. All rights reserved.
//

#ifndef Salesperson_hpp
#define Salesperson_hpp

#include <stdio.h>
#include "Person.hpp"
#include <iostream>
using std::cout;

class Salesperson : public Person
{
    float m_sales;
    float m_commission;
public:
    Salesperson();
    Salesperson(char *, char *, int, int, int, float, float);
    virtual void Display();
};

#endif /* Salesperson_hpp */
