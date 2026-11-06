#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
  private:
    int               _rawBits;
    static const int  _fractionalBits = 8;
  
  public:
    Fixed();
    Fixed(const int number);
    Fixed(const float number);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    void  setRawBits(int const raw);
    int   getRawBits(void) const;
    int   toInt(void) const;
    float toFloat(void) const;

    // Comparison operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Increment/decrement operators
    Fixed &operator++(void);
    Fixed &operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);

    static const Fixed &min(const Fixed &n,const Fixed &m);
    static Fixed min(Fixed &n,Fixed &m);
    static const Fixed &max(const Fixed &n, const Fixed &m);
    static Fixed max(Fixed &n, Fixed &m);
  };

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif