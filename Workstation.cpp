// Milestone 3 
// File Name: Workstation.cpp
// Author: Mann Patel
// AuthorID: 134633205
// Date: 01/12/2021

/*
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and  assignments.
*/

#include "Workstation.h"

using namespace std;

std::deque<sdds::CustomerOrder> pending{};
std::deque<sdds::CustomerOrder> completed{};
std::deque<sdds::CustomerOrder> incomplete{};

namespace sdds
{
	Workstation::Workstation(const std::string& str):Station(str), m_pNextStation { nullptr }
	{ }

	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty())
		{
			m_orders.begin()->fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder()
	{
		bool attempt{ false };
		if (!m_orders.empty())
		{
			if (m_orders.front().isItemFilled(getItemName()) || getQuantity() <= 0)
			{
				if (m_pNextStation != nullptr)
				{
					*m_pNextStation += std::move(m_orders.front());
					m_orders.pop_front();
					attempt = true;
				}
				else
				{
					if (m_orders.front().isFilled())
					{
						completed.push_back(std::move(m_orders.front()));
					}
					else
					{
						incomplete.push_back(std::move(m_orders.front()));
					}

					m_orders.pop_front();
					attempt = true;
				}
			}
		}
		return attempt;
	}

	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const
	{
		os << getItemName() << " --> ";
		if (m_pNextStation != nullptr)
		{
			os << m_pNextStation->getItemName();
		}
		else
		{
			os << "End of Line";
		}
		os << endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}


