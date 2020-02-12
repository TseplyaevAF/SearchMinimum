#pragma once
#include <vector>

using section = std::vector<float>;

// Функция
float f(float x);
// Метод Свенна
void Sven(float& a, float& b, float x0, float d);

// Метод деления пополам
float Halving(float a, float b);

// Метод золотого сечения
float Golden(float a, float b);

// Пассивный поиск
float Passive(float a, float b);