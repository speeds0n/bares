/*!
 * \file bares.h
 * \author Edson Cassiano
 * \date November, 2020
 */

#ifndef BARES_H
#define BARES_H

#include <vector>
#include "parser.h"

// A class Stack nao foi usada
/// This class is implementation of stack
/*!
 * Stack implematation
 */
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

/// This class manipulate convert the expressions to prefix and calculates the expressions
/*!
 * This class is responsible to calculates the expressions and also convert from infix to posfix
 * and calculates expression displaying the error messages needed
 */
class Bares{

	private:
		std::vector<Token> m_tk_list; //!< The token list

	public:
		void setTkList(std::vector<Token> expr);//!< set the list of tokens
		std::vector<Token> getTkList(){ return m_tk_list; }//!< get the list of tokens

		/// This function get the current token and check your type
		/*!
		 * Check if the current token is number
		 *
		 * This function use the token_type and check if it is number
		 *
		 * \param type is a token_type that stores the type of current token
		 * \return return logical expression true if token is a number and false otherwise
		 */
		bool isNumber(Token::token_t type);//!< check if current token is number

		/// This function get the current token and check your type
		/*!
		 * Check if the current token is operator
		 *
		 * This function use the token_type and check if it is operator
		 *
		 * \param type is a token_type that stores the type of current token
		 * \return return logical expression true if token is a operator and false otherwise
		 */
		bool isOperator(Token::token_t type);//!< check if current token is operator

		/// This function get the current token and check your type
		/*!
		 * Check if the current token is number
		 *
		 * This function use the token_type and check if it is "("
		 *
		 * \param type is a token_type that stores the type of current token
		 * \return return logical expression true if token is a "(" and false otherwise
		 */
		bool openScope(Token::token_t type);//!< check if "(" it was used

		/// This function get the current token and check your type
		/*!
		 * Check if current token is number
		 *
		 * This function use the token_type and check if it is ")"
		 *
		 * \param type is a token_type that stores the type of current token
		 * \return return logical expression true if token is a ")" and false otherwise
		 */
		bool closeScope(Token::token_t type);//!< check if ")" it was used
	
		/// This function rank the precedence of operations
		/*!
		 * Check the operator of expression and return the precedence
		 *
		 * This function use the token_type and check if it is number
		 *
		 * \param op the operation that will be analyzed
		 * \return return an int that will be used to rank the precedence
		 */
		int getPrecedence(std::string op);//!< check the precedence of operator

		/// This function compare who takes precedence
		/*!
		 * Compare two operator and return the precedence
		 *
		 * This function get two expression and check who has the precedence
		 *
		 * \param op1 the first operator
		 * \param op2 the second operator
		 * \return return true if the first operator is precedent the second
		 * \return return false if the second operator is precedent the first
		 * \return return true if the operators are equal the first operator is precedent the second
		 */
		bool precedence(std::string op1, std::string op2);//!< compare which one is precedence

		/// Use the stack to convert from infix to posfix
		/*!
		 * Convert the expression to posfix
		 *
		 * This function use stack to convert from infix to posfix, first the function add all number
		 * in the list, when the scope is open add in aux stack, also add the operators in the list,
		 * finish making swap with the list of token and posfix list
		 *
		 * \return return the list of tokens in posfix
		 */
		std::vector<Token> convert();//!< convert from infix to posfix

		/// calculates all expressions
		/*!
		 * This function calculates the expressions
		 *
		 * This function calculates a expressions
		 *
		 * \param number1 first members that are calculates
		 * \param number2 second members that are calculates
		 * \param error int value that in the case an error occurs when calculating the expressions
		 * \param c the operator
		 * \return return the result of expression
		 */
		int calculate(int number1, int number2, int *error, std::string c);//!< make the necessary calculations

		/// This function is responsable to calculates all expression
		/*!
		 * This function calculates the list of expressions
		 *
		 * This function get all expressions in the list and calculates, when find the number convert
		 * to int, if find the operator take two next numbers, storing the result in the stack,
		 * in the case it is necessary to recover the values
		 *
		 * \param error int value that in the case an error occurs when calculating the expressions
		 * \return return the result of expression
		 */
		int inspect(int *error);//!< evaluate the expression

};

#endif
