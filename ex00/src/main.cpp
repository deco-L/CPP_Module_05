/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/07 14:09:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include <unistd.h>
#include <sys/ioctl.h>

static size_t get_term_line() {
	winsize	terminal_size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal_size);
	return (terminal_size.ws_col);
}

static void draw_terminal_line() {
	size_t	terminal_col;

	terminal_col = get_term_line();
	for (size_t i = 0; i < terminal_col; i++)
		std::cout << "=";
	std::cout << std::endl;
	return ;
}

int main(void) {
  draw_terminal_line();
  Bureaucrat  human;
  std::cout << human;
  draw_terminal_line();
  try
  {
    Bureaucrat  human("yamada", 75);
    std::cout << human;
    human.upGrade();
    std::cout << human;
    human.downGrade();
    std::cout << human;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  try
  {
    Bureaucrat  human("yamada", -10);
    std::cout << human;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  try
  {
    Bureaucrat human("yamada", 151);
    std::cout << human;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
  draw_terminal_line();
  try
  {
    Bureaucrat  human("yamada", 1);
    std::cout << human;
    human.upGrade();
    std::cout << human;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  try
  {
    Bureaucrat  human("yamada", 150);
    std::cout << human;
    human.downGrade();
    std::cout << human;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
  draw_terminal_line();
  return (EXIT_SUCCESS);
}