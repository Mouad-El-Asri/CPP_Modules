#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("MOUAD", 15);
        bureaucrat.incrementGrade();
        bureaucrat.decrementGrade();
        std::cout << bureaucrat << "\n";

        std::cout << "\n";

        Bureaucrat bureaucrat1("AMINE", 1);
        bureaucrat1.incrementGrade();
        bureaucrat1.decrementGrade();
        std::cout << bureaucrat1 << "\n";
    }
    catch(std::exception & e)
    {
        std::cout << "Exception Caught : " << e.what() << "\n";
    }
    return (0);
}
