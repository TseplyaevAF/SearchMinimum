#pragma once
#include <vector>

using section = std::vector<float>;

// �������
float f(float x);
// ����� ������
void Sven(float& a, float& b, float x0, float d);

// ����� ������� �������
float Halving(float a, float b);

// ����� �������� �������
float Golden(float a, float b);

// ��������� �����
float Passive(float a, float b);