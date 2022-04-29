// Milestone 3 
// File Name: CustomerOrder.cpp
// Author: Mann Patel
// AuthorID: 134633205
// Date: 01/12/2021

/*
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and  assignments.
*/

#include <iomanip>
#include <algorithm>
#include "Utilities.h"
#include "CustomerOrder.h"

using namespace std;

namespace sdds
{
	size_t CustomerOrder::m_widthField{ 0 };

	CustomerOrder::CustomerOrder() :m_name{ }, m_product{ }, m_cntItem{ 0 }, m_lstItem{}
	{ }

	CustomerOrder::CustomerOrder(const std::string& str)
	{
		Utilities util_obj;
		bool found{ true };
		size_t f_pos{ 0 }, n_pos{ 0 }, i{ 0 };

		try
		{
			m_name = util_obj.extractToken(str, n_pos, found);
			m_product = util_obj.extractToken(str, n_pos, found);
			f_pos = n_pos;

			while (found)
			{
				util_obj.extractToken(str, n_pos, found);
				m_cntItem++;
			}

			m_lstItem = new Item * [m_cntItem];
			found = true;

			while (i < m_cntItem)
			{
				m_lstItem[i] = new Item(util_obj.extractToken(str, f_pos, found));
				i++;
			}

			if (m_widthField < util_obj.getFieldWidth())
			{
				m_widthField = util_obj.getFieldWidth();
			}
		}
		catch (string& errMessage)
		{
			cerr << errMessage;
		}
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& copyCustOrder)
	{
		throw string("Copy Operations are not allowed on CustomerOrder Object!");
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& moveCustOrder) noexcept
	{
		*this = std::move(moveCustOrder);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& m_assignCustOrder) noexcept
	{
		if (this != &m_assignCustOrder)
		{
			if (m_lstItem != nullptr)
			{
				for (size_t i = 0; i < m_cntItem; i++)
				{
					delete m_lstItem[i];
				}
			}
			delete[] m_lstItem;

			m_lstItem = m_assignCustOrder.m_lstItem;
			m_assignCustOrder.m_lstItem = nullptr;

			m_name = m_assignCustOrder.m_name;
			m_assignCustOrder.m_name = "";

			m_product = m_assignCustOrder.m_product;
			m_assignCustOrder.m_product = "";

			m_cntItem = m_assignCustOrder.m_cntItem;
			m_assignCustOrder.m_cntItem = 0u;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}

		delete[] m_lstItem;
		m_lstItem = nullptr;
	}

	bool CustomerOrder::isFilled() const
	{
		bool fill{ true };

		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (!m_lstItem[i]->m_isFilled)
			{
				fill = false;
			}
		}

		return fill;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool fill{ true };
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if ((m_lstItem[i]->m_itemName == itemName) && (!m_lstItem[i]->m_isFilled))
			{
				fill = false;
			}
		}
		return fill;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName())
			{
				os.setf(ios::right);
				os.fill(' ');
				os.width(11);

				if (station.getQuantity() >= 1)
				{
					station.updateQuantity();

					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;				
					os << "Filled ";
					os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
				else
				{	
					os << "    Unable to fill ";
					os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
				os.unsetf(ios::right);
			}
		}
	}


	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << endl;

		for (size_t i = 0; i < m_cntItem; i++)
		{
			// Formatting using IO manipulators
			os << "[" << setw(6) << right << setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
			os << setw(m_widthField) << left << setfill(' ') << m_lstItem[i]->m_itemName << " - ";

			if (m_lstItem[i]->m_isFilled)
			{
				os << "FILLED" << endl;
			}
			else
			{
				os << "TO BE FILLED" << endl;
			}
		}

	}




}