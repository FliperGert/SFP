#include <vector>
#include <cmath>
#include "masin.h"

long double xSInSecond(long double w, long double x0, long double t){
    return x0 * cos(w * t);
}

long double vInSecond(long double w, long double x0, long double t){
    return -x0 * w * sin(w *t);
}

long double aInSecond(long double w, long double x0, long double t){
    return -x0 * w * w * cos(w * t);
}

void inputDataMod2(std::vector<long double>& data){

    inputData("Введите массу тела(в кг): ", data[0]);

    inputData("Введите коэффицент жесткости пружины: ", data[1]);

    inputData("Введите отклонение от начального положения системы(в м): ", data[2]);

    inputData("Введите время симуляции(в с): ", data[3]);

}

void startModel2(std::vector<long double> data, std::vector<std::vector<long double>>& result, long double delta_time){

    std::vector<long double> data_model = {0, 0 ,0, 0};
    result.push_back({120, 118, 97, 116});

    long double w = std::sqrt(data[1] / data[0]);

    while (data_model[3] <= data[3]){
        data_model[0] = xSInSecond(w, data[2], data_model[3]);
        data_model[1] = vInSecond(w, data[2], data_model[3]);
        data_model[2] = aInSecond(w, data[2], data_model[3]);

        result.push_back(data_model);

        data_model[3] += delta_time;
    }

}