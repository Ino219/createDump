#pragma once

namespace createDump {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// DirSelect の概要
	/// </summary>
	public ref class DirSelect : public System::Windows::Forms::Form
	{
	public:
		DirSelect(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~DirSelect()
		{
			if (components)
			{
				delete components;
			}
		}




	private: System::Windows::Forms::Button^  DirOK;
	private: System::Windows::Forms::Button^  DirCancel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  DirBox;
	private: System::Windows::Forms::RadioButton^  South;
	private: System::Windows::Forms::RadioButton^  West;
	private: System::Windows::Forms::RadioButton^  East;
	private: System::Windows::Forms::RadioButton^  North;
	protected:






	protected:

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->DirOK = (gcnew System::Windows::Forms::Button());
			this->DirCancel = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->DirBox = (gcnew System::Windows::Forms::GroupBox());
			this->South = (gcnew System::Windows::Forms::RadioButton());
			this->West = (gcnew System::Windows::Forms::RadioButton());
			this->East = (gcnew System::Windows::Forms::RadioButton());
			this->North = (gcnew System::Windows::Forms::RadioButton());
			this->DirBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// DirOK
			// 
			this->DirOK->Location = System::Drawing::Point(12, 212);
			this->DirOK->Name = L"DirOK";
			this->DirOK->Size = System::Drawing::Size(75, 23);
			this->DirOK->TabIndex = 4;
			this->DirOK->Text = L"OK";
			this->DirOK->UseVisualStyleBackColor = true;
			this->DirOK->Click += gcnew System::EventHandler(this, &DirSelect::DirOK_Click);
			// 
			// DirCancel
			// 
			this->DirCancel->Location = System::Drawing::Point(93, 212);
			this->DirCancel->Name = L"DirCancel";
			this->DirCancel->Size = System::Drawing::Size(75, 23);
			this->DirCancel->TabIndex = 5;
			this->DirCancel->Text = L"Cancel";
			this->DirCancel->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(169, 12);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Wireの電流方向を指定してください";
			// 
			// DirBox
			// 
			this->DirBox->Controls->Add(this->South);
			this->DirBox->Controls->Add(this->West);
			this->DirBox->Controls->Add(this->East);
			this->DirBox->Controls->Add(this->North);
			this->DirBox->Location = System::Drawing::Point(24, 40);
			this->DirBox->Name = L"DirBox";
			this->DirBox->Size = System::Drawing::Size(117, 148);
			this->DirBox->TabIndex = 7;
			this->DirBox->TabStop = false;
			this->DirBox->Text = L"groupBox1";
			// 
			// South
			// 
			this->South->AutoSize = true;
			this->South->Location = System::Drawing::Point(32, 115);
			this->South->Name = L"South";
			this->South->Size = System::Drawing::Size(52, 16);
			this->South->TabIndex = 7;
			this->South->TabStop = true;
			this->South->Text = L"South";
			this->South->UseVisualStyleBackColor = true;
			// 
			// West
			// 
			this->West->AutoSize = true;
			this->West->Location = System::Drawing::Point(32, 82);
			this->West->Name = L"West";
			this->West->Size = System::Drawing::Size(48, 16);
			this->West->TabIndex = 6;
			this->West->TabStop = true;
			this->West->Text = L"West";
			this->West->UseVisualStyleBackColor = true;
			// 
			// East
			// 
			this->East->AutoSize = true;
			this->East->Location = System::Drawing::Point(32, 50);
			this->East->Name = L"East";
			this->East->Size = System::Drawing::Size(46, 16);
			this->East->TabIndex = 5;
			this->East->TabStop = true;
			this->East->Text = L"East";
			this->East->UseVisualStyleBackColor = true;
			// 
			// North
			// 
			this->North->AutoSize = true;
			this->North->Location = System::Drawing::Point(32, 18);
			this->North->Name = L"North";
			this->North->Size = System::Drawing::Size(51, 16);
			this->North->TabIndex = 4;
			this->North->TabStop = true;
			this->North->Text = L"North";
			this->North->UseVisualStyleBackColor = true;
			// 
			// DirSelect
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(190, 278);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->DirCancel);
			this->Controls->Add(this->DirOK);
			this->Controls->Add(this->DirBox);
			this->Name = L"DirSelect";
			this->Text = L"DirSelect";
			this->DirBox->ResumeLayout(false);
			this->DirBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DirOK_Click(System::Object^  sender, System::EventArgs^  e);
};
}
