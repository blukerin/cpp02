#include "../includes/Fixed.hpp"

Fixed::Fixed():_rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) {
  std::cout << "Int constructor called" << std::endl;
  this->_rawBits = number << this->_fractionalBits;
}

Fixed::Fixed(const float number) {
  std::cout << "Float constructor called" << std::endl;
  this->_rawBits = roundf(number * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
    this->_rawBits = other.getRawBits();
  return (*this);
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

void  Fixed::setRawBits(int const raw) {
  this->_rawBits = raw;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->_rawBits);
}

int Fixed::toInt(void) const {
  return (_rawBits >> this->_fractionalBits);
}

float Fixed::toFloat(void) const {
  return (float(this->_rawBits) / (1 << this->_fractionalBits));
}

std::ostream  &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return (out);
}

bool Fixed::operator>(const Fixed &other) const{
  if (this->_rawBits > other._rawBits)
    return (true);
  else
    return (false);
}

bool Fixed::operator<(const Fixed &other) const{
  if (this->_rawBits < other._rawBits)
    return (true);
  else
    return (false);
} 

bool Fixed::operator>=(const Fixed &other) const{
  if (this->_rawBits >= other._rawBits)
    return (true);
  else
    return (false);
}

bool Fixed::operator<=(const Fixed &other) const{
  if (this->_rawBits <= other._rawBits)
    return (true);
  else
    return (false);
}

bool Fixed::operator==(const Fixed &other) const{
  if (this->_rawBits == other._rawBits)
    return (true);
  else
    return (false);
}

bool Fixed::operator!=(const Fixed &other) const{
  if (this->_rawBits != other._rawBits)
    return (true);
  else
    return (false);
}