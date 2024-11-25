/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:29:41 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/25 13:40:52 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

class ValueNotFoundException : public std::exception  {
	public:
		virtual const char* what() const throw() {
			return "\033[31mError: \033[36mValue not found!\033[0m";
		} 
};

template <typename T>
typename T::iterator easyfind(T &arr, int value) {
	typename T::iterator it = std::find(arr.begin(), arr.end(), value);
	if (it == arr.end())
		throw ValueNotFoundException();
	return it;
}

#endif
