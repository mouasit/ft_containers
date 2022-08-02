template<class T, class myAlloc = std::allocator<T>>
class Vector{
    public:
        Vector();
        void assign(int len, T value);
        void push_back(T item);
        void pop_back();
        int operator[](int index);
        int size();
        void reserve(int n);
        



    private:
    int _size;
    myAlloc myVector;
    typename myAlloc::pointer pointer;
};
