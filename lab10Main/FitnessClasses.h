#pragma once
#include "SmartPointer.h"
#include <vector>
#include <string>

class Exercise {
public:
    virtual ~Exercise() = default;
    virtual std::wstring GetDescription() const = 0;
    virtual std::wstring GetMusclesWorked() const = 0;
    virtual System::String^ GetCombinedInfo() const;
};

class BenchPress : public Exercise {
public:
    std::wstring GetDescription() const override;
    std::wstring GetMusclesWorked() const override;
};

class Deadlift : public Exercise {
public:
    std::wstring GetDescription() const override;
    std::wstring GetMusclesWorked() const override;
};

class Squat : public Exercise {
public:
    std::wstring GetDescription() const override;
    std::wstring GetMusclesWorked() const override;
};

class ExerciseManager {
private:
    std::vector<SmartPointer<Exercise>> exercises;
public:
    ExerciseManager();
    SmartPointer<Exercise>&& GetExercise(size_t index);  // возврат по rvalue-ссылке
    size_t GetExerciseCount() const;
};

class NutritionCalculator {
public:
    struct NutritionInfo {
        double proteins;
        double fats;
        double carbs;
    };

    static NutritionInfo Calculate(int calories);
    static std::wstring GenerateDietPlan(int calories);
};