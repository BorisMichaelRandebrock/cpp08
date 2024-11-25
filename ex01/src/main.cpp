/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:11:05 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/25 19:00:34 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <list>
#include <limits>
#include "Span.hpp"

#define RESET   "\033[0m"
#define BOLD     "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void printTestHeader(const std::string& header) {
    std::cout << std::endl << MAGENTA << BOLD << header << RESET << std::endl;
    std::cout << std::string(header.length(), '*') << std::endl;
}

int main() {
	std::cout << "\033[2J\033[1;1H";
    srand(time(0));

    printTestHeader("TEST 1: Basic Functionality");
    Span span1(5);
    try {
        span1.addNumber(3);
        span1.addNumber(9);
        span1.addNumber(17);
        span1.addNumber(11);
        span1.addNumber(7);
        std::cout << GREEN << "Expected Shortest: 2 | Expected Longest: 14" << RESET << std::endl;
        std::cout << YELLOW << "Shortest: " << GREEN << span1.shortestSpan() << YELLOW << " Longest: " << GREEN << span1.longestSpan() << RESET << std::endl << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    // Test 2: Overflow
    printTestHeader("TEST 2: Overflow Test");
    Span span2(2);
    try {
        span2.addNumber(1);
        span2.addNumber(2);
        span2.addNumber(3); // Should throw
    } catch (const std::exception& e) {
        std::cout << YELLOW << "Expected Error: Vector overflow" << RESET << std::endl;
        std::cout << e.what() << RESET << std::endl << std::endl;
    }

    // Test 3: Not Enough Numbers
    printTestHeader("TEST 3: Not Enough Numbers");
    Span span3(2);
    try {
        span3.addNumber(42);
        std::cout << YELLOW << "Expected Error: At least 2 numbers required" << RESET << std::endl;
        std::cout << YELLOW << "Shortest: " << GREEN << span3.shortestSpan() << RESET << std::endl; // Should throw
    } catch (const std::exception& e) {
        std::cout << e.what() << RESET << std::endl << std::endl;
    }

    // Test 4: Large Range with addRange
    printTestHeader("TEST 4: Large Range Addition");
    Span span4(10000);
    std::vector<int> numbers(10000);
    for (size_t i = 0; i < numbers.size(); ++i)
        numbers[i] = i;
    try {
        span4.addRange(numbers.begin(), numbers.end());
        std::cout << GREEN << "Expected Shortest: 1 | Expected Longest: 9999" << RESET << std::endl;
        std::cout << YELLOW << "Shortest: " << GREEN << span4.shortestSpan() << YELLOW << " Longest: " << GREEN << span4.longestSpan() << RESET << std::endl << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    // Test 5: Negative Numbers
    printTestHeader("TEST 5: Negative Numbers");
    Span span5(5);
    try {
        span5.addNumber(-3);
        span5.addNumber(17);
        span5.addNumber(9);
        span5.addNumber(-11);
        span5.addNumber(1);
        std::cout << GREEN << "Expected Shortest: 4 | Expected Longest: 28" << RESET << std::endl;
        std::cout << YELLOW << "Shortest: " << GREEN << span5.shortestSpan() << YELLOW <<" Longest: " << GREEN << span5.longestSpan() << RESET << std::endl << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    // Test 6: Extreme Numbers
    printTestHeader("TEST 6: Extreme Values");
    Span span6(2);
    try {
        span6.addNumber(std::numeric_limits<int>::min());
        span6.addNumber(std::numeric_limits<int>::max());
        std::cout << GREEN << "Expected Shortest: 4294967295 | Expected Longest: 4294967295" << RESET << std::endl;
        std::cout << YELLOW << "Shortest: " << GREEN << span6.shortestSpan() << YELLOW << " Longest: " << GREEN << span6.longestSpan() << RESET << std::endl << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    // Test 7: Random Values
    printTestHeader("TEST 7: Random Values");
    Span span7(1000);
    try {
        for (int i = 0; i < 10; ++i)
            span7.addNumber(rand() % 10000);
        std::cout << GREEN << "Shortest: " << span7.shortestSpan() << " | Longest: " << span7.longestSpan() << RESET << std::endl << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    return 0;
}
