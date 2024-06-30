/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/30 20:02:50 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class Intern
{
private:
  static const std::string _formList[3];
  static Form* (*_makeForm[3])( const std::string& target );

public:
  Intern( void );
  Intern( const Intern& obj );
  ~Intern();

  static Form*  makePresidentialPardonForm( const std::string& target );
  static Form*  makeRobotomyRequestForm( const std::string& target );
  static Form*  makeShrubberyCreationForm( const std::string& target );
  Form* makeForm( const std::string& name, const std::string& target );

  Intern& operator=( const Intern& obj );
};

#endif
