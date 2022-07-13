#define BOOST_TEST_MODULE MoneyTest
#include <boost/test/included/unit_test.hpp>

#include "money.h" // project being tested
#include <string>

BOOST_AUTO_TEST_CASE(simple_add)
{
    Money m12chf(12, "CHF");
    Money m14chf(14, "CHF");
    Money expected (26, "CHF");
    Money* observed = m12chf.add(m14chf);
	
    BOOST_CHECK(expected == (*observed));
}
