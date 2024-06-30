/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/30 19:30:22 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm: public Form
{
private:
  const std::string _target;
  static const int  _sign;
  static const int  _exec;

public:
  ShrubberyCreationForm( void );
  ShrubberyCreationForm( const std::string& target );
  ShrubberyCreationForm( const ShrubberyCreationForm& obj );
  ~ShrubberyCreationForm();

  const std::string&  getTarget( void ) const;
  void                execute( Bureaucrat const & executor ) const;

  ShrubberyCreationForm& operator=( const ShrubberyCreationForm& obj );
};

std::ostream& operator<<( std::ostream& out, const ShrubberyCreationForm& obj );

#endif
