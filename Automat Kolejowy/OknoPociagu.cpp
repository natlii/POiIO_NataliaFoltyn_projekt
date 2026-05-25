#include "OknoPociagu.h"
#include "Kontakt.h"
#include <vector>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AutomatKolejowy::OknoPociagu form;
	Application::Run(% form);
	return 0;
}