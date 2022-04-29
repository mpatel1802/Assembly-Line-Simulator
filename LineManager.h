// Milestone 3 
// File Name: LineManager.h
// Author: Mann Patel
// AuthorID: 134633205
// Date: 01/12/2021

/*
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and  assignments.
*/

#ifndef SDDS_LINEMANAGER_H_
#define SDDS_LINEMANAGER_H_

#include <iostream>
#include <vector>
#include "Workstation.h"

namespace sdds
{
	class LineManager
	{
		std::vector<Workstation*> activeLine{};
		size_t m_cntCustomerOrder{};
		Workstation* m_firstStation{};

	public:

		LineManager(const std::string& file, const std::vector<Workstation*>& stations);

		void linkStations();

		bool run(std::ostream& os);

		void display(std::ostream& os) const;
	};
}
#endif 

