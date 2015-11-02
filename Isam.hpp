//
//  Isam.hpp
//  Sparse Matrix
//
//  Created by Ian Murphy on 10/22/15.
//  Copyright © 2015 Ian Murphy. All rights reserved.
//

#ifndef Isam_hpp
#define Isam_hpp
#include "Index.hpp"
#include <stdio.h>
#include <fstream>

const int MAX_COL_HEIGHT = 15;
struct coords
{
    int row = 0;
    int col = 0;
};

class Isam
{
    Index * m_col[MAX_COL_HEIGHT];
public:
    Isam();
    void Insert(Person *);
    bool Delete(coords);
    coords Search(char *);
    void ShiftDown(int);
    void ShiftUp(int);
    void Display(int, int);
};
#endif /* Isam_hpp */
