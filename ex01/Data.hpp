/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 05:02:43 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/21 05:30:13 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX01_DATA_HPP_
#define EX01_DATA_HPP_

#include <cstdlib>
#include <string>

static const char ASCII[] = {
    ' ', '!', '"', '#', '$',  '%', '&', '\'', '(', ')', '*', '+', ',', '-',
    '.', '/', '0', '1', '2',  '3', '4', '5',  '6', '7', '8', '9', ':', ';',
    '<', '=', '>', '?', '@',  'A', 'B', 'C',  'D', 'E', 'F', 'G', 'H', 'I',
    'J', 'K', 'L', 'M', 'N',  'O', 'P', 'Q',  'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', '[', '\\', ']', '^', '_',  '`', 'a', 'b', 'c', 'd', 'e',
    'f', 'g', 'h', 'i', 'j',  'k', 'l', 'm',  'n', 'o', 'p', 'q', 'r', 's',
    't', 'u', 'v', 'w', 'x',  'y', 'z', '{',  '|', '}', '~'};

static const size_t ASCII_SIZE = sizeof(ASCII) / sizeof(char);

struct Data {
    std::string str1;
    int n;
    std::string str2;
};

Data* initData() {
    Data* pdata = new Data();
    for (size_t i = 0; i < 8; i++) {
        pdata->str1.push_back(ASCII[std::rand() % ASCII_SIZE]);
        pdata->str2.push_back(ASCII[std::rand() % ASCII_SIZE]);
    }
    pdata->n = std::rand() % RAND_MAX;
    return pdata;
}

#endif  // EX01_DATA_HPP_
