#include "easyfind.hpp"

int main(void)
{
    std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

    try
    {
        int num = 100;
        int ret = easyfind(v, num);
        std::cout << "Found element " << ret << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}