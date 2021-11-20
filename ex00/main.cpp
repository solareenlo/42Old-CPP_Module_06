/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:55:27 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/21 03:01:22 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ScalarConversion.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << std::endl;
        std::cout << argv[0] << " \"string\"" << std::endl;
        return EXIT_FAILURE;
    }

    try {
        ScalarConversion scalar(argv[1]);

        scalar.asChar();
        scalar.asInt();
        scalar.asFloat();
        scalar.asDboule();
    } catch (std::exception& e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
