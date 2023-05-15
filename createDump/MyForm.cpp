#include "MyForm.h"
#include"DirSelect.h"

using namespace createDump;
using namespace System::Drawing;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main() {
	Application::Run(gcnew MyForm());
	return 0;
}

System::Void createDump::MyForm::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	ground->BackColor = Color::Black;
	
	return System::Void();
}

System::Void createDump::MyForm::ReadConfig_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (inputGrid->Text=="" || inputX->Text=="" || inputY->Text=="") {
		MessageBox::Show("空白の欄があるので、読み込めません");
		return;
	}
	if (inputGrid->Text == "0" || inputX->Text == "0" || inputY->Text == "0") {
		MessageBox::Show("0の欄があるので、読み込めません");
		return;
	}
	double res;
	if (!double::TryParse(inputGrid->Text, res_grid)|| !double::TryParse(inputX->Text, res_x)|| !double::TryParse(inputY->Text, res_y)) {
		MessageBox::Show("数字以外の値が入力されていますので、読み込めません");
		return;
	}

	//表示エリアの設定
	ground->Width = res_x * disp;
	ground->Height = res_y * disp;

	bmp = gcnew Bitmap(ground->Width, ground->Height);
	ground->Image = bmp;
	g = Graphics::FromImage(ground->Image);

	//マスの設定

	for (int i = 0; i < res_x; i++) {
		for (int n = 0; n < res_y; n++) {
			Rectangle^ temp_rct = gcnew Rectangle(i*disp, n*disp, disp, disp);
			g->DrawRectangle((gcnew Pen(Color::Red)), (Rectangle)temp_rct);
			rctList->Add((Rectangle)temp_rct);

		}
	}

	return System::Void();
}

System::Void createDump::MyForm::GridSelect(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
{
	
	double gridX=e->X/disp+1;
	double gridY = e->Y / disp + 1;
	int gridNumber = (gridX - 1)*res_x + gridY;

	tempStruct->CurrentWire_GridNumber->Add(gridNumber);

	Rectangle^ FillRect = gcnew Rectangle(rctList[gridNumber - 1].X, rctList[gridNumber - 1].Y, disp, disp);
	//表示処理
	g->FillRectangle((gcnew SolidBrush(Color::Navy)), (Rectangle)FillRect);
	g->DrawRectangle((gcnew Pen(Color::Red)), (Rectangle)FillRect);
	ground->Refresh();

	return System::Void();
}

System::Void createDump::MyForm::GridSelect_seg(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
{
	double gridX = e->X / disp + 1;
	double gridY = e->Y / disp + 1;
	int gridNumber = (gridX - 1)*res_x + gridY;

	tempSegment->CurrentWire_GridNumber->Add(gridNumber);

	Rectangle^ FillRect = gcnew Rectangle(rctList[gridNumber - 1].X, rctList[gridNumber - 1].Y, disp, disp);
	//表示処理
	g->FillRectangle((gcnew SolidBrush(Color::FromArgb(128, Color::Gray))), (Rectangle)FillRect);
	g->DrawRectangle((gcnew Pen(Color::Red)), (Rectangle)FillRect);
	ground->Refresh();
	return System::Void();
}


System::Void createDump::MyForm::WireButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	//segment作成モードの場合、メッセージを表示
	if (createWire == false) {
		//ワイヤ作成モードON
		createWire = true;
		//当該ワイヤ構造体を作成
		tempStruct = gcnew wireStruct();
		tempStruct->CurrentWire_GridNumber = gcnew Generic::List<int>;
		tempStruct->segmentList = gcnew Generic::List<segmentStruct^>;
		//マウスダブルクリックイベントを追加
		this->ground->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &createDump::MyForm::GridSelect);
		MessageBox::Show("Wireに追加するGridをダブルクリックで選択してください");
	}
	else {
		//ワイヤ作成モードがONになっているなら保存
		String^ msg = "Wireを登録しますか？";
		System::Windows::Forms::DialogResult^ re= MessageBox::Show(msg, "登録確認", MessageBoxButtons::OKCancel);
		if (re->Equals( (System::Windows::Forms::DialogResult^)System::Windows::Forms::DialogResult::OK)) {
			//あとでチェックのための関数を作成
			//Wire登録
			WireList->Add(tempStruct);
			createWire = false; 
			WireDataView->Rows->Add();
			WireDataView->Rows[WireDataView->RowCount-1]->Cells[0]->Value = "W-" + WireList->Count;
			//名前を設定
			WireList[WireList->Count-1]->name = WireDataView->Rows[WireDataView->RowCount - 1]->Cells[0]->Value->ToString();
			Generic::List<Point>^ accept=getPositionWire(tempStruct);
			WireDataView->Rows[WireDataView->RowCount - 1]->Cells[1]->Value = accept[0].ToString();
			WireDataView->Rows[WireDataView->RowCount - 1]->Cells[2]->Value = accept[1].ToString();
			WireDataView->Rows[WireDataView->RowCount - 1]->Cells[3]->Value = accept[2].ToString();
			WireDataView->Rows[WireDataView->RowCount - 1]->Cells[4]->Value = accept[3].ToString();

			DirSelect^ ds = gcnew DirSelect();
			ds->ShowDialog();

			WireDataView->Rows[WireDataView->RowCount - 1]->Cells[6]->Value = current_name;

			double width;
			if (current_name == "West" || current_name == "East") {
				//横向き電流の場合、Xの幅
				width=Math::Abs(accept[0].Y - accept[1].Y);
			}
			else {
				//縦向き電流の場合、Yの幅
				width = Math::Abs(accept[1].X - accept[2].X);
			}

			WireDataView->Rows[WireDataView->RowCount - 1]->Cells[5]->Value = width.ToString();

			createWire = false;

			MessageBox::Show("登録が完了しました");

			this->ground->MouseDoubleClick -= gcnew System::Windows::Forms::MouseEventHandler(this, &createDump::MyForm::GridSelect);

		}
		else {
			return;
		}

	}
	return System::Void();
}

