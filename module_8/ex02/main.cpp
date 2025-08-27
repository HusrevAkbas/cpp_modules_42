/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:03:09 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/27 14:46:58 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "MutantStack.tpp"

int	main()
{
	MutantStack<int>	st;
	st.push(1);
	std::cout << st.top() << std::endl;
	st.push(2);
	std::cout << st.top() << std::endl;

	MutantStack<int>::iterator	it = st.begin();
	for (size_t i = 0; i < 2; i++)
	{
		std::cout << *it << " ";
		// it++;
	}

	return (0);
}