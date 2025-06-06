#include <iostream>
#include <string>
long long eighth(int n){
    if(n > 7){
        return (eighth((n-(n%8))/8)*10) + n%8;
    }else{
        return n;
    }
}
int main()
{
    setlocale(LC_ALL, "RUS");
    std::cout<<"Введите ваше имя, пользователь" << std::endl;
    std::string name;
    std::cin >> name;
    std::cout<<"Приятного пользования," << name << std::endl;
    std::cout<< name << ",Выберите программу которой вы бы хотели воспользоваться" << std::endl;
    std::cout<<"1 - перевод числа из десятичной в восьмиричную систему" << std::endl;
    std::cout<<"2 - перевод числа из десятичной в шестнадцатеричную систему" << std::endl;
    int l = 0;
    std::cin >> l;
    while(l != 1 && l != 2){
        std::cout<< name << ",Формат введенных данных не отвечает возможностям системы. Попробуйте еще раз!" << std::endl;
        std::cin >> l;
    }
    std::cout<<"Благодарим," << name << ".Теперь введите число от -2147483648 до 2147483647" << std::endl;
    std::string number = "";
    std::cin >> number;
    bool meaning = false;
    int k = 0;
    while(meaning == false){
        for(int i = 0; i < number.length(); i++){
            if(isdigit(number[i])){
                k++;
            }else if(i == 0 && number[i] == '-'){
                k++;
            }
        }
        if(number.length() == k && number.length() < 13){
            if(stoll(number) <= 2147483647 && stoll(number) >= -2147483648){
                meaning = true;
            }
        }
        if(meaning == false){
            std::cout<< name << ",Формат введенных данных не отвечает возможностям системы. Попробуйте еще раз!" << std::endl;
            std::cin >> number;
            k = 0;
        }
    }
    int n = stoi(number);
    if(l == 1){
        if(n >= 0){
            std::cout << eighth(n);
        }else{
            std::cout<< name << ",К сожалению операции над отрицательными числами в разработке. Можем уверить что эта функция скоро станет доступна!" << std::endl;
        }
    }else if(n >= 0){
        std::string ans = "";
        while(n != 0){
            std::string stri = std::__cxx11::to_string(n%16);
            ans = stri + " " + ans;
            n = (n - (n%16)) / 16;
        }
        std::cout << ans;
    }else{
        std::cout<< name << ",К сожалению операции над отрицательными числами в разработке. Можем уверить что эта функция скоро станет доступна!" << std::endl;
    }
    return 0;
}