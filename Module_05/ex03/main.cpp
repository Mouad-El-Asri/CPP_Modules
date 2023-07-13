#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
		Bureaucrat bureaucrat("Bureaucrat", 1);
		Intern someRandomIntern;
		AForm *form;

		std::cout << '\n';

		form = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *form;
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;

		std::cout << '\n';

		form = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *form;
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;

		std::cout << '\n';

		form = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << *form;
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;

		std::cout << '\n';
    }
    catch(std::exception & e)
    {
        std::cout << "Exception Caught : " << e.what() << "\n";
    }
    return (0);
}
