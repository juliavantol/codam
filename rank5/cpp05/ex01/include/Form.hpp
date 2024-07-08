/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/08 12:57:20 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/08 14:10:00 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form
{
	private:
		std::string	const	_name;
		bool				_signed;
		int	const			_signGrade;
		int	const			_executeGrade;

	public:
		Form(const std::string &name, int gradeToSign);
		~Form();

		// Getters
		std::string	getName(void) const;
		bool		getSignStatus(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;

		// Exceptions
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream & operator<<(std::ostream &o, const Form &rhs);

#endif