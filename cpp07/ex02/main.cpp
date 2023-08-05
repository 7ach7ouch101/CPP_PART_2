#include "Array.hpp"

int main(void)
{
    Array<int> a(3);
	a[0] = 50;
	a[1] = 100;
	a[2] = 30;
	int s = a.size();
	std::cout << s << std::endl;
	std::cout << a[1] << std::endl;
	std::cout << "----------------------" << std::endl;
	try
	{
	    Array<int> b;
        std::cout << b.size() << std::endl;
		std::cout << b[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----------------------" << std::endl;
	try
	{
    	Array<char> b(3);
		b[0] = 'a';
		b[1] = 'b';
		b[2] = 'c';
        std::cout << b[2] << std::endl;
		std::cout << b[5] << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';	
	}
	std::cout << "----------------------" << std::endl;
	Array<int> c(a);
	for (unsigned int i = 0; i < c.size(); i++)
	{
		std::cout << c[i] << "\n";
	}
    return (0);
}