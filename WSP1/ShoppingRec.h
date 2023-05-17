#ifndef NAMESPACE_SHOPPINGREC_H 
#define NAMESPACE_SHOPPINGREC_H

#include <cstdio>
#include <iostream>

namespace sdds {
	const int MAX_TITLE_LENGTH = 50;
	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;

	};
	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);
}

#endif