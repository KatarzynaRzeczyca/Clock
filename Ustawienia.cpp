#include "Ustawienia.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

void ZegarAnalogowy::Ustawienia::PostInitUstawienia()
{	
	SYSTEMTIME lt;

	GetLocalTime(&lt);
	int t = ((lt.wHour % 12) * 60 + lt.wMinute) * 60 + lt.wSecond;		/////Zapami�tanie czasu systemowego w zmiennej t.
	t = t + timeOffsets;												/////Zapami�tanie w zmiennej t czasu razem z podanym przez Uzytkownika z przesuni�ciem
	if (t < 0)															/////Uwzgl�dnienie przypadku, gdy U�ytkownik "cofa" pokazany czas a� do uzyskania 
	{																	/////warto�ci ujemnej, co wynika m.in. z 12-godzinnego trybu zegara
		t = t + 12 * 3600;
	}

	numericUpDownGodzina->Value = (t/3600) % 12;						/////Zapami�tanie nowej warto�ci przez kontrolk� godzinn�
	numericUpDownMinuta->Value = (t/60)  % 60;							/////Zapami�tanie nowej warto�ci przez kontrolk� minutow�

	pictureBoxTarcza->Image = domyslnaTarczaZegara();
	pictureBoxGodzina->Image = domyslnaWskazowkaGodzinowa();
	pictureBoxMinuta->Image = domyslnaWskazowkaMinutowa();
	pictureBoxSekunda->Image = domyslnaWskazowkaSekundowa();
}

System::Void ZegarAnalogowy::Ustawienia::buttonUstaw_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	SYSTEMTIME lt;

	GetLocalTime(&lt);
	int t1 = ((lt.wHour % 12) * 60 + lt.wMinute) * 60 + lt.wSecond;
	
	int godz = System::Decimal::ToInt32( numericUpDownGodzina->Value);
	int min = System::Decimal::ToInt32(numericUpDownMinuta->Value);

	int t2 = godz * 3600 + min * 60;

	timeOffsets = t2 - t1;
}

System::Void ZegarAnalogowy::Ustawienia::buttonTarczaZmien_Click(System::Object ^ sender, System::EventArgs ^ e)		/////Zmiana obrazu tarczy
{
	openFileDialogPng->InitialDirectory = Application::StartupPath;		/////Oznaczenie folderu z kt�rego startuje aplikacja jako folderu pocz�tkowego
	openFileDialogPng->Filter = "Obraz tarczy zegara|*.PNG";
	openFileDialogPng->FilterIndex = 2;
	//openFileDialogPng->RestoreDirectory = true;

	/////Otworzenie okna dialogowego na ekranie
	if (openFileDialogPng->ShowDialog() == ::System::Windows::Forms::DialogResult::OK) {
		/////W razie zaakceptowania zmian
//		Image^ obrazTarczy = Image::FromFile(openFileDialogPng->FileName);
		Image^ obrazTarczy = Image::FromStream(openFileDialogPng->OpenFile());		/////Zapami�tanie pod uchwytem obrazTarczy wyboru obrazka
		pictureBoxTarcza->Image = obrazTarczy;		/////Podstawienie wybranego obrazu jako Tarczy
	}

}

System::Void ZegarAnalogowy::Ustawienia::buttonSekundaZmie�_Click(System::Object ^ sender, System::EventArgs ^ e)		/////Zmiana obrazu sekundnika-analogicznie do tarczy
{

	openFileDialogPng->Filter = "Obraz tarczy zegara|*.PNG";
	openFileDialogPng->FilterIndex = 2;
	//openFileDialogPng->RestoreDirectory = true;

	if (openFileDialogPng->ShowDialog() == ::System::Windows::Forms::DialogResult::OK) {

		//		Image^ obrazTarczy = Image::FromFile(openFileDialogPng->FileName);
		Image^ obraz = Image::FromStream(openFileDialogPng->OpenFile());
		pictureBoxSekunda->Image = obraz;
	}

}

