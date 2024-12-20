#include <stdexcept>

template <typename t> class vec {
public:
    vec();
    vec(unsigned int size);
    vec(int size);
    ~vec();
    
    t const & operator[](int id);
    t const & operator[](unsigned int id);
    
    void push_back(t const & item);
    void resize(unsigned int size);
    
    unsigned int size();
    unsigned int capacity();
        
private:
    int m_size;
    int m_capacity;
    t* m_array;

    void realloc(unsigned int n);  
};


template <typename t>
vec<t>::vec() {
    m_capacity = 2;
    m_size = 0;
    m_array = new t[m_capacity];
}

template <typename t>
vec<t>::vec(int size) {
    if(size < 0) {
        throw std::invalid_argument("size of vec is less then 0!");
    }
    m_capacity = size;
    m_size = size;
    m_array = new t[capacity];
}

template <typename t>
vec<t>::vec(unsigned int size) {
    m_capacity = size;
    m_size = size;
    m_array = new t[capacity];
}

template <typename t> 
vec<t>::~vec() {
    delete[] m_array;
}

template <typename t>
t const & vec<t>::operator[](int id) {
    if(id < 0 || id >= m_capacity){
        throw std::invalid_argument("bad acces error");
    }
    return m_array[id];
}

template <typename t>
t const & vec<t>::operator[](unsigned int id) {
    if(id >= m_capacity){
        throw std::invalid_argument("bad acces error");
    }
    return m_array[id];
}

template <typename t>
void vec<t>::push_back(t const & item) {
    if(m_size >= m_capacity){
        realloc(2*m_capacity);
    }
    m_array[m_size] = item;
    m_size++;
}

template <typename t>
void vec<t>::resize(unsigned int size) {
    m_size = size;
    realloc(size);
}

template <typename t>
unsigned int vec<t>::size() {
    return m_size;
}

template <typename t>
unsigned int vec<t>::capacity() {
    return m_capacity;
}

template <typename t>
void vec<t>::realloc(unsigned int n) {
    t * temp = new t[n];
    m_capacity = n;
    for(int i = 0 ; i < m_size; i++) {
        temp[i] = m_array[i];
    }
    m_array = temp;
    delete[] temp;
}