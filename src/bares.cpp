#include <iostream>
#include <string>
#include <vector>

#include "../lib/bares.h"

Bares::Bares(std::string value){
	m_input = value;
}

void Bares::setInput(std::string value){
	m_input = value;
}

void Bares::read(std::string expression){
	int i{0};
	bool end{false};
	std::string substr;

	while(i < expression.size()){

		if(expression[i] >= '0' && expression[i] <= '9'){
			if(!end){
				substr.push_back(expression[i]);
			}
		}else{
			end = true;
			//TODO ACABOU
		}
		i++;
	}
}
