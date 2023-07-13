#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 150);
        Form form("Form", 5, 1);

        bureaucrat.signForm(form);
        std::cout << form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    return (0);
}
