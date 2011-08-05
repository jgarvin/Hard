#ifndef INCLUDED_HARD_NUMERIC_HPP
#define INCLUDED_HARD_NUMERIC_HPP

#include <iostream>

namespace Hard
{

#define HARD_DETAIL_STATIC_ABORT(Type)              \
    {                                               \
        char foo[-sizeof(Type)];                     \
    }

template<class T>
class Hard
{
public:
    explicit inline Hard()
        : val_(0)
    {}

    explicit inline Hard(T val)
        : val_(val)
    {}

    // Prevents implicit conversions to T invoking
    // constructor above.
    template<class Invalid>
    explicit inline Hard(Invalid)
    {
        HARD_DETAIL_STATIC_ABORT(Invalid);
    }

    inline Hard(Hard const& o)
        : val_(o.val_)
    {}

    inline ~Hard()
    {
    }

    bool zero() const
    {
        return val_ == 0;
    }

    bool nonzero() const
    {
        return val_ != 0;
    }

    inline bool operator==(Hard<T> o) const
    {
        return val_ == o.val_;
    }

    inline Hard<T> operator+(Hard<T> o) const
    {
        return Hard<T>(val_ + o.val_);
    }

    inline Hard<T> operator-(Hard<T> o) const
    {
        return Hard<T>(val_ - o.val_);
    }

    inline Hard<T> operator*(Hard<T> o) const
    {
        return Hard<T>(val_ * o.val_);
    }

    inline Hard<T> operator/(Hard<T> o) const
    {
        return Hard<T>(val_ / o.val_);
    }

    inline Hard<T> operator<<(Hard<T> o) const
    {
        return Hard<T>(val_ << o.val_);
    }

    inline Hard<T> operator>>(Hard<T> o) const
    {
        return Hard<T>(val_ >> o.val_);
    }

    inline Hard<T> operator+=(Hard<T> o)
    {
        val_ += o.val_;
        return *this;
    }

    inline Hard<T> operator-=(Hard<T> o)
    {
        val_ -= o.val_;
        return *this;
    }

    inline Hard<T> operator*=(Hard<T> o)
    {
        val_ *= o.val_;
        return *this;
    }

    inline Hard<T> operator/=(Hard<T> o)
    {
        val_ /= o.val_;
        return *this;
    }

    inline Hard<T> operator>>=(Hard<T> o)
    {
        val_ >>= o.val_;
        return *this;
    }

    inline Hard<T> operator<<=(Hard<T> o)
    {
        val_ <<= o.val_;
        return *this;
    }

    T raw() const
    {
        return val_;
    }

private:
    T val_;
};

#undef HARD_DETAIL_STATIC_ABORT

template<class T>
std::ostream& operator<<(std::ostream& o, Hard<T> const& h)
{
    return o << h.raw();
}

typedef Hard<signed char> Char;
typedef Hard<signed short> Short;
typedef Hard<signed int> Int;
typedef Hard<signed long> Long;
typedef Hard<signed long long> LongLong;

typedef Hard<unsigned char> UChar;
typedef Hard<unsigned short> UShort;
typedef Hard<unsigned int> UInt;
typedef Hard<unsigned long> ULong;
typedef Hard<unsigned long long> ULongLong;

} // namespace Hard

#endif
