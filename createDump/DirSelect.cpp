#include "DirSelect.h"
#include"MyForm.h"

using namespace createDump;
using namespace System::Windows::Forms;

System::Void createDump::DirSelect::DirOK_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	for each (Control^ rb in DirBox->Controls)
	{
		RadioButton^ current = (RadioButton^)rb;
		if (current->Checked) {
			MyForm::current_name = rb->Name;

			this->Close();
		}
	}

	return System::Void();
}
