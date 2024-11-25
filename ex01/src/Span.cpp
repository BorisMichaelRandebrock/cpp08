/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:55:23 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/25 17:39:19 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &cpy) {
	*this = cpy;
}

Span &Span::operator=(const Span &cpy) {
	this->_N = cpy._N;
	return *this;
}

Span::~Span() {}

void Span::addNumber(const int num) {
	if (this->_N <= _vec.size())
		throw VectorFullException();
	_vec.push_back(num);
}

unsigned int Span::shortestSpan() const {
	if (this->_vec.size() <= 1)
		throw TooFewNumbersException();
	std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());
	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	for (unsigned int i = 0; i < sorted.size() -1; ++i) {
		unsigned int span = static_cast<unsigned int>(sorted[i + 1] - sorted[i]);

		if (static_cast<unsigned int>(span) < shortest)
			shortest = static_cast<unsigned int>(span);
	}
	return shortest;
}

unsigned int Span::longestSpan() const {
	if (this->_vec.size() <= 1)
		throw TooFewNumbersException();
	int minElement = *std::min_element(_vec.begin(), _vec.end());
	int maxElement = *std::max_element(_vec.begin(), _vec.end());
	unsigned int longest = static_cast<unsigned int>(maxElement) - static_cast<unsigned int>(minElement);
	return longest;

}

const char *Span::VectorFullException::what() const throw() {
	return "\033[31mError: \033[36mVector overflow.. can not add more numbers!\033[0m";
}

const char *Span::TooFewNumbersException::what() const throw() {
	return "\033[31mError: \033[36mYou need at least 2 different numbers to return a valid span!\033[0m";
}
