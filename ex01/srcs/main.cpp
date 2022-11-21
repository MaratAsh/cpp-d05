#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat a("Lol", 1);
		Bureaucrat b(a);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		a.decGrade();
		std::cout << a << std::endl;
		a.incGrade();
		std::cout << a << std::endl;
		a.incGrade();
		std::cout << a << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout << RED << ex.what() << RESET << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Form b("Form 1", 0, 15); // FAIL
		Form c(b);
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout << RED << ex.what() << RESET << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Form b("Form 1", 100, 151); // FAIL
		std::cout << b << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout << RED << ex.what() << RESET << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Form b("Form 1", 100, 15); // FAIL
		Bureaucrat b2("Kek", 101);
		b.beSigned(b2);
		std::cout << b << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout << RED << ex.what() << RESET << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Form b("Form 1", 100, 15); //
		Bureaucrat b2("Cheburek", 100);
		b.beSigned(b2);
		b.beSigned(b2);
		std::cout << b << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout << RED << ex.what() << RESET << std::endl;
	}
	catch (const char * ex)
	{
		std::cout << RED << ex << RESET << std::endl;
	}

	std::cout << std::endl;
	Form b("Form 1", 100, 15); // нельзя подписать по рангу
	Bureaucrat b2("LolKek", 101);
	b2.signForm(b);
	std::cout << std::endl << b << std::endl;

	std::cout << std::endl;
	Form c("Form 2", 100, 15); // подписываем
	Bureaucrat c2("LolKek", 100);
	c2.signForm(c);
	c2.signForm(c); // нельзя второй раз подписать
	std::cout << std::endl << c << std::endl;

	return (0);
}
