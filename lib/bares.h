#ifndef BARES_H
#define BARES_H

#include <vector>

class Stack{

	private:
		std::vector<std::string> m_expression;
		int m_top;

	public:
		Stack();

		void push(std::string expr);
		std::string pop();
		std::string top();
		bool isEmpty();
		bool isFull();
};

class Bares{

	private:
		std::string m_input;
		Stack m_operator;
		Stack m_operand;

	public:
		Bares(std::string value="");

		void setInput(std::string value);
		int inputSize();
		std::string getInput(){ return m_input; }

		void read();
};

#endif
