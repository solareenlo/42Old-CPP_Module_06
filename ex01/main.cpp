/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 04:30:55 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/21 05:36:17 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Data.hpp"

#if defined(__linux) || defined(linux)
typedef __intptr_t uintptr_t;
#endif

uintptr_t serialize(Data* ptr) { return reinterpret_cast<uintptr_t>(ptr); }
Data* deserialize(uintptr_t raw) { return reinterpret_cast<Data*>(raw); }

int main() {
    std::srand(time(NULL));

    Data* ptr = initData();

    uintptr_t raw = serialize(ptr);
    Data* ptr_dese = deserialize(raw);

    std::cout << "ptr     : " << ptr << std::endl;
    std::cout << "ptr_dese: " << ptr_dese << std::endl;
    std::cout << "str1: " << ptr->str1 << std::endl;
    std::cout << "str1: " << ptr_dese->str1 << std::endl;
    std::cout << "n:    " << ptr->n << std::endl;
    std::cout << "n:    " << ptr_dese->n << std::endl;
    std::cout << "str2: " << ptr->str2 << std::endl;
    std::cout << "str2: " << ptr_dese->str2 << std::endl;

    delete ptr;
    return 0;
}
