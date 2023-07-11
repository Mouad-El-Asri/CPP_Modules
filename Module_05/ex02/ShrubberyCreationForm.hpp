#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

# define SHRUBBERYCREATIONFORM_NAME "Shrubbery Creation Form"
# define SHRUBBERYCREATIONFORM_SIGN_GRADE 145
# define SHRUBBERYCREATIONFORM_EXEC_GRADE 137

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual                 ~ShrubberyCreationForm();

        std::string             getTarget() const;
};

#endif