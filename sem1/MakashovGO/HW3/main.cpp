#include <iostream>
#include <vector>

auto getLen = [](const std::string& s) {return s.length();};

int main()
{
	std::vector <std::string> str = { "Ma - ya - hi", "ma - ya - hoo", "Ma - ya - hah", "ma - ya - ha - ha" };
	for (const auto& song : str)
	{
		std::cout << getLen(song) << std::endl;
	}
}