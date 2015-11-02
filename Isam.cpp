//
//  Isam.cpp
//  Sparse Matrix
//
//  Created by Ian Murphy on 10/22/15.
//  Copyright © 2015 Ian Murphy. All rights reserved.
//

#include "Isam.hpp"
#include <iostream>
extern std::ofstream fout;

Isam::Isam()
{
    for(int i = 0; i< MAX_COL_HEIGHT; ++i)
    {
        m_col[i] = new Index;
    }
}

void Isam::Insert(Person * newPerson)
{
    bool done = false;
    int col = 0;
    node * nn = m_col[0]->CreateNode(newPerson);
    
    while(!done)
    {
        if(m_col[col +1]->GetSize() == 0 || _CASECMP(m_col[col+1]->GetFirst(), nn->_data->GetLast()) > 0)
        {
            m_col[col]->Insert(nn);
            
            if(m_col[col]->GetSize() > MAX_ROW_SIZE)
            {
                nn = m_col[col]->GetLast();
                ShiftDown(col);
                col++;
            }
            else
                done = true;
        }
        else
        {
            col++;
        }
        
    }
    
}

bool Isam::Delete(coords loc)
{
    m_col[loc.col]->Delete(loc.row);
    if(m_col[loc.col]->GetSize() == 0 )
    {
        ShiftUp(loc.col+1);
    }
    return true;
}

coords Isam::Search(char * query)
{
    int col = 0;
    coords f;
    bool done = false;
    while(!done)
    {
        if(m_col[col +1]->GetFirst()[0] == '\0' || _CASECMP(m_col[col+1]->GetFirst(), query) > 0)
        {
            f.row = m_col[col]->Search(query);
            done = true;
        }
        else
        {
            col++;
        }
        
    }
    f.col = col;
    
    return f;
}

void Isam::ShiftDown(int offset)
{
    Index * hold = m_col[MAX_COL_HEIGHT - 1];
    if(m_col[offset+1]->GetSize() == MAX_ROW_SIZE)
    {
        for(int i = 0; i< MAX_COL_HEIGHT - (offset+2); ++i)
        {
            m_col[MAX_COL_HEIGHT - (i +1)] = m_col[MAX_COL_HEIGHT-(i+2)];
        }
        m_col[offset+1] = hold;
    }
}

void Isam::ShiftUp(int offset)
{
    delete m_col[offset - 1];
    for(int i = offset; i< MAX_COL_HEIGHT -1; ++i)
    {
        m_col[i-1] = m_col[i];
    }
}

void Isam::Display(int col1, int col2)
{
    fout<<"\nDisplaying row "<<col1<<" through row "<<col2<<"."<<std::endl;
    for(int i = col1; i<col2+1; ++i)
    {
        fout<<"-------ROW "<<i<<"-------"<<std::endl;
        m_col[i]->Display();
    }
}

