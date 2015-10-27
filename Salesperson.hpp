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

class Salesperson : public Person
{
    float m_sales;
    float m_commission;
public:
    void Display();
};

#endif /* Salesperson_hpp */
