#include <iostream>
#include <vector>
#include <string>


int main()
{
	std::vector<std::string> vecOfStrigns{};

	std::cout << "Input the strings! For exit press Ctrl + Z and later Enter.\n";
	std::string line;
	while (std::getline(std::cin, line))
		vecOfStrigns.push_back(line);

	std::vector<size_t> lengthsOfStrings = [&vecOfStrigns]() {
		std::vector<size_t> lengthsOfStrings;

		for (const auto& string : vecOfStrigns)
			lengthsOfStrings.push_back(string.size());

		return lengthsOfStrings;
	}();
}