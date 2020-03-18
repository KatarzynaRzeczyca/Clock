#pragma once //////////Zapobiega ponownemu za³¹czeniu treœci pliku
#include "Ustawienia.h"

//////////Nowa przestrzeñ nazw
namespace ZegarAnalogowy {

	using namespace System;                      /////Do³¹czenie niezbêdnej przestrzeni nazw zawiraj¹cej m.in. event'y i event handler'y 
	using namespace System::ComponentModel;      /////obs³uga Container lub ISupportInitialize
	using namespace System::Collections;         /////
	using namespace System::Windows::Forms;      /////obs³uga klikniêcia myszy, kontrolek np. Button
	using namespace System::Data;                /////
	using namespace System::Drawing;             /////obs³uga obiektu Graphics lub Bitmap

	/// <summary>
	/// Summary for ZegarMainFrame
	/// </summary>
	public ref class ZegarMainFrame : public System::Windows::Forms::Form
	{
		ZegarAnalogowy::Ustawienia^ ustawieniaForm;
	private:
		void PostInit(void);    /////Funkcja zawiera czynnoœci realizowane przed wykonaniem ustawienia wskazówek
		void UstawWskazowki(void);
		System::Drawing::Bitmap ^ RotateImage(System::Drawing::Image ^ image, float angle);   /////Funkcja obracajaca obraz wskazówki
		//System::Drawing::Bitmap ^ RotateImage(System::Drawing::Image ^ image, int height, int width, float angle);    /////Tutaj funkcja RotateImage alternatywna niewykorzystana,
																														//////kod osiagalny pod kodem wykorzystywanej funkcji RotateImage
	public:
		ZegarMainFrame(void)
		{
			ustawieniaForm = gcnew Ustawienia;


			InitializeComponent();

			PostInit();

			timer1->Start();		/////Uruchomienie timera
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ZegarMainFrame()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBoxTarcza;
	private: System::Windows::Forms::PictureBox^  pictureBoxGodzina;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ustawieniaToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBoxMinuta;
	private: System::Windows::Forms::PictureBox^  pictureBoxSekunda;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

/////Przestrzeñ wygenerowana przez Visual Studio nie ulegaj¹ca zmianom
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ZegarMainFrame::typeid));
			this->pictureBoxTarcza = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxGodzina = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ustawieniaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBoxMinuta = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxSekunda = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxTarcza))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGodzina))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMinuta))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSekunda))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBoxTarcza
			// 
			this->pictureBoxTarcza->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBoxTarcza->Location = System::Drawing::Point(0, 24);
			this->pictureBoxTarcza->Name = L"pictureBoxTarcza";
			this->pictureBoxTarcza->Size = System::Drawing::Size(628, 602);
			this->pictureBoxTarcza->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxTarcza->TabIndex = 0;
			this->pictureBoxTarcza->TabStop = false;
			// 
			// pictureBoxGodzina
			// 
			this->pictureBoxGodzina->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxGodzina->Location = System::Drawing::Point(38, 37);
			this->pictureBoxGodzina->Name = L"pictureBoxGodzina";
			this->pictureBoxGodzina->Size = System::Drawing::Size(300, 382);
			this->pictureBoxGodzina->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxGodzina->TabIndex = 1;
			this->pictureBoxGodzina->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ustawieniaToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(628, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ustawieniaToolStripMenuItem
			// 
			this->ustawieniaToolStripMenuItem->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->ustawieniaToolStripMenuItem->Name = L"ustawieniaToolStripMenuItem";
			this->ustawieniaToolStripMenuItem->Size = System::Drawing::Size(76, 20);
			this->ustawieniaToolStripMenuItem->Text = L"Ustawienia";
			this->ustawieniaToolStripMenuItem->Click += gcnew System::EventHandler(this, &ZegarMainFrame::ustawieniaToolStripMenuItem_Click);
			// 
			// pictureBoxMinuta
			// 
			this->pictureBoxMinuta->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxMinuta->Location = System::Drawing::Point(134, 60);
			this->pictureBoxMinuta->Name = L"pictureBoxMinuta";
			this->pictureBoxMinuta->Size = System::Drawing::Size(293, 305);
			this->pictureBoxMinuta->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxMinuta->TabIndex = 3;
			this->pictureBoxMinuta->TabStop = false;
			// 
			// pictureBoxSekunda
			// 
			this->pictureBoxSekunda->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxSekunda->Location = System::Drawing::Point(193, 110);
			this->pictureBoxSekunda->Name = L"pictureBoxSekunda";
			this->pictureBoxSekunda->Size = System::Drawing::Size(309, 288);
			this->pictureBoxSekunda->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxSekunda->TabIndex = 4;
			this->pictureBoxSekunda->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &ZegarMainFrame::timer1_Tick);
			// 
			// ZegarMainFrame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(628, 626);
			this->Controls->Add(this->pictureBoxSekunda);
			this->Controls->Add(this->pictureBoxMinuta);
			this->Controls->Add(this->pictureBoxGodzina);
			this->Controls->Add(this->pictureBoxTarcza);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"ZegarMainFrame";
			this->Text = L"Zegar Analogowy";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxTarcza))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGodzina))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMinuta))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSekunda))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void ustawieniaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);	/////klikniêcie "Ustawieñ" - wiêcej w Ustawienia.cpp
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);	/////"tykaj¹cy" timer - wiêcej w Ustawienia.cpp
};
}
