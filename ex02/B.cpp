/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 06:46:49 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/21 07:06:33 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "B.hpp"

B::B() {}
B::~B() {}
B::B(B const& src) { this->operator=(src); }
B& B::operator=(B const& rhs) {
    if (this != &rhs) {
        (void)rhs;
    }
    return *this;
}
