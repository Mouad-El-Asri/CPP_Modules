#include "whatever.hpp"

int	main()
{
	int a = 2;
	int b = 3;

	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << "\n";
	std::cout << "min(a, b) = " << ::min<int>(a, b) << "\n";
	std::cout << "max(a, b) = " << ::max<int>(a, b) << "\n";

	std::string c = "chaine1";
	std::string d = "chaine2";

	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << "\n";
	std::cout << "min(c, d) = " << ::min<std::string>(c, d) << "\n";
	std::cout << "max(c, d) = " << ::max<std::string>(c, d) << "\n";

	return (0);
}
