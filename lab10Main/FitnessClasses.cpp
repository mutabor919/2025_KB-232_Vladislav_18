#include "FitnessClasses.h"
#include <sstream>

using namespace System;

std::wstring BenchPress::GetDescription() const {
    return L"��� ��� - ������� ���������� ��� ������� ����.\n\n"
        L"������� ����������:\n"
        L"1. ����� �� ������, �������� ������ ������ ���� ����\n"
        L"2. �������� ������ � �����, �������� ��������\n"
        L"3. ������� ������ �����, �� �������� �����\n\n"
        L"������������:\n- ������������ � ������ ������\n"
        L"- ����������� ��������� ��� ������ � �������� ������\n"
        L"- ������� �� ��������, �������� �� ���������� ��������";
}

std::wstring BenchPress::GetMusclesWorked() const {
    return L"���������� �����: �������, ��������, �������� ������";
}

std::wstring Deadlift::GetDescription() const {
    return L"�������� ���� - ���������� ��� ����� � ���.\n\n"
        L"������� ����������:\n"
        L"1. �������� ����� �������, ���� �� ������ ����\n"
        L"2. ����������� � ������ ������, �������� ������\n"
        L"3. ��������� ������, �������� ���� � �����\n\n"
        L"������������:\n- ������ ������� ����� ������\n"
        L"- ��������� � ������ ����� ��� ��������� �������\n"
        L"- ����������� ���� ��� ������ � �������� ������";
}

std::wstring Deadlift::GetMusclesWorked() const {
    return L"���������� �����: ����������� �����, ���������, ������� �����";
}

std::wstring Squat::GetDescription() const {
    return L"���������� �� ������� - ��������������� ���������� ��� �������� ���.\n\n"
        L"������� ����������:\n"
        L"1. ��������� � ������, ���������� ������ �� �������������� ������\n"
        L"2. ���������� �� ���� ������� ������, ������� ������ �� �����\n"
        L"3. �������� ��� �����, ���� �� ������ ����, ����� ������ ����������\n"
        L"4. �� ����� �������� �����������, ������ ��� �����\n"
        L"5. � ������ ����� ����� ����������� ���� (��� ����)\n"
        L"6. �� ������ ����� ����������� � �������� ���������\n\n"
        L"������������:\n- ����������� ����� � ������� ��������\n"
        L"- ��������� � ��������� �����\n"
        L"- ������� �� �������� - ��� �� ������ ������������ ������";
}

std::wstring Squat::GetMusclesWorked() const {
    return L"���������� �����: �����������, ��������� �����, ������� �����";
}

System::String^ Exercise::GetCombinedInfo() const {
    std::wstring combined = GetDescription() + L"\n\n" + GetMusclesWorked();
    return gcnew System::String(combined.c_str());
}

ExerciseManager::ExerciseManager() {
    exercises.emplace_back(new BenchPress());
    exercises.emplace_back(new Deadlift());
    exercises.emplace_back(new Squat());
}

SmartPointer<Exercise>&& ExerciseManager::GetExercise(size_t index) {
    if (index < exercises.size()) {
        return std::move(exercises[index]);  // ����� �����������
    }
    static SmartPointer<Exercise> empty;  // ����������� ������ ��� �������� �� ���������
    return std::move(empty);
}

size_t ExerciseManager::GetExerciseCount() const {
    return exercises.size();
}

NutritionCalculator::NutritionInfo NutritionCalculator::Calculate(int calories) {
    NutritionInfo info;
    info.proteins = (calories * 0.3) / 4;
    info.fats = (calories * 0.3) / 9;
    info.carbs = (calories * 0.4) / 4;
    return info;
}

std::wstring NutritionCalculator::GenerateDietPlan(int calories) {
    if (calories <= 1200) {
        return L"�������: ����� �� 2 ���, �����\n"
            L"�������: 100 � �������\n"
            L"����: 150 � ������� ������, ������, �����\n"
            L"�������: ������, 10 ������\n"
            L"����: 150 � ����, ������� �����\n\n"
            L"�����: ���������� ������ ������ ��� ������";
    }
    else if (calories <= 1500) {
        return L"�������: ������� � ������� � �������\n"
            L"�������: ������ � �������\n"
            L"����: 200 � ��������, ���, �����\n"
            L"�������: ����������� ��������\n"
            L"����: 150 � �������, ����� �� ������\n\n"
            L"�����: ����������� �������� ���� (��������� �����, �������)";
    }
    else if (calories <= 1800) {
        return L"�������: 3 ����, ���� �� ��������������� �����\n"
            L"�������: ��������� ������ � �����\n"
            L"����: 200 � ������, �����, ��������\n"
            L"�������: ����������� ��������\n"
            L"����: 200 � ������, ������� ���������\n\n"
            L"�����: ������������� ����� ���������� � ������� ���";
    }
    else if (calories <= 2200) {
        return L"�������: ����� �� 3 ��� � �����, �����\n"
            L"�������: ������ � ������� � �����\n"
            L"����: 250 � ������, ���������, �����\n"
            L"�������: ������� � �������� � �������\n"
            L"����: 200 � ����, ���, �����\n"
            L"����� ����: ���������� �������\n\n"
            L"�����: ������������ ������ ����������";
    }
    else {
        return L"�������: 4 ����, ������� � ������� � ��������\n"
            L"�������: ����������� �������� � �������\n"
            L"����: 300 � ������, �������� �� ������� ������, �����\n"
            L"�������: ���������� � ���������� ������\n"
            L"����: 250 � ��������, ������, �����\n"
            L"����� ����: ������ � ������� ������\n\n"
            L"�����: ������� �� ��������� ���������� �����";
    }
}