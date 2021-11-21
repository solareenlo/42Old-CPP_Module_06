/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:02:10 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/21 08:57:02 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX00_SCALARCONVERSION_HPP_
#define EX00_SCALARCONVERSION_HPP_

#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

enum { kChar, kInt, kFloat, kDouble, kImpossible };

union UniVal {
    char c_;
    int i_;
    float f_;
    double d_;
};

class ScalarConversion {
 public:
    explicit ScalarConversion(std::string const& str);
    virtual ~ScalarConversion();
    ScalarConversion(ScalarConversion const& src);

    ScalarConversion& operator=(ScalarConversion const& rhs);

    void asChar();
    void asInt();
    void asFloat();
    void asDboule();

    class Fatal : public std::exception {
     public:
        char const* what() const throw();
    };

 private:
    ScalarConversion();

    static const int base_ = 10;

    std::string const str_;
    int precision_;
    int type_;
    union UniVal val_;

    std::string const getNumStr() const;
    int getPrecision() const;
    int getType() const;
    union UniVal getVal() const;

    bool isValidNumber(std::string const& str);
    int detectType(std::string const& str);
    void setPrecision(std::string const& str);

    class NonDisplayable : public std::exception {
     public:
        char const* what() const throw();
    };

    class Impossible : public std::exception {
     public:
        char const* what() const throw();
    };
};

#endif  // EX00_SCALARCONVERSION_HPP_
