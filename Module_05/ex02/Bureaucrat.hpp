#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class	Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&			operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string			getName() const;
		int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();

        void                signForm(class AForm& form) const;

        void				executeForm(AForm const & form) const;

    public:
        class   GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class   GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif