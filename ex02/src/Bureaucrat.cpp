/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/07/14 15:13:01 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

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
{}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
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

void  Bureaucrat::signForm(Form& obj)
{
  try
  {
    obj.beSigned(*this);
  }
  catch(const std::exception& e)
  {
    std::cerr << "\e[38;5;82mBureaucrat \e[0m" << this->getName()
              << " couldn't sign \e[38;5;82mForm \e[0m" << obj.getName()
              << " because " << e.what() << '\n';
  }
  return ;
}

void  Bureaucrat::executeForm(Form const & form)
{
  form.execute(*this);
  return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
  if (this != &obj) {
    this->_grade = obj.getGrade();
  }
  else
  {
    std::cout << "\e[1;31mError: "
              << "Attempted self-assignment in copy assignment operator.\e[0m"
              << std::endl;
  }
  return (*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
  std::cout << "\e[38;5;82m" << obj.getName() << "\e[0m, bureaucrat grade " 
            << obj.getGrade() << "."<< std::endl;
  return (out);
}