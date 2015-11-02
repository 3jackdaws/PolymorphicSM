//
//  Controller.cpp
//  Sparse Matrix
//
//  Created by Ian Murphy on 10/22/15.
//  Copyright © 2015 Ian Murphy. All rights reserved.
//

#include "Controller.hpp"
#include <fstream>
extern std::ofstream fout;
#include <iostream>
using std::ifstream;

Controller::Controller()
{
    
}

void Controller::Execute(char * in)
{
    
    ifstream fin(in);
    
    
    if(fin.is_open())
    {
        bool exit = false;
        while(!exit && !fin.eof())
        {
            
            fin.getline(m_current_command, 50);
            GetCommand();
            exit = SwitchCommand();
        }
    }
    else
        throw "File cannot be opened";
    
}

bool Controller::SwitchCommand()
{
    switch(*arg[0])
    {
        case 'I':
        {
            switch(*arg[6])
            {
                case 'S':
                {
                    Person * temp = new Salesperson(arg[2], arg[3], atoi(arg[1]), atoi(arg[4]), atoi(arg[5]), atof(arg[7]), atof(arg[8]));
                    myIsam.Insert(temp);
                    break;
                }
                case 'T':
                {
                    Person * temp = new Temp(arg[2], arg[3], atoi(arg[1]), atoi(arg[4]), atoi(arg[5]), atof(arg[7]), atof(arg[8]));
                    myIsam.Insert(temp);
                    break;
                }
                case 'M':
                {
                    Person * temp = new Manager(arg[2], arg[3], atoi(arg[1]), atoi(arg[4]), atoi(arg[5]), atof(arg[7]), atof(arg[8]));
                    myIsam.Insert(temp);
                    break;
                }
            }
            
            break;
        }
        case 'R':
        {
            myIsam.Display(atoi(arg[1]), atoi(arg[2]));
            break;
        }
        case 'E':
        {
            return true;
        }
        case 'S':
        {
            fout<<"\nSearching for "<<arg[1]<<"\n";
            coords loc = myIsam.Search(arg[1]);
            if(loc.row != -1)
            {
                fout<<"Found at ["<<loc.col<<", "<<loc.row<<"]"<<std::endl;
            }
            break;
        }
        case 'D':
        {
            fout<<"\nSearching for "<<arg[1]<<" to delete\n";
            coords loc = myIsam.Search(arg[1]);
            if(loc.row != -1)
            {
                myIsam.Delete(loc);
                fout<<"Found at ["<<loc.col<<", "<<loc.row<<"] and deleted"<<std::endl;
            }
            
        }
        default:
        {
            //fhaksdfhka
        }
            
    }
    return false;
}

void Controller::GetCommand()
{
    
    char * c = strtok(m_current_command, " \r");
    int i = 0;
    arg[i] = c;
    while(c)
    {
        i++;
        c = strtok(NULL, " \r");
        arg[i] = c;
    }

}
