// Milestone 3 
// File Name: Utilities.cpp
// Author: Mann Patel
// AuthorID: 134633205
// Date: 01/12/2021

/*
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and  assignments.
*/

#include <iostream>
#include <string>
#include "Utilities.h"

using namespace std;

namespace sdds
{
	char Utilities::m_delimiter{ ' ' };

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	std::size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		string temp {};
		string errorMessage = "Delimeter was found at ";
		string exceptionMsg{};

		if (str[next_pos] == m_delimiter)
		{
			more = false;
			exceptionMsg = errorMessage + to_string(next_pos);
			throw exceptionMsg;
			
		}
		else if (str.find(m_delimiter, next_pos) == std::string::npos)
		{
			temp = str.substr(next_pos);
			more = false;
			next_pos = 0;
		}
		else 
		{
			temp = str.substr(next_pos, str.find_first_of(m_delimiter, next_pos) - next_pos);
			more = true;
			next_pos = str.find(m_delimiter, next_pos) + 1; 
		}

		if (m_widthField < temp.length())
		{
			m_widthField = temp.length();
		}

		return temp;
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}

