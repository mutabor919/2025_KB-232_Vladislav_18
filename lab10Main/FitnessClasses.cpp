#include "FitnessClasses.h"
#include <sstream>

using namespace System;

std::wstring BenchPress::GetDescription() const {
    return L"Жим лёжа - базовое упражнение для грудных мышц.\n\n"
        L"Техника выполнения:\n"
        L"1. Лягте на скамью, возьмите штангу хватом шире плеч\n"
        L"2. Опустите штангу к груди, сохраняя контроль\n"
        L"3. Выжмите штангу вверх, не блокируя локти\n\n"
        L"Рекомендации:\n- Разминайтесь с пустым грифом\n"
        L"- Используйте страховку при работе с большими весами\n"
        L"- Следите за техникой, особенно за положением поясницы";
}

std::wstring BenchPress::GetMusclesWorked() const {
    return L"Работающие мышцы: грудные, трицепсы, передние дельты";
}

std::wstring Deadlift::GetDescription() const {
    return L"Становая тяга - упражнение для спины и ног.\n\n"
        L"Техника выполнения:\n"
        L"1. Встаньте перед штангой, ноги на ширине плеч\n"
        L"2. Наклонитесь с прямой спиной, возьмите штангу\n"
        L"3. Поднимите штангу, разгибая ноги и спину\n\n"
        L"Рекомендации:\n- Всегда держите спину прямой\n"
        L"- Начинайте с легких весов для отработки техники\n"
        L"- Используйте пояс при работе с большими весами";
}

std::wstring Deadlift::GetMusclesWorked() const {
    return L"Работающие мышцы: разгибатели спины, ягодичные, бицепсы бедер";
}

std::wstring Squat::GetDescription() const {
    return L"Приседания со штангой - фундаментальное упражнение для развития ног.\n\n"
        L"Техника выполнения:\n"
        L"1. Подойдите к стойке, разместите штангу на трапециевидных мышцах\n"
        L"2. Возьмитесь за гриф широким хватом, снимите штангу со стоек\n"
        L"3. Сделайте шаг назад, ноги на ширине плеч, носки слегка развернуты\n"
        L"4. На вдохе медленно опускайтесь, отводя таз назад\n"
        L"5. В нижней точке бедра параллельны полу (или ниже)\n"
        L"6. На выдохе мощно поднимитесь в исходное положение\n\n"
        L"Рекомендации:\n- Используйте обувь с твердой подошвой\n"
        L"- Начинайте с небольших весов\n"
        L"- Следите за коленями - они не должны заваливаться внутрь";
}

std::wstring Squat::GetMusclesWorked() const {
    return L"Работающие мышцы: квадрицепсы, ягодичные мышцы, бицепсы бедер";
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
        return std::move(exercises[index]);  // Явное перемещение
    }
    static SmartPointer<Exercise> empty;  // Статический объект для возврата по умолчанию
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
        return L"Завтрак: омлет из 2 яиц, овощи\n"
            L"Перекус: 100 г творога\n"
            L"Обед: 150 г куриной грудки, гречка, салат\n"
            L"Перекус: яблоко, 10 орехов\n"
            L"Ужин: 150 г рыбы, тушеные овощи\n\n"
            L"Совет: добавляйте больше овощей для объема";
    }
    else if (calories <= 1500) {
        return L"Завтрак: овсянка с ягодами и орехами\n"
            L"Перекус: творог с бананом\n"
            L"Обед: 200 г говядины, рис, овощи\n"
            L"Перекус: протеиновый коктейль\n"
            L"Ужин: 150 г индейки, салат из овощей\n\n"
            L"Совет: используйте полезные жиры (оливковое масло, авокадо)";
    }
    else if (calories <= 1800) {
        return L"Завтрак: 3 яйца, тост из цельнозернового хлеба\n"
            L"Перекус: греческий йогурт с медом\n"
            L"Обед: 200 г лосося, киноа, брокколи\n"
            L"Перекус: протеиновый батончик\n"
            L"Ужин: 200 г курицы, сладкий картофель\n\n"
            L"Совет: распределяйте белок равномерно в течение дня";
    }
    else if (calories <= 2200) {
        return L"Завтрак: омлет из 3 яиц с сыром, тосты\n"
            L"Перекус: творог с орехами и медом\n"
            L"Обед: 250 г стейка, картофель, овощи\n"
            L"Перекус: сэндвич с индейкой и авокадо\n"
            L"Ужин: 200 г рыбы, рис, овощи\n"
            L"Перед сном: казеиновый протеин\n\n"
            L"Совет: увеличивайте порции постепенно";
    }
    else {
        return L"Завтрак: 4 яйца, овсянка с орехами и фруктами\n"
            L"Перекус: протеиновый коктейль с бананом\n"
            L"Обед: 300 г курицы, макароны из твердых сортов, овощи\n"
            L"Перекус: бутерброды с арахисовой пастой\n"
            L"Ужин: 250 г говядины, гречка, салат\n"
            L"Перед сном: творог с льняным маслом\n\n"
            L"Совет: следите за качеством набираемой массы";
    }
}