#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			execGrade;

	private:
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

	public:
		Form();
		Form(std::string formName, bool formSign, int formSignGrade, int formExecGrade);
		Form(const Form& other);
		Form&				operator=(const Form& other);
		~Form();

		std::string			getName() const;
		bool				isSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void				beSigned(const Bureaucrat& bureaucrat);
		void				signForm(const Bureaucrat& bureaucrat) const;
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
