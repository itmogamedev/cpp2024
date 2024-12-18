#include <iostream>


class ReadOnly {
private:
  std::string readonlyString = "важный текст";
public:
    std::string getString() {return readonlyString;}
};

int main() {
    ReadOnly readOnly;
    readOnly.getString() = "не очень важный бла бла";
    std::cout<<"readOnly " << readOnly.getString() << '\n';

    return 0;
}