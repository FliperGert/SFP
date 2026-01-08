#pragma once
#include <vector>
#include <string>

void inputData(std::string text, long double& data);
void outputResult(std::vector <std::vector<long double>> result);

void saveInFile(std::vector <std::vector<long double>> result);
bool readFile(std::vector <std::vector<long double>>& result);
