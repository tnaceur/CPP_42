#ifndef FORM_HPP
#define FORM_HPP

#include <fstream>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Form
{
    const   std::string name;
    bool    signe;
    const int grade;
    const int grade_exec;
    public:
        Form(const std::string&, const int, const int);
        Form ();
        ~Form ();
        Form (const Form&);
        Form &operator=(const Form&);
        const std::string getName() const;
        bool getSigne() const;
        int getGrade() const;
        int getExec() const;
        void    beSigned(const Bureaucrat&);
};

std::ostream& operator<<(std::ostream&, Form&);

#endif