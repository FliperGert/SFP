#include <fstream>
#include <ios>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <iostream>
#include "rang.hpp"


void inputData(std::string text, long double& data){
    while (true) {
        std::cout << text;
        std::cin >> data;
        if (std::cin.fail()){
            std::cin.clear();
            std::cout << rang::fg::red << "\nНеверный ввод(проверьте правильность ввода)\n" << rang::fg::reset;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }
}

void outputResult(std::vector <std::vector<long double>> result){
    int n = result[0].size();
    for (int i = 0; i < n; i++){
        char sim = static_cast<char>(result[0][i]);
        std::cout << std::setw(16) << std::right << rang::fg::green << sim << rang::fg::reset;
    }
    std::cout << '\n' << '\n';

    for (size_t i = 1; i < result.size(); i++){
        for (int j = 0; j < n; j++){
            std::cout << std::setw(16) << std::right << result[i][j];
        }
        std::cout << '\n';
    }
}

void saveInFile(std::vector<std::vector<long double>> result){
    std::fstream f;
    f.open("output.txt", std::ios::out);
    for(std::vector<long double> i : result){
        for (long double k : i){
            f << k << ' '; 
        }
        f << '\n';
    }
    f.close();
}

bool readFile(std::vector<std::vector<long double>>& result){
    std::fstream f;
    f.open("output.txt", std::ios::in);

    if (!f.is_open()){
        std::cout << rang::fg::red << "Не получилось открыть файл! Проверьте находиться ли он в одной директории с приложением!" << rang::fg::reset;
        return false;
    }


    std::string line;
    int i = 0;
    while(std::getline(f, line)){
        std::stringstream ss(line);
        std::vector<long double> row;
        long double value;

        while(ss >> value){
            row.push_back(value);
        }

        if (!row.empty()){
            result.push_back(row);
        }
    }

    f.close();
    return true;
}