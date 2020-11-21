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
            std::cout << ">>> Unexpected end of input at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::ILL_FORMED_INTEGER:
            std::cout << ">>> Ill formed integer at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::MISSING_TERM:
            std::cout << ">>> Missing <term> at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::EXTRANEOUS_SYMBOL:
            std::cout << ">>> Extraneous symbol after valid expression found at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::INTEGER_OUT_OF_RANGE:
            std::cout << ">>> Integer constant out of range beginning at column (" << result.at_col << ")!\n";
            break;
        default:
            std::cout << ">>> Unhandled error found!\n";
            break;
    }

    std::cout << "\"" << str << "\"\n";
    std::cout << " " << error_indicator << std::endl;
}

int main(){

	Parser my_parser;
	Bares r;

	std::string expression;

	getline(std::cin, expression);

	
	auto result = my_parser.parse(expression);
	if(result.type != Parser::ResultType::OK){
		print_error_msg( result, expression);
	}else{
		// IMPLEMENTAR AQUI PRE FIXO POS FIXO
	}

	auto lista = my_parser.get_tokens();
	std::cout << ">>> Token: {";
	std::copy( lista.begin(), lista.end(), std::ostream_iterator< Token >(std::cout, " ") );
	std::cout << "}\n";

	int g{0};
	while(g < lista.size()){
		std::cout << lista[g].value << std::endl;
		g++;
	}

	return 0;
}
