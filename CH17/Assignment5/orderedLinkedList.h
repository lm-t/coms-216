//orderedLinkedList.h
#ifndef H_orderedListType
#define H_orderedListType

#include "linkedList.h"

using namespace std;

template <class Type>
class orderedLinkedList : public linkedListType<Type> {
public:
  bool search(const Type& searchItem) const;
  //Function to determine whether searchItem is in the list.
  //Postcondition: Returns true if searchItem is in the list, otherwise the value false is returned.

  void insert(const Type& newItem);
  //Function to insert newItem in the list.
  //Postcondition: first points to the new list, newItem is inserted at the proper place in the list, and count is incremented by 1.

  void insertFirst(const Type& newItem);
  //Function to insert newItem at the beginning of the list.
  //Postcondition: first points to the new list, newItem is insertedat the proper place in the list, last points to the last node in the list, and count is incremented by 1.

  void insertLast(const Type& newItem);
  //Function to insert newItem at the end of the list.
  //Postcondition: first points to the new list, newItem is inserted at the proper place in the list, last points to the last node in the list, and count is incremented by 1.

  void deleteNode(const Type& deleteItem);
  //Function to delete deleteItem from the list.
  //Postcondition: If found, the node containing deleteItem is deleted from the list; first points to the first node of the new list, and count is decremented by 1. If deleteItem is not in the list, and appropiate message is printed.
};

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const {
  bool found = false;
  nodeType<Type> *current; //pointer to traverse the list

  current = this->first; //start the search at the first node

  while (current != nullptr && !found) {
    if (current->info >= searchItem) {
      found = true;
    } else {
      current = current->link;
    }
  }

  if (found) {
    found = (current->info == searchItem); //test for equality
  }

  return found;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem) {
  nodeType<Type> *current; //pointer to traverse the list
  nodeType<Type> *trailCurrent; //pointer just before current
  nodeType<Type> *newNode; //pointer to create a node

  bool found;

  newNode = new nodeType<Type>;
  newNode->info = newItem;
  newNode->link = nullptr;

  if (this->first == nullptr) {
    this->first = newNode;
    this->last = newNode;
    this->count++;
  } else {
    current = this->first;
    found = false;

    while (current != nullptr && !found) {
      if (current->info >= newItem) {
        found = true;
      } else {
        trailCurrent = current;
        current = current->link;
      }
    }

    if (current == this->first) {
      newNode->link = this->first;
      this->first = newNode;
      this->count++;
    } else {
      trailCurrent->link = newNode;
      newNode->link = current;

      if (current == nullptr) {
        this->last = newNode;
      }

      this->count++;
    }
  }
}

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem) {
  insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem) {
  insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem) {
  nodeType<Type> *current; //pointer to traverse the list
  nodeType<Type> *trailCurrent; //pointer just before current
  bool found;

  if (this->first == nullptr) {
    cout << "Cannot delete from an empty list." << endl;
  } else {
    current = this->first;
    found = false;

    while (current != nullptr && !found) {
      if (current->info >= deleteItem) {
        found = true;
      } else {
        trailCurrent = current;
        current = current->link;
      }
    }

    if (current == nullptr) {
      cout << "The item to be deleted is not int the list." << endl;
    } else {
      if (current->info == deleteItem) {
        if (this->first == current) {
          this->first = this->first->link;
          if (this->first == nullptr) {
            this->last = nullptr;
          }
          delete current;
        } else {
          trailCurrent->link = current->link;
          if (current == this->last) {
            this->last = trailCurrent;
          }
          delete current;
        }
        this->count--;
      } else {
        cout << "The item to be deleted is not in the list." << endl;
      }
    }
  }
}
#endif
