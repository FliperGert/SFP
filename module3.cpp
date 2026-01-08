#include <vector>
#include "masin.h"

long double speedInSecond(long double v0, long double a, long double t){
    return v0 + a * t / 2;
}

long double motionInSecond(long double v0, long double a, long double t){
    return v0 * t + a * t * t / 2;
}

long double xInSecond(long double x0, long double v0, long double a, long double t){
    return x0 + v0 * t + a * t * t / 2;
}

void inputDataMod3(std::vector<long double>& data){
    inputData("Введите начальную координату тела(x0)(в м):", data[0]);

    inputData("Введите начальную скорость тела(v0)(в м/с):", data[1]);

    inputData("Введите ускорение тела(a)(в м/с^2):", data[2]);

    inputData("Введите время симуляции(в c):", data[3]);
}

void startModel3(std::vector<long double> data, std::vector<std::vector <long double>>& result, long double delta_time){
    std::vector<long double> data_model = {0, 0, 0,0};
    result.push_back({120, 118, 83, 116});

    while (data_model[3] <= data[3]){
        data_model[0] = xInSecond(data[0], data[1], data[2], data_model[3]);
        data_model[1] = speedInSecond(data[1], data[2], data_model[3]);
        data_model[2] = motionInSecond(data[1], data[2], data_model[3]);

        result.push_back(data_model);

        data_model[3] += delta_time;
    }

}

