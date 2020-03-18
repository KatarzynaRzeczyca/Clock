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

	pictureBoxTarcza->Image = ustawieniaForm->pictureBoxTarcza->Image;		/////Przypisanie bie¿¹cego obrazka ustawionego jako tarcza zegara 
																			/////Przypisanie odpowiednich obrazów do wskazówek wykonane w funkcji UstawWskazówki
	UstawWskazowki();
}

void ZegarAnalogowy::ZegarMainFrame::UstawWskazowki(void)
{
	SYSTEMTIME lt;

	GetLocalTime(&lt);													/////pobranie czasu lokalnego

	int t1 = ((lt.wHour % 12) * 60 + lt.wMinute) * 60 + lt.wSecond;		/////Zapamiêtanie w zmiennej t1 pobranego czasu w sekundach
	t1 = t1 + ustawieniaForm->timeOffsets;								/////Dodanie do t1 przesuniêcia wykonanego przez U¿ytkownika poprzez zmianê ustawieñ godziny (mo¿e byæ 0)
	if (t1 < 0)															/////Uwzglêdnienie duzego "cofniêcia" godziny przez U¿ytkownika
	{
		t1 = t1 + 12 * 3600;
	}

	/////Zapamiêtanie w zmiennych nowego czasu (godziny; minuty; sekundy)
	int godz = (t1/3600)%12;
	int min = (t1/60)%60;
	int sek = t1%60;

//	int width = pictureBoxTarcza->Image->Width;
//	int height = pictureBoxTarcza->Image->Height;

	/////Stworzenie uchwytów na obrazy wskazówek (godzinowa, minutowa, sekundowa)
	Image^ g = pictureBoxGodzina->Image;
	Image^ m = pictureBoxMinuta->Image;
	Image^ s = pictureBoxSekunda->Image;
	/////Obracanie wskazówek
	pictureBoxGodzina->Image = RotateImage( ustawieniaForm->pictureBoxGodzina->Image, (float)30.0* godz + (float)30.0/60*min + (float)30.0 / 3600 * sek);
	pictureBoxMinuta->Image = RotateImage( ustawieniaForm->pictureBoxMinuta->Image, (float)6.0* min + (float)6.0/60*sek );
	pictureBoxSekunda->Image = RotateImage( ustawieniaForm->pictureBoxSekunda->Image, (float)6.0*sek);

	/////RotateImage tworzy nowy obiekt Bitmap, wiêc nale¿y zwolniæ zbêdne zasoby

	delete g;
	delete m;
	delete s;
}

System::Void ZegarAnalogowy::ZegarMainFrame::ustawieniaToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)	/////Interpretacja klikniêcia przycisku "Ustawienia" na formularzu g³ównym
{
	ZegarAnalogowy::Ustawienia^ noweUstawienia;							/////Stworzenie uchwytu i pod³¹czenie do niego nowego obiektu klasy Ustawienia
	noweUstawienia = gcnew Ustawienia(ustawieniaForm->timeOffsets);

	if (noweUstawienia->ShowDialog(this) == ::DialogResult::OK) /////W razie zatwierdzenia zmian przyciskiem "Ustaw"
	{
		delete ustawieniaForm;							/////Usuniêcie dotychczasowych ustawieñ
		ustawieniaForm = noweUstawienia;				/////Zapamiêtanie zmian
		PostInit();										/////Wprowadzenie zmian w ¿ycie
	}
	else														/////W razie anulowania zmian
	{
		delete noweUstawienia;
	}
}
System::Void ZegarAnalogowy::ZegarMainFrame::timer1_Tick(System::Object ^ sender, System::EventArgs ^ e)
{
	UstawWskazowki();		/////Ka¿de "tykniêcie" timera ustawi wskazówki wzglêdem aktualnego czasu
}
System::Drawing::Bitmap^ ZegarAnalogowy::ZegarMainFrame::RotateImage(System::Drawing::Image^ image, float angle)		/////Obracanie obrazka
{
	System::Drawing::Bitmap^ rotatedBmp = gcnew System::Drawing::Bitmap(image->Width, image->Height);		/////Nowy Bitmap; pobranie wysokoœci i szerokoœci
	rotatedBmp->SetResolution(image->HorizontalResolution, image->VerticalResolution);
	
	Graphics^ g = Graphics::FromImage(rotatedBmp);		/////Utworzenie nowego obiektu Graphics, którego zadaniem bêdzie przetworzyæ obraz wskazówki
	
	g->TranslateTransform(image->Width / (float)2, image->Height / (float)2);		/////Obrót odbywa siê wzglêdem punktu 0 (na pocz¹tku znajduje sie w prawym górnym rogu)
																					/////Obraz przemieszczony tak, aby obracaj¹c siê wzglêdem 0 obraca³ siê wzglêdem swojego œrodka
	g->RotateTransform(angle);		/////Obrócenie o dany k¹t

	g->TranslateTransform(image->Width / (float)-2, image->Height / (float)-2);		/////Przesuniêcie obrazka na pierwotne miejsce
	
	g->DrawImage(image, 0, 0);		/////Wygenerowanie nowego obrazka na ekranie

	delete g;						/////Usuniêcie obiektu Graphics

	return rotatedBmp;				/////Zwrócenie przez funkcjê zmienionego obrazka
}


