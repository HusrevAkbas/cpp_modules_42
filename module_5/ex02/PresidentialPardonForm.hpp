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
#include "AForm.hpp"

class	Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm &a);
		PresidentialPardonForm( std::string name);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &a);

		void	execute( Bureaucrat const & executer) const;
};
