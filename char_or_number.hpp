#ifndef _CHAR_OR_NUMBER_HPP_
#define _CHAR_OR_NUMBER_HPP_

#include <string>

class CharOrNumber{
private:
	bool is_number_;
	std::string buf_;
public:
	
	CharOrNumber(){}
	CharOrNumber(std::string buf, bool is_number) : buf_(buf), is_number_(is_number) {};
	const std::string buf() const;
	bool operator<(const CharOrNumber & other) const;
	bool operator==(const CharOrNumber & other) const;
	bool operator>(const CharOrNumber & other) const;
};

#endif // _CHAR_OR_NUMBER_HPP_

