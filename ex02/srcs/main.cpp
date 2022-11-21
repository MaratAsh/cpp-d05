#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b1("Fryderyk Chopin", 135);
	ShrubberyCreationForm form_sh("home");
	std::cout << form_sh << std::endl;
	b1.signForm(form_sh);
	std::cout << std::endl << form_sh << std::endl;
	try
	{
		form_sh.execute(b1);
	}
	catch (const char * er)
	{
		std::cout << er << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "-------------------------------------------" << std::endl;
	Bureaucrat b2("Johann Bach", 40);
	RobotomyRequestForm form_2("Bach AForm");
	b2.signForm(form_2);
	std::cout << std::endl << form_2 << std::endl;
	try
	{
		form_2.execute(b2);
	}
	catch (const char * er)
	{
		std::cout << er << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "------------------------------------------" << std::endl << std::endl;
	Bureaucrat b3("Wolfgang Mozart", 30);
	PresidentialPardonForm form_3("Mozart AForm");
	b3.signForm(form_3);
	std::cout << std::endl << form_3 << std::endl;
	try
	{
		form_3.execute(b3);
	}
	catch (const char * er)
	{
		std::cout << er << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "------------------------------------------" << std::endl;
	Bureaucrat b4("Ludwig van Beethoven", 1);
	PresidentialPardonForm form_pres2("Beethoven AForm 2");
	b4.signForm(form_pres2);
	b4.executeForm(form_pres2);

	return (0);
}
