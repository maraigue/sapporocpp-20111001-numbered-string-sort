#include "char_or_number.hpp"

const std::string CharOrNumber::buf() const{
	return buf_;
}

bool CharOrNumber::operator<(const CharOrNumber & other) const{
	// 「数字が1文字以上連続した領域」か「数字でない1文字」が2つ与えられた時に
	// それらを比較することをここで行う。
	if(is_number_ && !(other.is_number_)){
		// 一方が数字、もう一方が数字でない1文字である場合、
		// 数字の方を小さいとみなす。
		return true;
	}else if(!is_number_ && other.is_number_){
		// 同上。
		return false;
	}else if(is_number_ && other.is_number_){
		// 両方が数字である場合、
		// (1)文字数が異なるなら、文字数が少ない方を小さいとみなす。
		// (2)文字数が同じなら、普通に文字列として比較する。
		if(buf_.length() == other.buf_.length()){
			return(buf_ < other.buf_);
		}else{
			return(buf_.length() < other.buf_.length());
		}
	}else{
		// 両方が数字でない1文字である場合、普通に比較する。
		return(buf_ < other.buf_);
	}
}

bool CharOrNumber::operator==(const CharOrNumber & other) const{
	return(
		(is_number_ == other.is_number_) &&
		(buf_ == other.buf_));
}

bool CharOrNumber::operator>(const CharOrNumber & other) const{
	return(other < *this);
}
	
