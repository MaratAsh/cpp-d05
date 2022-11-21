#include "Intern.hpp"

int main()
{
	Bureaucrat me("Marat", 20);

	Intern a;
	AForm *f = a.makeForm("robotomy form", "sweet");

	std:: cout << *f << std::endl;
	me.signForm(*f);
	try
	{
		f->execute(me);
	}
	catch (const char * er)
	{
		std::cout << er << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return (0);
}
