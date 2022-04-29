// Milestone 3 
// File Name: Workstation.h
// Author: Mann Patel
// AuthorID: 134633205
// Date: 01/12/2021

/*
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and  assignments.
*/

#ifndef SDDS_WORKSTATION_H_
#define SDDS_WORKSTATION_H_

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

extern std::deque<sdds::CustomerOrder> pending;
extern std::deque<sdds::CustomerOrder> completed;
extern std::deque<sdds::CustomerOrder> incomplete;


namespace sdds
{

	class Workstation :public Station
	{
		std::deque<sdds::CustomerOrder> m_orders{};
		Workstation* m_pNextStation{};

	public:

		Workstation(const std::string& str);

		void fill(std::ostream& os);

		bool attemptToMoveOrder();

		void setNextStation(Workstation* station = nullptr);

		Workstation* getNextStation() const;

		void display(std::ostream& os) const;

		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}

#endif
