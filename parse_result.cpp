#include "parse_result.hpp"

ParseResult::ParseResult(){
	// do nothing
}

ParseResult::ParseResult(const std::string & source){
	using namespace boost::xpressive;
	std::string buf;
	
	sregex re = sregex::compile("[0-9]+|[^0-9]");
	sregex_token_iterator begin(source.begin(), source.end(), re), end;
	for(sregex_token_iterator it = begin; it != end; it++){
		buf = *it;
		if(buf.length() == 1 && (buf[0] < '0' || buf[0] > '9')){
			// 1文字の場合
			result.push_back(CharOrNumber(buf, false));
		}else{
			// 文字列の場合
			result.push_back(CharOrNumber(buf, true));
		}
	}
}

bool ParseResult::operator<(const ParseResult & other) const{
	return(result < other.result);
}

bool ParseResult::operator==(const ParseResult & other) const{
	return(result == other.result);
}

bool ParseResult::operator>(const ParseResult & other) const{
	return(result > other.result);
}

void ParseResult::output(std::ostream& os) const{
	for(std::vector<CharOrNumber>::const_iterator it = result.begin(); it != result.end(); it++){
		os << it->buf();
	}
}

std::ostream& operator<<(std::ostream& os, const ParseResult & cn){
	cn.output(os);
	return os;
}

