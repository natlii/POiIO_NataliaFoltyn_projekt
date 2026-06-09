#include "OknoPociagu.h"
#include "Kontakt.h"
#include <vector>
#include "TDisplay.h"
#include "TStation.h"
#include "TTrain.h"
#include <windows.h>

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