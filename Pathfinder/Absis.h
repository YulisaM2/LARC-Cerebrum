#ifndef _ABSIS_H_
#define _ABSIS_H_

using namespace std;

template<class T>
class Absis {
public:
    Absis(){
        array = new T[currentSize];
    }
    void push_back(T t){
        T *newArray = new T[currentSize + 1];

        for(int i = 0; i < currentSize; ++i){
            newArray[i] = array[i];
        }
        newArray[currentSize] = t;
        delete [] array;
        array = newArray;

        currentSize++;
    }

    void emplace_back(T t){
        push_back(t);
    }

    void addStart(T t){
        T *newArray = new T[currentSize + 1];

        for(int i = 0; i < currentSize; ++i){
            newArray[i + 1] = array[i];
        }
        newArray[0] = t;
        delete [] array;
        array = newArray;

        currentSize++;
       
    }
    unsigned short int size()const{
        return currentSize ;
    }

    T& operator[](unsigned short int index)const{
        if(index >= 0 && index < currentSize){
            return array[index];
        }
    }

    void remove(T element){
        int pos = -1;
        for(int j = size() - 1; j >= 0; --j){
            if(array[j] == element){
               pos = j;
               break;
            }
        }

        if(pos == -1){
            return;
        }
        
        if(pos < size() - 1){
            for(int i = pos; i < size() - 1; ++i){
                array[i] = array[i + 1];
            }
        }

        currentSize--;
    }

    int count(T element){
        int counter = 0;
        for(int i = 0; i < size(); ++i){
            if(array[i] == element){
                ++counter;
            }
        }
        return counter;
    }

private:
    unsigned short int currentSize = 0;
    T *array;
};

#endif