#pragma once
#include"MyForm.h"

namespace GameClient {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Con_Form에 대한 요약입니다.
	/// </summary>
	public ref class Con_form : public System::Windows::Forms::Form
	{
	public:
		Con_form(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Con_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  ipTextBox;
	private: System::Windows::Forms::TextBox^  inputTextBox;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  enterButton;
	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Con_form::typeid));
			this->ipTextBox = (gcnew System::Windows::Forms::TextBox());
			this->inputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->enterButton = (gcnew System::Windows::Forms::Button());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// ipTextBox
			// 
			this->ipTextBox->Location = System::Drawing::Point(449, 203);
			this->ipTextBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ipTextBox->Name = L"ipTextBox";
			this->ipTextBox->Size = System::Drawing::Size(149, 21);
			this->ipTextBox->TabIndex = 3;
			this->ipTextBox->Text = L"127.0.0.1";
			// 
			// inputTextBox
			// 
			this->inputTextBox->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->inputTextBox->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->inputTextBox->ForeColor = System::Drawing::SystemColors::WindowText;
			this->inputTextBox->Location = System::Drawing::Point(449, 237);
			this->inputTextBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->inputTextBox->Name = L"inputTextBox";
			this->inputTextBox->Size = System::Drawing::Size(149, 21);
			this->inputTextBox->TabIndex = 6;
			this->inputTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Con_form::inputTextBox_KeyDown);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(41, 38);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(308, 410);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// enterButton
			// 
			this->enterButton->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->enterButton->Location = System::Drawing::Point(487, 288);
			this->enterButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->enterButton->Name = L"enterButton";
			this->enterButton->Size = System::Drawing::Size(91, 25);
			this->enterButton->TabIndex = 0;
			this->enterButton->Text = L"접속";
			this->enterButton->UseVisualStyleBackColor = false;
			this->enterButton->Click += gcnew System::EventHandler(this, &Con_form::enterButton_Click);
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// Con_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(748, 488);
			this->Controls->Add(this->enterButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->inputTextBox);
			this->Controls->Add(this->ipTextBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Con_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Con_form";
			this->Load += gcnew System::EventHandler(this, &Con_form::Con_form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	
	private: System::Void Con_form_Load(System::Object^  sender, System::EventArgs^  e) {
		inputTextBox->Focus();
	}
	private: System::Void enterButton_Click(System::Object^  sender, System::EventArgs^  e) {
		MyForm^ Myf = gcnew MyForm;

		Myf->inputTextBox->Text = inputTextBox->Text;
		Myf->ipTextBox->Text = ipTextBox->Text;
		Myf->Show();
		Myf->enterButton->PerformClick();
		if (Myf->check == 1)
			this->Hide();
		else 
			Myf->Hide();
	}
	private: System::Void inputTextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
		{
			e->SuppressKeyPress = true;
			this->enterButton->PerformClick();
		}
	}
};
}