#pragma once

namespace BTol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MaterialSkin;
	using namespace MaterialSkin::Controls;

	/// <summary>
	/// Summary for TestingForm
	/// </summary>
	public ref class TestingForm : public MaterialForm
	{
	public:
		TestingForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TestingForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: MaterialSkin::Controls::MaterialFlatButton^  materialFlatButton1;
	private: System::Windows::Forms::Label^  label1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->materialFlatButton1 = (gcnew MaterialSkin::Controls::MaterialFlatButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// materialFlatButton1
			// 
			this->materialFlatButton1->AutoSize = true;
			this->materialFlatButton1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->materialFlatButton1->Depth = 0;
			this->materialFlatButton1->Icon = nullptr;
			this->materialFlatButton1->Location = System::Drawing::Point(114, 235);
			this->materialFlatButton1->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
			this->materialFlatButton1->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialFlatButton1->Name = L"materialFlatButton1";
			this->materialFlatButton1->Primary = false;
			this->materialFlatButton1->Size = System::Drawing::Size(65, 36);
			this->materialFlatButton1->TabIndex = 1;
			this->materialFlatButton1->Text = L"check";
			this->materialFlatButton1->UseVisualStyleBackColor = true;
			this->materialFlatButton1->Click += gcnew System::EventHandler(this, &TestingForm::materialFlatButton1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(108, 156);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TEST";
			this->label1->Visible = false;
			this->label1->Click += gcnew System::EventHandler(this, &TestingForm::label1_Click);
			// 
			// TestingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 300);
			this->Controls->Add(this->materialFlatButton1);
			this->Controls->Add(this->label1);
			this->Name = L"TestingForm";
			this->Text = L"Testing";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void materialFlatButton1_Click(System::Object^  sender, System::EventArgs^  e) {
		label1->Visible = true;
	}
	};
}
