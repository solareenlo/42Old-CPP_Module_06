/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 06:46:22 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/21 07:01:13 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_B_HPP_
#define EX02_B_HPP_

#include "Base.hpp"

class B : public Base {
 public:
    B();
    virtual ~B();
    B(B const& src);
    B& operator=(B const& rhs);
};
#endif  // EX02_B_HPP_
