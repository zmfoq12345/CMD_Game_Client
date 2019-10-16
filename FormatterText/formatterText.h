
// 필요한 데이터 추가
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::Runtime::Serialization::Formatters;

#pragma once
using namespace System;

// FormatterText라는 클래스 라이브러리 정의
namespace FormatterText {

	[Serializable]

	// 텍스트의 형태를 나타내는 StructChat 클래스 정의
	public ref class StructChat
	{

	// 기본 변수 선언
	public:
		String^ userName;
		String^ textChat;
		String^ tttdata;
		int Order;
		
	// 기본 생성자 선언
	public: StructChat()
	{
		userName = "";
		textChat = "";
		tttdata = "";
		Order = 0;
	}

	public: StructChat(String^ name, String^ text, int order, String^ ttt)
	{
		userName = name;
		textChat = text;
		Order = order;
		tttdata = ttt;
	}

	// 현재의 객체 데이터를 얻어오는 함수
	public: void GetObjectData(SerializationInfo^ info, StreamingContext^ context)
	{
		info->AddValue("name", userName);
		info->AddValue("text", textChat);
		info->AddValue("turn", Order);
		info->AddValue("ttt", tttdata);
	}

	// Serialization 정보를 이용해 초기화하는 생성자
	public: StructChat(SerializationInfo^ info, StreamingContext^ context)
	{
		userName = (String^)info->GetValue("name", String::typeid);
		textChat = (String^)info->GetValue("text", String::typeid);
		tttdata = (String^)info->GetValue("ttt", String::typeid);
		Order = (int)info->GetValue("turn", int::typeid);
	}
	};
}