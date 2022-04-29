// Milestone 3 
// File Name: Station.h
// Author: Mann Patel
// AuthorID: 134633205
// Date: 01/12/2021

/*
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and  assignments.
*/

#ifndef SDDS_STATION_H_
#define SDDS_STATION_H_

#include <iostream>

namespace sdds
{
	class Station
	{
		int m_id{};
		std::string m_item{};
		std::string m_description{};
		unsigned int m_serialNumber{};
		unsigned int m_stock{};
		static std::size_t m_widthField;
		static int id_generator;

	public:

		Station();

		Station(const std::string& strObj);

		const std::string& getItemName() const;

		std::size_t getNextSerialNumber();

		std::size_t getQuantity() const;

		void updateQuantity();

		void display(std::ostream& os, bool full) const;
	};

	
}


#endif
