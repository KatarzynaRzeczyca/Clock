#include "ZegarMainFrame.h"
#include <Windows.h>


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ZegarAnalogowy::ZegarMainFrame form;
	Application::Run(%form);
}

void ZegarAnalogowy::ZegarMainFrame::PostInit(void)
{
	pictureBoxTarcza->Parent = this;
	pictureBoxGodzina->Parent = pictureBoxTarcza;
	pictureBoxMinuta->Parent = pictureBoxGodzina;
	pictureBoxSekunda->Parent = pictureBoxMinuta;

	pictureBoxTarcza->Dock = System::Windows::Forms::DockStyle::Fill;
	pictureBoxGodzina->Dock = System::Windows::Forms::DockStyle::Fill;
	pictureBoxMinuta->Dock = System::Windows::Forms::DockStyle::Fill;
	pictureBoxSekunda->Dock = System::Windows::Forms::DockStyle::Fill;

	pictureBoxTarcza->Image = ustawieniaForm->pictureBoxTarcza->Image;		/////Przypisanie bie��cego obrazka ustawionego jako tarcza zegara 
																			/////Przypisanie odpowiednich obraz�w do wskaz�wek wykonane w funkcji UstawWskaz�wki
	UstawWskazowki();
}

void ZegarAnalogowy::ZegarMainFrame::UstawWskazowki(void)
{
	SYSTEMTIME lt;

	GetLocalTime(&lt);													/////pobranie czasu lokalnego

	int t1 = ((lt.wHour % 12) * 60 + lt.wMinute) * 60 + lt.wSecond;		/////Zapami�tanie w zmiennej t1 pobranego czasu w sekundach
	t1 = t1 + ustawieniaForm->timeOffsets;								/////Dodanie do t1 przesuni�cia wykonanego przez U�ytkownika poprzez zmian� ustawie� godziny (mo�e by� 0)
	if (t1 < 0)															/////Uwzgl�dnienie duzego "cofni�cia" godziny przez U�ytkownika
	{
		t1 = t1 + 12 * 3600;
	}

	/////Zapami�tanie w zmiennych nowego czasu (godziny; minuty; sekundy)
	int godz = (t1/3600)%12;
	int min = (t1/60)%60;
	int sek = t1%60;

//	int width = pictureBoxTarcza->Image->Width;
//	int height = pictureBoxTarcza->Image->Height;

	/////Stworzenie uchwyt�w na obrazy wskaz�wek (godzinowa, minutowa, sekundowa)
	Image^ g = pictureBoxGodzina->Image;
	Image^ m = pictureBoxMinuta->Image;
	Image^ s = pictureBoxSekunda->Image;
	/////Obracanie wskaz�wek
	pictureBoxGodzina->Image = RotateImage( ustawieniaForm->pictureBoxGodzina->Image, (float)30.0* godz + (float)30.0/60*min + (float)30.0 / 3600 * sek);
	pictureBoxMinuta->Image = RotateImage( ustawieniaForm->pictureBoxMinuta->Image, (float)6.0* min + (float)6.0/60*sek );
	pictureBoxSekunda->Image = RotateImage( ustawieniaForm->pictureBoxSekunda->Image, (float)6.0*sek);

	/////RotateImage tworzy nowy obiekt Bitmap, wi�c nale�y zwolni� zb�dne zasoby

	delete g;
	delete m;
	delete s;
}

System::Void ZegarAnalogowy::ZegarMainFrame::ustawieniaToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)	/////Interpretacja klikni�cia przycisku "Ustawienia" na formularzu g��wnym
{
	ZegarAnalogowy::Ustawienia^ noweUstawienia;							/////Stworzenie uchwytu i pod��czenie do niego nowego obiektu klasy Ustawienia
	noweUstawienia = gcnew Ustawienia(ustawieniaForm->timeOffsets);

	if (noweUstawienia->ShowDialog(this) == ::DialogResult::OK) /////W razie zatwierdzenia zmian przyciskiem "Ustaw"
	{
		delete ustawieniaForm;							/////Usuni�cie dotychczasowych ustawie�
		ustawieniaForm = noweUstawienia;				/////Zapami�tanie zmian
		PostInit();										/////Wprowadzenie zmian w �ycie
	}
	else														/////W razie anulowania zmian
	{
		delete noweUstawienia;
	}
}
System::Void ZegarAnalogowy::ZegarMainFrame::timer1_Tick(System::Object ^ sender, System::EventArgs ^ e)
{
	UstawWskazowki();		/////Ka�de "tykni�cie" timera ustawi wskaz�wki wzgl�dem aktualnego czasu
}
System::Drawing::Bitmap^ ZegarAnalogowy::ZegarMainFrame::RotateImage(System::Drawing::Image^ image, float angle)		/////Obracanie obrazka
{
	System::Drawing::Bitmap^ rotatedBmp = gcnew System::Drawing::Bitmap(image->Width, image->Height);		/////Nowy Bitmap; pobranie wysoko�ci i szeroko�ci
	rotatedBmp->SetResolution(image->HorizontalResolution, image->VerticalResolution);
	
	Graphics^ g = Graphics::FromImage(rotatedBmp);		/////Utworzenie nowego obiektu Graphics, kt�rego zadaniem b�dzie przetworzy� obraz wskaz�wki
	
	g->TranslateTransform(image->Width / (float)2, image->Height / (float)2);		/////Obr�t odbywa si� wzgl�dem punktu 0 (na pocz�tku znajduje sie w prawym g�rnym rogu)
																					/////Obraz przemieszczony tak, aby obracaj�c si� wzgl�dem 0 obraca� si� wzgl�dem swojego �rodka
	g->RotateTransform(angle);		/////Obr�cenie o dany k�t

	g->TranslateTransform(image->Width / (float)-2, image->Height / (float)-2);		/////Przesuni�cie obrazka na pierwotne miejsce
	
	g->DrawImage(image, 0, 0);		/////Wygenerowanie nowego obrazka na ekranie

	delete g;						/////Usuni�cie obiektu Graphics

	return rotatedBmp;				/////Zwr�cenie przez funkcj� zmienionego obrazka
}


