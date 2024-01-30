#include <initializer_list>

class Vector {
    private: 
        int* MyArray;
        size_t size; 

    public:

        Vector(int size) 
        {
            this->size = size;
            MyArray = new int[size];

            for (size_t i = 0; i != size; ++i ) {
                MyArray[i] = 0;
            }
        }

        Vector(std::initializer_list<int> list) 
        {
            this->size = list.size();
            MyArray = new int[size];
            size_t i = 0;

            for (int n : list) 
            {
                MyArray[i++] = n;
            }

        }

        int& operator[](int index)
        {
            if (index < size && index >= 0) {
                return MyArray[index];
            } else {
                throw std::out_of_range("Index out of scope");
            }
        }

        void AddElemToTheEnd(int elem) 
        {
            MyArray[size] = elem;
            ++size; 
        };

        void DeleteTheLastElem() {
            int* NewMyArray = new int[size];

            for(size_t i = 0; i < size - 1; ++i) 
            {
                NewMyArray[i] = MyArray[i];
            }

            delete[] MyArray;
            MyArray = NewMyArray;
            --size;
        }

        void InsertElemByIndex(int pos, int elem) 
        {
            int* NewMyArray = new int[size + 1];

            for(size_t i = 0; i != pos; ++i) 
            {
                NewMyArray[i] = MyArray[i];

            }

            NewMyArray[pos] = elem;

            for(size_t i = pos; i != size; ++i)
            {
                NewMyArray[i + 1] = MyArray[i];
            }

            delete[] MyArray;
            MyArray = NewMyArray;
            ++size;
        }

        void DeleteElemByIndex(size_t index) 
        {
            int* NewMyArray = new int[size - 1];

            for(size_t i = 0; i != index; ++i)
            {
                NewMyArray[i] = MyArray[i];
            }

            for(size_t i = index + 1; i < size; ++i) 
            {
                NewMyArray[i - 1] = MyArray[i];
            }

            delete[] MyArray;
            MyArray = NewMyArray;
            --size;
        }


        void ClearVector() 
        {
            int* MyNewArray = new int[0];

            delete[] MyArray;
            MyArray = MyNewArray;

        }

        ~Vector() 
        {
            delete[] MyArray;
        }

};