#ifndef CPP_FORM_HPP
#define CPP_FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm
{
private:
	std::string	const	_name;
	bool 				_sign;
	int const			_gradeExec;
	int const			_gradeSign;

public:
	AForm();
	AForm(std::string name, int gradeSign, int gradeExec);
	~AForm(){};
	AForm(const AForm & copy);
	AForm& operator=(const AForm& copy);

	std::string getName() const;
	int			getGradeExec() const;
	int			getGradeSign() const;
	bool		getSign() const;

	void	beSigned(Bureaucrat & bur);

	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		virtual ~GradeTooHighException() throw();

		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		virtual ~GradeTooLowException() throw();

		virtual const char* what() const throw();
	};
};

std::ostream& operator<< (std::ostream &out, const AForm &form);

#endif
