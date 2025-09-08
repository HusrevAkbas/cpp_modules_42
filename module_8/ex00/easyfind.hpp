/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:43:41 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/09/08 12:31:12 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

class	ElementNotFoundException : public std::exception
{
	public:
		const char*	what() const throw()
		{
			return ("\e[1;31mElement not found\e[0m");
		}
};

template <typename T>
int	easyfind(const T &container, int num)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
		throw ElementNotFoundException();
	return *it;
	// typename T::const_iterator it;
	// for (it = container.begin(); it != container.end(); ++it)
	// {
	// 	if (*it == num) 
	// 		return (*it);
	// }
	// for (size_t i = 0; i < container.size(); i++)
	// {
	// 	if (container.at(i) == num)
	// 		return (container.at(i));
	// }
	// throw ElementNotFoundException();
}
