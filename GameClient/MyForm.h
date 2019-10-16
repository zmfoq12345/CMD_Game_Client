#pragma once
#include<stdlib.h>
#include<time.h>
#include<iostream>

namespace GameClient {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Runtime::Serialization;
	using namespace System::Runtime::Serialization::Formatters::Binary;
	using namespace System::Runtime::Serialization::Formatters;
	using namespace System::Threading;
	using namespace FormatterText;
	using namespace System::IO;
	
	/// <summary>
	/// MyForm�� ���� ����Դϴ�.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
			CheckForIllegalCrossThreadCalls = false;
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public: System::Windows::Forms::Button^  enterButton;
	private: System::Windows::Forms::RichTextBox^  mainTextBox;
	public: System::Windows::Forms::TextBox^  ipTextBox;
	public: System::Windows::Forms::RichTextBox^  inputTextBox;
	private: System::Windows::Forms::Button^  sendButton;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::RichTextBox^  TTT_GameBox;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;


	private: System::Windows::Forms::PictureBox^  pictureBox2;

	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->enterButton = (gcnew System::Windows::Forms::Button());
			this->mainTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->ipTextBox = (gcnew System::Windows::Forms::TextBox());
			this->inputTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->TTT_GameBox = (gcnew System::Windows::Forms::RichTextBox());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// enterButton
			// 
			this->enterButton->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->enterButton->Location = System::Drawing::Point(383, 14);
			this->enterButton->Name = L"enterButton";
			this->enterButton->Size = System::Drawing::Size(75, 23);
			this->enterButton->TabIndex = 0;
			this->enterButton->Text = L"����";
			this->enterButton->UseVisualStyleBackColor = false;
			this->enterButton->Click += gcnew System::EventHandler(this, &MyForm::enterButton_Click);
			// 
			// mainTextBox
			// 
			this->mainTextBox->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->mainTextBox->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->mainTextBox->ForeColor = System::Drawing::Color::Black;
			this->mainTextBox->Location = System::Drawing::Point(12, 362);
			this->mainTextBox->Name = L"mainTextBox";
			this->mainTextBox->ReadOnly = true;
			this->mainTextBox->Size = System::Drawing::Size(724, 86);
			this->mainTextBox->TabIndex = 2;
			this->mainTextBox->Text = L"";
			// 
			// ipTextBox
			// 
			this->ipTextBox->Location = System::Drawing::Point(287, 14);
			this->ipTextBox->Name = L"ipTextBox";
			this->ipTextBox->Size = System::Drawing::Size(65, 21);
			this->ipTextBox->TabIndex = 3;
			// 
			// inputTextBox
			// 
			this->inputTextBox->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->inputTextBox->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->inputTextBox->ForeColor = System::Drawing::SystemColors::WindowText;
			this->inputTextBox->Location = System::Drawing::Point(12, 453);
			this->inputTextBox->Name = L"inputTextBox";
			this->inputTextBox->Size = System::Drawing::Size(629, 26);
			this->inputTextBox->TabIndex = 6;
			this->inputTextBox->Text = L"";
			this->inputTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::inputTextBox_KeyDown);
			// 
			// sendButton
			// 
			this->sendButton->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->sendButton->Cursor = System::Windows::Forms::Cursors::Default;
			this->sendButton->Location = System::Drawing::Point(647, 453);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(89, 26);
			this->sendButton->TabIndex = 7;
			this->sendButton->Text = L"����";
			this->sendButton->UseVisualStyleBackColor = false;
			this->sendButton->Click += gcnew System::EventHandler(this, &MyForm::sendButton_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox1->Location = System::Drawing::Point(1, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(747, 502);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// TTT_GameBox
			// 
			this->TTT_GameBox->BackColor = System::Drawing::SystemColors::Window;
			this->TTT_GameBox->Font = (gcnew System::Drawing::Font(L"����ü", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->TTT_GameBox->ForeColor = System::Drawing::Color::Black;
			this->TTT_GameBox->Location = System::Drawing::Point(253, 0);
			this->TTT_GameBox->Name = L"TTT_GameBox";
			this->TTT_GameBox->ReadOnly = true;
			this->TTT_GameBox->Size = System::Drawing::Size(244, 362);
			this->TTT_GameBox->TabIndex = 9;
			this->TTT_GameBox->Text = L"     |     |     \n  1  |  2  |  3  \n_____|_____|_____\n     |     |     \n  4  |  5"
				L"  |  6  \n_____|_____|_____\n     |     |     \n  7  |  8  |  9   \n_____|_____|____"
				L"_\n";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(1, -1);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(747, 489);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 12;
			this->pictureBox2->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(748, 488);
			this->Controls->Add(this->sendButton);
			this->Controls->Add(this->inputTextBox);
			this->Controls->Add(this->mainTextBox);
			this->Controls->Add(this->TTT_GameBox);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->ipTextBox);
			this->Controls->Add(this->enterButton);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Game_Client";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// ����� ���� ���� ����
	 public: Socket^ client;
	 public: IPEndPoint^ IP;
	 public: Thread^ clientThread;

	 public: int MyTTTData, player = 0, order = 0;
	 public: int check = 0;
	 public: String^ User_Name = "";
	 public: String^ square = "o";
	 public: String^ ex = "o123456789";
	 public: String^ Test = "o123456789";
	 public: String^ Turn;
	 public: String^ mark;

	 private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		 square = ex;
		 TTTGame_Print();
		 
		 // ������ �ʱ�ȭ
		 client = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::IP);

		 mainTextBox->SelectionFont = gcnew System::Drawing::Font("���� ���", 9, FontStyle::Bold);
		 mainTextBox->SelectionColor = Color::Red;
		 mainTextBox->AppendText("�г��� �Է� �� ���ӹ�ư�� �����ּ���\n");
	 }

			  // �������� ���� ��ư �̺�Ʈ
	 private: System::Void enterButton_Click(System::Object^  sender, System::EventArgs^  e) {
		 User_Name = inputTextBox->Text;
		 mainTextBox->Clear();
		 inputTextBox->Clear();

		 {
			 mainTextBox->SelectionFont = gcnew System::Drawing::Font("���� ���", 10, FontStyle::Bold);
			 mainTextBox->SelectionColor = Color::Red;
			 mainTextBox->AppendText("Welcome "+User_Name+"!!\n");
			 inputTextBox->Text = "����!";
		 }

		 // �ش� ������ 2016 ��Ʈ�� ����
		 try {
			 IP = gcnew IPEndPoint(IPAddress::Parse(ipTextBox->Text), 2016);
			 client->Connect(IP);

			 // backgroundWorker1 �̺�Ʈ ����
			 backgroundWorker1->RunWorkerAsync();
			 check = 1;

			 this->sendButton->PerformClick();
		 }

		 // ������ �߻��� ���
		 catch (Exception^ ex)
		 {
			 MessageBox::Show(ex->Message);
		 }
	 }

			  // backgroundWorker1 �̺�Ʈ ����
	 private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		 // ������������ ���� �޽����� �ݺ������� ����
		 while (true)
		 {
			 // �޽����� ���ۿ� ����
			 array<unsigned char>^ buf = gcnew array<unsigned char>(1024);
			 int temp = client->Receive(buf);
			 FormatterText::StructChat^ str = gcnew FormatterText::StructChat();

			 // ���۷� �Ѿ�� �����͸� FomatterText::StructChat ��ü�� str�� ��ȯ�� �ؽ�Ʈ�� ������
			 str = Deserialize(buf);

			 if (order == 0)
			 {
				 order = str->Order;
				 mark = (order == 1) ? "O" : "X";
				 Turn = (order == 1) ? "Your" : "Enermy";
				 std::cout << order << std::endl;
			 }
			 if (str->textChat[0] == '/') {
				 ex = str->tttdata;
				 square = ex;
				 TTTGame_Print();
				 for(int i = 0; i < 9; i++)
					std::cout << str->tttdata[i];
				 std::cout << "\n";
				 if (str->tttdata == "o123456789") continue;
				 str->textChat = "�� ���ʾ�!";
			 }
			 addText(str->userName, str->textChat);
		 }
		 inputTextBox->Clear();
	 }

			  // �ؽ�Ʈ�� �߰��ϴ� �Լ� addText()
	 private: void addText(String^ name, String^ text)
	 {
		 if (name == "") {
			 name = "�͸��� ������";
		 }
		 // ���� �ؽ�Ʈ �ڽ��� �ش� ���ڿ��� ������
		 mainTextBox->AppendText(name + ": ");
		 mainTextBox->AppendText(text + "\n");
		 mainTextBox->ScrollToCaret();
	 }
	 private: int checkwin() {
		 if (square[1] == square[2] && square[2] == square[3])

			 return 1;
		 else if (square[4] == square[5] && square[5] == square[6])

			 return 1;
		 else if (square[7] == square[8] && square[8] == square[9])

			 return 1;
		 else if (square[1] == square[4] && square[4] == square[7])

			 return 1;
		 else if (square[2] == square[5] && square[5] == square[8])

			 return 1;
		 else if (square[3] == square[6] && square[6] == square[9])

			 return 1;
		 else if (square[1] == square[5] && square[5] == square[9])

			 return 1;
		 else if (square[3] == square[5] && square[5] == square[7])

			 return 1;
		 else if (square[1] != Test[1] && square[2] != Test[2] && square[3] != Test[3]
			 && square[4] != Test[4] && square[5] != Test[5] && square[6] != Test[6]
			 && square[7] != Test[7] && square[8] != Test[8] && square[9] != Test[9])
			 return -1;
		 else return 0;
	 }
	 private: void TTTGame() {
		int i = 0;
		for (int j = 1; j <= 9; j++)
		{
			if (MyTTTData == (int)ex[j] - 48)
			{
				square += mark;
				continue;
			}
			square += ex[j];
		}

		if (ex == square)
		{
			std::cout << "err\n";
			ex = square;
			return;
		}

		ex = square;
		player++;

		i = checkwin();
		if (i == 1)
		{
			player -= 1;
			mainTextBox->AppendText("Server:==>\aPlayer " + order + " win! \n");
			ex = "o123456789";
			square = ex;
		}
		else if(i == -1)
		{
			mainTextBox->AppendText("==>\aGame draw \n");
			ex = "o123456789";
			square = ex;
		}
	 }
	 private: void TTTGame_Print() {
		 TTT_GameBox->Clear();
		 System::Drawing::Font^ font = gcnew System::Drawing::Font("����ü", 9);
		 TTT_GameBox->SelectionFont = font;
		 Turn = (Turn == "Your") ? "Enermy" : "Your";

		 TTT_GameBox->AppendText("       Player 1 (O)  -  Player 2 (X)\n");
		 

		 TTT_GameBox->AppendText("     |     |     \n");
		 TTT_GameBox->AppendText("  " + square[1] + "  |  " + square[2] + "  |  " + square[3] + "\n");

		 TTT_GameBox->AppendText("_____|_____|_____\n");
		 TTT_GameBox->AppendText("     |     |     \n");

		 TTT_GameBox->AppendText("  " + square[4] + "  |  " + square[5] + "  |  " + square[6] + "\n");

		 TTT_GameBox->AppendText("_____|_____|_____\n");
		 TTT_GameBox->AppendText("     |     |     \n");

		 TTT_GameBox->AppendText("  " + square[7] + "  |  " + square[8] + "  |  " + square[9] + "\n");

		 TTT_GameBox->AppendText("     |     |     ");

		 TTT_GameBox->SelectionFont = gcnew System::Drawing::Font("���� ���", 9, FontStyle::Bold);
		 
		 TTT_GameBox->AppendText("         "+Turn+" Turn!");
		 square = "o";
	 }
	 // MemoryStream�� BinaryFormatter�� �̿��� FormatterText::StructChat�� ���ڿ� ���¸� ���� ���·� ��ȯ�ϰ� �ٽ� ���� ���� �� �� ����
	 public: array<unsigned char, 1>^ Serialize(FormatterText::StructChat^ str)
	 {
		 MemoryStream^ ms = gcnew MemoryStream();
		 BinaryFormatter^ bf = gcnew BinaryFormatter();
		 bf->Serialize(ms, str);
		 return ms->ToArray();
	 }
	 public: FormatterText::StructChat^ Deserialize(array<unsigned char>^ buff)
	 {
		 MemoryStream^ ms = gcnew MemoryStream(buff);
		 BinaryFormatter^ bf = gcnew BinaryFormatter();
		 return (FormatterText::StructChat^)bf->Deserialize(ms);
	 }
	 // ���� ��ư�� ������ ��
	 private: System::Void sendButton_Click(System::Object^  sender, System::EventArgs^  e) {
		 if (inputTextBox->Text == "" || inputTextBox->Text == "\n") return;
		 FormatterText::StructChat^ str = gcnew FormatterText::StructChat();

		 // ������ ���� ���ڿ��� StructChat ��ü ���·� ��ȯ
		 str->userName = User_Name;
		 str->textChat = inputTextBox->Text;
		 str->tttdata = ex;
		 if (order == 0)
			 str->Order = 0;

		 if (str->textChat[0] == '/') {
			 if (Turn == "Enermy") {
				 mainTextBox->SelectionFont = gcnew System::Drawing::Font("���� ���", 9, FontStyle::Bold);
				 mainTextBox->SelectionColor = Color::Red;
				 mainTextBox->AppendText("��� �����Դϴ�!!\n");
				 mainTextBox->ScrollToCaret();
				 inputTextBox->Clear();
				 return;
			 }
			 MyTTTData = (int)str->textChat[1] - 48;
			 if (MyTTTData < 1 || MyTTTData > 9)
			 {
				 System::Drawing::Color^ color = Color::Red;
				 mainTextBox->SelectionColor = (Color)color;
				 mainTextBox->AppendText("\n����! �ٽ��Է¹ٶ�\n");
				 mainTextBox->ScrollToCaret();
				 return;
			 }
			 if ((int)ex[MyTTTData]-48 != MyTTTData) {
				 mainTextBox->SelectionFont = gcnew System::Drawing::Font("���� ���", 9, FontStyle::Bold);
				 mainTextBox->SelectionColor = Color::Red;
				 mainTextBox->AppendText("�̹� �Էµ� ĭ�Դϴ�.!!\n");
				 mainTextBox->ScrollToCaret();
				 inputTextBox->Clear();
				 return;
			 }
			 if (str->textChat == "/sttt") TTTGame_Print();
			 TTTGame();
			 str->tttdata = ex;
		 }	
		 
		 // �ش� StructChat ��ü ���¸� ���۷� ���� �� �ְ� Serialize() �ؼ� ������ ������
		 array<unsigned char>^ buf = gcnew array<unsigned char>(1024);
		 MemoryStream^ ms = gcnew MemoryStream();
		 BinaryFormatter^ bf = gcnew BinaryFormatter();
		 bf->Serialize(ms, str);
		 buf = ms->ToArray();
		 client->Send(buf, buf->Length, SocketFlags::None);
		 inputTextBox->Clear();
		 inputTextBox->Focus();
	 }
	private: System::Void inputTextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
		{
			e->SuppressKeyPress = true;
			this->sendButton->PerformClick();
		}
	}
};
}

