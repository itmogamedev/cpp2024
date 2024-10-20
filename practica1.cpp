#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Data
{
    private:
    enum MENU {
        add = 0,
        printData = 1,
        search = 2,
        dataDelete = 3
    };
    public:
    void Add(std::string id, std::string FIO, std::string Sr, std::string Spec)
    {
        std::ofstream out;
        out.open("DataBase.txt", std::ios::app);
        
        out << id << "\n";
        out << FIO << "\n";
        out << Sr << "\n";
        out << Spec << "\n";
        
        out.close();
    }
    void Print()
    {
        std::ifstream in("DataBase.txt");
        if (in.is_open())
        {
            std::string line;
            int i = 0;
            std::cout << "Database in the format >> ID, FIO, Average score, Specialization:" << "\n";
            while (std::getline(in, line))
            {
                switch (i)
                {
                case 0:
                    std::cout << line << "\t";
                    break;
                case 1:
                    std::cout << line << "\t";
                    break;
                case 2:
                    std::cout << line << "\t";
                    break;
                case 3:
                    std::cout << line;
                    break;    
                }
                ++i;
                if (i == 4){ i = 0; std::cout << "\n";}
            }
        }
        in.close();
        std::cout << "\n";
    }
    void Search(std::string name)
    {
         std::ifstream in("DataBase.txt");
         std::string line;
         int i = 0;
         int flag = 0;
         if (in.is_open())
           {
                while (std::getline(in, line)){
                    if (flag == 1 and i <= 4){
                        std::cout << line << "\t";
                    }
                    else if (flag == 1 and i > 4){
                        std::cout << "\n";
                        break;
                    }
                    if (i % 4 == 1 and line == name){
                        flag = 1;
                        std::cout << line << "\t";
                    }
                    if (flag == 1){
                        i++;
                    }
                }
           }
         in.close();
         std::cout << "\n";
    }
    void Delete(std::string id)
        {
             std::ifstream out("DataBase.txt");
             std::string line;
             int i = 0;
             int flag = 0;
             std::vector<std::string> data;
             if (out.is_open())
               {
                    while (std::getline(out, line)){
                        i++;
                        if (i == 5) i = 1;
                        if (flag == 0){
                            data.push_back(line);
                        }
                        if (flag == 1 and i == 4) i = 0;
                        if (i == 1 and line == id){
                            flag = 1;
                            continue;
                        
                    }
                    
                    std::ofstream out;
                    std::remove("DataBase.txt");std::ifstream out("DataBase.txt");
                    out.open("DataBase.txt", std::ios::app);
                    for(std::string el : data){        
                        out << el << "\n";
                    }     
                    out.close();  
                    }  
               }
             std::cout << "\n";
        }
    void Menu()
    {
        int number;
        std::cout << "*** Data base of ITMO students ***" << "\n";
        std::cout<< "\t" << add << " - Add a student " <<"\n";
        std::cout<< "\t" << printData << " - Data output " <<"\n";
        std::cout<< "\t" << search << " - Search " <<"\n";
        std::cout<< "\t" << dataDelete << " - Delete by ID " <<"\n";
        
        std::cin >> number; std::cout << "\n";
        std::string id; std::string FIO; std::string Sr; std::string Spec;
        
        std::string n;
        
        switch (number){
        case add:
            std::cout << "<<< Write correctly >>>\n";
            std::cout << "Input ID: "; std::cin >> id; std::cout << "\n";
            std::cout << "Input FIO (together): "; std::cin >> FIO; std::cout << "\n";
            std::cout << "Input Average score: "; std::cin >> Sr; std::cout << "\n";
            std::cout << "Input Specialization: "; std::cin >> Spec; std::cout << "\n";
            Add(id, FIO, Sr, Spec);
            break;
        case printData:
            Print();
            break;
        case search:
            std::cout << "Input criterion (ID): ";
            std::cin >> n;
            std::cout << "The result search: ";
            Search(n);
            std::cout << "\n";
            break;
        case dataDelete:
            std::cout << "Input ID: "; std::cin >> id; std::cout << "\n";
            Delete(id);
            break;
        default:
            std::cout << "You made a mistake! Try again." << "\n";
        }
    }
};



int main()
{
    Data Base;
    while (true)
    {
        Base.Menu();
    }
    return 0;
}
