#pragma once
#include "FitnessClasses.h"

namespace lab10Main {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            InitializeComboBox();
            exerciseManager = new ExerciseManager(); 
            radioButton1->Checked = true;
        }

    protected:
        ~MyForm()
        {
            delete exerciseManager; 
            if (components)
            {
                delete components;
            }
        }

    private:
        ExerciseManager* exerciseManager;
        System::Windows::Forms::TabPage^ tabPage1;
        System::Windows::Forms::Button^ buttonCalculate;
        System::Windows::Forms::RichTextBox^ richTextBox3;
        System::Windows::Forms::RichTextBox^ richTextBox2;
        System::Windows::Forms::RichTextBox^ richTextBox1;
        System::Windows::Forms::RadioButton^ radioButton3;
        System::Windows::Forms::RadioButton^ radioButton2;
        System::Windows::Forms::RadioButton^ radioButton1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::ComboBox^ comboBox1;
        System::Windows::Forms::Label^ label5;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::TabControl^ tabControl1;
        System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
        System::ComponentModel::IContainer^ components;

        void InitializeComboBox()
        {
            comboBox1->Items->Add("1200 ккал (похудение)");
            comboBox1->Items->Add("1500 ккал (поддержание)");
            comboBox1->Items->Add("1800 ккал (легкий набор)");
            comboBox1->Items->Add("2200 ккал (набор массы)");
            comboBox1->Items->Add("2500 ккал (интенсивный набор)");
            comboBox1->SelectedIndex = 1;
        }

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
            this->buttonCalculate = (gcnew System::Windows::Forms::Button());
            this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
            this->tabPage1->SuspendLayout();
            this->tabControl1->SuspendLayout();
            this->SuspendLayout();
            // 
            // tabPage1
            // 
            this->tabPage1->Controls->Add(this->buttonCalculate);
            this->tabPage1->Controls->Add(this->richTextBox3);
            this->tabPage1->Controls->Add(this->richTextBox2);
            this->tabPage1->Controls->Add(this->richTextBox1);
            this->tabPage1->Controls->Add(this->radioButton3);
            this->tabPage1->Controls->Add(this->radioButton2);
            this->tabPage1->Controls->Add(this->radioButton1);
            this->tabPage1->Controls->Add(this->label2);
            this->tabPage1->Controls->Add(this->comboBox1);
            this->tabPage1->Controls->Add(this->label5);
            this->tabPage1->Controls->Add(this->label4);
            this->tabPage1->Controls->Add(this->label3);
            this->tabPage1->Controls->Add(this->label1);
            this->tabPage1->Location = System::Drawing::Point(4, 22);
            this->tabPage1->Name = L"tabPage1";
            this->tabPage1->Padding = System::Windows::Forms::Padding(3);
            this->tabPage1->Size = System::Drawing::Size(891, 347);
            this->tabPage1->TabIndex = 0;
            this->tabPage1->Text = L"Тренировка";
            this->tabPage1->UseVisualStyleBackColor = true;
            // 
            // buttonCalculate
            // 
            this->buttonCalculate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->buttonCalculate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->buttonCalculate->ForeColor = System::Drawing::Color::White;
            this->buttonCalculate->Location = System::Drawing::Point(609, 179);
            this->buttonCalculate->Name = L"buttonCalculate";
            this->buttonCalculate->Size = System::Drawing::Size(251, 28);
            this->buttonCalculate->TabIndex = 25;
            this->buttonCalculate->Text = L"Рассчитать питание";
            this->buttonCalculate->UseVisualStyleBackColor = false;
            this->buttonCalculate->Click += gcnew System::EventHandler(this, &MyForm::buttonCalculate_Click);
            // 
            // richTextBox3
            // 
            this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->richTextBox3->Location = System::Drawing::Point(276, 236);
            this->richTextBox3->Name = L"richTextBox3";
            this->richTextBox3->Size = System::Drawing::Size(584, 105);
            this->richTextBox3->TabIndex = 24;
            this->richTextBox3->Text = L"";
            // 
            // richTextBox2
            // 
            this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->richTextBox2->Location = System::Drawing::Point(23, 236);
            this->richTextBox2->Name = L"richTextBox2";
            this->richTextBox2->Size = System::Drawing::Size(247, 105);
            this->richTextBox2->TabIndex = 23;
            this->richTextBox2->Text = L"";
            // 
            // richTextBox1
            // 
            this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->richTextBox1->Location = System::Drawing::Point(291, 36);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(584, 130);
            this->richTextBox1->TabIndex = 22;
            this->richTextBox1->Text = L"";
            // 
            // radioButton3
            // 
            this->radioButton3->AutoSize = true;
            this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->radioButton3->Location = System::Drawing::Point(23, 83);
            this->radioButton3->Name = L"radioButton3";
            this->radioButton3->Size = System::Drawing::Size(168, 20);
            this->radioButton3->TabIndex = 21;
            this->radioButton3->TabStop = true;
            this->radioButton3->Text = L"Приседания со штангой";
            this->radioButton3->UseVisualStyleBackColor = true;
            this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
            // 
            // radioButton2
            // 
            this->radioButton2->AutoSize = true;
            this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->radioButton2->Location = System::Drawing::Point(23, 60);
            this->radioButton2->Name = L"radioButton2";
            this->radioButton2->Size = System::Drawing::Size(113, 20);
            this->radioButton2->TabIndex = 20;
            this->radioButton2->TabStop = true;
            this->radioButton2->Text = L"Становая тяга";
            this->radioButton2->UseVisualStyleBackColor = true;
            this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
            // 
            // radioButton1
            // 
            this->radioButton1->AutoSize = true;
            this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->radioButton1->Location = System::Drawing::Point(23, 37);
            this->radioButton1->Name = L"radioButton1";
            this->radioButton1->Size = System::Drawing::Size(85, 20);
            this->radioButton1->TabIndex = 19;
            this->radioButton1->TabStop = true;
            this->radioButton1->Text = L"Жим лёжа";
            this->radioButton1->UseVisualStyleBackColor = true;
            this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label2->Location = System::Drawing::Point(20, 167);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(204, 16);
            this->label2->TabIndex = 17;
            this->label2->Text = L"Выберите свой дневной калораж:";
            // 
            // comboBox1
            // 
            this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Location = System::Drawing::Point(23, 183);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(580, 24);
            this->comboBox1->TabIndex = 16;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label5->Location = System::Drawing::Point(273, 220);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(185, 16);
            this->label5->TabIndex = 11;
            this->label5->Text = L"Примерный рацион на день:";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label4->Location = System::Drawing::Point(288, 12);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(154, 16);
            this->label4->TabIndex = 9;
            this->label4->Text = L"Описание упражнения:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label3->Location = System::Drawing::Point(20, 220);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(86, 16);
            this->label3->TabIndex = 7;
            this->label3->Text = L"Расчёт БЖУ:";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->Location = System::Drawing::Point(20, 12);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(154, 16);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Выберите упражнение:";
            // 
            // tabControl1
            // 
            this->tabControl1->Controls->Add(this->tabPage1);
            this->tabControl1->Location = System::Drawing::Point(12, 12);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(899, 373);
            this->tabControl1->TabIndex = 0;
            // 
            // contextMenuStrip1
            // 
            this->contextMenuStrip1->Name = L"contextMenuStrip1";
            this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::White;
            this->ClientSize = System::Drawing::Size(923, 397);
            this->Controls->Add(this->tabControl1);
            this->Name = L"MyForm";
            this->Text = L"Фитнес-инструктор";
            this->tabPage1->ResumeLayout(false);
            this->tabPage1->PerformLayout();
            this->tabControl1->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion

    private:
        System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
            if (radioButton1->Checked && exerciseManager) {
                auto exercise = exerciseManager->GetExercise(0);
                if (exercise) {
                    richTextBox1->Text = exercise->GetCombinedInfo();
                }
            }
        }

        System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
            if (radioButton2->Checked && exerciseManager) {
                auto exercise = exerciseManager->GetExercise(1);
                if (exercise) {
                    richTextBox1->Text = exercise->GetCombinedInfo();
                }
            }
        }

        System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
            if (radioButton3->Checked && exerciseManager) {
                auto exercise = exerciseManager->GetExercise(2);
                if (exercise) {
                    richTextBox1->Text = exercise->GetCombinedInfo();
                }
            }
        }

        System::Void buttonCalculate_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ selectedItem = comboBox1->SelectedItem->ToString();
            int calories = 0;

            if (selectedItem->Contains("1200")) calories = 1200;
            else if (selectedItem->Contains("1500")) calories = 1500;
            else if (selectedItem->Contains("1800")) calories = 1800;
            else if (selectedItem->Contains("2200")) calories = 2200;
            else if (selectedItem->Contains("2500")) calories = 2500;

            auto nutrition = NutritionCalculator::Calculate(calories);
            richTextBox2->Text = String::Format(
                "Белки: {0:F1} г\nЖиры: {1:F1} г\nУглеводы: {2:F1} г\n\n" +
                "Рекомендации:\n- Пейте 2-3 литра воды в день\n" +
                "- Ешьте каждые 3-4 часа\n" +
                "- Сочетайте животные и растительные белки",
                nutrition.proteins, nutrition.fats, nutrition.carbs);

            richTextBox3->Text = gcnew System::String(NutritionCalculator::GenerateDietPlan(calories).c_str());
        }
    };
}