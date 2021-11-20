/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 06:40:44 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/21 06:48:07 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_A_HPP_
#define EX02_A_HPP_

#include "Base.hpp"

class A : public Base {
 public:
    A();
    virtual ~A();
    A(A const& src);
    A& operator=(A const& rhs);
};

#endif  // EX02_A_HPP_
