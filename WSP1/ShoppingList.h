#ifndef NAMESPACE_SHOPPINGLIST_H 
#define NAMESPACE_SHOPPINGLIST_H

#include <cstdio>
#include <iostream>


namespace sdds {
	
	bool loadList();
	void displayList();
	void removeItem(int index);
	void removeBoughtItems();
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();

}


#endif