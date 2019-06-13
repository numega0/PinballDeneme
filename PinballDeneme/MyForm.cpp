#include "MyForm.h"

using namespace WindowsFormsTamplateDLL;

int UIMain()
{
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm^ NewUi = gcnew MyForm();
	Application::Run(NewUi);
	return 1;
}