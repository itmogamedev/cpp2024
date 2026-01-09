#include <iostream>
#include <vector>
#include <string>

auto func = [](std::vector<std::string>& vec) -> std::vector<int> {
    std::vector<int> len;
    for (int i = 0; i < vec.size(); i++) {
        len.push_back(vec[i].length());
        std::cout << "string: " << vec[i] << " has length " <<  vec[i].length() << "\n";
    }
    return len;
    };

int main() {
    std::vector<std::string> vec{ "1293490890", "jsfaoikjhoias", "KSOFJHOioihsfiuoah928", "sajfoihj38fHf_9f"};
    func(vec);
}
