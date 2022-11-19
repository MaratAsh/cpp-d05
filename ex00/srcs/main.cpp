#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Lol", 1);
		std::cout << a << std::endl;
		a.decGrade();
		std::cout << a << std::endl;
		a.incGrade();
		std::cout << a << std::endl;
		a.incGrade();
		std::cout << a << std::endl;
		std::cout << "ALL OK" << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "-----     Next Bureaucrat     -----" << std::endl;

	try
	{
		Bureaucrat a("Kek", -1);
		std::cout << a << std::endl;
		std::cout << "ALL OK" << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "-----     Next Bureaucrat     -----" << std::endl;

	try
	{
		Bureaucrat a("Cheburek", 150);
		std::cout << a << std::endl;
		a.decGrade();
		std::cout << a << std::endl;
		std::cout << "ALL OK" << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return (0);
}
