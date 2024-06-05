/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/05 16:19:11 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):_name(""), _grade()
{

}

Bureaucrat::Bureaucrat(const std::string& name):_name(name), _grade()
{

}

Bureaucrat::Bureaucrat(const std::string& name, int grade):_name(name), _grade(grade)
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& obj):_name(obj.getName())
{
  *this = obj;
}

Bureaucrat::~Bureaucrat(void)
{
  std::cout << "\e[1;92mBureaucrat deconstructor called.\n";
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
  std::cout << "Grade too high.\n";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
  std::cout << "Grade too low.\n";
}

const std::string&  Bureaucrat::getName(void) const
{
  return (this->_name);
}

int  Bureaucrat::getGrade(void) const
{
  return (this->_grade);
} 

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
  if (this != &obj) {
    this->_grade = obj.getGrade();
  }
    std::cout << "\e[1;31mError: "
              << "Attempted self-assignment in copy assignment operator.\e[0m"
              << std::endl;
}