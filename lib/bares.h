#ifndef BARES_H
#define BARES_H

#include <vector>

class Bares{

	private:
		std::string m_input;
		std::vector<std::string> list;
	public:
		Bares(std::string value="");

		void setInput(std::string value);
		std::string getInput(){ return m_input; }

		void read(std::string expression);
};

#endif
