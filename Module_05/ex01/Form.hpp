#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        const		std::string name;
        bool		sign;
        const int	signGrade;
        const int	execGrade;
    
    public:
        Form();
        Form(std::string formName, int formSignGrade, int formExecGrade);
        Form(const Form &other);
        Form		&operator=(const Form &other);
        ~Form();
    
        std::string	getName() const;
        bool		getIsSigned() const;
        int			getSignGrade() const;
        int			getExecGrade() const;
    
        void		beSigned(const Bureaucrat &bureaucrat);

    public:
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
    
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream	&operator<<(std::ostream &os, const Form &form);

#endif
