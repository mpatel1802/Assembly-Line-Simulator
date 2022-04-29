// Milestone 3 
// File Name: LineManager.cpp
// Author: Mann Patel
// AuthorID: 134633205
// Date: 01/12/2021

/*
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and  assignments.
*/

#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		try
		{
			fstream file_open(file);
			Utilities util_obj;
			string st, nextSt, newSt;
			size_t n_pos{ 0 };
			bool found{ false };
			m_cntCustomerOrder = pending.size();


			while (getline(file_open, st))
			{
				nextSt = util_obj.extractToken(st, n_pos, found);
				newSt = found ? util_obj.extractToken(st, n_pos, found) : "";

				// As per the instructions for this constructor, I have used for_each().
				for_each(stations.begin(), stations.end(), [&](Workstation* ws)
					{
						if (ws->getItemName() == nextSt)
						{
							for_each(stations.begin(), stations.end(), [&](Workstation* ws2)
								{
									if (ws2->getItemName() == newSt)
									{
										ws->setNextStation(ws2);
									}
								});
							activeLine.push_back(ws);
						}
					});
				m_firstStation = activeLine.front();
			}
			file_open.clear();
			file_open.seekg(ios::beg);
		}
		catch (...)
		{
			cerr << "*** Something went wrong ***";
		}
	}

	void LineManager::linkStations()
	{
		vector<Workstation*> sorted;
		Workstation* current_station = m_firstStation;

		while (current_station != nullptr)
		{
			sorted.push_back(current_station);
			current_station = current_station->getNextStation();
		}

		activeLine = sorted;
	}

	bool LineManager::run(std::ostream& os)
	{
		static size_t curr_iteration{ 1 };
		bool filled{ false };

		size_t prev_orders = completed.size() + incomplete.size();

		os << "Line Manager Iteration: " << curr_iteration << endl;

		if (!pending.empty())
		{
			*m_firstStation += std::move(pending.front());
			pending.pop_front();
		}

		for_each(activeLine.begin(), activeLine.end(), [&](Workstation* ws)
			{
				ws->fill(os);
			});

		for_each(activeLine.begin(), activeLine.end(), [&](Workstation* ws)
			{
				ws->attemptToMoveOrder();
			});
		
		m_cntCustomerOrder -= ((completed.size() + incomplete.size()) - prev_orders);

		curr_iteration++;

		if (m_cntCustomerOrder <= 0)
		{
			filled = true;
		}

		return filled;
	}

	void LineManager::display(std::ostream& os) const
	{
		for (size_t i = 0; i < activeLine.size(); i++)
		{
			activeLine[i]->display(os);
		}
	}
}
