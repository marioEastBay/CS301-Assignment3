//
// Created by Mario O Salinas on 9/13/23.
//

#ifndef CS301_ASSIGNMENT3_ITEMTYPE_H
#define CS301_ASSIGNMENT3_ITEMTYPE_H
#include <fstream>
const int MAX_ITEMS = 5;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType
{
public:
    ItemType();
    RelationType ComparedTo(ItemType) const;
    void Print(std::ostream&) const;
    void Initialize(int number);
private:
    int value;
};

ItemType::ItemType()
{
    value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const
{
    if (value < otherItem.value)
        return LESS;
    else if (value > otherItem.value)
        return GREATER;
    else return EQUAL;
}

void ItemType::Initialize(int number)
{
    value = number;
}

void ItemType::Print(std::ostream& out) const
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
    out << value;
}

#endif //CS301_ASSIGNMENT3_ITEMTYPE_H
