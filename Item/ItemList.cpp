//
// Created by Marthel Rodriguez on 11/14/23.
//

#ifndef SFMLTEMPLATE_ITEMLIST_CPP
#define SFMLTEMPLATE_ITEMLIST_CPP

#include "ItemList.h"


template<typename T>
ItemList<T>::ItemList() {

}

template<typename T>
ItemList<T>::ItemList(std::vector<ItemStruct> initlist) {

}

/**
 * methods
 * */

///TODO: delete this one.
template<typename T>
void ItemList<T>::pushItem(ItemStruct newItemData) {
    T newItem;
//    newItem.setOnClickFunction(newItemData.functPtr);
//    newItem.setFont(Font::getFont(OPEN_SANS));
//    newItem.setText(newItemData.text);
//    newItem.setTextColor(sf::Color::White);

    if (itemList.empty()) {
        newItem.setPosition({initPos.x, initPos.y + 30});
    } else {
        newItem.setPosition({itemList.back().getPos().x, itemList.back().getPos().y + 30});
    }
    itemList.push_back(newItem);
}


template<typename T>
void ItemList<T>::pushItem(T &newItem) {
    if (itemList.empty()) {
        itemList.push_back(newItem);
    } else {
//        sf::Vector2f newPos = sf::Vector2f(
//                );
        newItem.setPosition(
                {itemList.back().getPosition().x, itemList.back().getPosition().y + itemList.back().getSize().
                        y});
    }
    itemList.push_back(newItem);
}


template<typename T>
void ItemList<T>::popItem() {
    if (!itemList.empty())
        itemList.pop_back();
}

template<typename T>
void ItemList<T>::setInitPos(sf::Vector2f initPos) {
    this->initPos = initPos;
}

/**
 * iterators
 **/

template<typename T>
typename ItemList<T>::iterator ItemList<T>::begin() {
    return itemList.begin();
}

template<typename T>
typename ItemList<T>::iterator ItemList<T>::end() {
    return itemList.end();
}


template<typename T>
typename ItemList<T>::constIterator ItemList<T>::begin() const {
    return itemList.begin();
}

template<typename T>
typename ItemList<T>::constIterator ItemList<T>::end() const {
    return itemList.end();
}

/**
 * getters
 * */
template<typename T>
std::vector<T> &ItemList<T>::getItemList() {
    return itemList;
}

template<typename T>
T &ItemList<T>::getItem(int i) {
    return itemList(i);
}

#endif