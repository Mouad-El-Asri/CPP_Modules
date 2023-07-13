#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat  bureaucrat("Bureaucrat", 1);

        std::cout << bureaucrat;

        bureaucrat.decrementGrade();
        std::cout << bureaucrat;

        bureaucrat.incrementGrade();
        std::cout << bureaucrat;

        bureaucrat.decrementGrade();
        std::cout << bureaucrat;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
