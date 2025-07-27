/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:32:41 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/23 14:11:15 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BASEFORM_H
# define	BASEFORM_H

#include <iostream>

class BaseForm
{
	private:
	public:
		BaseForm();
		~BaseForm();
		BaseForm(const BaseForm &a);
		BaseForm& operator=(const BaseForm &a);
};
#endif	//	BASEFORM_H