System::Void ZegarAnalogowy::Ustawienia::buttonMinutaZmie�_Click(System::Object ^ sender, System::EventArgs ^ e)		/////Zmiana obrazu wskaz�wki minutowej-analogicznie do tarczy
{
	openFileDialogPng->Filter = "Obraz tarczy zegara|*.PNG";
	openFileDialogPng->FilterIndex = 2;

	if (openFileDialogPng->ShowDialog() == ::System::Windows::Forms::DialogResult::OK) {

		Image^ obraz = Image::FromStream(openFileDialogPng->OpenFile());
		pictureBoxMinuta->Image = obraz;
	}
}

System::Void ZegarAnalogowy::Ustawienia::buttonGodzinaZmie�_Click(System::Object ^ sender, System::EventArgs ^ e)		/////Zmiana obrazu wskaz�wki godzinowej-analogicznie do tarczy
{
	openFileDialogPng->Filter = "Obraz tarczy zegara|*.PNG";
	openFileDialogPng->FilterIndex = 2;

	if (openFileDialogPng->ShowDialog() == ::System::Windows::Forms::DialogResult::OK) {

		Image^ obraz = Image::FromStream(openFileDialogPng->OpenFile());
		pictureBoxGodzina->Image = obraz;
	}
}

System::Drawing::Bitmap^ ZegarAnalogowy::Ustawienia::domyslnaTarczaZegara()		/////Obracanie obrazka
{
	int width = 1000;
	int height = 1000;
	float offsetW = width / 2.0f; 
	float offsetH = height / 2.0f;
	System::Drawing::Bitmap^ img = gcnew System::Drawing::Bitmap(width, height);		/////Nowy Bitmap; 
	img->SetResolution(200, 200);


	Graphics^ g = Graphics::FromImage(img);		/////Utworzenie nowego obiektu Graphics, kt�rego zadaniem b�dzie przetworzy� obraz wskaz�wki

//	Color silver = Color::FromArgb(0xFFC0C0C0); //	

	System::Drawing::Rectangle rec;
	rec.X = 0;
	rec.Y = 0;
	rec.Width = width;
	rec.Height = height;

	Brush^ b = gcnew System::Drawing::Drawing2D::LinearGradientBrush(rec, Color::White, Color::Black, System::Drawing::Drawing2D::LinearGradientMode::ForwardDiagonal);
	g->FillEllipse(b, 0, 0, width, height);


	Brush^ lgb = gcnew System::Drawing::Drawing2D::LinearGradientBrush(rec, Color::White, Color::Aquamarine, System::Drawing::Drawing2D::LinearGradientMode::ForwardDiagonal);
	g->FillEllipse(lgb, 50, 50, width - 100, height - 100);

//	rysujemy znaczniki minutowe
	g->TranslateTransform(offsetW, offsetH);		/////Obr�t odbywa si� wzgl�dem punktu 0 (na pocz�tku znajduje sie w prawym g�rnym rogu)
	System::Drawing::Font ^ f = gcnew System::Drawing::Font(this->Font->FontFamily, 20.0);

	Brush^ sb = gcnew SolidBrush(Color::Black);
	for (int i = 1; i <= 60; i++) {
		/////Obraz przemieszczony tak, aby obracaj�c si� wzgl�dem 0 obraca� si� wzgl�dem swojego �rodka
		g->RotateTransform(360/60);		/////Obr�cenie o dany k�t
		if (i % 5 == 0) {
			rec.X = -5;
			rec.Y = -450;
			rec.Width = 10;
			rec.Height = 30;

			int h = i / 5;
			if (h > 8 || h < 4) { //// od 8 do 4 piszemy od g�ry
				String^ s = "" + h;
				SizeF^ rozmiarTekstu = g->MeasureString(s, f);
				g->DrawString(s, f, sb, -(rozmiarTekstu->Width / 2), -410.0);
				if (h > 9 || h < 3) { //// Od 4 do 8 rysujemy od do�u
					h = (h + 6) % 12;
					String^ s = "" + h;
					SizeF^ rozmiarTekstu = g->MeasureString(s, f);
					g->DrawString(s, f, sb, -(rozmiarTekstu->Width / 2.f), 410.0f- rozmiarTekstu->Height);
				}
			}
		}
		else {
			rec.X = -2;
			rec.Y = -450;
			rec.Width = 4;
			rec.Height = 20;
		}
		g->FillRectangle(sb, rec);


	}

	delete g;						/////Usuni�cie obiektu Graphics
	delete f;
	delete sb;
	delete b;
	delete lgb;
	
	return img;				/////Zwr�cenie przez funkcj� zmienionego obrazka
}

