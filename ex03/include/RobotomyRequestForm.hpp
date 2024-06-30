/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/30 19:30:19 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm: public Form
{
private:
  const std::string _target;
  static const int  _sign;
  static const int  _exec;

public:
  RobotomyRequestForm( void );
  RobotomyRequestForm( const std::string& target );
  RobotomyRequestForm( const RobotomyRequestForm& obj );
  ~RobotomyRequestForm();

  const std::string&  getTarget( void ) const;
  void                execute( Bureaucrat const & executor ) const;

  RobotomyRequestForm& operator=( const RobotomyRequestForm& obj );
};

std::ostream& operator<<( std::ostream& out, const RobotomyRequestForm& obj );

#endif
