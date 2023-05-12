#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class	ShrubberyCreationForm
{
    std::string target;
    public:
        ShrubberyCreationForm (const std::string&);
        ShrubberyCreationForm ();
        ~ShrubberyCreationForm ();
        ShrubberyCreationForm (const ShrubberyCreationForm&);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);
};

#endif