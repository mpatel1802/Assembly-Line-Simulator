// Milestone 3	
// File Name: Station.cpp
// Author: Mann Patel
// AuthorID: 134633205
// Date: 01/12/2021

/*
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and  assignments.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
	size_t Station::m_widthField{ 0 };
	int Station::id_generator{ 1 };

	Station::Station() :m_id{}, m_item{}, m_description{}, m_serialNumber{}, m_stock{}
	{ }

	Station::Station(const std::string& strObj)
	{
		Utilities temp{};
		size_t next_position{ 0 };
		bool found = true;

		try
		{
			m_item = temp.extractToken(strObj, next_position, found);

			m_serialNumber = stoi(temp.extractToken(strObj, next_position, found));

			m_stock = stoi(temp.extractToken(strObj, next_position, found));

			if (m_widthField < temp.getFieldWidth())
			{
				m_widthField = temp.getFieldWidth();
			}

			m_description = temp.extractToken(strObj, next_position, found);
		}
		catch (string& msg)
		{
			cerr << msg;
		}

		m_id = id_generator++;
	}

	const std::string& Station::getItemName() const
	{
		return m_item;
	}

	size_t Station::getNextSerialNumber()
	{
		m_serialNumber++;
		return m_serialNumber - 1;
	}

	size_t Station::getQuantity() const
	{
		return m_stock;
	}

	void Station::updateQuantity()
	{
		m_stock -= 1;
		if (m_stock < 0)
		{
			m_stock = 0;
		}
	}

	void Station::display(std::ostream& os, bool full) const
	{
		os.setf(ios::right);
		os << "[";
		os.fill('0');
		os.width(3);
		os << m_id << "]";
		os.unsetf(ios::right);
		os << " Item: ";
		os.width(m_widthField);
		os.setf(ios::left);
		os.fill(' ');
		os << m_item;
		os.unsetf(ios::left);
		os << " [";
		os.width(6);
		os.setf(ios::right);
		os.fill('0');
		os << m_serialNumber << "]";
		os.unsetf(ios::right);

		if (full)
		{
			os << " Quantity: ";
			os.width(m_widthField);
			os.setf(ios::left);
			os.fill(' ');
			os << m_stock;
			os << " Description: " << m_description << endl;
			os.unsetf(ios::left);
		}
		else
		{
			os << endl;
		}

	}
}
