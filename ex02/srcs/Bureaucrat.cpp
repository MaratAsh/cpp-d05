#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int range) : _name(name), _grade(range)
{
	if (range > 150)
		throw Bureaucrat::GradeTooLowException();
	if (range < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat & copy)
{
	(*this) = copy;
}

Bureaucrat & Bureaucrat::operator= (const Bureaucrat & copy)
{
	if (this == &copy)
		return (*this);
	const_cast<std::string &>(this->_name) = copy._name;
	this->_grade = copy._grade;
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

void Bureaucrat::incGrade()
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decGrade()
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "<" << this->getName() << "> signs <" << form.getName() << ">" << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout <<"<"<< this->getName() << "> cannot sign <" << form.getName() << "> because " << ex.what();
	}
	catch (const char * ex)
	{
		std::cout << RED << ex << RESET << std::endl;
	}
}

std::ostream& operator<< (std::ostream &out, const Bureaucrat &bur)
{
	out << "<" << bur.getName() << ">, bureaucrat grade <" << bur.getGrade() << ">";
	return (out);
}



Bureaucrat::GradeTooLowException::GradeTooLowException() {}
Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The Grade Bureaucrat is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The Grade Bureaucrat is too low!";
}


void Bureaucrat::executeForm(const Form &form)
{
	try
	{
		form.execute(*this);
		std::cout << "<" << this->getName() << "> executes <" << form.getName() << ">" << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout <<"<"<< this->getName() << "> cannot execute <" << form.getName() << "> because " << ex.what();
	}
	catch (const char * ex)
	{
		std::cout << RED << ex << RESET << std::endl;
	}
}
