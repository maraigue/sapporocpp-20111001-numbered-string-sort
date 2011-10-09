#include <boost/foreach.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include "parse_result.hpp"

void readlines(std::istream & ifs, std::vector<std::string> & result){
	if(ifs.eof()) return;
	
	for(;;){
		std::string buf;
		getline(ifs, buf);
		if(ifs.eof()) break;
		result.push_back(buf);
	}
	
	// 最終行が空行なら除去
	if(result[result.size() - 1].empty()) result.pop_back();
}

int main(int argc, char *argv[]){
	using namespace std;
	vector<string> source;
	
	// 読み込み
	switch(argc){
	case 2:
		// 指定されたファイルを読み込む
		{
			ifstream ifs(argv[1], ios::in);
			if(!ifs){
				cerr << "Invalid file" << endl;
				return -1;
			}
			readlines(ifs, source);
		}
		break;
	default:
		cerr << "Usage " << argv[0] << " FILE" << endl;
		return -1;
	}
	/*
    BOOST_FOREACH(const string & entry, source){
    	cout << '[' << entry << ']' << endl;
    }
    */
    
    // 比較用のデータに変換
    vector< ParseResult > data;
    BOOST_FOREACH(const string & entry, source){
    	data.push_back(ParseResult(entry));
    }
    
    sort(data.begin(), data.end());
    BOOST_FOREACH(const ParseResult & entry, data){
    	cout << '[' << entry << ']' << endl;
    }
        
    return 0;
}

