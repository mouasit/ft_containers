class myVector{
    public:
        myVector();
        void push_back(int item);
        void pop_back();
        int operator[](int index);
        int size();
    private:
    int lenSize;
    int *table;
};

std::ostream&	operator<<(std::ostream& cout, myVector & inst);