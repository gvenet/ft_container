/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:53:07 by rchallie          #+#    #+#             */
/*   Updated: 2021/09/07 22:24:57 by gvenet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../inc/vector.hpp"

int main() {
	ft::vector<int>			  v1(3, 5);
	ft::vector<int>::iterator it;

	v1.push_back(42);
	for ( it = v1.begin(); it != v1.end(); it++ ) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}