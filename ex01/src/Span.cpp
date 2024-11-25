/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:55:23 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/25 14:32:56 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span();

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &cpy) {
	*this = cpy;
}

Span &Span::operator=(const Span &cpy) {
	this->_N = cpy._N;
	return *this;
}

Span::~Span() {}

Span::addNumber(const int num) const {
	if (this->_N <= _vec.size())
		throw VectorFullException();
	_vec.push_back(num);
}

const char *Span::VectorFullException::what() const throw() {
	return "\033[31mError: \033[36mVector overflow.. can not add more numbers!\033[0m"
}

const char *Span::TooFewNumbersException::what() const throw {
	return "\033[31mError: \033[36mYou need at least 2 different numbers to return a valid span!\033[0m"
}
