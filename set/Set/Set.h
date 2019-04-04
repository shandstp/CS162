#ifndef SET_H
#define SET_H

template <class T>
class Set {
private:
    int size;
    int currentIndex;
    T array[size];
public:
    Set(){
        size = 8;
        currentIndex = 0;
        array[size] = {0};
    }

    bool contains(T item){
        bool contains = false;
        for(int i = 0; i < size; i++){
            if(item == array[i]){
                contains = true;
            }
        }
        return contains;
    }

    void add(T item){
        array[currentIndex] = item;
        ++currentIndex;
    }
};

//template <class T>
//Set::Set(){
//    size = 8;
//    array[] = {0};
//}

#endif // SET_H
