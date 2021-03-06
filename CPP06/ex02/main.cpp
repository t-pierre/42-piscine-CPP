# include <iostream>
# include <cstdlib>
# include <typeinfo>
# include "Base.hpp"

Base * generate(void) {

	std::srand(time(0));
	int rand = std::rand() % 3;
	if (rand == 0)
		return new A;
	if (rand == 1)
		return new B;
	return new C;

}

void identify(Base * p) {

	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify( Base & p) {

	try {
		static_cast<void>(dynamic_cast<A &>(p));
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &e) {
		try {
			static_cast<void>(dynamic_cast<B &>(p));
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast &e) {
			std::cout << "C" << std::endl;
		}
	}
}

int main( void ) {

	Base *random = generate();

	identify(random);
	identify(*random);

	delete random;
	return 0;
}
