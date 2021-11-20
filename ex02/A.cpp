/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 06:41:38 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/21 07:06:25 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "A.hpp"

A::A() {}
A::~A() {}
A::A(A const& src) { this->operator=(src); }
A& A::operator=(A const& rhs) {
    if (this != &rhs) {
        (void)rhs;
    }
    return *this;
}
