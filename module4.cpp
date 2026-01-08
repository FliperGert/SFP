#include <cmath>
#include <vector>
#include "masin.h"

const long double g = 9.8;

long double xInSecond(long double v0, long double alpha, long double t){
    return v0 * std::cos(alpha * 3.1415/180) * t;
}

long double yInSecond(long double v0, long double alpha, long double t){
    return v0 * std::sin(alpha * 3.1415/180) * t - g * t * t / 2;
}

long double vYInSecond(long double v0, long double alpha, long double t){
    return std::sqrt(std::pow(v0 * std::sin(alpha * 3.1415/180) - g * t / 2, 2) + std::pow(v0 * cos(alpha * 3.1415/180), 2));
}

void inputDataMod4(std::vector<long double>& data){
    inputData("Введите начальную скорость тела(в м/с): ", data[0]);

    inputData("Введите угол полета(в градусах): ", data[1]);

    inputData("Введите время симуляции(в с): ", data[2]);

}

void startModel4(std::vector<long double> data, std::vector<std::vector <long double>>& result, long double delta_time){
    std::vector<long double> data_model = {0, 0, 0, 0};
    result.push_back({120, 121, 118, 116});

    while (data_model[3] <= data[2] && data_model[1] >= 0){

        data_model[0] = xInSecond(data[0], data[1], data_model[3]);
        data_model[1] = yInSecond(data[0], data[1], data_model[3]);
        data_model[2] = vYInSecond(data[0], data[1], data_model[3]);

        result.push_back(data_model);

        data_model[3] += delta_time;
    }
}