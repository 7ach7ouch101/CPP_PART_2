/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:15:52 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/19 11:28:27 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	check_date(int year, int month, int day)
{
	if(year == 2009 && month == 1 && day == 1)
		return (0);
	if (year < 2009 || year > 2022)
		return (0);
	if (month < 1 || month > 12)
		return (0);
	if (day < 1 || day > 31)
		return (0);
	if( (month == 2) && (day > 29) )
		return (0);
	if( (month == 2) && (year % 4 != 0) && (day == 29))
		return (0);
	if(day == 31)
	{
		if( (month == 4) || (month == 6) || (month == 9) || (month == 11))
			return (0);
	}
	return (1);
}

int	check_date_data(int year, int month, int day)
{
	if(year == 2009 && month == 1 && day == 1)
		return (0);
	if (year < 2009 || year > 2022)
		return (0);
	if (month < 1 || month > 12)
		return (0);
	if (day < 1 || day > 31)
		return (0);
	if( (month == 2) && (day > 29) )
		return (0);
	if( (month == 2) && (year % 4 != 0) && (day == 29))
		return (0);
	if(day == 31)
	{
		if((month == 4) || (month == 6) || (month == 9) || (month == 11))
			return (0);
	}
	return (1);
}

int Bitcoin::check_date_and_value(std::string s)
{
	int count = 0;
	size_t y = s.find('-');
	std::string year = s.substr(0, y);
	size_t m = s.find('-', y);
	std::string month = s.substr((m + 1), 2);
	size_t d = s.find('-', (m + 1));
	std::string day = s.substr((d + 1), 2);
	size_t v = s.find(',',d);
	std::string value = s.substr((v + 1), (s.length() - v));

	int year_n = std::atof(year.c_str()) ;
	int month_n = std::atof(month.c_str());
	int day_n = std::atof(day.c_str());

	if(check_date_data(year_n ,month_n , day_n) == 1)
	{
		for(size_t i = 0; i < value.length(); i++)
		{
			if ((value[0] == '.' || value[(value.length() - 1)] == '.') || (value[i] <= '0' && value[i] >= '9') || (value[0] == '-'))
				return (0);
			if(value[i] == '.')
				count++;
			if(count > 1)
				return (0);
		}
		this->data[year + '-' + month + '-' + day] = std::atof(value.c_str());
		return (1);
	}
	
	return (0);
}

int Bitcoin::parse_data()
{
	std::ifstream file;
	std::string s;
	file.open("data.csv");
	if(file)
	{
		std::getline(file, s);
		if(s.empty())
			return (std::cout << "File data is empty" << std::endl, 0);
		while(std::getline(file, s))
		{
			while(s.length() == 0)
				std::getline(file, s);
			if(check_date_and_value(s) == 0)
			{
				std::cout << "Error: missing values in data.csv" << std::endl;
				return (0);
			}
		}
	}
	else
		return (std::cout << "File does not exists" << std::endl, 0);
	file.close();
	return (1);
}


int Bitcoin::check_date_and_value2(std::string s)
{
	int error = 0;
	int year_n = 0;
	int month_n = 0;
	int day_n = 0;	
	int value_n = 0;
	int count = 0;
	int number = 0;
	int i = 0;

	while(s[i] == ' ' || s[i] == '\t')
		i++;
	s.erase(0, i);
	if(s[4] == '-' && s[7] == '-')
	{
		size_t y = s.find('-');
		if(y == std::string::npos)
			error++;
		std::string year = s.substr(0, y);
		if(std::atof(year.c_str()) != 0.0 && year.length() > 0)
			year_n = std::atof(year.c_str());
		else
			error++;
		size_t m = s.find('-', y);
		if(m == std::string::npos)
			error++;
		std::string month = s.substr((m + 1), 2);
		if(std::atof(month.c_str()) != 0.0 && month.length() > 0)
			month_n = std::atof(month.c_str());
		else
			error++;
		size_t d = s.find('-', (m + 1));
		if(d == std::string::npos)
			error++;
		std::string day = s.substr((d + 1), 2);
		if(std::atof(day.c_str()) != 0.0 && day.length() > 0)
			day_n = std::atof(day.c_str());
		else
			error++;
		size_t v = s.find('|',d);
		if(v == std::string::npos)
			error++;
		if (!(s[v + 1]))
			error++;
		std::string value = s.substr((v + 1), (s.length() - v));
		if(std::atof(value.c_str()) != 0.0 && value.length() > 0)
			value_n = std::atof(value.c_str());
		else
			error++;
		std::string in = (year + "-" + month + "-" + day);
		if((check_date(year_n , month_n , day_n) == 0) || (error > 0))
			return (std::cout << "Error: bad input => " << in << std::endl, 1);
		for(size_t i = 0; i < value.length(); i++)
		{	
			if(value[i] == '-')
				return (std::cout << "Error: not a positive number." << std::endl ,1);
			if(value[i] == ' ' || value[i] == '\t')
				continue ;
			if ((!(value[i] >= '0' && value[i] <= '9')))
				return (std::cout << "Error: bad input => " << in << std::endl, 1);
			if(number == 0)
			{
				while( (value[i] >= '0' && value[i] <= '9') || (value[i]  == '.'))
				{
					if(value[i] == '.')
					{
						count++;
						if(count > 1)
							return (std::cout << "Error: bad input => " << in << std::endl, 1);
					}
					i++;
					number++;
				}
			}
			else
				return (std::cout << "Error: bad input => " << in << std::endl, 1);
		}
		int value_int = std::atof(value.c_str());
		if(value_int > 1000 || value_int < 0)
			return (std::cout << "Error: too large a number." << std::endl ,1);
		std::map<std::string, double>::iterator it;
		it = data.find(in);
		if(it != data.end())
			std::cout << in << " => " << std::atof(value.c_str()) << " = " << (it->second * std::atof(value.c_str())) << std::endl;
		else
		{
			it = data.lower_bound(in);
			it--;
			std::cout << in << " => " << std::atof(value.c_str()) << " = " << (it->second * std::atof(value.c_str())) << std::endl;
		}
	}
	else
		return (std::cout << "Error: bad input => " << s << std::endl, 1);
	return (1);
}

int Bitcoin::parse_input(std::string argvv)
{
	std::ifstream file;
	std::string s;
	file.open(argvv);
	if(file)
	{
		while(std::getline(file, s))
		{
			while(s.length() == 0)
				std::getline(file, s);
			if (!(s == "date | value"))
				return (std::cout << "bad input in input.txt" << std::endl, 0);
			else
				break ;
		}
		if(s.empty())
			return (std::cout << "File input is empty" << std::endl, 0);
		while(std::getline(file, s))
		{

			if(s.empty())
				continue;
			if(check_date_and_value2(s) == 0)
				return (0);
		}
	}
	else
		std::cout << "File does not exists" << std::endl;
	file.close();
	return (0);
}