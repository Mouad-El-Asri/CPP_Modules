#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(SHRUBBERYCREATIONFORM_NAME, SHRUBBERYCREATIONFORM_SIGN_GRADE, SHRUBBERYCREATIONFORM_EXEC_GRADE)
{
    this->target = "default";
    std::cout << "ShrubberyCreationForm Default Constructor Called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(SHRUBBERYCREATIONFORM_NAME, SHRUBBERYCREATIONFORM_SIGN_GRADE, SHRUBBERYCREATIONFORM_EXEC_GRADE)
{
    this->target = target;
    std::cout << "ShrubberyCreationForm parameterized Constructor Called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    this->target = other.target;
    std::cout << "ShrubberyCreationForm Copy Constructor Called\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        this->target = other.target;
    std::cout << "ShrubberyCreationForm Copy Assignment Operator Called\n";
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor Called\n";
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (this->target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream outputFile(filename);
	outputFile << "      /\\\n";
	outputFile << "     /\\*\\\n";
	outputFile << "    /\\0\\*\\\n";
	outputFile << "   /*/\\/\\/\\\n";
	outputFile << "  /\\O\\/\\*\\/\\\n";
	outputFile << " /\\*\\/\\*\\/\\/\\\n";
	outputFile << "/\\O\\/\\/*/\\/O/\\\n";
	outputFile << "      ||\n";
	outputFile << "      ||\n";
	outputFile << "      ||\n";
	outputFile.close();
}
