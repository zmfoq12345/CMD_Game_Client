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
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			CheckForIllegalCrossThreadCalls = false;
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
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
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
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
			this->label1->Text = L"IP 주소";
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
			this->StartButton->Text = L"시작";
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
			this->End_Button->Text = L"종료";
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
		
				 // 통신에 필요한 각종 변수 선언
	public: static Socket^ server;
	public: static List<Socket^>^ listClient = gcnew List<Socket^>();
	public: static IPEndPoint^ IP;
	public: static Thread^ threadClient;
	public: static String^ username = "";
	public: static int i = 0;
			 // 시작 버튼 클릭 이벤트
	private: System::Void StartButton_Click(System::Object^  sender, System::EventArgs^  e) {
		StartButton->Hide();
		End_Button->Show();
		// 2016 포트를 열고 해당 아이피에서 서버 시작
		IP = gcnew IPEndPoint(IPAddress::Parse(ipTextBox->Text), 2016);

		// backgroundWorker1 작동
		backgroundWorker1->WorkerSupportsCancellation = true;
		backgroundWorker1->RunWorkerAsync();
	}

	// 하나의 클라이언트를 다루는 쓰레드 함수
	private: static void client(Object^ obj)
	{
		Socket^ socket = (Socket^)obj;
		while (true)
		{
			try
			{
				Sleep(100);
				// 클라이언트에게서 버퍼를 통해 메시지를 입력 받음
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
					
				// 모든 클라이언트에게 해당 메시지를 전송
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

			// 오류가 발생한 경우 해당 클라이언트 삭제
			catch (Exception^ ex)
			{
				i--;
				listClient->Remove(socket);
				return;
			}
		}
	}

	// 메인 텍스트 박스에 텍스트를 쓰는 함수
	private: void addTextToMainTextBox(String^ name, String ^text, System::Drawing::Font^ font, System::Drawing::Color^ color)
	{
		mainTextBox->SelectionFont = font;
		mainTextBox->SelectionColor = (Color)color;
		mainTextBox->AppendText(name + text + "\n");
	}

			  // 프로그램이 로드(Load) 되면 자동 실행되는 함수
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		server = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::IP);
	}

			  // backgroundWorker1 실행 함수
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		// 서버 동작을 알림
		server->Bind(IP);
		server->Listen(10);
		String^ name = "Server";
		String^ text = "가 동작하고 있습니다.";
		System::Drawing::Font^ font = gcnew System::Drawing::Font("맑은 고딕", 9, FontStyle::Bold);
		System::Drawing::Color^ color = Color::Red;
		addTextToMainTextBox(name, text, font, color);
		// 무한 반복으로 사용자들을 컨트롤함
		while (true)
		{
			i++;

			Socket^ clientAccept = server->Accept();
			listClient->Add(clientAccept);

			// 클라이언트 접속 시 해당 클라이언트만의 쓰레드를 할당해 client 함수 시작
			threadClient = gcnew Thread(gcnew ParameterizedThreadStart(GameServer::MyForm::client));
			threadClient->IsBackground = true;
			threadClient->Start(clientAccept);

			// 클라이언트 접속을 알림
			String^ UserNum = i + "번째";
			String^ textTemp = "클라이언트가 접속했습니다." + clientAccept->RemoteEndPoint->ToString();
			System::Drawing::Font^ fontTemp = gcnew System::Drawing::Font("맑은 고딕", 9, FontStyle::Bold);
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
		String^ name = "모든";
		String^ text = " 접속을 종료합니다...";
		System::Drawing::Font^ font = gcnew System::Drawing::Font("맑은 고딕", 9, FontStyle::Bold);
		System::Drawing::Color^ color = Color::Red;
		addTextToMainTextBox(name, text, font, color);
		this->MyForm::Close();
	}
};
}
