/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/09 20:04:35 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm: public Form
{
private:
  const std::string _target;
  static const int  _sign;
  static const int  _exec;

public:
  PresidentialPardonForm( void );
  PresidentialPardonForm( const std::string& target );
  PresidentialPardonForm( const PresidentialPardonForm& obj );
  ~PresidentialPardonForm();

  const std::string&  getTarget( void ) const;
  void                execute( Bureaucrat const & executor ) const;

  PresidentialPardonForm& operator=( const PresidentialPardonForm& obj );
};

std::ostream& operator<<( std::ostream& out, const PresidentialPardonForm& obj );

#endif
