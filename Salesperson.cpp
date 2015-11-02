//
//  Salesperson.cpp
//  Polymorphic SM
//
//  Created by Ian Murphy on 10/26/15.
//  Copyright © 2015 Ian Murphy. All rights reserved.
//

#include "Salesperson.hpp"

Salesperson::Salesperson()
{
    
}
Salesperson::Salesperson(char * lname, char * fname, int bday, int id, int num, float sales, float commission):Person(lname, fname, bday, id, num),m_sales(sales),m_commission(commission)
{
    
}

void Salesperson::Display()
{
    Person::Display();
    
}