#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <utility> 
#include <stdexcept> 
#include <sstream> 
#include <stdlib.h>


typedef std::vector<std::pair<std::string, std::vector<std::string>>> vecInfo;
vecInfo read_csv(std::string filename) { // функция, для прочтения csv - файла
    vecInfo result;
  
    std::ifstream myFile(filename);

    if (!myFile.is_open()) throw std::runtime_error("Could not open file");

    
    std::string line = "";
    std::string colname = "";
    std::string val = "";

    if (myFile.good())
    {
        std::getline(myFile, line);

        std::stringstream ss(line);

        while (std::getline(ss, colname, ',')) {

            
            result.push_back({ colname, std::vector<std::string> {} });
        }
    }
   
   
    while (std::getline(myFile, line))
    {
        
        std::stringstream ss(line);

     
        int colIdx = 0;

        while (std::getline(ss, val, ',')) {

            
            result.at(colIdx).second.push_back(val);
           
            colIdx++;
        }
    }

    myFile.close();

    return result;
}

int main() {
    std::vector<std::string> dopInfo(5);
    vecInfo myvec = read_csv("option1.csv");
    std::vector<std::vector<std::string>> bestHexagonbyPopulation; // вектор, хранящий самые лучшие гексагоны
    double bestAveragePopulation; // переменная, отвечающая за среднюю плотность населения
                                  // на гексагон
    double summa = 0;
    for (auto it = myvec[2].second.begin(); it != myvec[2].second.end(); it++) {
        summa += atof((*it).c_str());
    }
    bestAveragePopulation = 1.15 * (summa / 34856);
    for (auto it = myvec[2].second.begin(); it != myvec[2].second.end(); it++) {
        summa += atof((*it).c_str());
    }
    for (auto it = myvec[2].second.begin(); it != myvec[2].second.end(); it++) {
        if (atof((*it).c_str()) > bestAveragePopulation) {
            dopInfo[0] = myvec[0].second[std::distance(myvec[2].second.begin(), it)];
            dopInfo[1] = myvec[1].second[std::distance(myvec[2].second.begin(), it)];
            dopInfo[2] = myvec[2].second[std::distance(myvec[2].second.begin(), it)];
            dopInfo[3] = myvec[3].second[std::distance(myvec[2].second.begin(), it)];
            dopInfo[4] = myvec[4].second[std::distance(myvec[2].second.begin(), it)];
            bestHexagonbyPopulation.push_back(dopInfo);
        }
        
    }
    std::cout << "1" <<std::endl;
    return 0;
}


