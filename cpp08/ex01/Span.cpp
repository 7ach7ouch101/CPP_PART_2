#include "Span.hpp"
#include <limits>

Span::Span()
{
	std::cout << "default constructor called." << std::endl;
	this->s = 0;
	this->index = 0;
}

Span::Span(unsigned int N)
{
	std::cout << "constructor called." << std::endl;
	this->s = N;
	this->index = 0;
}

Span::Span(const Span &span)
{
	std::cout << "copy constructor called." << std::endl;
	this->s = span.s;
	this->v = span.v;
	this->index = 0;
}

Span &Span::operator=(const Span &span)
{
	std::cout << "assignation operator called." << std::endl;
	this->s = span.s;
	this->v = span.v;
	this->index = span.index;
	return (*this);
}

Span::~Span()
{
	std::cout << "destructor called." << std::endl;
}

void Span::addNumber(int num)
{
	if (this->index < this->s)
	{
		this->v.push_back(num);
		this->index++;
	}
	else
		throw Span::FULL();
}

int Span::shortestSpan( void )
{
	int ret = 2147483647;
	std::vector<int>::iterator it = this->v.begin();
	std::vector<int>::iterator it2 = this->v.begin();
	it2++;

	if (this->index <= 1)
		throw Span::Nospancanbefound();
	while (it2 != this->v.end())
	{
		if (std::abs(*it - *it2) < ret)
			ret = std::abs(*it - *it2);
		it2++;
		it++;
	}
	return (ret);
}

int Span::longestSpan( void )
{
	int ret = 0;
	std::vector<int>::iterator it = this->v.begin();
	std::vector<int>::iterator it2 = this->v.begin();
	it2++;

	if (this->index <= 1)
		throw Span::Nospancanbefound();
	while (it2 != this->v.end())
	{
		if (std::abs(*it - *it2) > ret)
			ret = std::abs(*it - *it2);
		it2++;
		it++;
	}
	return (ret);
}

void Span::addNumbers(std::vector<int>::iterator it, std::vector<int>::iterator it2)
{
	while (it != it2)
	{
		this->addNumber(*it);
		it++;
	}
}

const char* Span::FULL::what() const throw()
{
	return ("Span is full.");
}

const char* Span:: Nospancanbefound::what() const throw()
{
	return ("No span can be found!");
}