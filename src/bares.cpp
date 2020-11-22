/*!
 * \file bares.cpp
 * \author Edson Cassiano
 * \date November, 2020
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

#include "../lib/parser.h"
#include "../lib/bares.h"

Stack::Stack(){
	m_expression;
	m_top = -1;
}

void Stack::push(std::string expr){
	m_expression.push_back(expr);
	m_top++;
}

std::string Stack::pop(){
	std::string aux;
	aux = m_expression[m_top];
	m_top--;

	return aux;
}
std::string Stack::top(){

	return m_expression[m_top];

}
bool Stack::isEmpty(){
	return m_top == -1;
}

bool Stack::isFull(){
	return m_top == 500;
}

void Bares::setTkList(std::vector<Token> expr){
	m_tk_list = expr;
}

bool Bares::isNumber(Token::token_t type){
	return type == Token::token_t::OPERAND;
}

bool Bares::isOperator(Token::token_t type){
	return type == Token::token_t::OPERATOR;
}

bool Bares::openScope(Token::token_t type){
	return type == Token::token_t::OPEN_SCOPE;
}

bool Bares::closeScope(Token::token_t type){
	return type == Token::token_t::CLOSE_SCOPE;
}

int Bares::getPrecedence(std::string op){

	int index{0};
	while(index < op.size()){

		if(op[index] != ' '){
			break;
		}
		index++;
	}
	switch(op[index]){
		case '^': return 3;
		case '*':
		case '/':
		case '%': return 2;
		case '+':
		case '-': return 1;
		case ')':
		case '(': return 0;
		default: return -1;
	}
}

bool Bares::precedence(std::string op1, std::string op2){
	int cast1 = getPrecedence(op1);
	int cast2 = getPrecedence(op2);

	if(cast1 > cast2){
		return true;
	}else if(cast1 < cast2){
		return false;
	}else{
		return true;
	}
}

std::vector<Token> Bares::convert(){
	std::vector<Token> posf;
	std::stack<Token> c;

	for(auto i : m_tk_list){
		if(isNumber(i.type)){
			posf.emplace_back(i);
		}else if(openScope(i.type)){
			c.push(i);
		}else if(closeScope(i.type)){
			while(!openScope(c.top().type)){
				posf.emplace_back(c.top());
				c.pop();
			}
			c.pop();
		}else if(isOperator(i.type)){
			while(!c.empty() && precedence(c.top().value, i.value)){
				posf.emplace_back(c.top() );
				c.pop();
			}
			c.push(i);
		}
	}

	while(!c.empty()){
		posf.emplace_back(c.top());
		c.pop();
	}
	swap(m_tk_list, posf);

	return m_tk_list;
}

int Bares::calculate(int number1, int number2, int *error, std::string c){
	*error = 0;
	switch(c[0]){
		case '^': return pow(number1, number2);
		case '*': return number1*number2;
		case '/':{
					if(number2 == 0){
						*error = 1;
						return 0;
					}else{
						return number1/number2;
					}
				}
		case '%':{
					if(number2 == 0){
						*error = 1;
						return 0;
					}else{
						return number1%number2;
					}
				}
		case '+': return number2+number1;
		case '-': return number1-number2;
		default: std::cout <<"undefined operator";

	}
	return 0;
}

int Bares::inspect(int *error){
	std::stack<int> c;
	*error = 0;
	for(auto i : m_tk_list){
		if(isNumber(i.type)){
			c.push(stoll(i.value));
		}else if(isOperator(i.type)){
			auto op2 = c.top();
			c.pop();
			auto op1 = c.top();
			c.pop();
			auto value = calculate(op1, op2, error, i.value);
			c.push(value);
		}else{
			std::cout << "error";
		}
	}

	if(c.top() < -32768 || c.top() > 32768){
		*error = 2;
		return 0;
	}

	return c.top();

}