Generic::List<Point>^ createDump::MyForm::getPositionWire(wireStruct^ wire)
{
	//最小のGridと最大のGridを取得
	if (wire->CurrentWire_GridNumber->Count == 0) {
		//
	}
	int minGrid=res_x*res_y;
	int maxGrid=0;
	for each (int num in wire->CurrentWire_GridNumber)
	{
		if (num < minGrid) {
			minGrid = num;
		}
		if (num > maxGrid) {
			maxGrid = num;
		}
	}
	//X1,Y2座標の特定
	int xPosi_min;
	if (minGrid % (int)res_x == 0) {
		xPosi_min = minGrid/res_x-1;
	}
	else {
		xPosi_min = minGrid/res_x;
	}
	int yPosi_min;
	if (minGrid % (int)res_y == 0) {
		yPosi_min = res_y - 1;
	}
	else {
		yPosi_min = minGrid % (int)res_y - 1;
	}
	Point^ MinPoint = gcnew Point(xPosi_min*disp, yPosi_min*disp);
	int xPosi_max;
	if (maxGrid % (int)res_x == 0) {
		xPosi_max = maxGrid / res_x - 1;
	}
	else {
		xPosi_max = maxGrid / res_x;
	}
	int yPosi_max;
	if (maxGrid % (int)res_y == 0) {
		yPosi_max = res_y - 1;
	}
	else {
		yPosi_max = maxGrid % (int)res_y - 1;
	}
	Point^ MaxPoint = gcnew Point(xPosi_max*disp+disp, yPosi_max*disp+disp);
	//X2,Y1の座標特定
	Point^ X1 = gcnew Point(xPosi_min*disp, yPosi_max*disp + disp);
	Point^ Y1 = gcnew Point(xPosi_max*disp + disp, yPosi_min*disp);

	Generic::List<Point>^ temp_point = gcnew Generic::List<Point>;
	temp_point->Add((Point)X1);
	temp_point->Add((Point)MinPoint);
	temp_point->Add((Point)Y1);
	temp_point->Add((Point)MaxPoint);

	return temp_point;
}

