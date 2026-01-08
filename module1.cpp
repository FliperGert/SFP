#include <cmath>
#include <vector>
#include "masin.h"

const double g = 9.8;

long double resistInSecond(long double beta,  long double v){
    return beta * v * v;
}

long double vInSecond(long double v_l, long double t){
    return v_l * std::tanh(g * t / v_l);
}

long double aFInSecond(long double beta, long double v, long double m){
    return g - (beta * v * v / m);
}

void sInSecond(long double& s, long double v, long double t){
    s += v * t;
}

long double xInSecond(long double x0, long double s){
    return x0 - s;
}

void inputDataMod1(std::vector< long double>& data){

    inputData("Введите высоту, с которой телу падает(в м):", data[0]);

    inputData("Введите площадь поперечного сечения тела(в м^2): ", data[1]);
    
    inputData("Введите коэффицент сопротивления: ", data[2]);

    inputData("Введите массу тела(в кг): ", data[3]);

    inputData("Введите время симуляции(в с):", data[4]);
}

void startModel1(std::vector<long double> data, std::vector<std::vector <long double>>& result, long double delta_time){
    std::vector <long double> data_model = {0, 0, 0, 0, data[0], 0};

    long double beta = data[1] * data[2] * 1.293; // Плотность воздуха при температу 0 и нормальном давлении
    long double v_limit = std::sqrt(data[3] * g / beta);

    result.push_back({70, 118, 97, 83, 120, 116});

    while (data_model[5] <= data[4] && data_model[4] > 0){
        data_model[0] = resistInSecond(beta, data_model[1]);

        data_model[1] = vInSecond(v_limit, data_model[5]);

        data_model[2] = aFInSecond(beta, data_model[1], data[3]);

        sInSecond(data_model[3], data_model[1], data_model[5]);

        data_model[4] = xInSecond(data_model[4], data_model[3]);

        result.push_back(data_model);

        data_model[5] += delta_time;
    }
}