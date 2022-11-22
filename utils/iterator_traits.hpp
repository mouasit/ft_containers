    #ifndef  ITERATOR_TRAITS
    #define ITERATOR_TRAITS
    

    namespace ft
    {
        template<class Iterator>
        struct iterator_traits{
            typedef typename Iterator::value_type       value_type;
            typedef typename Iterator::pointer          pointer;
            typedef typename Iterator::reference        reference;
            typedef typename Iterator::difference_type  difference_type;
            typedef typename Iterator::iterator_category iterator_category;
        };   
    }
    #endif