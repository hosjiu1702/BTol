#pragma once

namespace Tool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace MaterialSkin;
	using namespace MaterialSkin::Controls;

	/// <summary>
	/// Summary for OfficalForm
	/// </summary>
	public ref class OfficalForm : public MaterialForm
	{
	public:
		OfficalForm(void)
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
		~OfficalForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^  pictureBox1;
	private: MaterialSkin::Controls::MaterialLabel^  materialLabel1;
	private: MaterialSkin::Controls::MaterialLabel^  materialLabel2;
	private: MaterialSkin::Controls::MaterialLabel^  materialLabel3;

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
			MaterialSkin::Controls::MaterialLabel^  materialLabel4;
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->materialLabel1 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->materialLabel2 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->materialLabel3 = (gcnew MaterialSkin::Controls::MaterialLabel());
			materialLabel4 = (gcnew MaterialSkin::Controls::MaterialLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(28, 103);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(375, 373);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &OfficalForm::pictureBox1_Click);
			// 
			// materialLabel1
			// 
			this->materialLabel1->AutoSize = true;
			this->materialLabel1->Depth = 0;
			this->materialLabel1->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel1->Location = System::Drawing::Point(463, 131);
			this->materialLabel1->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel1->Name = L"materialLabel1";
			this->materialLabel1->Size = System::Drawing::Size(74, 19);
			this->materialLabel1->TabIndex = 1;
			this->materialLabel1->Text = L"Container";
			this->materialLabel1->Click += gcnew System::EventHandler(this, &OfficalForm::materialLabel1_Click);
			// 
			// materialLabel2
			// 
			this->materialLabel2->AutoSize = true;
			this->materialLabel2->Depth = 0;
			this->materialLabel2->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel2->Location = System::Drawing::Point(463, 194);
			this->materialLabel2->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel2->Name = L"materialLabel2";
			this->materialLabel2->Size = System::Drawing::Size(52, 19);
			this->materialLabel2->TabIndex = 2;
			this->materialLabel2->Text = L"Coach";
			this->materialLabel2->Click += gcnew System::EventHandler(this, &OfficalForm::materialLabel2_Click);
			// 
			// materialLabel3
			// 
			this->materialLabel3->AutoSize = true;
			this->materialLabel3->Depth = 0;
			this->materialLabel3->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel3->Location = System::Drawing::Point(463, 256);
			this->materialLabel3->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel3->Name = L"materialLabel3";
			this->materialLabel3->Size = System::Drawing::Size(47, 19);
			this->materialLabel3->TabIndex = 3;
			this->materialLabel3->Text = L"Truck";
			// 
			// materialLabel4
			// 
			materialLabel4->AutoSize = true;
			materialLabel4->Depth = 0;
			materialLabel4->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			materialLabel4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			materialLabel4->Location = System::Drawing::Point(463, 320);
			materialLabel4->MouseState = MaterialSkin::MouseState::HOVER;
			materialLabel4->Name = L"materialLabel4";
			materialLabel4->Size = System::Drawing::Size(32, 19);
			materialLabel4->TabIndex = 4;
			materialLabel4->Text = L"Car";
			materialLabel4->Click += gcnew System::EventHandler(this, &OfficalForm::materialLabel4_Click);
			// 
			// OfficalForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(646, 556);
			this->Controls->Add(materialLabel4);
			this->Controls->Add(this->materialLabel3);
			this->Controls->Add(this->materialLabel2);
			this->Controls->Add(this->materialLabel1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"OfficalForm";
			this->Text = L"Label";
			this->Load += gcnew System::EventHandler(this, &OfficalForm::OfficalForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void materialLabel1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void materialLabel2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void materialLabel4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void OfficalForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
