#include <initializer_list>

template <class T>
class Vector {
    T* arr;
    size_t size;
    size_t capacity;

    public:

        Vector()
        {
            capacity = 8;
            arr = new int[capacity];
            size = 0;
        }

       Vector(int sz)
       {
            size = sz;
            capacity = sz * 2;
            arr = new int[capacity];

            for (size_t i = 0; i <= sz; ++i)
            {
                arr[i] = 0;
            }
            
       }

       Vector(std::initializer_list<T> list)
       {
            size = list.size();
            capacity = list.size() * 2;
            arr = new int[capacity];
            
 
            int i = 0;
            for (int el : list) 
            {
                arr[i++] = el;
            }
 
       }

       int operator[](int index)
       {
            if (index < size && index >= 0)
            {
                return arr[index];

            } else {
 
                throw std::out_of_range("Index out of scope");
            }
       }

        void AddElemToTheEnd(T elem)
        {
            ++size;
 
            if (size <= capacity)
            {
                arr[size - 1] = elem;
            } else { 

                capacity *= 2;
                T* newArr = new int[capacity];
 
                for (size_t i = 0; i <= size; ++i) 
                {
                    newArr[i] = arr[i];
                }
 
                newArr[size - 1] = elem;
                delete[] arr;
                arr = newArr;
            }

       }

        void DeleteTheEndElem()
        {
            if ( size == 0)
            {
                std::cout << "Array is empty";
            } else {
                --size;
            }
       }

        void InsertElemByPos(size_t pos, T value)
        {   
            ++size;

            if (size >= capacity) {
                capacity *= 2;
            }

            T* newArr = new int[capacity]; 

            auto InsertingElement = [&]() { 
                for (size_t i = 0; i < pos; ++i) {
                    newArr[i] = arr[i];
                }

                newArr[pos] = value; 

                for (size_t i = pos; i < size; ++i) {
                    newArr[i + 1] = arr[i];
                }
            };
            
            InsertingElement();

            delete[] arr;
            arr = newArr; 
        }

        
        size_t v_capacity()
        {
            return capacity;
        }
 
        size_t v_size()
        {
            return size;
        }

        void ClearVector() 
        {   
            delete[] arr;

            capacity = 8;
            arr = new int[capacity];
            size = 0;
        }
 
       ~Vector()
       {
            delete[] arr;
       }
};