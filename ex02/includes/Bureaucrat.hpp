#ifndef CPP_BUREAUCRAT_HPP
#define CPP_BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

class AForm;

class Bureaucrat
{
private:
	std::string const	_name;
	int 				_grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat & copy);
	Bureaucrat(const std::string name, int range);
	~Bureaucrat();
	Bureaucrat & operator= (const Bureaucrat & copy);

	std::string getName() const;
	int getGrade() const;

	void incGrade();
	void decGrade();
	void signForm(AForm & form);

	void executeForm(AForm const & form);

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
		virtual ~GradeTooLowException()  throw();

		virtual const char* what() const throw();
	};
};

std::ostream& operator<< (std::ostream &out, const Bureaucrat &bur);

#endif
