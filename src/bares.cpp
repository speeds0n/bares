#include <iostream>
#include <string>
#include <vector>

#include "../lib/bares.h"

Stack::Stack(){
	m_expression;
	m_top = -1;
}

void Stack::push(std::string expr){
	m_expression.push_back(expr);
	m_top++;
	//TODO implementar verificação se a pilha está cheia
}

std::string Stack::pop(){
	//TODO implementar a verficação se a pilha está vazia
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

Bares::Bares(std::string value){
	m_input = value;
}

int Bares::inputSize(){
	return m_input.size();
}

void Bares::setInput(std::string value){
	m_input = value;
}

void Bares::read(){

	int i{0};
	std::string expr;
	std::string test;

	expr = getInput();

	while(i < inputSize()){

		if(expr[i] >= '0' && expr[i] <= '9'){
			test.push_back(expr[i]);
		}else{
			std::cout << test << std::endl;
			test.clear();
		}
		i++;
	}
}
