/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:07:26 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/21 03:16:40 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion() : str_("0"), precision_(1), type_(kChar) {
    this->val_.c_ = '\0';
}

ScalarConversion::ScalarConversion(std::string const& str)
    : str_(str), precision_(1) {
    char* endptr;
    this->type_ = this->detectType(str);
    switch (this->type_) {
        case kChar:
            this->val_.c_ = std::atoi(this->str_.c_str());
            break;
        case kInt:
            this->val_.i_ = std::atoi(this->str_.c_str());
            break;
        case kFloat:
            errno = 0;
            this->val_.f_ =
                static_cast<float>(std::strtod(str.c_str(), &endptr));
            if (errno) {
                throw ScalarConversion::Fatal();
            }
            this->setPrecision(str);
            break;
        case kDouble:
            errno = 0;
            this->val_.d_ = std::strtod(str.c_str(), &endptr);
            if (errno) {
                throw ScalarConversion::Fatal();
            }
            this->setPrecision(str);
            break;
        default:
            this->val_.c_ = '\0';
    }
}

ScalarConversion::~ScalarConversion() {}

ScalarConversion::ScalarConversion(ScalarConversion const& src)
    : str_(src.getNumStr()),
      precision_(src.getPrecision()),
      type_(src.getType()),
      val_(src.getVal()) {}

ScalarConversion& ScalarConversion::operator=(ScalarConversion const& rhs) {
    if (this != &rhs) {
        this->precision_ = rhs.getPrecision();
        this->type_ = rhs.getType();
        this->val_ = rhs.getVal();
    }
    return *this;
}

