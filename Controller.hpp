//
//  Controller.hpp
//  Sparse Matrix
//
//  Created by Ian Murphy on 10/22/15.
//  Copyright © 2015 Ian Murphy. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>
#include "Isam.hpp"
#include <fstream>


class Controller
{
    char * arg[10];
    Isam myIsam;
    char m_current_command[60];
public:
    Controller();
    void Execute(char * in, char * out);
    bool SwitchCommand(std::ofstream &);
    void GetCommand();
    void DisplayAll();
};

#endif /* Controller_hpp */
