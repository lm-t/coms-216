//linkedList.h
#include <iostream>
#include "linkedListIterator.h"

using namespace std;

template <class Type>
class linkedListType {
public:
  const linkedListType<Type>& operator = (const linkedListType<Type>&);
  //Overload the assignment operator.

  void initializeList();
  //Initialize the list to an empty state.
  //Postcondition: first = nullptr, last = nullptr, count = 0;

  bool isEmptyList() const;
  //Function to determine wheter the list is empty.
  //Postcondition: Returns tru if the list is empty, otherwise it returns false.

  void print() const;
  //Function to output the data contained in each node.
  //Postcondition: none

  void printListReverse() const;
  //Function to output the data in reverse.

  int length() const;
  //Function to return the number of nodes in the list.
  //Postcondition: The value of count is returned.

  void destroyList();
  //Function to delete all the nodes from the list.
  //Postcondition: first = nullptr, last = nullptr, count = 0;

  Type front() const;
  //Function to return the first element of the list.
  //Precondition: The list myst exist and must not be empty.
  //Postcondition: If the list is empty, the program terminates; otherwise, the first element of the list is returned.

  Type back() const;
  //Function to return the last element of the list.
  //Precondition: The list must exist and must not be empty.
  //Postcondition: If the list is empty, the program terminates; otherwise, the last element of the list is returned.

  virtual bool search(const Type& searchItem) const = 0;
  //Function to determine wheter searchItem is in the list.
  //Postcondition: Returns true if searchItem is in the list, otehrwise the value false is returned.

  virtual void insertFirst(const Type& newItem) = 0;
  //Function to insert newItem at the beginning of the list.
  //Postcondition: first points to the new list, newItem is inserted at the beginning of thelist, last points to the last node in the list, and count is incremented by 1.

  virtual void insertLast(const Type& newItem) = 0;
  //Function to insert newItem at the end of the list.
  //Postcondition: first points to the new list, newItem is inserted at the end of thelist, last points to the last node in the list, and count is incremented by 1.

  virtual void deleteNode(const Type& deleteItem) = 0;
  //Function to delete deleteItem from the list.
  //Postcondition: If found, the node containing deleteItem is deleted from the list. first points to the first node, last points to the last node of the updated list, and count is decremented by 1.

  linkedListIterator<Type> begin();
  //Function to return an iterator at the beginning of the linked list.
  //Postcondition: Returns an iterator such that current is set to first.

  linkedListIterator<Type> end();
  //Function to return an interator one element past the last element of the linked list.
  //Postcondition: Returns an iterator such that current is set to nullptr.

  linkedListType();
  //default constructor
  //Initializes the list to an empty state.
  //Postcondition: first = nullptr, last = nullptr, count = 0;

  linkedListType(const linkedListType<Type>& otherList);
  //copy constructor

  ~linkedListType();
  //destructor
  //Deletes all the nodes from the list.
  //Postcondition: The list object is destroyed.

protected:
  int count; //variable to store the number of elements in the list
  nodeType<Type> *first; //pointer to the first node of the list
  nodeType<Type> *last; //pointer to the last node of the list

private:
  void copyList(const linkedListType<Type>& otherList);
  //Function to make a copy of otherList.
  //Postcondition: A copy of otherList is created and assigned to this list.

  void reversePrint(nodeType<Type> *current) const;
  //Function to recursivley output data in reverse.
};

template <class Type>
bool linkedListType<Type>::isEmptyList() const {
  return (first == nullptr);
}

template <class Type>
linkedListType<Type>::linkedListType() {
  first = nullptr;
  last = nullptr;
  count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList() {
  nodeType<Type> *temp;
  while (first != nullptr) {
    temp = first;
    first = first -> link;
    delete temp;
  }
  last = nullptr;
  count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList() {
  destroyList();
}

template <class Type>
void linkedListType<Type>::print() const {
  nodeType<Type> * current;
  current = first;
  while (current != nullptr) {
    cout << current -> info << " ";
    current = current -> link;
  }
}

template <class Type>
int linkedListType<Type>::length() const {
  return count;
}

template <class Type>
Type linkedListType<Type>::front() const {
  assert(first != nullptr);
  return first -> info;
}

template <class Type>
Type linkedListType<Type>::back() const {
  assert(last != nullptr);
  return last -> info;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin() {
  linkedListIterator<Type> temp(first);
  return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end() {
  linkedListIterator<Type> temp(nullptr);
  return temp;
}

template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList) {
  nodeType<Type> *newNode; //pointer to create a node
  nodeType<Type> *current; //pointer to traverse the list

  if (first != nullptr) {
    destroyList();
  }
  if (otherList.first == nullptr) {
    first = nullptr;
    last = nullptr;
    count = 0;
  } else {
    current = otherList.first; //current points to the list to be copied
    count = otherList.count;

    //copy the first node
    first = new nodeType<Type>;
    first -> info = current -> info;
    first -> link = nullptr;

    last = first;

    current = current -> link;

    while (current != nullptr) {
      newNode = new nodeType<Type>;
      newNode -> info = current -> info;
      newNode -> link = nullptr;

      last -> link = newNode;
      last = newNode;

      current = current -> link;
    } //end while
  } // end else
}

template <class Type>
linkedListType<Type>::~linkedListType() {
  destroyList();
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList) {
  first = nullptr;
  copyList(otherList);
} //end of copy constructor

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList) {
  if (this != &otherList) {
    copyList(otherList);
  }
  return *this;
}

template <class Type>
void linkedListType<Type>::reversePrint(nodeType<Type> *current) const {
  if (current != nullptr) {
    reversePrint(current->link); //print to tail
    cout << current->info << " "; //print the node
  }
}

template <class Type>
void linkedListType<Type>::printListReverse() const {
  reversePrint(first);
  cout << endl;
}
