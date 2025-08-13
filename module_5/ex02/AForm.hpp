/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:41 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:11:15 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;
	public:
		AForm();
		~AForm();
		AForm(const AForm &a);
		AForm( std::string name, int grade_to_execute, int grade_to_sign );
		AForm& operator=(const AForm &a);
		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw ();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw ();
		};
		const std::string	getName();
		bool	isSigned();
		int	getGradeToSign();
		int	getGradeToExecute();
		void	beSigned(const Bureaucrat &b);
};

std::ostream& operator<< (std::ostream &o, AForm &f);