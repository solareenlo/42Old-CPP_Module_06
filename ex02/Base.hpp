/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 06:36:17 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/21 06:59:02 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_BASE_HPP_
#define EX02_BASE_HPP_

class Base {
 public:
    Base();
    virtual ~Base();
    Base(Base const& src);
    Base& operator=(Base const& rhs);
};
#endif  // EX02_BASE_HPP_
