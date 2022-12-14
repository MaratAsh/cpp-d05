#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
		AForm("shrubbery form", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & copy) : AForm(copy), _target(copy._target)
{
	(*this) = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &  ShrubberyCreationForm::operator= (const ShrubberyCreationForm & copy)
{
	if (this == &copy)
		return (*this);
	AForm::operator=(copy);
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	fout;
	std::string 	filename;
	std::string 	buf;

	if (executor.getGrade() <= this->getGradeExec() && this->getSign() == true)
	{
		buf = "\n"
			  "           *             ,\n"
			  "                       _/^\\_\n"
			  "                      < 4 2 >\n"
			  "     *                 /.-.\\         *\n"
			  "              *        `/&\\`                   *\n"
			  "                      ,@.*;@,\n"
			  "                     /_o.I %_\\    *\n"
			  "        *           (`'--:o(_@;\n"
			  "                   /`;--.,__ `')             *\n"
			  "                  ;@`o % O,*`'`&\\\n"
			  "            *    (`'--)_@ ;o %'()\\      *\n"
			  "                 /`;--._`''--._O'@;\n"
			  "                /&*,()~o`;-.,_ `\"\"`)\n"
			  "     *          /`,@ ;+& () o*`;-';\\\n"
			  "               (`\"\"--.,_0 +% @' &()\\\n"
			  "               /-.,_ 21 ``''--....-'`)  *\n"
			  "          *    /@%;o`:;'--,.__ 42 __.'\\\n"
			  "              ;*,&(); @ % &^;~`\"`o;@();         *\n"
			  "              /(); o^~; & ().o@*&`;&%O\\\n"
			  "        jgs   `\"=\"==\"\"==,,,.,=\"==\"===\"`\n"
			  "           __.----.(\\-''#####---...___...-----._\n"
			  "         '`         \\)_`\"\"\"\"\"`\n"
			  "                 .--' ')\n"
			  "               o(  )_-\\\n"
			  "                 `\"\"\"` `\n"
			  "\n"
			  "------------------------------------------------\n";
		filename = this->_target + "_shrubbery";
		fout.open(filename);
		fout << buf;
		fout.close();
	}
	else if (!(this->getSign()))
		throw RED"The AForm not signed!"RESET;
	else
		throw Bureaucrat::GradeTooLowException();
}