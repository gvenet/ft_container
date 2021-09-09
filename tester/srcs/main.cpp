/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:53:07 by rchallie          #+#    #+#             */
/*   Updated: 2021/09/09 11:36:30 by gvenet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>

#include "../inc/vector.hpp"

static int rf = 20;

void test_ft(int i) {
	ft::vector<std::string> v1(i, "toto");
	for ( int i = 0; i < rf; i++ ) {
		v1.insert(v1.end(), "titi");
		std::cout << v1.size() << " " << v1.capacity() << " | ";
	}
}

void test_std(int i) {
	std::vector<std::string> v1(i, "toto");
	for ( int i = 0; i < rf; i++ ) {
		v1.insert(v1.end(), "titi");
		std::cout << v1.size() << " " << v1.capacity() << " | ";
	}
}

int main() {
	int r = 10;

	std::cout << "S C\n\n";
	for ( int i = 0; i < r; i++ ) {
		test_ft(i);
		std::cout << std::endl;
		test_std(i);
		std::cout << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
