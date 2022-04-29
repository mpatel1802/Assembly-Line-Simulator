// Milestone 3 
// File Name: CustomerOrder.h
// Author: Mann Patel
// AuthorID: 134633205
// Date: 01/12/2021

/*
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and  assignments.
*/

#ifndef SDDS_CUSTOMERORDER_H_
#define SDDS_CUSTOMERORDER_H_

#include <iostream>
#include "Station.h"

namespace sdds
{
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{		
		std::string m_name{};
		std::string m_product{};
		std::size_t m_cntItem{};
		Item** m_lstItem{};
		static size_t m_widthField;

	public:
		// Default Constructor
		CustomerOrder();

		// 1-arg Constructor
		CustomerOrder(const std::string& str);

		// Copy Contructor
		CustomerOrder(const CustomerOrder& copyCustOrder);

		// Copy assignment operator
		CustomerOrder& operator=(const CustomerOrder& c_assignCustOrder) = delete;

		// Move Contructor
		CustomerOrder(CustomerOrder&& moveCustOrder) noexcept;

		// Move assignment operator
		CustomerOrder& operator=(CustomerOrder&& m_assignCustOrder) noexcept;

		// Queries
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void display(std::ostream& os) const;

		// Modifier
		void fillItem(Station& station, std::ostream& os);

		// Destructor
		~CustomerOrder();
	};
}

#endif