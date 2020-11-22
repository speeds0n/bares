#include <iostream>
#include <stdexcept>
int main(){

	int a{0};
	std::cin >> a;

	if(a == 1){
		throw std::runtime_error("error error error");
		std::cout << "teste" << std::endl;
	}

	return 0;
}
