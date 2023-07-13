#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
		Bureaucrat bureaucrat("Bureaucrat", 1);

		std::cout << '\n';

		ShrubberyCreationForm shrubberyCreationForm("ShrubberyCreationForm");
		RobotomyRequestForm robotomyRequestForm("RobotomyRequestForm");
		PresidentialPardonForm presidentialPardonForm("PresidentialPardonForm");

		std::cout << '\n';

		bureaucrat.signForm(shrubberyCreationForm);
		bureaucrat.signForm(robotomyRequestForm);
		bureaucrat.signForm(presidentialPardonForm);

		std::cout << '\n';

		bureaucrat.executeForm(shrubberyCreationForm);
		bureaucrat.executeForm(robotomyRequestForm);
		bureaucrat.executeForm(presidentialPardonForm);

		std::cout << '\n';
    }
    catch(std::exception & e)
    {
        std::cout << "Exception Caught : " << e.what() << "\n";
    }
    return (0);
}
