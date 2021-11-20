/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 06:38:57 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/21 07:07:18 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base() {}
Base::~Base() {}
Base::Base(Base const& src) { this->operator=(src); }
Base& Base::operator=(Base const& rhs) {
    if (this != &rhs) {
        (void)rhs;
    }
    return *this;
}
