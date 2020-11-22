/*!
 * \file main.cpp
 * \author Edson Cassiano
 * \date November, 2020
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "lib/bares.h"
#include "lib/parser.h"

void print_error_msg( const Parser::ResultType & result, std::string str )
{
    std::string error_indicator( str.size()+1, ' ');

    // Have we got a parsing error?
    error_indicator[result.at_col] = '^';
    switch ( result.type )
    {
        case Parser::ResultType::UNEXPECTED_END_OF_EXPRESSION:
            std::cout << "Unexpected end of input at column (" << result.at_col+1 << ")!\n";
            break;
        case Parser::ResultType::ILL_FORMED_INTEGER:
            std::cout << "Ill formed integer at column (" << result.at_col+1 << ")!\n";
            break;
        case Parser::ResultType::MISSING_TERM:
            std::cout << "Missing <term> at column (" << result.at_col+1 << ")!\n";
            break;
        case Parser::ResultType::EXTRANEOUS_SYMBOL:
            std::cout << "Extraneous symbol after valid expression found at column (" << result.at_col+1 << ")!\n";
            break;
        case Parser::ResultType::INTEGER_OUT_OF_RANGE:
            std::cout << "Integer constant out of range beginning at column (" << result.at_col+1 << ")!\n";
			break;
		case Parser::ResultType::INCOMPLETE_EXPRE:
			std::cout << "Unexprected end of expression at column (" << result.at_col+1 << ")!\n";
			break;
		case Parser::ResultType::MISS_CLOSE_SCOPE:
			std::cout << "Missing closing \")\" at column (" << result.at_col+1 <<")!\n";
            break;
		case Parser::ResultType::DIV_BY_ZERO:
			std::cout << "Division by zero!\n"; 
			break;
		case Parser::ResultType::OUT_RANGE:
			std::cout << "Numeric overflow error!\n";
			break;
        default:
            std::cout << ">>> Unhandled error found!\n";
            break;
    }

//    std::cout << "\"" << str << "\"\n";
//    std::cout << " " << error_indicator << std::endl;
}

int main(){

	Parser my_parser;
	Bares r;
	int error{0};

	std::string expression;

	while( getline(std::cin, expression) ){

		auto result = my_parser.parse(expression);

		r.setTkList(my_parser.get_tokens() );

		if(result.type != Parser::ResultType::OK){
			print_error_msg( result, expression);
		}else{
			auto list = my_parser.get_tokens();
			list = r.convert();
			auto rCal = r.inspect(&error);
			if(error == 1){
				std::cout << "Division by zero!\n";
			}else if(error == 2){
				std::cout << "Numeric overflow error!\n";
			}else{
				std::cout << rCal << std::endl;
			}
		}
	}

	return 0;
}
