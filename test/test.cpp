#include <hard/numeric.hpp>
#include <stdlib.h>

#include <sstream>

#define TEST_ASSERT(x) \
    if(!(x)) {         \
        abort();       \
    }

template<class TestT>
void stringtest()
{
    std::ostringstream o;
    o << Hard::Hard<TestT>(TestT(128));
    TEST_ASSERT(o.str() == "128");
}

template<>
void stringtest<signed char>()
{
    std::ostringstream o;
    o << Hard::Hard<signed char>((signed char)(65));
    TEST_ASSERT(o.str() == "A");
}

template<>
void stringtest<unsigned char>()
{
    std::ostringstream o;
    o << Hard::Hard<unsigned char>((unsigned char)(65));
    TEST_ASSERT(o.str() == "A");
}

template<class TestT>
void test()
{
    Hard::Hard<TestT> x(TestT(2));
    x += Hard::Hard<TestT>(TestT(2));

    TEST_ASSERT(x == Hard::Hard<TestT>(TestT(4)));

    x *= Hard::Hard<TestT>(TestT(2));
    TEST_ASSERT(x == Hard::Hard<TestT>(TestT(8)));

    x -= Hard::Hard<TestT>(TestT(2));
    TEST_ASSERT(x == Hard::Hard<TestT>(TestT(6)));

    x /= Hard::Hard<TestT>(TestT(2));
    TEST_ASSERT(x == Hard::Hard<TestT>(TestT(3)));

    x <<= Hard::Hard<TestT>(TestT(1));
    TEST_ASSERT(x == Hard::Hard<TestT>(TestT(6)));

    x >>= Hard::Hard<TestT>(TestT(1));
    TEST_ASSERT(x == Hard::Hard<TestT>(TestT(3)));

    stringtest<TestT>();
}

int main()
{
    test<signed char>();
    test<signed short>();
    test<signed int>();
    test<signed long>();
    test<signed long long>();

    test<unsigned char>();
    test<unsigned short>();
    test<unsigned int>();
    test<unsigned long>();
    test<unsigned long long>();

    return 0;
}
