#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
		AForm("robotomy form", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & copy) : AForm(copy), _target(copy._target)
{
	(*this) = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm & copy)
{
	if (this == &copy)
		return (*this);
	AForm::operator=(copy);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() <= this->getGradeExec() && this->getSign() == true)
	{
		std::cout << "....Bzzzz.....Phhzzzz.....Bbrrzzzz...." << std::endl;
		std::cout << "<" << this->_target << "> has been robotomized successfully 50% of the time." << std::endl;
	}
	else if (!(this->getSign()))
		throw (RED"The AForm not signed!"RESET);
	else
		throw Bureaucrat::GradeTooLowException();
}
