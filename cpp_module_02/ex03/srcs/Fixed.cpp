/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:25:38 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/10 10:33:43 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
	//std::cout << "Copy constructor called" << std::endl;
	_fixedPointValue = src.getRawBits();
}

Fixed::~Fixed(void) {
	//std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	//std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

Fixed::Fixed(int const value) {
	//std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(float const value) {
	//std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const {
	return (float)this->_fixedPointValue / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
	return (int)this->getRawBits() >> this->_fractionalBits;
}

std::ostream& operator<<(std::ostream& os, Fixed const& rhs) {
	os << rhs.toFloat();
	return os;
}

//comparison operators

bool Fixed::operator>(Fixed const& rhs) const{
	if (this->toFloat() > rhs.toFloat())
		return true;
	return false;
}
bool Fixed::operator<(Fixed const& rhs) const{
	if (this->toFloat() < rhs.toFloat())
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const& rhs) const{
	if (this->toFloat() >= rhs.toFloat())
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const& rhs) const{
	if (this->toFloat() <= rhs.toFloat())
		return true;
	return false;
}

bool Fixed::operator==(Fixed const& rhs) const{
	if (this->toFloat() == rhs.toFloat())
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const& rhs) const{
	if (this->toFloat() != rhs.toFloat())
		return true;
	return false;
}

//arithmetic operators

Fixed Fixed::operator+(Fixed const& rhs) const{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const& rhs) const{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const& rhs) const{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const& rhs) const{
	return Fixed(this->toFloat() / rhs.toFloat());
}

//increment and decrement operators

Fixed& Fixed::operator++(void){
	this->_fixedPointValue += 1;
	return (*this);
}

Fixed Fixed::operator++(int){
	Fixed temp = *this;
	this->_fixedPointValue += 1;
	return temp;
}

Fixed& Fixed::operator--(void){
	this->_fixedPointValue -= 1;
	return (*this);
}

Fixed Fixed::operator--(int){
	Fixed temp = *this;
	this->_fixedPointValue += 1;
	return temp;
}

//min and max functions

Fixed& Fixed::min(Fixed& a, Fixed& b){
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b){
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b){
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}
Fixed const& Fixed::max(Fixed const& a, Fixed const& b){
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}
