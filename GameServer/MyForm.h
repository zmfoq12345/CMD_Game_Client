#pragma once
#include<Windows.h>

namespace GameServer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace FormatterText;
	using namespace System::Collections::Generic;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Threading;
	using namespace System::Runtime::Serialization::Formatters::Binary;
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  ipTextBox;

	private: System::Windows::Forms::RichTextBox^  mainTextBox;
	private: System::Windows::Forms::Button^  StartButton;


	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Button^  End_Button;





	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ipTextBox = (gcnew System::Windows::Forms::TextBox());
			this->mainTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->End_Button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"IP �ּ�";
			// 
			// ipTextBox
			// 
			this->ipTextBox->Location = System::Drawing::Point(62, 7);
			this->ipTextBox->Name = L"ipTextBox";
			this->ipTextBox->Size = System::Drawing::Size(122, 21);
			this->ipTextBox->TabIndex = 1;
			this->ipTextBox->Text = L"127.0.0.1";
			// 
			// mainTextBox
			// 
			this->mainTextBox->Location = System::Drawing::Point(0, 34);
			this->mainTextBox->Name = L"mainTextBox";
			this->mainTextBox->Size = System::Drawing::Size(545, 244);
			this->mainTextBox->TabIndex = 2;
			this->mainTextBox->Text = L"";
			this->mainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::mainTextBox_KeyPress);
			// 
			// StartButton
			// 
			this->StartButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->StartButton->Location = System::Drawing::Point(459, 6);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Size = System::Drawing::Size(75, 23);
			this->StartButton->TabIndex = 3;
			this->StartButton->Text = L"����";
			this->StartButton->UseVisualStyleBackColor = false;
			this->StartButton->Click += gcnew System::EventHandler(this, &MyForm::StartButton_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// End_Button
			// 
			this->End_Button->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->End_Button->Location = System::Drawing::Point(459, 7);
			this->End_Button->Name = L"End_Button";
			this->End_Button->Size = System::Drawing::Size(75, 23);
			this->End_Button->TabIndex = 4;
			this->End_Button->Text = L"����";
			this->End_Button->UseVisualStyleBackColor = false;
			this->End_Button->Click += gcnew System::EventHandler(this, &MyForm::End_Button_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(546, 279);
			this->Controls->Add(this->StartButton);
			this->Controls->Add(this->mainTextBox);
			this->Controls->Add(this->ipTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->End_Button);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Game_Server";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void mainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		e->Handled = true;
	}
		
				 // ��ſ� �ʿ��� ���� ���� ����
	public: static Socket^ server;
	public: static List<Socket^>^ listClient = gcnew List<Socket^>();
	public: static IPEndPoint^ IP;
	public: static Thread^ threadClient;
	public: static String^ username = "";
	public: static int i = 0;
			 // ���� ��ư Ŭ�� �̺�Ʈ
	private: System::Void StartButton_Click(System::Object^  sender, System::EventArgs^  e) {
		StartButton->Hide();
		End_Button->Show();
		// 2016 ��Ʈ�� ���� �ش� �����ǿ��� ���� ����
		IP = gcnew IPEndPoint(IPAddress::Parse(ipTextBox->Text), 2016);

		// backgroundWorker1 �۵�
		backgroundWorker1->WorkerSupportsCancellation = true;
		backgroundWorker1->RunWorkerAsync();
	}

	// �ϳ��� Ŭ���̾�Ʈ�� �ٷ�� ������ �Լ�
	private: static void client(Object^ obj)
	{
		Socket^ socket = (Socket^)obj;
		while (true)
		{
			try
			{
				Sleep(100);
				// Ŭ���̾�Ʈ���Լ� ���۸� ���� �޽����� �Է� ����
				array<unsigned char>^ buff = gcnew array<unsigned char>(1024);
				int temp = socket->Receive(buff);
				FormatterText::StructChat^ str = gcnew FormatterText::StructChat();

				str = Deserialize(buff);
				if (str->Order == 0)
				{
					str->Order = i-1;
					MemoryStream^ ms = gcnew MemoryStream();
					BinaryFormatter^ bf = gcnew BinaryFormatter();
					bf->Serialize(ms, str);
					buff = ms->ToArray();
				}
					
				// ��� Ŭ���̾�Ʈ���� �ش� �޽����� ����
				for each(Socket^ sock in listClient)
				{
					try {
						sock->Send(buff, buff->Length, SocketFlags::None);
					}
					catch (Exception^ ex)
					{
					}
				}
			}

			// ������ �߻��� ��� �ش� Ŭ���̾�Ʈ ����
			catch (Exception^ ex)
			{
				i--;
				listClient->Remove(socket);
				return;
			}
		}
	}

	// ���� �ؽ�Ʈ �ڽ��� �ؽ�Ʈ�� ���� �Լ�
	private: void addTextToMainTextBox(String^ name, String ^text, System::Drawing::Font^ font, System::Drawing::Color^ color)
	{
		mainTextBox->SelectionFont = font;
		mainTextBox->SelectionColor = (Color)color;
		mainTextBox->AppendText(name + text + "\n");
	}

			  // ���α׷��� �ε�(Load) �Ǹ� �ڵ� ����Ǵ� �Լ�
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		server = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::IP);
	}

			  // backgroundWorker1 ���� �Լ�
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		// ���� ������ �˸�
		server->Bind(IP);
		server->Listen(10);
		String^ name = "Server";
		String^ text = "�� �����ϰ� �ֽ��ϴ�.";
		System::Drawing::Font^ font = gcnew System::Drawing::Font("���� ���", 9, FontStyle::Bold);
		System::Drawing::Color^ color = Color::Red;
		addTextToMainTextBox(name, text, font, color);
		// ���� �ݺ����� ����ڵ��� ��Ʈ����
		while (true)
		{
			i++;

			Socket^ clientAccept = server->Accept();
			listClient->Add(clientAccept);

			// Ŭ���̾�Ʈ ���� �� �ش� Ŭ���̾�Ʈ���� �����带 �Ҵ��� client �Լ� ����
			threadClient = gcnew Thread(gcnew ParameterizedThreadStart(GameServer::MyForm::client));
			threadClient->IsBackground = true;
			threadClient->Start(clientAccept);

			// Ŭ���̾�Ʈ ������ �˸�
			String^ UserNum = i + "��°";
			String^ textTemp = "Ŭ���̾�Ʈ�� �����߽��ϴ�." + clientAccept->RemoteEndPoint->ToString();
			System::Drawing::Font^ fontTemp = gcnew System::Drawing::Font("���� ���", 9, FontStyle::Bold);
			System::Drawing::Color^ colorTemp = Color::Red;
			addTextToMainTextBox(UserNum, textTemp, fontTemp, colorTemp);
			mainTextBox->ScrollToCaret();
		}
	}
	 public: static array<unsigned char, 1>^ Serialize(FormatterText::StructChat^ str)
	 {
		 MemoryStream^ ms = gcnew MemoryStream();
		 BinaryFormatter^ bf = gcnew BinaryFormatter();
		 bf->Serialize(ms, str);
		 return ms->ToArray();
	 }

	public: static FormatterText::StructChat^ Deserialize(array<unsigned char>^ buff)
	{
		MemoryStream^ ms = gcnew MemoryStream(buff);
		BinaryFormatter^ bf = gcnew BinaryFormatter();
		return (FormatterText::StructChat^)bf->Deserialize(ms);
	}

	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (backgroundWorker1->IsBusy)
		{
			backgroundWorker1->CancelAsync();
		}
	}
	private: System::Void End_Button_Click(System::Object^  sender, System::EventArgs^  e) {
		StartButton->Show();
		End_Button->Hide();
		i = 0;
		listClient = gcnew List<Socket^>();
		server->Close();
		mainTextBox->Clear();
		String^ name = "���";
		String^ text = " ������ �����մϴ�...";
		System::Drawing::Font^ font = gcnew System::Drawing::Font("���� ���", 9, FontStyle::Bold);
		System::Drawing::Color^ color = Color::Red;
		addTextToMainTextBox(name, text, font, color);
		this->MyForm::Close();
	}
};
}
