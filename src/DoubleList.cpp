#include "../include/DoubleList.hpp"

DoubleList::DoubleList() {
    head = new DoubleNode;
    head->next = nullptr;
    head->previous = nullptr;
}

DoubleList::~DoubleList() {
    clean();
    delete head;
    std::cout << "Deletando";
}

void DoubleList::getList(size_t size) {
    clean();

    DoubleNode* current = head;
    for(size_t index = 0; index < size; ++index){
        int value;
        std::cin >> value;
        insertAt(value, current);
        current = current->next;
    }
}

void DoubleList::getRandomList(size_t size, int minimumValue, int maximumValue) {
    clean();
    
    std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(minimumValue, maximumValue);

    DoubleNode* current = head;
	for(size_t index = 0; index < size; ++index) {
		insertAt(distrib(gen), current);
        current = current->next;
	}
}


void DoubleList::insertAt(int value, DoubleNode *previous) {
    if(previous == nullptr){
        DoubleNode* newNode = new DoubleNode;
        newNode->data = value;
        newNode->previous = head;
        newNode->next = head->next;
        head->next = newNode;
        return;
    }

    if(previous->next != nullptr){
        previous->next->data = value;
        return;
    }
    
    DoubleNode* newNode = new DoubleNode;
    newNode->data = value;
    newNode->previous = previous;
    newNode->next = previous->next;
    previous->next = newNode;
    
    return;
}

bool DoubleList::swapValue(DoubleNode *nodeA, DoubleNode *nodeB) {
    if(nodeA == head || nodeA == nullptr || nodeB == head || nodeB == nullptr){
        return false;
    }

    int temp = nodeA->data;
    nodeA->data = nodeB->data;
    nodeB->data = temp;   
    return true;
}

DoubleList::DoubleNode *DoubleList::search(int value, unsigned &numberOfAccess){ 
    DoubleNode* current = head->next;
    numberOfAccess = 1;
    
    while(current != nullptr){
        int currentValue = current->data;
        if(currentValue == value){
            numberOfAccess += 2;
            return current;
        }
        
        current = current->next;
        numberOfAccess += 3;
    }

    return nullptr;
}

DoubleList::DoubleNode *DoubleList::findMinimum(unsigned &numberOfAccess, int &minimum){
    minimum = INT32_MAX;
    DoubleNode* minNode = nullptr;
    
    DoubleNode* current = head->next;
    numberOfAccess = 1;
    
    while(current != nullptr){
        int currentValue = current->data;
        if(currentValue < minimum){
            minNode = current;
            minimum = currentValue;
        }
        
        current = current->next;
        numberOfAccess += 3;
    }

    return minNode;
}

void DoubleList::displayList() const {
    DoubleNode* current = head->next;
    while(current != nullptr){
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout << std::endl;
}

void DoubleList::displayReversedList() const {
    printfReversedOrder(head->next);
    std::cout << std::endl;
}

DoubleList::DoubleNode *DoubleList::getNodeByIndex(unsigned index) const {
    DoubleNode *current = head->next;
    unsigned currentIndex = 0;
    while(current != nullptr && currentIndex != index){
        current = current->next;
        currentIndex++;
    }
    return current;
}

unsigned DoubleList::getIndexOfNode(DoubleNode *node) const {
    DoubleNode *current = head->next;
    unsigned currentIndex = 0;
    while(current != nullptr && current != node){
        current = current->next;
        currentIndex++;
    }
    return currentIndex;
}

void DoubleList::printfReversedOrder(DoubleNode* node) const {
    if(node == nullptr){
        return;
    }

    printfReversedOrder(node->next);
    std::cout << node->data << ' ';
}

void DoubleList::clean() {
    DoubleNode* current = head->next;
    while(current != nullptr){
        DoubleNode* temp = current;
        current = current->next;
        delete temp;
    }
}
