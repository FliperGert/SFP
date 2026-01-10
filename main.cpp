#define NOMINMAX  
#include <clocale>
#include <vector>
#include <limits>
#include <iostream>
#include <locale>
#include <windows.h>
#include "rang.hpp"
#include "masin.h"
#include "module.h"


int main(){
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    std::cout << rang::fg::cyan << "Дорогой пользователь, ты запустил программу симуляцию физических моделей\n" << rang::fg::reset;

    bool working = true;
    while (working){

        std::vector<std::vector<long double>> result;

        std::cout << rang::fg::cyan << "\nДоступные симуляции:\n" << rang::fg::reset;
        std::cout << rang::fg::green << "1.Падения тела с сопротивление воздуха\n2.Колебания пружины\n3.Движение с постоянным ускорением\n4.Баллистическое движение\n\n" << rang::fg::reset;

        std::cout << rang::fg::blue <<"Выбирите модель(1-4, другой цифровой ввод - переход к действиям над данными и выходу):" << rang::fg::reset;

        long double choice;
        std::cin >> choice;
        if (std::cin.fail()){
            std::cin.clear();
            std::cout << rang::fg::red << "\nНеверный ввод(проверьте правильность ввода)\n" << rang::fg::reset;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (static_cast<int>(choice)) {
            case 1:
            {
                std::vector<long double> data{0,0,0,0,0};
                inputDataMod1(data);
                long double delta_time;
                inputData("Введите шаг симуляции(в с): ", delta_time);
                startModel1(data, result, delta_time);
                break;
            }
            case 2:
            {
                std::vector<long double> data{0,0,0,0};
                inputDataMod2(data);
                long double delta_time;
                inputData("Введите шаг симуляции(в с): ", delta_time);
                startModel2(data, result, delta_time);
                break;
            }
            case 3:
            {
                std::vector<long double> data{0,0,0,0};
                inputDataMod3(data);
                long double delta_time;
                inputData("Введите шаг симуляции(в с): ", delta_time);
                startModel3(data, result, delta_time);
                break;
            }
            case 4:
            {
                std::vector<long double> data{0,0,0,0};
                inputDataMod4(data);
                long double delta_time;
                inputData("Введите шаг симуляции(в с): ", delta_time);
                startModel4(data, result, delta_time);
                break;
            }
            default:
            {
                break;
            }
        }
        std::cout << rang::fg::cyan << "\nДоступные действия:\n" << rang::fg::reset;
        std::cout << rang::fg::green << "1.Вывод результатов\n2.Запись данных в файл\n3.Чтение данных из файла\n4.Вывод данных и запись в файл\n5.Пропуск действия\nДругой ввод - выход из симуляции\n" << rang::fg::reset;

        std::cout << rang::fg::blue <<"Выбирите действия:" << rang::fg::reset;

        std::cin >> choice;

        switch (static_cast<int>(choice)){
            case 1:
            {
                if (result.empty()){
                    std::cout << rang::fg::red << "Пустой массив данных, создайте сначала массив(проведите симуляцию)\n" << rang::fg::reset;
                }
                else{
                    outputResult(result);
                }
                break;
            }
            case 2:
            {
                if (result.empty()) {
                    std::cout << rang::fg::red << "Пустой массив данных, создайте сначала массив\n" << rang::fg::reset;
                }
                else {
                    saveInFile(result);
                }
                break;
            }
            case 3:
            {
                if(readFile(result)){
                    outputResult(result);
                }
                break;
            }
            case 4:
            {
                if (result.empty()){
                    std::cout << rang::fg::red << "Пустой массив данных, создайте сначала массив\n" << rang::fg::reset;
                }
                else{
                    outputResult(result);
                    saveInFile(result);
                }
                break;
            }
            case 5:
            {
                break;
            }
            default:{
                working = false;
                break;
            }
        }
    }
}