System::Drawing::Bitmap^ ZegarAnalogowy::Ustawienia::domyslnaWskazowkaGodzinowa()		/////Obracanie obrazka
{
	int width = 1000;
	int height = 1000;
	float offsetW = width / 2.0f;
	float offsetH = height / 2.0f;
	System::Drawing::Bitmap^ img = gcnew System::Drawing::Bitmap(width, height);		/////Nowy Bitmap; 
	img->SetResolution(200, 200);


	Graphics^ g = Graphics::FromImage(img);		/////Utworzenie nowego obiektu Graphics, kt�rego zadaniem b�dzie przetworzy� obraz wskaz�wki


	System::Drawing::RectangleF rec;
	rec.X = offsetW-20;
	rec.Y = offsetH-300;
	rec.Width = 40;
	rec.Height = 300;

	Brush^ sb = gcnew SolidBrush(Color::Black);
	g->FillRectangle(sb, rec);

	delete g;						/////Usuni�cie obiektu Graphics
	delete sb;

	return img;				/////Zwr�cenie przez funkcj� zmienionego obrazka
}

System::Drawing::Bitmap^ ZegarAnalogowy::Ustawienia::domyslnaWskazowkaMinutowa()		/////Obracanie obrazka
{
	int width = 1000;
	int height = 1000;
	float offsetW = width / 2.0f;
	float offsetH = height / 2.0f;
	System::Drawing::Bitmap^ img = gcnew System::Drawing::Bitmap(width, height);		/////Nowy Bitmap; 
	img->SetResolution(200, 200);


	Graphics^ g = Graphics::FromImage(img);		/////Utworzenie nowego obiektu Graphics, kt�rego zadaniem b�dzie przetworzy� obraz wskaz�wki


	System::Drawing::RectangleF rec;
	rec.X = offsetW - 10;
	rec.Y = offsetH - 400;
	rec.Width = 20;
	rec.Height = 400;

	Brush^ sb = gcnew SolidBrush(Color::DarkBlue);
	g->FillRectangle(sb, rec);

	delete g;						/////Usuni�cie obiektu Graphics
	delete sb;

	return img;				/////Zwr�cenie przez funkcj� zmienionego obrazka
}

System::Drawing::Bitmap^ ZegarAnalogowy::Ustawienia::domyslnaWskazowkaSekundowa()		/////Obracanie obrazka
{
	int width = 1000;
	int height = 1000;
	float offsetW = width / 2.0f;
	float offsetH = height / 2.0f;
	System::Drawing::Bitmap^ img = gcnew System::Drawing::Bitmap(width, height);		/////Nowy Bitmap; 
	img->SetResolution(200, 200);


	Graphics^ g = Graphics::FromImage(img);		/////Utworzenie nowego obiektu Graphics, kt�rego zadaniem b�dzie przetworzy� obraz wskaz�wki


	System::Drawing::RectangleF rec;
	rec.X = offsetW - 5;
	rec.Y = offsetH - 440;
	rec.Width = 10;
	rec.Height = 550;

	Brush^ sb = gcnew SolidBrush(Color::Red);
	g->FillRectangle(sb, rec);
	g->FillEllipse(sb, offsetW - 20, offsetH - 20, 40.0f, 40.0f);

	delete g;						/////Usuni�cie obiektu Graphics
	delete sb;

	return img;				/////Zwr�cenie przez funkcj� zmienionego obrazka
}