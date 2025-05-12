#include "../include/ArrayList.hpp"

ArrayList::ArrayList()
{
    array = new int[capacity];
}

ArrayList::~ArrayList()
{
    clean();
}
void ArrayList::getList(size_t size)
{
    clean();
    array = new int[capacity];

    for(size_t index = 0; index < size; index++)
    {
        int value;
        std::cin >> value;
        insertAt(value, index);
    }
}
void ArrayList::getRandomList(int sizeRandom, int minimumValue, int maximumValue)
{
    clean();
    array = new int[capacity];

    std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(minimumValue, maximumValue);

    for(size_t index = 0; index < sizeRandom;index++)
    {
        insertAt(distrib(gen), index);
    }
}
bool ArrayList::insertAt(int value, int position)
{
    if(position > size) 
    return false;
    
    if(size == capacity)
    {
        capacity += capacity;
        int* newArray = new int[capacity];
        
        for(int index = 0; index < capacity/2; index++)
        newArray[index] = array[index];

        delete[] array;
        newArray[position] = value;
        array = newArray;
        size++;
        return true;     
    }

    array[position] = value;

    if(position == size) 
    size++;

    return true;
}
bool ArrayList::swapValue(int firstPosition, int secondPosition)
{
    if(firstPosition > size || secondPosition > size)
    return false;

    int temp = array[firstPosition];
    array[firstPosition] = array[secondPosition];
    array[secondPosition] = temp;
    return true;

}
int ArrayList::search(int value, unsigned& numberOfAccess)
{
    for(int index = 0; index < size; index++)
    {
        if(array[index] == value)
        {
            numberOfAccess++;
            return index;
        }
        numberOfAccess++;
   }

   return -1;
}
int ArrayList::findMinimum(unsigned& numberOfAccess, int& minimum) 
{
    minimum = INT32_MAX;
    int minimumIndex = -1;
    for(int index = 0; index < size; index++)
    {
        if(minimum > array[index])
        {
            minimumIndex = index;
            minimum = array[index];
            numberOfAccess++;
        }
        numberOfAccess++;
    }

    return minimumIndex;
}
void ArrayList::displayList()const
{
    if(size == 0)
    return;

    for(int index = 0; index < size; index++)
    {
        std::cout << array[index] << " ";
    }
    std::cout << std:: endl;
}
void ArrayList::displayReversedList() const
{
    if(size == 0)
    return;

    for(int index = size - 1; index >= 0; index--)
    {
        std::cout << array[index] << " ";
    }
    std::cout << std::endl;
}
void ArrayList::clean()
{
    delete[] array;
}