#include "AForm.hpp"

AForm::AForm() : _name(""), _sign(false), _gradeExec(150), _gradeSign(150)
{}

AForm::AForm(std::string name, int gradeSign, int gradeExec) :
	_name(name), _sign(false), _gradeExec(gradeExec), _gradeSign(gradeSign)
{
	if (_gradeExec <= 0 || _gradeSign <= 0)
		throw AForm::GradeTooHighException();
	if (_gradeExec > 150 || _gradeSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm & copy) : _name(copy._name), _sign(false),
								   _gradeExec(copy._gradeExec), _gradeSign(copy._gradeSign)
{
	(*this) = copy;
}

AForm & AForm::operator=(AForm const & copy)
{
	if (this == &copy)
		return (*this);
	const_cast<std::string &>(this->_name) = copy._name;
	const_cast<int &>(this->_gradeSign) = copy._gradeSign;
	const_cast<int &>(this->_gradeExec) = copy._gradeExec;
	this->_sign = copy._sign;
	return (*this);
}


std::string AForm::getName() const
{
	return (this->_name);
}

int			AForm::getGradeExec() const
{
	return (this->_gradeExec);
}

int			AForm::getGradeSign() const
{
	return (this->_gradeSign);
}
bool		AForm::getSign() const
{
	return (this->_sign);
}

void	AForm::beSigned(Bureaucrat & bur)
{
	if (bur.getGrade() <= this->_gradeSign)
	{
		if (this->_sign == true)
			throw "The AForm already signed!";
		this->_sign = true;
		std::cout << GREEN << "* The AForm " << this->getName() << " is signed *" << RESET << std::endl;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "The Grade AForm is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "The Grade AForm is too low!";
}

AForm::GradeTooLowException::GradeTooLowException() {}
AForm::GradeTooHighException::GradeTooHighException() {}
AForm::GradeTooLowException::~GradeTooLowException() throw() {}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}

std::ostream& operator<< (std::ostream &out, const AForm &form)
{
	out << "Name form: " << form.getName() << "\nSign: " << form.getSign() << "\nGrade to Sign: " <<
		form.getGradeSign() << "\nGrade to Execute: " << form.getGradeExec();
	return (out);
}
