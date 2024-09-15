#include <iostream>

class CBase{
private:
  int privateBase;
protected:
  int protBase;
public:
  int pubBase;
};

class CDerived : public CBase{ // пробуем protected и private тут
  public:
    void updateDerived() {
      privateBase=0; 
      protBase=0;
      pubBase=0;
    }
};


int main() {
    CDerived cDerived;
    cDerived.updateDerived();
    std::cout<<"privateBase " << cDerived.privateBase << '\n';
    std::cout<<"protBase " << cDerived.protBase << '\n';
    std::cout<<"pubBase " << cDerived.pubBase << '\n';

    return 0;
}
class Base {
public:
      Base() {cout << "\nBase created\n";}
      ~Base() {cout << "Base destroyed\n\n,"; }
};
class D_class1(): public Base {
public:
    D_class1() {cout << "D_class1 created\n";}
    ~D_class1() {cout << "D_class1 destroyed\n "; }
};
int main(){
    D_class1 d1;
    return 0;
}
#include <iostream>

class Base {
public:
    void b() {std::cout << "b\n";}
    void b(int n) {std::cout << "b int \n";}
    void b(std::string n) {std::cout << "b string \n";}
};

int main(){
    Base myB;
    myB.b();
    myB.b(123213);
    myB.b("sdufhudhsfuhdsui;fh");

    return 0;
}