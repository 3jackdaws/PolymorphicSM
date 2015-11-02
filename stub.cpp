//
//  main.cpp
//  Sparse Matrix
//
//  Created by Ian Murphy on 10/22/15.
//  Copyright © 2015 Ian Murphy. All rights reserved.
//
#include <fstream>
extern std::ofstream fout;


const char * output = "output.txt";
#include <iostream>
#include "Controller.hpp"


int main(int argc, const char * argv[]) {
    
    Controller myController;
    myController.Execute("input.txt");
    std::cin.get();
    
    
    return 0;
}
