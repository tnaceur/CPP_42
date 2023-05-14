#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	ShrubberyCreationForm : public AForm
{
    std::string target;
    public:
        ShrubberyCreationForm (const std::string&);
        ShrubberyCreationForm ();
        ~ShrubberyCreationForm ();
        ShrubberyCreationForm (const ShrubberyCreationForm&);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);
        void execute(Bureaucrat const &) const;
};

#endif