void ScalarConversion::asChar() {
    std::cout << "char: ";
    try {
        switch (this->getType()) {
            case kChar:
                if (this->val_.c_ < 32 || 126 < this->val_.c_)
                    throw ScalarConversion::NonDisplayable();
                std::cout << "'" << this->val_.c_ << "'" << std::endl;
                break;
            case kInt:
                if (this->val_.i_ > std::numeric_limits<char>::max() ||
                    this->val_.i_ < std::numeric_limits<char>::min())
                    throw ScalarConversion::Impossible();
                if (this->val_.i_ < 32 || 126 < this->val_.i_)
                    throw ScalarConversion::NonDisplayable();
                std::cout << "'" << static_cast<char>(this->val_.i_) << "'"
                          << std::endl;
                break;
            case kFloat:
                if (this->str_ == "nanf" || this->str_ == "+nanf" ||
                    this->str_ == "-nanf")
                    throw ScalarConversion::Impossible();
                if (this->val_.f_ > std::numeric_limits<char>::max() ||
                    this->val_.f_ < std::numeric_limits<char>::min())
                    throw ScalarConversion::Impossible();
                if (this->val_.f_ < 32 || 126 < this->val_.f_)
                    throw ScalarConversion::NonDisplayable();
                std::cout << "'" << static_cast<char>(this->val_.f_) << "'"
                          << std::endl;
                break;
            case kDouble:
                if (this->str_ == "nan" || this->str_ == "+nan" ||
                    this->str_ == "-nan")
                    throw ScalarConversion::Impossible();
                if (this->val_.d_ > std::numeric_limits<char>::max() ||
                    this->val_.d_ < std::numeric_limits<char>::min())
                    throw ScalarConversion::Impossible();
                if (this->val_.d_ < 32 || 126 < this->val_.d_)
                    throw ScalarConversion::NonDisplayable();
                std::cout << "'" << static_cast<char>(this->val_.d_) << "'"
                          << std::endl;
                break;
            default:
                throw ScalarConversion::Impossible();
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConversion::asInt() {
    std::cout << "int: ";
    try {
        switch (this->getType()) {
            case kChar:
                std::cout << static_cast<int>(this->val_.c_) << std::endl;
                break;
            case kInt:
                std::cout << this->val_.i_ << std::endl;
                break;
            case kFloat:
                if (this->str_ == "nanf" || this->str_ == "+nanf" ||
                    this->str_ == "-nanf")
                    throw ScalarConversion::Impossible();
                if (this->val_.f_ > (1 << 24) - 1)
                    throw ScalarConversion::Impossible();
                if (this->val_.f_ < -(1 << 24) + 1)
                    throw ScalarConversion::Impossible();
                std::cout << static_cast<int>(this->val_.f_) << std::endl;
                break;
            case kDouble:
                if (this->str_ == "nan" || this->str_ == "+nan" ||
                    this->str_ == "-nan")
                    throw ScalarConversion::Impossible();
                if (this->val_.d_ > std::numeric_limits<int>::max())
                    throw ScalarConversion::Impossible();
                if (this->val_.d_ < std::numeric_limits<int>::min())
                    throw ScalarConversion::Impossible();
                std::cout << static_cast<int>(this->val_.d_) << std::endl;
                break;
            default:
                throw ScalarConversion::Impossible();
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConversion::asFloat() {
    std::cout << std::fixed << std::setprecision(this->getPrecision());
    std::cout << "float: ";
    try {
        switch (this->getType()) {
            case kChar:
                std::cout << static_cast<float>(this->val_.c_) << "f"
                          << std::endl;
                break;
            case kInt:
                if (this->val_.i_ > (1 << 24) - 1)
                    throw ScalarConversion::Impossible();
                if (this->val_.i_ < -(1 << 24) + 1)
                    throw ScalarConversion::Impossible();
                std::cout << static_cast<float>(this->val_.i_) << "f"
                          << std::endl;
                break;
            case kFloat:
                std::cout << this->val_.f_ << "f" << std::endl;
                break;
            case kDouble:
                if (this->val_.d_ > std::numeric_limits<float>::max())
                    throw ScalarConversion::Impossible();
                if (this->val_.d_ < -std::numeric_limits<float>::max())
                    throw ScalarConversion::Impossible();
                if (this->val_.d_ != 0.0) {
                    if (this->val_.d_ < std::numeric_limits<float>::min() &&
                        this->val_.d_ > -std::numeric_limits<float>::min())
                        throw ScalarConversion::Impossible();
                }
                std::cout << static_cast<float>(this->val_.d_) << "f"
                          << std::endl;
                break;
            default:
                throw ScalarConversion::Impossible();
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::defaultfloat;
}

void ScalarConversion::asDboule() {
    std::cout << std::fixed << std::setprecision(this->getPrecision());
    std::cout << "double: ";
    try {
        switch (this->getType()) {
            case kChar:
                std::cout << static_cast<double>(this->val_.c_) << std::endl;
                break;
            case kInt:
                std::cout << static_cast<double>(this->val_.i_) << std::endl;
                break;
            case kFloat:
                std::cout << static_cast<double>(this->val_.f_) << std::endl;
                break;
            case kDouble:
                std::cout << this->val_.d_ << std::endl;
                break;
            default:
                throw ScalarConversion::Impossible();
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::defaultfloat;
}

char const* ScalarConversion::Fatal::what() const throw() { return "fatal"; }

std::string const ScalarConversion::getNumStr() const { return this->str_; }
int ScalarConversion::getPrecision() const { return this->precision_; }
int ScalarConversion::getType() const { return this->type_; }
union UniVal ScalarConversion::getVal() const {
    return this->val_;
}

bool ScalarConversion::isValidNumber(std::string const& str) {
    char* endptr;
    errno = 0;
    double d = std::strtod(str.c_str(), &endptr);
    (void)d;
    if (errno) {
        return false;
    }
    if (*endptr && !(*endptr == 'f' && *(endptr + 1) == '\0')) {
        return false;
    }
    if (*endptr && str.size() == 1) {
        return false;
    }
    return true;
}

int ScalarConversion::detectType(std::string const& str) {
    if (this->isValidNumber(str) == false) {
        return kImpossible;
    }

    if (!str.compare("-inff") || !str.compare("+inff") ||
        !str.compare("inff") || !str.compare("nanf") || !str.compare("+nanf") ||
        !str.compare("-nanf")) {
        return (kFloat);
    }

    if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("inf") ||
        !str.compare("nan") || !str.compare("+nan") || !str.compare("-nan")) {
        return (kDouble);
    }

    char* endptr;
    errno = 0;
    double d = std::strtod(str.c_str(), &endptr);
    if (errno) {
        throw ScalarConversion::Fatal();
    }
    if (*endptr == 'f') {
        return (kFloat);
    }

    if (d > std::numeric_limits<int>::max() ||
        d < std::numeric_limits<int>::min()) {
        return (kDouble);
    }

    int i = std::strtol(str.c_str(), &endptr, this->base_);
    errno = 0;
    if (errno) {
        throw ScalarConversion::Fatal();
    }
    if (*endptr == '.' || *endptr == 'e') {
        return (kDouble);
    }

    if (i > std::numeric_limits<char>::max() ||
        i < std::numeric_limits<char>::min()) {
        return (kInt);
    }
    return (kChar);
}

void ScalarConversion::setPrecision(std::string const& str) {
    std::string::size_type pos_dot = str.find(".");
    if (pos_dot == std::string::npos) {
        return;
    }

    std::string::size_type pos_e = str.find("e", pos_dot + 1);
    std::string::size_type pos_f = str.find("f", pos_e + 1);
    if (pos_dot == str.size() - 1) {
        return;
    }
    if (pos_f != std::string::npos) {
        if (pos_dot == str.size() - 2) {
            return;
        }
    }
    if (pos_e == std::string::npos) {
        if (pos_f == std::string::npos)
            this->precision_ = str.size() - pos_dot - 1;
        else
            this->precision_ = str.size() - pos_dot - 2;
    } else {
        this->precision_ = pos_e - pos_dot;
        std::string tmp = str.substr(pos_e + 1, str.size() - pos_e);
        if (pos_f == std::string::npos)
            tmp = str.substr(pos_e + 1, str.size() - 1 - pos_e);
        int i = std::atoi(tmp.c_str());
        if (i < 0) {
            this->precision_ += std::abs(i) - 1;
        } else {
            this->precision_ -= std::abs(i) + 1;
            if (this->precision_ < 1) this->precision_ = 1;
        }
    }
}

char const* ScalarConversion::NonDisplayable::what() const throw() {
    return "Non displayable";
}

char const* ScalarConversion::Impossible::what() const throw() {
    return "impossible";
}
