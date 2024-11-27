/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:45:19 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/27 14:22:17 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <vector>
#include <limits>
#include <stdexcept>

class Span {
	private:
		unsigned int _N;
		std::vector<int> _vec;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &);
		Span &operator=(const Span &);
		~Span();

		void addNumber(const int num);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		template <typename InputIterator>
		void addRange(InputIterator begin, InputIterator end) {
				for (InputIterator it = begin; it != end; ++it) {
					addNumber(*it);
				}
			}


		class VectorFullException : public std::exception {
			public:
				const char * what() const throw();
		};

		class TooFewNumbersException : public std::exception {
			public:
				const char *what() const throw();
		};

};

#endif
