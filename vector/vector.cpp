



/*
Vector::Vector(){
    this->lenSize = 0;

}

void Vector::reserve(int n){
    if(n > 0)
    {
        pointer start = this->myVector.allocate(n);
        this->_size++;
    }
}


int Vector::size(){
    return this->size;
}

void Vector::assign(int len, int value){

    this->table = new int[len + 1];
    this->lenSize = len;
    for (size_t i = 0; i < len; i++)
        this->table[i] = value;
    

}

void Vector::pop_back(){
    int *tmp = this->table;

    if (this->lenSize > 0)
    {
        this->lenSize--;
        this->table = new int[this->lenSize + 1];
        for (size_t i = 0; i < this->lenSize; i++)
            this->table[i] = tmp[i];
    }
}


void Vector::push_back(int item){
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

int Vector::size(){
    return this->lenSize;
}

int Vector::operator[](int index){
    return this->table[index];
}

void printVector(Vector vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << std::endl;
    }
}*/