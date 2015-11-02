//
//  Index.cpp
//  Sparse Matrix
//
//  Created by Ian Murphy on 10/22/15.
//  Copyright © 2015 Ian Murphy. All rights reserved.
//

#include "Index.hpp"
#include <fstream>
#include "Consts.h"

using std::ofstream;
using std::endl;

Index::Index()
{
    m_num_elements=0;
}

void Index::Insert(node * nn)
{
    bool done = false;
    node * travel = m_head;
    node * trail = m_head;
    node * reject = nullptr;
    if(m_head == nullptr)
    {
        m_head = nn;
        m_num_elements++;
        strcpy(m_index, nn->_data->GetLast());
        done = true;
    }
    else
    {
        do
        {
            if(travel == nullptr)
            {
                trail->_next = nn;
                m_num_elements++;
                done = true;
            }
            else if(_CASECMP(travel->_data->GetLast(), nn->_data->GetLast()) > 0)
            {
                if(m_head == travel)
                {
                    m_head = nn;
                    nn->_next = travel;
                    strcpy(m_index, nn->_data->GetLast());
                    done = true;
                }
                else
                {
                    nn->_next = travel;
                    trail->_next = nn;
                }
                m_num_elements++;
                done = true;
            }
            else
            {
                trail = travel;
                travel = travel->_next;
            }
        }while(!done );

    }
}

bool Index::Delete(int index)
{
    node * travel = m_head;
    node * trail = m_head;
    if(index == 0)
    {
        m_head = trail->_next;
        if(m_head)
        {
            strcpy(m_index, m_head->_data->GetLast());
        }
    }
    else
    {
        for(int i = 0; i<index; ++i)
        {
            trail = travel;
            travel = travel->_next;
        }
        trail->_next = travel->_next;
    }
    delete travel->_data;
    delete travel;
    m_num_elements--;
    return true;
}

char * Index::GetFirst()
{
    return m_index;
}

int Index::GetSize(){
    return m_num_elements;
}

node * Index::CreateNode(Person * np)
{
    node * nn = new node;
    nn->_data = np;
    nn->_next = nullptr;
    return nn;
}

void Index::SetHead(node * nn)
{
    m_head = nn;
}

node * Index::GetHead()
{
    return m_head;
}

void Index::Display()
{
    node * travel = m_head;
    while(travel != nullptr)
    {
        fout<<travel->_data->m_lname<<", ";
        fout<<travel->_data->m_fname<<", ";
        fout<<travel->_data->m_birthday<<", ";
        fout<<travel->_data->m_id<<", ";
        fout<<travel->_data->m_num<<endl;
        travel = travel->_next;
    }
}

void Index::Display(int index)
{
    if(index != -1)
    {
        node * travel = m_head;
        for(int i = 0; i < index; ++i)
        {
            travel = travel->_next;
        }
        fout<<travel->_data->m_lname<<", ";
        fout<<travel->_data->m_fname<<", ";
        fout<<travel->_data->m_birthday<<", ";
        fout<<travel->_data->m_id<<", ";
        fout<<travel->_data->m_num<<endl;
    }
    else
        fout<<"Record not found."<<endl<<endl;
    
}

node * Index::GetLast()
{
    node * travel = m_head;
    node * trail = m_head;
    
    while( travel->_next != nullptr)
    {
        trail = travel;
        travel = travel->_next;
    }
    trail->_next = nullptr;
    m_num_elements--;
    return travel;
}

int Index::Search(char * query)
{
    node * travel = m_head;
    bool found = false;
    int foundAt = 0;
    
    while(!found)
    {
        if(travel == nullptr)
        {
            foundAt = -1;
            Display(foundAt);
            found = true;
        }
        else if(_CASECMP(query, travel->_data->GetLast()) == 0)
        {
            Display(foundAt);
            found = true;
        }
        else
        {
            travel = travel->_next;
            foundAt++;
        }
            
    }
    return foundAt;
}



