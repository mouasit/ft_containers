#include <iostream>
#include <vector>
#include "vector.hpp"

myVector::myVector(){
    this->lenSize = 0;
}

int myVector::operator[](int index){
    return this->table[index];
}

void myVector::pop_back(){
    int *tmp = this->table;

    if (this->lenSize > 0)
    {
        this->lenSize--;
        this->table = new int[this->lenSize + 1];
        for (size_t i = 0; i < this->lenSize; i++)
            this->table[i] = tmp[i];
    }
}



void myVector::push_back(int item){
    int *tmp = this->table;
    this->lenSize++;
    this->table = new int[this->lenSize + 1];
    if(this->lenSize > 1)
    {
        for (size_t i = 0; i < this->lenSize; i++)
        {
            if(i == this->lenSize - 1)
                this->table[this->lenSize - 1] = item;
            else
                this->table[i] = tmp[i];
        }
    }

    else
        this->table[this->lenSize - 1] = item;
}

int myVector::size(){
    return this->lenSize;
}

void printVector(myVector vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << std::endl;
    }
}

int main(){
    myVector vector;
    std::vector<int>test;

    vector.push_back(5);
    
    printVector(vector);

    std::cout << "-------------" << std::endl;

    vector.pop_back();
    std::cout << vector.size();
    printVector(vector);
}