#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class	Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	
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
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&			operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string			getName() const;
		int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif