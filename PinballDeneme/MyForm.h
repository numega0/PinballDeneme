#include <windows.h>

#pragma once

void PuanEkle() {

	DWORD addy = 0x01017526;
	DWORD cHook = 5000;
	__asm {
		pushad
		pushfd
		mov ecx, dword ptr ds : [0x1025040]
		push cHook
		call addy

		popfd
		popad

	}
}


void YeniOyun() {

	DWORD dwYeniOyunAddr = 0x010153AE;
	__asm {
		PUSH 0x0
		MOV EDI, EAX
		call dwYeniOyunAddr

	}


}

void Oyuncu4(DWORD _sayi) {


	DWORD Addr = 0x010056D3;
	__asm {
		mov eax,_sayi
		MOV DWORD PTR DS : [0x1028234], eax
		PUSH ECX
		PUSH 0x198
		CALL Addr
	}


}



namespace WindowsFormsTamplateDLL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(364, 228);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(196, 73);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Puan Ekle";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 11);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(196, 34);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Yeni Oyun";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 51);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(93, 21);
			this->button3->TabIndex = 2;
			this->button3->Text = L"4 Oyuncu";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1 Oyuncu", L"2 Oyuncu", L"3 Oyuncu", L"4 Oyuncu" });
			this->comboBox1->Location = System::Drawing::Point(111, 51);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(97, 21);
			this->comboBox1->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(594, 324);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		PuanEkle();
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		YeniOyun();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {



		Oyuncu4(comboBox1->SelectedIndex + 1);

	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		comboBox1->SelectedIndex = 0;
	}
};
}
