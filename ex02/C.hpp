/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 06:48:44 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/21 06:51:24 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_C_HPP_
#define EX02_C_HPP_

#include "Base.hpp"

class C : public Base {
 public:
    C();
    virtual ~C();
    C(C const& src);
    C& operator=(C const& rhs);
};
#endif  // EX02_C_HPP_
