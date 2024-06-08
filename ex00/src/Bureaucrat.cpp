/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/08 19:25:40 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

const int Bureaucrat::_highGrade = 1;
const int Bureaucrat::_middleGrade = 75;
const int Bureaucrat::_lowGrade = 150;

Bureaucrat::Bureaucrat(void):_name("nameless"), _grade(this->_middleGrade)
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade):_name(name), _grade(grade)
{
  if (this->_grade < this->_highGrade)
    throw Bureaucrat::GradeTooHighException();
  else if (this->_grade > this->_lowGrade)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj):_name(obj.getName())
{
  *this = obj;
}

Bureaucrat::~Bureaucrat(void)
{
  std::cout << "\e[1;92mBureaucrat deconstructor called.\e[0m\n";
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
  return ("\e[1;38;5;182mError: Grade too high.\e[0m");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
  return ("\e[1;38;5;182mError: Grade too low.\e[0m");
}

const std::string&  Bureaucrat::getName(void) const
{
  return (this->_name);
}

int  Bureaucrat::getGrade(void) const
{
  return (this->_grade);
}

void  Bureaucrat::upGrade(void)
{
  try
  {
    this->_grade--;
    if (this->_grade < this->_highGrade)
      throw Bureaucrat::GradeTooHighException();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    this->_grade++;
  }
  return ;
}

void  Bureaucrat::downGrade(void)
{
  try
  {
    this->_grade++;
    if (this->_grade > this->_lowGrade)
      throw Bureaucrat::GradeTooLowException();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    this->_grade--;
  }
  return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
  if (this != &obj) {
    this->_grade = obj.getGrade();
  }
    std::cout << "\e[1;31mError: "
              << "Attempted self-assignment in copy assignment operator.\e[0m"
              << std::endl;
  return (*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
  std::cout << obj.getName() << ", bureaucrat grade " 
            << obj.getGrade() << "."<< std::endl;
  return (out);
}