Generic::List<Point>^ createDump::MyForm::getPositionSegment(segmentStruct ^ segment)
{
	if (segment->CurrentWire_GridNumber->Count == 0) {
		//
	}

	int minGrid = res_x * res_y;
	int maxGrid = 0;
	for each (int num in segment->CurrentWire_GridNumber)
	{
		if (num < minGrid) {
			minGrid = num;
		}
		if (num > maxGrid) {
			maxGrid = num;
		}
	}
	//X1,Y2座標の特定
	int xPosi_min;
	if (minGrid % (int)res_x == 0) {
		xPosi_min = minGrid / res_x - 1;
	}
	else {
		xPosi_min = minGrid / res_x;
	}
	int yPosi_min;
	if (minGrid % (int)res_y == 0) {
		yPosi_min = res_y - 1;
	}
	else {
		yPosi_min = minGrid % (int)res_y - 1;
	}
	Point^ MinPoint = gcnew Point(xPosi_min*disp, yPosi_min*disp);
	int xPosi_max;
	if (maxGrid % (int)res_x == 0) {
		xPosi_max = maxGrid / res_x - 1;
	}
	else {
		xPosi_max = maxGrid / res_x;
	}
	int yPosi_max;
	if (maxGrid % (int)res_y == 0) {
		yPosi_max = res_y - 1;
	}
	else {
		yPosi_max = maxGrid % (int)res_y - 1;
	}
	Point^ MaxPoint = gcnew Point(xPosi_max*disp + disp, yPosi_max*disp + disp);
	//X2,Y1の座標特定
	Point^ X1 = gcnew Point(xPosi_min*disp, yPosi_max*disp + disp);
	Point^ Y1 = gcnew Point(xPosi_max*disp + disp, yPosi_min*disp);

	Generic::List<Point>^ temp_segment_point = gcnew Generic::List<Point>;
	temp_segment_point->Add((Point)X1);
	temp_segment_point->Add((Point)MinPoint);
	temp_segment_point->Add((Point)Y1);
	temp_segment_point->Add((Point)MaxPoint);

	return temp_segment_point;

	//throw gcnew System::NotImplementedException();
	// TODO: return ステートメントをここに挿入します
}

int createDump::MyForm::getIndexWireName(String ^ name)
{
	int index = -1;
	for each (wireStruct^ var in WireList)
	{
		index += 1;
		if (name == var->name) {
			return index;
		}
	}
	return 0;
}

