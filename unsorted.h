#include "ItemType.h"

class UnsortedType {
public:
  UnsortedType();
  // Constructor
  
  void MakeEmpty();
  // Function: Returns the list to the empty state.
  // Post:  List is empty.
  
  bool IsFull() const;
  // Function:  Determines whether list is full.
  // Pre:  List has been initialized.
  // Post: Function value = (list is full)

  int GetLength() const;
  // Function: Determines the number of elements in list.
  // Pre:  List has been initialized.
  // Post: Function value = number of elements in list

  ItemType GetItem(ItemType, bool&);
  // Function: Retrieves list element whose key matches item's key (if
  //           present).
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then found = true and someItem is returned.
  // 	 otherwise found = false and item is returned.
  //       List is unchanged.

  void PutItem(ItemType item);
  // Function: Adds item to list.
  // Pre:  List has been initialized.
  //       List is not full.
  //       item is not in list.
  // Post: item is in list.

  void DeleteItem(ItemType item);
  // Function: Deletes the element whose key matches item's key.
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  //       One and only one element in list has a key matching item's key.
  // Post: No element in list has a key matching item's key.

  void ResetList();
  // Function: Initializes current position for an iteration through the list.
  // Pre:  List has been initialized.
  // Post: Current position is prior to list.

  ItemType GetNextItem();
  // Function: Gets the next element in list.
  // Pre:  List has been initialized and has not been changed since last call.
  //       Current position is defined.
  //       Element at current position is not last in list.
  //	     
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

private:
  int length;
  ItemType info[MAX_ITEMS];
  int currentPos;
};

UnsortedType::UnsortedType()
{
    length = 0;
}
bool UnsortedType::IsFull() const
{
    return (length == MAX_ITEMS);
}
int UnsortedType::GetLength() const
{
    return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the
//       list and a copy of that element has been returned;
//       otherwise, item is returned.
{
    bool moreToSearch;
    int location = 0;
    found = false;

    moreToSearch = (location < length);

    while (moreToSearch && !found)
    {
        switch (item.ComparedTo(info[location]))
        {
            case LESS    :
            case GREATER : location++;
                moreToSearch = (location < length);
                break;
            case EQUAL   : found = true;
                item = info[location];
                break;
        }
    }
    return item;
}
void UnsortedType::MakeEmpty()
// Post: list is empty.
{
    length = 0;
}
void UnsortedType::PutItem(ItemType item)
// Post: item is in the list.
{
    info[length] = item;
    length++;
}
void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    int location = 0;

    while (item.ComparedTo(info[location]) != EQUAL)
        location++;

    info[location] = info[length - 1];
    length--;
}
void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
    currentPos = -1;
}

ItemType UnsortedType::GetNextItem()
// Pre:  ResetList was called to initialized iteration.
//       No transformer has been executed since last call.
//       currentPos is defined.
// Post: item is current item.
//       Current position has been updated.
{
    currentPos++;
    return info[currentPos];
}

