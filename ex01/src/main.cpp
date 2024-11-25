/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:11:05 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/25 13:28:04 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"
#include <unistd.h>

#define RESET   "\033[0m"
#define BOLD     "\033[1m"
#define RED_BACKGROUND "\033[41m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"


int main() {
	std::vector<int> myVector;
	std::cout << CYAN << BOLD << "🚀 Launching the Vector Search Experiment... 🎯\n" << RESET;
	sleep(1);
	myVector.push_back(5);
	myVector.push_back(20);
	myVector.push_back(30);
	myVector.push_back(60);
	myVector.push_back(50);
	std::cout << BLUE << "We've got a vector full of numbers: {5, 20, 30, 60, 50}.\n" << RESET;
	sleep(1);

	std::cout << YELLOW << "⏳ Let's begin the hunt! Looking for 10... It should give us an error. 🤔\n" << RESET;
	sleep(1);
	try {
		std::vector<int>::iterator it = easyfind(myVector, 10);
		int position = it - myVector.begin();
		std::cout << GREEN << "🎉 Found it! But wait, how? We shouldn't have... It was found at position " << position << RESET << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << "💥 Oops! " << e.what() << RESET << std::endl;
	}
	sleep(1);

	std::cout << YELLOW << "🔍 Searching for 30... It should be found at position 2 (third spot)!\n" << RESET;
	sleep(1);
	try {
		std::vector<int>::iterator it = easyfind(myVector, 30);
		int position = it - myVector.begin();
		std::cout << GREEN << "🎉 Success! The number 30 is chilling at position " << position << " (a.k.a. the 3rd position)!" << RESET << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << "💥 Oops! " << e.what() << RESET << std::endl;
	}

	sleep(1);
	std::cout << YELLOW << "🧐 Searching for 50... Surely it's here... let's see!\n" << RESET;
	sleep(1);
	try {
		std::vector<int>::iterator it = easyfind(myVector, 50);
		int position = it - myVector.begin();
		std::cout << GREEN << "🎉 Found it! Number 50 is sitting comfortably at position " << position << " (fifth place)!" << RESET << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << "💥 Oops! " << e.what() << RESET << std::endl;
	}
	sleep(1);

	std::cout << BLUE << "🚀 All searches complete! Thanks for joining the Vector Adventure! 🌟\n" << RESET;
	return 0;
}

