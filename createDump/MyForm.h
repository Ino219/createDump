#pragma once

namespace createDump {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm の概要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			rctList = gcnew Generic::List<Rectangle>;
			disp = 50;
			createWire = false;
			createSegment = false;
			WireList = gcnew Generic::List<wireStruct^>;
			SegmentList = gcnew Generic::List<wireStruct^>;
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  ground;
	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  inputGrid;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  inputX;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  inputY;

	private: System::Windows::Forms::Button^  ReadConfig;
	private: System::Windows::Forms::Button^  WireButton;
	private: System::Windows::Forms::DataGridView^  WireDataView;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  X1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  X2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Y1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Y2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  width;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dir;
	private: System::Windows::Forms::Button^  SegmentButton;
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
			this->ground = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->inputGrid = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->inputX = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->inputY = (gcnew System::Windows::Forms::TextBox());
			this->ReadConfig = (gcnew System::Windows::Forms::Button());
			this->WireButton = (gcnew System::Windows::Forms::Button());
			this->WireDataView = (gcnew System::Windows::Forms::DataGridView());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->X1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->X2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Y1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Y2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->width = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dir = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SegmentButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->WireDataView))->BeginInit();
			this->SuspendLayout();
			// 
			// ground
			// 
			this->ground->Location = System::Drawing::Point(13, 39);
			this->ground->Name = L"ground";
			this->ground->Size = System::Drawing::Size(274, 267);
			this->ground->TabIndex = 0;
			this->ground->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(306, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"グリッド";
			// 
			// inputGrid
			// 
			this->inputGrid->Location = System::Drawing::Point(307, 57);
			this->inputGrid->Name = L"inputGrid";
			this->inputGrid->Size = System::Drawing::Size(55, 19);
			this->inputGrid->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(307, 94);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(12, 12);
			this->label2->TabIndex = 3;
			this->label2->Text = L"X";
			// 
			// inputX
			// 
			this->inputX->Location = System::Drawing::Point(307, 110);
			this->inputX->Name = L"inputX";
			this->inputX->Size = System::Drawing::Size(55, 19);
			this->inputX->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(309, 148);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(12, 12);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Y";
			// 
			// inputY
			// 
			this->inputY->Location = System::Drawing::Point(307, 164);
			this->inputY->Name = L"inputY";
			this->inputY->Size = System::Drawing::Size(55, 19);
			this->inputY->TabIndex = 6;
			// 
			// ReadConfig
			// 
			this->ReadConfig->Location = System::Drawing::Point(307, 214);
			this->ReadConfig->Name = L"ReadConfig";
			this->ReadConfig->Size = System::Drawing::Size(55, 23);
			this->ReadConfig->TabIndex = 7;
			this->ReadConfig->Text = L"設定";
			this->ReadConfig->UseVisualStyleBackColor = true;
			this->ReadConfig->Click += gcnew System::EventHandler(this, &MyForm::ReadConfig_Click);
			// 
			// WireButton
			// 
			this->WireButton->Location = System::Drawing::Point(384, 30);
			this->WireButton->Name = L"WireButton";
			this->WireButton->Size = System::Drawing::Size(75, 23);
			this->WireButton->TabIndex = 8;
			this->WireButton->Text = L"Wire作成";
			this->WireButton->UseVisualStyleBackColor = true;
			this->WireButton->Click += gcnew System::EventHandler(this, &MyForm::WireButton_Click);
			// 
			// WireDataView
			// 
			this->WireDataView->AllowUserToAddRows = false;
			this->WireDataView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->WireDataView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->WireDataView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Number,
					this->X1, this->X2, this->Y1, this->Y2, this->width, this->dir
			});
			this->WireDataView->Location = System::Drawing::Point(479, 39);
			this->WireDataView->Name = L"WireDataView";
			this->WireDataView->RowHeadersVisible = false;
			this->WireDataView->RowTemplate->Height = 21;
			this->WireDataView->Size = System::Drawing::Size(444, 267);
			this->WireDataView->TabIndex = 9;
			// 
			// Number
			// 
			this->Number->HeaderText = L"番号";
			this->Number->Name = L"Number";
			// 
			// X1
			// 
			this->X1->HeaderText = L"X1";
			this->X1->Name = L"X1";
			// 
			// X2
			// 
			this->X2->HeaderText = L"X2";
			this->X2->Name = L"X2";
			// 
			// Y1
			// 
			this->Y1->HeaderText = L"Y1";
			this->Y1->Name = L"Y1";
			// 
			// Y2
			// 
			this->Y2->HeaderText = L"Y2";
			this->Y2->Name = L"Y2";
			// 
			// width
			// 
			this->width->HeaderText = L"width";
			this->width->Name = L"width";
			// 
			// dir
			// 
			this->dir->HeaderText = L"dir";
			this->dir->Name = L"dir";
			// 
			// SegmentButton
			// 
			this->SegmentButton->Location = System::Drawing::Point(384, 72);
			this->SegmentButton->Name = L"SegmentButton";
			this->SegmentButton->Size = System::Drawing::Size(89, 23);
			this->SegmentButton->TabIndex = 10;
			this->SegmentButton->Text = L"Segment作成";
			this->SegmentButton->UseVisualStyleBackColor = true;
			this->SegmentButton->Click += gcnew System::EventHandler(this, &MyForm::SegmentButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(935, 318);
			this->Controls->Add(this->SegmentButton);
			this->Controls->Add(this->WireDataView);
			this->Controls->Add(this->WireButton);
			this->Controls->Add(this->ReadConfig);
			this->Controls->Add(this->inputY);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->inputX);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->inputGrid);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ground);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ground))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->WireDataView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		//描画
		Bitmap^ bmp;
		Graphics^ g;
		//表示用の補正係数
		int disp;
		//各入力欄の入力取得
		double res_grid;
		double res_x;
		double res_y;
		//正方形グリッドのリスト
		Generic::List<Rectangle>^ rctList;
		//ワイヤ作成モードのフラグ
		bool createWire;
		//セグメント作成モードのフラグ
		bool createSegment;
		ref struct segmentStruct {
			Generic::List<int>^ CurrentWire_GridNumber;
			array<Point>^ t_array;
			String^ name;
		};
		//ワイヤ構造体
		ref struct wireStruct {
			Generic::List<int>^ CurrentWire_GridNumber;
			Generic::List<segmentStruct^>^ segmentList;
			String^ name;
		};
		
		//一時的な保存のための構造体
		wireStruct^ tempStruct;
		segmentStruct^ tempSegment;
		//保存したワイヤのリスト
		Generic::List<wireStruct^>^ WireList;
		Generic::List<wireStruct^>^ SegmentList;
		int selectedWire_index;
		String^ SelectSegmentName;
		String^ SelectSegmentFullName;
	public:
		static System::String^ current_name;

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ReadConfig_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void GridSelect(System::Object^  sender, System::Windows::Forms::MouseEventArgs ^ e);
	private: System::Void GridSelect_seg(System::Object^  sender, System::Windows::Forms::MouseEventArgs ^ e);
	private: System::Void WireButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: Generic::List<Point>^ getPositionWire(wireStruct^ wire);
	private: Generic::List<Point>^ getPositionSegment(segmentStruct^ segment);
	private: int getIndexWireName(String^ name);
	private: System::Void SegmentButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SelectWire(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs ^ e);
	private: System::Void GridPaint(int gridNum);
	private: System::Void SegmentPaint(array<Point>^ t_array);
	private: System::Void Disp_all();
};
}
