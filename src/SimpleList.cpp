#include "../include/SimpleList.hpp"

SimpleList::SimpleList()
{
    head = new SimpleNode;
    head->next = nullptr;
}

SimpleList::~SimpleList()
{
    clean();
    delete head;
}

SimpleList::SimpleNode* SimpleList::newNode(int value)
{
    SimpleNode* node = new SimpleNode;
    node->data = value;
    node->next = NULL;
    return node;
}
void SimpleList::getList(size_t size)
{
    clean();

    SimpleNode *current = head;

    
    for(size_t index = 0; index < size; index++)
    {
        int value;
        std::cin >> value;
        insertAt(value, current);
        current = current->next;
    }
}

void SimpleList::getRandomList(size_t size, int minimumValue, int maximumValue)
{   
    clean();
    std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(minimumValue, maximumValue);

    SimpleNode* current = head;
	for(size_t index = 0; index < size; ++index) {
		insertAt(distrib(gen), current);
        current = current->next;
	}

}
void SimpleList::insertAt(int value, SimpleNode* previous)
{
    //Caso 1: Insere no primero nó da lista
    if(previous == nullptr && head->next != nullptr){
        head->next->data = value;
        return;
    }
    
    //Caso 2: Criar e insere no primeiro nó
    if(previous == nullptr && head->next == nullptr)
    {
        SimpleNode *node = newNode(value);
        node->next = head->next;
        head->next = node;
        return;
    }

    //Caso 3: O campo proximo do nodo aponta para NULL
    if(previous->next == nullptr)
    {
        SimpleNode *node = newNode(value);
        previous->next = node;
        return;
    }

    //Caso genérico: Insere em um posição existente
    previous->next->data = value;
}
bool SimpleList::swapValue(SimpleNode* nodeA, SimpleNode* nodeB)
{
    if(nodeA == nullptr || nodeA == nullptr)
    return false;
    
    if(nodeA == head || nodeB == head)
    return false;

    int temp;

    temp = nodeA->data;
    nodeA->data = nodeB->data;
    nodeB->data = temp;
    
    return true;
}
SimpleList:: SimpleNode* SimpleList::search(int value, unsigned& numberOfAccess)
{
    SimpleNode* current = head->next;
    numberOfAccess++;

    while(current != nullptr)
    {
        int currentValue = current->data;
        numberOfAccess++;

        if(currentValue == value)
        {
            numberOfAccess++;
            return current;
        }
        current = current->next;
        numberOfAccess++;
    }

    return nullptr;
}
SimpleList:: SimpleNode* SimpleList:: findMinimum(unsigned& numberOfAccess, int& lowest_value)
{
    SimpleNode* minNode = nullptr;
    SimpleNode* current = head->next;
    numberOfAccess++;

    lowest_value = INT32_MAX;

    while(current != nullptr)
    {
        if(current->data < lowest_value)
        {
            lowest_value = current->data;
            minNode = current;
            numberOfAccess++;
        }
        numberOfAccess++;

        current = current->next;
        numberOfAccess++;
    }
    
    return minNode;
}
void SimpleList:: displayList() const
{
    if(head->next == nullptr)
    {
        return;
    }

    SimpleNode* current = head->next;

    while(current != NULL)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
void SimpleList::displayReversedList() const
{
    SimpleNode* node = head->next;
    printfReverseOrder(node);
    std::cout << std::endl;
}
void SimpleList::printfReverseOrder(SimpleNode* node) const
{
    if(node == nullptr)
    return;

    printfReverseOrder(node->next);
    std::cout << node->data << " ";
} 
void SimpleList::clean() {
    SimpleNode* current = head->next;
    while(current != nullptr) {
        SimpleNode* temp = current;
        current = current->next;
        delete temp;
    }
    head->next = nullptr;
}

SimpleList::SimpleNode *SimpleList::getNodeByIndex(unsigned index) {
    SimpleNode *current = head->next;
    unsigned currentIndex = 0;
    while(current != nullptr && currentIndex != index){
        current = current->next;
        currentIndex++;
    }
    return current;
}

unsigned SimpleList::getIndexOfNode(SimpleNode *node) {
    SimpleNode *current = head->next;
    unsigned currentIndex = 0;
    while(current != nullptr && current != node){
        current = current->next;
        currentIndex++;
    }
    return currentIndex;
}