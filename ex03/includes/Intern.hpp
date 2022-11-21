#ifndef CPP_INTERN_HPP
#define CPP_INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	std::string 	arrForm[3];
	AForm *(Intern::*func[3])(std::string target);

	AForm * newShrubbery(std::string target);
	AForm * newRobotomy(std::string target);
	AForm * newPresidential(std::string target);

public:
	Intern();
	~Intern();

	AForm * makeForm(std::string name, std::string target);
};

#endif
