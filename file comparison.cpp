#include <iostream>
#include <Windows.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <thread>

void ExitApp()
{
    std::chrono::milliseconds timespan(3000);
    std::cout << "The executable will exit in 3 seconds." << std::endl;
    std::this_thread::sleep_for(timespan);
    exit(0);
}

int main()
{

    std::string Space;
    Space = "";
    const char* Doc1 = "Doc1.txt";
    const char* Doc2 = "Doc2.txt";
    const char* Doc3 = "Doc3.txt";
    const char* Doc4 = "Doc4.txt";
    const char* Doc5 = "Doc5.txt";
    const char* Doc6 = "Doc6.txt";
    const char* Doc7 = "Doc7.txt";
    const char* Doc8 = "Doc8.txt";
    const char* Doc9 = "Doc9.txt";
    const char* Doc10 = "Doc10.txt";
    const char* DocDiff = "DocDiff.txt";


    double DocumentLength = 0;
    std::cout << "Whats the length of the documents u want to compare?" << std::endl;
    std::cin >> DocumentLength;

    int* Difference;
    Difference = new int[DocumentLength];

    std::ifstream file1(Doc1);
    std::ifstream file2(Doc2);
    std::ifstream file3(Doc3);
    std::ifstream file4(Doc4);
    std::ifstream file5(Doc5);
    std::ifstream file6(Doc6);
    std::ifstream file7(Doc7);
    std::ifstream file8(Doc8);
    std::ifstream file9(Doc9);
    std::ifstream file10(Doc10);
    std::ofstream fileDiff(DocDiff);
    if (file1.is_open() && file2.is_open() && file3.is_open() && file4.is_open() && file5.is_open() && file6.is_open() && file7.is_open() && file8.is_open() && file9.is_open() && file10.is_open() && fileDiff.is_open())
    {
        std::string line1;
        std::string line2;
        std::string line3;
        std::string line4;
        std::string line5;
        std::string line6;
        std::string line7;
        std::string line8;
        std::string line9;
        std::string line10;
        for (int i = 0; std::getline(file1, line1) && std::getline(file2, line2) && std::getline(file3, line3) && std::getline(file4, line4) && std::getline(file5, line5) && std::getline(file6, line6) && std::getline(file7, line7) && std::getline(file8, line8) && std::getline(file9, line9) && std::getline(file10, line10) && i < DocumentLength; i++)
        {
            if (line1.compare(line2) != 0 || line1.compare(line3) != 0 || line1.compare(line4) != 0 || line1.compare(line5) != 0 || line1.compare(line6) != 0 || line1.compare(line7) != 0 || line1.compare(line8) != 0 || line1.compare(line9) != 0 || line1.compare(line10) != 0)
            {
                Difference[i] = 1;
                fileDiff << "" << "\n";
            }
            else
            {
                Difference[i] = 0;
                fileDiff << line1 << "\n";
            }
            
        }
    }
    else
    {
        std::cout << "File did not open" << std::endl;
    }
    file1.close();
    file2.close();
    file3.close();
    file4.close();
    file5.close();
    file6.close();
    file7.close();
    file8.close();
    file9.close();
    file10.close();
    fileDiff.close();
    
    int temp = 0;
    std::vector<int> DifferenceLocation;
    for (int i = 0; i < DocumentLength; i++)
    {
        if (Difference[i] == 1)
        {
            temp += 1;
            DifferenceLocation.push_back(i);
        }
    }

    for (int i = 0; i < temp; i++)
    {
        std::cout << DifferenceLocation[i] << std::endl;
    }
    system("pause");
    ExitApp();
}

