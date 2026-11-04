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

    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif