/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/30 20:03:35 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const std::string Intern::_formList[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
Form* (*Intern::_makeForm[3])(const std::string& target) = {
  &Intern::makePresidentialPardonForm,
  &Intern::makeRobotomyRequestForm,
  &Intern::makeShrubberyCreationForm
};

Intern::Intern(void)
{}

Intern::Intern( const Intern& obj )
{
  *this = obj;
}

Intern::~Intern()
{}

Form* Intern::makePresidentialPardonForm(const std::string& target)
{
  return (new PresidentialPardonForm(target));
}

Form* Intern::makeRobotomyRequestForm(const std::string& target)
{
  return (new RobotomyRequestForm(target));
}

Form* Intern::makeShrubberyCreationForm(const std::string& target)
{
  return (new ShrubberyCreationForm(target));
}

Form* Intern::makeForm( const std::string& name, const std::string& target )
{
  for (int index = 0; index < 3; index++)
  {
    if (name == this->_formList[index])
      return (this->_makeForm[index](target));
  }
  std::cout << "\e[1;38;5;182mError: There is no such Form.\e[0m" << std::endl;
  return (NULL);
}

Intern& Intern::operator=( const Intern& obj )
{
  if (this != &obj)
  {
    std::cout << "\e[1;31mError: "
              << "Attempted self-assignment in copy assignment operator.\e[0m"
              << std::endl;
  }
  return (*this);
}