System::Void createDump::MyForm::SegmentButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (createSegment == false) {
		MessageBox::Show("Viewから対象のワイヤを選択してください");
		this->WireDataView->CellMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &createDump::MyForm::SelectWire);
		for each (int num in WireList[getIndexWireName(SelectSegmentFullName)]->CurrentWire_GridNumber)
		{
			GridPaint(num);
		}
		tempSegment = gcnew segmentStruct();
		tempSegment->CurrentWire_GridNumber = gcnew Generic::List<int>;
		tempSegment->t_array = gcnew array<Point>{};
		createSegment = true;
	}
	else {
		String^ msg = "Segmentを登録しますか？";
		System::Windows::Forms::DialogResult^ re = MessageBox::Show(msg, "登録確認", MessageBoxButtons::OKCancel);
		if (re->Equals((System::Windows::Forms::DialogResult^)System::Windows::Forms::DialogResult::OK)) {
			
			createSegment = false;
			//以下、セグメント用に改修

			int count = WireList[getIndexWireName(SelectSegmentFullName)]->segmentList->Count;

			WireDataView->Rows->Insert(selectedWire_index+count+1);
			//WireDataView->Rows[selectedWire_index+count+1]->Cells[0]->Value = "WS-" + SegmentList->Count;
			WireDataView->Rows[selectedWire_index + count + 1]->Cells[0]->Value = "WS-" + SelectSegmentName + count;
			//名前を設定
			//tempSegment->name = WireDataView->Rows[WireDataView->RowCount - 1]->Cells[0]->Value->ToString();
			tempSegment->name = "WS-" + SelectSegmentName + count;

			//改修の必要ありtempStruct
			Generic::List<Point>^ accept = getPositionSegment(tempSegment);
			WireDataView->Rows[selectedWire_index+count+1]->Cells[1]->Value = accept[0].ToString();
			WireDataView->Rows[selectedWire_index+count+1]->Cells[2]->Value = accept[1].ToString();
			WireDataView->Rows[selectedWire_index+count+1]->Cells[3]->Value = accept[2].ToString();
			WireDataView->Rows[selectedWire_index+count+1]->Cells[4]->Value = accept[3].ToString();

			String^ Wire_Dir = WireDataView->Rows[selectedWire_index]->Cells[6]->Value->ToString();

			WireDataView->Rows[selectedWire_index + count + 1]->Cells[6]->Value = Wire_Dir;
				
			double width;
			if (Wire_Dir == "West" || Wire_Dir == "East") {
				//横向き電流の場合、Xの幅
				width = Math::Abs(accept[0].Y - accept[1].Y)/2;
			}
			else {
				//縦向き電流の場合、Yの幅
				width = Math::Abs(accept[1].X - accept[2].X)/2;
			}

			WireDataView->Rows[selectedWire_index + count + 1]->Cells[5]->Value = width.ToString();

			Point^ t1;
			Point^ t2;
			Point^ t3;

			if (Wire_Dir == "North") {
				t1 = accept[0];
				t2 = gcnew Point((accept[2].X + accept[1].X)/2, accept[1].Y);
				t3 = accept[3];
			}
			else if (Wire_Dir == "South") {
				t1 = accept[1];
				t2 = gcnew Point((accept[0].X + accept[3].X) / 2, accept[0].Y);
				t3 = accept[2];
			}
			else if (Wire_Dir == "East") {
				t1 = accept[2];
				t2 = gcnew Point(accept[0].X,(accept[0].Y + accept[1].Y) / 2 );
				t3 = accept[3];
			}
			else {
				t1 = accept[0];
				t2 = gcnew Point(accept[2].X, (accept[2].Y + accept[3].Y) / 2);
				t3 = accept[1];
			}

			
			array<Point>^ t_array = gcnew array<Point>{(Point)t1,(Point)t2,(Point)t3};
			SegmentPaint(t_array);
			tempSegment->t_array = t_array;
			
			WireList[getIndexWireName(SelectSegmentFullName)]->segmentList->Add(tempSegment);

			MessageBox::Show("登録が完了しました");

			this->ground->MouseDoubleClick -= gcnew System::Windows::Forms::MouseEventHandler(this, &createDump::MyForm::GridSelect);

		}
	}
	return System::Void();
}

System::Void createDump::MyForm::SelectWire(System::Object ^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs ^ e)
{
	
	String^ val=WireDataView->Rows[e->RowIndex]->Cells[0]->Value->ToString();
	array<String^>^ arr = val->Split('-');
	if (arr[0]->Equals("W")) {
		//ワイヤを選択した場合
		selectedWire_index = e->RowIndex;
		SelectSegmentName = arr[1];
		SelectSegmentFullName = val;
		MessageBox::Show("ワイヤを選択しました");
		createSegment = true;
	}
	this->WireDataView->CellMouseDoubleClick -= gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &createDump::MyForm::SelectWire);
	
	this->ground->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &createDump::MyForm::GridSelect_seg);
	
	MessageBox::Show("Segmentに追加するGridをダブルクリックで選択してください");

	return System::Void();
}

System::Void createDump::MyForm::GridPaint(int gridNum)
{
	Rectangle^ FillRect = gcnew Rectangle(rctList[gridNum - 1].X, rctList[gridNum - 1].Y, disp, disp);
	//表示処理
	g->FillRectangle((gcnew SolidBrush(Color::Yellow)), (Rectangle)FillRect);
	g->DrawRectangle((gcnew Pen(Color::Red)), (Rectangle)FillRect);
	ground->Refresh();
	return System::Void();
}

System::Void createDump::MyForm::SegmentPaint(array<Point>^ t_array)
{
	System::Drawing::Drawing2D::GraphicsPath^ triangle = gcnew System::Drawing::Drawing2D::GraphicsPath();
	triangle->AddPolygon(t_array);
	g->DrawPath(gcnew Pen(Color::Blue), triangle);
	ground->Refresh();
	return System::Void();
}

System::Void createDump::MyForm::Disp_all()
{
	for each (wireStruct^ var in WireList)
	{
		for each (int num in var->CurrentWire_GridNumber)
		{
			GridPaint(num);
		}
	}

	return System::Void();
}


