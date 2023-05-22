#ifndef BUREAUCRAT_HPP
#define  BUREAUCRAT_HPP

#include <iostream>
#include <exception>


class Bureaucrat
{
private:
    const std::string name;
    int               grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string n, int g);
    Bureaucrat (const Bureaucrat&);
    Bureaucrat &operator=(const Bureaucrat&);
    void    increment();
    void    decrement();
    int getGrade() const;
    const std::string& getName() const;
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
    ~Bureaucrat();
};

std::ostream& operator<<(std::ostream &out, Bureaucrat& a);

#endif