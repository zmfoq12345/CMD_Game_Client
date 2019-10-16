#include "Con_form.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	//	srand(time(NULL));

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	GameClient::Con_form form;

	Application::Run(%form);
}