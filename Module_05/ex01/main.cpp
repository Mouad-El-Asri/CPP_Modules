#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bureaucrat("MOUAD", 15);
	bureaucrat.incrementGrade();
	bureaucrat.decrementGrade();
	std::cout << bureaucrat.getName() << " : " << bureaucrat.getGrade() << "\n";

	Bureaucrat bureaucrat1("AMINE", 1);
	bureaucrat1.incrementGrade();
	bureaucrat1.decrementGrade();
	std::cout << bureaucrat1.getName() << " : " << bureaucrat1.getGrade() << "\n";
	return (0);
}
