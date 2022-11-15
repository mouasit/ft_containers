#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft{
    template <typename T1, typename T2>
    class pair
    {
        private:
        public:
            T1      first;
            T2      second;
        pair(void){};
        pair(const T1 first, const T2 second){
            this->first = first;
            this->second = second;
        }
        
        pair &operator=(const pair &pair)
        {
            this->first = pair.first;
            this->second = pair.second;
            return *this;
        }
    };
    template <typename T1, typename T2>
    pair<T1,T2> make_pair(const T1 value1, const T2 value2)
    {
        pair<T1,T2> pair(value1,value2);
        return (pair);
    }
}

#endif