/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/09 20:05:22 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

const int ShrubberyCreationForm::_sign = 145;
const int ShrubberyCreationForm::_exec = 137;

ShrubberyCreationForm::ShrubberyCreationForm(void):
Form::Form("ShrubberyCreationForm", this->_sign, this->_exec), _target("noTarget")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
Form::Form("ShrubberyCreationForm", this->_sign, this->_exec), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj):
Form::Form(obj), _target(obj.getTarget())
{
  *this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

const std::string& ShrubberyCreationForm::getTarget(void) const
{
  return (this->_target);
}

static bool  isFilePath(const char *path) {
  struct stat status;

  if (stat(path, &status) != 0 )
  {
    std::cerr << "\e[1;31mError: Could not open the file.\e[0m" << std::endl;
    return (true);
  }
  if (S_ISDIR(status.st_mode))
  {
    std::cerr << "\e[1;31mError: path is a directory.\e[0m" << std::endl;
    return (true);
  }
  return (false);
}

bool fileExists(const std::string& filename) {
    std::FILE* file = std::fopen(filename.c_str(), "r");
    if (file) {
        std::fclose(file);
        return true;
    }
    return false;
}

void  ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
  std::ofstream bery;

  if (executor.getGrade() > this->getExec())
    throw  ShrubberyCreationForm::GradeTooLowException();
  if (!this->isSigned())
    throw ShrubberyCreationForm::FormNotSigned();
  if (fileExists(this->_target + "_shrubbery"))
    bery.open((this->_target + "_shrubbery").c_str(), std::ios::app);
  else
    bery.open((this->_target + "_shrubbery").c_str());
  if (isFilePath((this->_target + "_shrubbery").c_str()))
  {
    bery.close();
    return ;
  }
  std::cout << "\e[38;5;82m" << executor.getName() << "\e[0m"
            << " executed " << this->getName() << std::endl;
  bery  << "                            ░░▒▒    ▒▒▒▒    ▓▓░░                                         " << std::endl
        << "                            ▓▓░░    ░░▓▓▓▓  ▓▓▓▓░░  ██                                   " << std::endl
        << "                  ▒▒      ░░▓▓░░░░▒▒▒▒  ▓▓░░  ▓▓▓▓  ▓▓██  ░░▒▒                           " << std::endl
        << "                  ▒▒▓▓▒▒  ▓▓██  ▓▓▒▒  ▒▒▒▒░░▒▒  ░░  ▒▒▓▓░░  ██▓▓    ░░                   " << std::endl
        << "                    ██▓▓▒▒        ▒▒▒▒▓▓████▒▒        ▓▓▓▓  ░░▓▓░░▓▓▒▒                   " << std::endl
        << "                  ▓▓██▓▓██  ░░▒▒  ▓▓▒▒▓▓██░░          ░░░░░░  ░░  ▓▓▒▒                   " << std::endl
        << "              ▒▒▓▓  ░░▓▓▓▓▓▓░░▓▓░░▓▓██    ░░▓▓  ▒▒▓▓██      ▒▒░░  ░░  ▒▒░░▒▒░░           " << std::endl
        << "      ▓▓    ▓▓▓▓▒▒  ░░██▒▒▓▓░░░░░░░░▒▒  ░░▓▓░░▒▒▓▓▓▓░░    ░░▒▒▓▓  ░░▒▒██▓▓██▓▓           " << std::endl
        << "      ██▒▒    ░░        ░░░░    ░░██░░        ▒▒▓▓░░░░▓▓░░  ░░▓▓░░▓▓▓▓▓▓██▒▒             " << std::endl
        << "      ▓▓▓▓░░▓▓▒▒░░  ▓▓▒▒        ▒▒▓▓░░  ░░    ░░░░▒▒▓▓██  ▓▓░░      ▒▒▒▒                 " << std::endl
        << "        ▒▒  ░░▒▒▓▓░░  ░░░░░░▒▒  ▓▓▒▒██░░  ░░░░░░  ▒▒▓▓  ▒▒░░  ░░░░    ▓▓▓▓░░             " << std::endl
        << "  ▒▒▓▓▒▒  ░░      ░░      ▓▓▒▒  ░░  ▒▒██  ░░  ██░░░░          ░░      ▒▒▒▒░░  ▓▓         " << std::endl
        << "      ░░▓▓▓▓▓▓▒▒░░  ▒▒    ▓▓        ██▓▓▓▓░░░░▓▓░░  ░░▒▒▓▓▓▓▓▓  ░░░░▓▓▒▒    ▓▓▓▓         " << std::endl
        << "    ▒▒▓▓▓▓▓▓▓▓    ░░▓▓░░░░  ░░▒▒██░░  ▓▓▓▓░░░░▓▓░░      ░░░░▒▒      ▓▓▓▓▒▒░░▓▓░░         " << std::endl
        << "    ▓▓████░░▓▓      ░░    ░░  ▓▓██  ░░██▒▒▒▒░░░░░░    ░░  ▒▒▒▒░░  ▒▒▒▒░░░░  ▒▒           " << std::endl
        << "    ░░░░▒▒        ░░  ▒▒▒▒    ▓▓        ▒▒░░▓▓░░  ░░░░▓▓░░▒▒  ░░  ▒▒░░    ░░    ▒▒       " << std::endl
        << "  ▒▒██▓▓░░░░░░░░░░██░░▓▓░░              ░░▒▒  ░░░░░░▓▓▒▒░░    ░░    ░░    ▒▒▓▓  ▓▓▒▒     " << std::endl
        << "    ▒▒░░  ▓▓░░    ██▒▒▒▒░░░░    ░░  ░░  ░░░░░░▓▓▒▒  ░░  ░░▒▒  ░░▓▓  ▓▓  ▓▓▓▓░░    ░░     " << std::endl
        << "    ▓▓▓▓░░  ▓▓    ▓▓▓▓    ▒▒  ▒▒░░  ░░▓▓██  ▒▒▓▓▒▒▒▒  ▒▒  ▒▒░░  ░░░░▒▒▒▒▓▓▒▒░░▓▓▓▓░░     " << std::endl
        << "    ░░▓▓▓▓      ░░▓▓░░  ▒▒▓▓░░██  ░░▓▓░░▓▓░░░░  ▓▓  ██      ░░░░  ░░  ░░▒▒░░██▓▓▒▒    ░░ " << std::endl
        << "██▓▓▓▓  ░░  ░░░░▒▒▒▒  ░░▒▒▓▓░░▒▒    ░░░░  ▒▒▓▓  ░░  ██  ░░▒▒  ▓▓▒▒██▒▒░░░░░░▓▓▒▒    ██░░ " << std::endl
        << "  ▒▒▓▓  ▒▒  ▒▒  ▒▒░░▓▓▒▒░░▓▓  ▒▒▓▓▒▒  ░░░░░░▒▒██▒▒██▒▒░░██  ░░██░░░░▒▒▓▓▓▓▒▒░░░░  ██▓▓   " << std::endl
        << "    ░░▓▓▓▓▓▓▓▓▒▒░░▓▓▒▒  ▓▓▒▒▓▓▓▓░░░░  ▓▓  ██░░▒▒██░░▒▒▓▓██░░▒▒████▒▒    ▒▒▓▓░░░░░░░░     " << std::endl
        << "  ░░████▓▓▓▓██░░  ░░░░    ▒▒▓▓      ░░░░████  ▒▒▓▓░░▓▓▓▓    ▒▒▒▒  ░░  ░░▓▓░░░░▓▓         " << std::endl
        << "░░▒▒    ▒▒  ░░▒▒▒▒░░    ▓▓▓▓░░▓▓  ▒▒▒▒  ▒▒▓▓░░▓▓██▒▒▒▒░░    ██  ░░  ░░░░░░    ▒▒░░       " << std::endl
        << "▒▒▓▓▓▓    ░░░░  ██▓▓▓▓░░▒▒▓▓▓▓  ██▓▓    ██▓▓░░████▒▒  ▓▓▒▒▒▒██░░░░  ▒▒██░░  ░░▓▓░░       " << std::endl
        << "  ░░▒▒░░░░░░  ▒▒  ▒▒▒▒  ▒▒░░░░  ░░▒▒    ▒▒░░██████  ▒▒▓▓  ██▒▒▓▓██░░██▒▒████▓▓▓▓▓▓▒▒     " << std::endl
        << "        ▓▓▓▓    ▒▒▒▒▒▒░░  ▓▓  ░░░░▓▓  ░░  ████████    ▓▓████  ▓▓▓▓    ▓▓▓▓██░░           " << std::endl
        << "      ▓▓▒▒  ░░    ▓▓░░░░░░▒▒▒▒▒▒████▒▒░░▓▓██████  ░░██▓▓▓▓▓▓  ░░▓▓▓▓  ░░  ▓▓██░░         " << std::endl
        << "      ░░  ▒▒▓▓░░▓▓▒▒▒▒    ▒▒░░    ▓▓████▒▒██████  ██████▓▓░░  ▒▒██  ░░░░  ▒▒  ░░         " << std::endl
        << "          ░░  ░░▓▓▒▒▒▒░░  ▒▒▓▓██▒▒▒▒░░████▓▓▓▓▓▓░░██████  ▓▓▓▓  ▒▒  ▒▒▓▓▓▓               " << std::endl
        << "            ░░▓▓██    ▓▓██░░░░░░  ░░  ▒▒██████▓▓░░▓▓██      ▓▓▒▒      ░░▓▓▓▓             " << std::endl
        << "            ▒▒▒▒░░      ▓▓▓▓    ░░▓▓░░▒▒████▓▓██░░██▓▓                                   " << std::endl
        << "                                ▓▓░░  ▒▒██▒▒████░░████                                   " << std::endl
        << "                                      ████▓▓██████████░░                                 " << std::endl
        << "                                      ██▒▒██████▓▓██▓▓                                   " << std::endl
        << "                                      ▓▓░░██████▒▒██▒▒                                   " << std::endl
        << "                                      ██  ████▓▓▓▓██▒▒                                   " << std::endl
        << "                                      ██  ████▓▓▓▓██▒▒▒▒                                 " << std::endl
        << "                                    ████  ██████████▒▒██                                 " << std::endl
        << "                                ▒▒██████  ██████▓▓▓▓▓▓▓▓▓▓                               " << std::endl
        << "                          ▒▒▓▓██▓▓▓▓██▓▓░░██████▓▓▓▓██▒▒▓▓████▓▓░░                       " << std::endl
        << "                      ░░░░░░▓▓██▒▒████░░▓▓████████▒▒████████████▓▓██▓▓                   " << std::endl
        << "                      ▓▓██████▓▓▓▓██▓▓▓▓██████████░░▓▓██████▓▓▒▒▒▒▓▓▒▒░░                 " << std::endl
        << "                    ▒▒████▓▓░░▒▒██████████████████▒▒▓▓██████████▓▓                       " << std::endl
        << "          ░░    ░░░░░░      ░░████████░░████▓▓  ▓▓██▒▒▓▓██▒▒██▓▓██▓▓                     " << std::endl
        << "                        ░░▓▓██████▓▓    ██░░      ░░██  ▓▓  ░░▓▓░░▓▓▒▒                   " << std::endl
        << "                  ░░▒▒████████▒▒░░      ░░          ▓▓  ░░      ▒▒      ░░░░             " << std::endl
        << "                ▒▒░░                                ░░  ▒▒                               " << std::endl
        << "                                                      ░░░░                               " << std::endl;
  bery.close();
  return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
  if (this != &obj)
    return *this;
  std::cout << "\e[1;31mError: "
            << "Attempted self-assignment in copy assignment operator.\e[0m"
            << std::endl;
  return *this;
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& obj)
{
  std::cout << "\e[38;5;82m" << obj.getName() << "\e[0m";
  if (obj.isSigned())
    std::cout << " signed: ○ ";
  else
    std::cout << " signed: ✗ ";
  std::cout << "requiredGrade: " << obj.getRequired() << " "
            << "execGrade: " << obj.getExec() << " "
            << "target: " << obj.getTarget() << std::endl;
  return (out);
}
