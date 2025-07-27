/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:36 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:18:58 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseForm.hpp"

BaseForm::BaseForm(){}

BaseForm::~BaseForm(){}

BaseForm::BaseForm(const BaseForm &a)
{	*this = a;	}

BaseForm& BaseForm::operator=(const BaseForm &a)
{
	// assign variables here
	return (*this);
}
