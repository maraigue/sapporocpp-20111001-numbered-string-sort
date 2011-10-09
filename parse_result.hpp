#ifndef _PARSE_RESULT_HPP_
#define _PARSE_RESULT_HPP_

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <boost/xpressive/xpressive.hpp>
#include "char_or_number.hpp"

class ParseResult{
private:
	std::vector<CharOrNumber> result;
public:
	ParseResult();
	ParseResult(const std::string & source);
	bool operator<(const ParseResult & other) const;
	bool operator==(const ParseResult & other) const;
	bool operator>(const ParseResult & other) const;
	void output(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const ParseResult & cn);

#endif // _PARSE_RESULT_HPP_

