// Milestone 3 
// File Name: Utilities.h
// Author: Mann Patel
// AuthorID: 134633205
// Date: 01/12/2021

/*
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and  assignments.
*/

#ifndef SDDS_UTILITIES_H_
#define SDDS_UTILITIES_H_

#include <iostream>

namespace sdds
{
	class Utilities
	{
		std::size_t m_widthField{ 1 };
		static char m_delimiter;

	public:

		void setFieldWidth(std::size_t newWidth);

		std::size_t getFieldWidth() const;

		std::string extractToken(const std::string& str, std::size_t& next_pos, bool& more);

		static void setDelimiter(char newDelimiter);

		static char getDelimiter();
	};

	
}


#endif

