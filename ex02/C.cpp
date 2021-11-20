/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 06:49:01 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/21 07:06:42 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "C.hpp"

C::C() {}
C::~C() {}
C::C(C const& src) { this->operator=(src); }
C& C::operator=(C const& rhs) {
    if (this != &rhs) {
        (void)rhs;
    }
    return *this;
}
