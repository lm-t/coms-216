#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

#include "linkedList.h"
#include <iostream>

// //Definition of the node
// template <class Type>
// struct nodeType {
//   int info;
//   nodeType *link;
// };

using namespace std;

template <class Type>
class unorderedLinkedList: public linkedListType<Type> {
public:
  bool search(const Type& searchItem) const;
  //Function to determine whether searchItem is in the list.
  //Postcondition: Returns true if searchItem is in the list, otherwise the value false is returned.

  void insertFirst(const Type& newItem);
  //Function to insert newItem at the beginning of the list.
  //Postcondition: first points to the new list, newItem is inserted at the beginning of the list, last points to the last node in the list, and count is incremented by 1.

  void insertLast(const Type& newItem);
  //Function to insert newItem at the end of the list.
  //Postcondition: first points to the new list, newItem is inserted at the end of the list, last points to the last node in the list, and count is incremented by 1.

  void deleteNode(const Type& deleteItem);
  //Function to tdelete deleteItem from the list.
  //Postcondition: If found, the node containing deleteItem is deleted from the list. first points to the first node, last points to the last node of the updated list, and count is decremented by 1.
};

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const {
  bool found = false;
  nodeType<Type> *current; //pointer to traverse the list

  current = this -> first; //start the search at the first node

  while (current != nullptr && !found) {
    if (current -> info == searchItem) {
      found = true;
    } else {
      current = current -> link;
    }
  }
  return found;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem) {
  nodeType<Type> *newNode; //pointer to create the new nodeType
  newNode = new nodeType<Type>; //create the new node
  newNode -> info = newItem; //store the new item in the node
  newNode -> link = this -> first; //insert newNode before first
  this -> first = newNode; //make first point to the actual node
  this -> count++; //increment count
  if (this -> last == nullptr) {
    this -> last = newNode;
  }
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem) {
  nodeType<Type> *newNode; //pointer to create the new node
  newNode -> info = newItem; //store the new item in the node
  newNode -> link = nullptr; //set the link field of newNode to nullptr
  if (this -> first == nullptr) {
    this -> first = newNode;
    this -> last = newNode;
    this -> count++;
  } else {
    this -> last -> link = newNode; //insert newNode after last
    this -> last = newNode; //make last point to the actual last node in the list
    this -> count++;
  }
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem) {
  nodeType<Type> *current; //pointer to traverse the list
  nodeType<Type> *trailCurrent; //pointer just before current
  bool found;

  if (this -> first == nullptr) {
    cout << "Cannot delete from an empty list." << endl;
  } else {
    if (this -> first -> info == deleteItem) {
      current = this -> first;
      this -> first = this -> first -> link;
      this -> count--;
      if (this -> first == nullptr) {
        this -> last = nullptr;
      }
      delete current;
    } else {
      found = false;
      trailCurrent = this -> first; //set trailCurrent to toint to the first node
      current = this -> first -> link; //set current to point to the second node

      while (current != nullptr && !found) {
        if (current -> info != deleteItem) {
          trailCurrent = current;
          current = current -> link;
        } else {
          found = true;
        }
      }

      if (found) {
        trailCurrent -> link = current -> link;
        this -> count--;

        if (this -> last == current) {
          this -> last = trailCurrent;
        }

        delete current;
      } else {
        cout << "The item to be deleted is not in the list." << endl;
      }
    }
  }
}
#endif
