#pragma once

namespace ZegarAnalogowy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Ustawienia
	/// </summary>
	public ref class Ustawienia : public System::Windows::Forms::Form
	{
	private:
		void PostInitUstawienia();		/////Ustawienia zmiany godziny na kontrolkach
	public: System::Windows::Forms::OpenFileDialog^  openFileDialogPng;		/////Uchwyt do okna, który pos³uzy do obs³ugi wyboru obrazów sk³adaj¹cych siê na zegar

	/////kontrolki w formularzu Ustawieñ inicjuj¹ce zmianê obrazów sk³adaj¹cych siê na zegar
	private: System::Windows::Forms::Button^  buttonSekundaZmieñ;
	private: System::Windows::Forms::Button^  buttonMinutaZmieñ;
	private: System::Windows::Forms::Button^  buttonGodzinaZmieñ;
	private: System::Windows::Forms::Button^  buttonTarczaZmien;
	
	public:
		int timeOffsets = 0; /////przesuniecie wzgledem czasu aktualnego w sekundach
		
		Ustawienia(int offset)		/////Nazwa przeci¹¿ona! Funkcja ustawiania czasu z uwzglêdnieniem igerencji U¿ytkownika w ustawienia godziny
		{
			timeOffsets = offset;
			InitializeComponent();
			PostInitUstawienia();

			//
			//TODO: Add the constructor code here
			//
		}
		Ustawienia(void)		/////Nazwa przeci¹¿ona! Funkcja ustawiania czasu sprzed igerencji U¿ytkownika w ustawienia godziny
		{
			InitializeComponent();
			PostInitUstawienia();
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Ustawienia()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownMinuta;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownGodzina;





	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;









	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;


	private: System::Windows::Forms::Button^  buttonUstaw;
	private: System::Windows::Forms::Button^  buttonAnuluj;
	public: System::Windows::Forms::PictureBox^  pictureBoxTarcza;
	public: System::Windows::Forms::PictureBox^  pictureBoxGodzina;
	public: System::Windows::Forms::PictureBox^  pictureBoxMinuta;
	public: System::Windows::Forms::PictureBox^  pictureBoxSekunda;









/////Przestrzeñ wygenerowana przez Visual Studio nie ulegaj¹ca zmianom

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Ustawienia::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownMinuta = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownGodzina = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->buttonUstaw = (gcnew System::Windows::Forms::Button());
			this->buttonAnuluj = (gcnew System::Windows::Forms::Button());
			this->pictureBoxTarcza = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxGodzina = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxMinuta = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxSekunda = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialogPng = (gcnew System::Windows::Forms::OpenFileDialog());
			this->buttonSekundaZmieñ = (gcnew System::Windows::Forms::Button());
			this->buttonMinutaZmieñ = (gcnew System::Windows::Forms::Button());
			this->buttonGodzinaZmieñ = (gcnew System::Windows::Forms::Button());
			this->buttonTarczaZmien = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownMinuta))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownGodzina))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxTarcza))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGodzina))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMinuta))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSekunda))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(74, 87);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nowa godzina";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(74, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nowa minuta";
			// 
			// numericUpDownMinuta
			// 
			this->numericUpDownMinuta->Location = System::Drawing::Point(205, 113);
			this->numericUpDownMinuta->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59, 0, 0, 0 });
			this->numericUpDownMinuta->Name = L"numericUpDownMinuta";
			this->numericUpDownMinuta->Size = System::Drawing::Size(51, 20);
			this->numericUpDownMinuta->TabIndex = 2;
			// 
			// numericUpDownGodzina
			// 
			this->numericUpDownGodzina->Location = System::Drawing::Point(205, 85);
			this->numericUpDownGodzina->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->numericUpDownGodzina->Name = L"numericUpDownGodzina";
			this->numericUpDownGodzina->Size = System::Drawing::Size(51, 20);
			this->numericUpDownGodzina->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 167);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Styl zegara";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(156, 167);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(120, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Wskazówka godzinowa";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(417, 167);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(124, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Wskazówka sekundowa";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(289, 167);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(114, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Wskazówka minutowa";
			// 
			// buttonUstaw
			// 
			this->buttonUstaw->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->buttonUstaw->Location = System::Drawing::Point(287, 415);
			this->buttonUstaw->Name = L"buttonUstaw";
			this->buttonUstaw->Size = System::Drawing::Size(75, 23);
			this->buttonUstaw->TabIndex = 16;
			this->buttonUstaw->Text = L"Ustaw";
			this->buttonUstaw->UseVisualStyleBackColor = true;
			this->buttonUstaw->Click += gcnew System::EventHandler(this, &Ustawienia::buttonUstaw_Click);
			// 
			// buttonAnuluj
			// 
			this->buttonAnuluj->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonAnuluj->Location = System::Drawing::Point(393, 415);
			this->buttonAnuluj->Name = L"buttonAnuluj";
			this->buttonAnuluj->Size = System::Drawing::Size(75, 23);
			this->buttonAnuluj->TabIndex = 17;
			this->buttonAnuluj->Text = L"Anuluj";
			this->buttonAnuluj->UseVisualStyleBackColor = true;
			this->buttonAnuluj->Click += gcnew System::EventHandler(this, &Ustawienia::buttonAnuluj_Click_);
			// 
			// pictureBoxTarcza
			// 
			this->pictureBoxTarcza->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxTarcza->Location = System::Drawing::Point(32, 205);
			this->pictureBoxTarcza->Name = L"pictureBoxTarcza";
			this->pictureBoxTarcza->Size = System::Drawing::Size(70, 70);
			this->pictureBoxTarcza->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxTarcza->TabIndex = 18;
			this->pictureBoxTarcza->TabStop = false;
			// 
			// pictureBoxGodzina
			// 
			this->pictureBoxGodzina->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxGodzina->Location = System::Drawing::Point(159, 205);
			this->pictureBoxGodzina->Name = L"pictureBoxGodzina";
			this->pictureBoxGodzina->Size = System::Drawing::Size(70, 70);
			this->pictureBoxGodzina->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxGodzina->TabIndex = 19;
			this->pictureBoxGodzina->TabStop = false;
			// 
			// pictureBoxMinuta
			// 
			this->pictureBoxMinuta->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxMinuta->Location = System::Drawing::Point(292, 205);
			this->pictureBoxMinuta->Name = L"pictureBoxMinuta";
			this->pictureBoxMinuta->Size = System::Drawing::Size(70, 70);
			this->pictureBoxMinuta->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxMinuta->TabIndex = 20;
			this->pictureBoxMinuta->TabStop = false;
			// 
			// pictureBoxSekunda
			// 
			this->pictureBoxSekunda->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxSekunda->Location = System::Drawing::Point(420, 205);
			this->pictureBoxSekunda->Name = L"pictureBoxSekunda";
			this->pictureBoxSekunda->Size = System::Drawing::Size(70, 70);
			this->pictureBoxSekunda->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxSekunda->TabIndex = 21;
			this->pictureBoxSekunda->TabStop = false;
			// 
			// openFileDialogPng
			// 
			this->openFileDialogPng->DefaultExt = L"png";
			this->openFileDialogPng->FileName = L".png";
			this->openFileDialogPng->InitialDirectory = L".";
			this->openFileDialogPng->Title = L"Zmieñ";
			// 
			// buttonSekundaZmieñ
			// 
			this->buttonSekundaZmieñ->Location = System::Drawing::Point(415, 302);
			this->buttonSekundaZmieñ->Name = L"buttonSekundaZmieñ";
			this->buttonSekundaZmieñ->Size = System::Drawing::Size(75, 23);
			this->buttonSekundaZmieñ->TabIndex = 22;
			this->buttonSekundaZmieñ->Text = L"Zmieñ";
			this->buttonSekundaZmieñ->UseVisualStyleBackColor = true;
			this->buttonSekundaZmieñ->Click += gcnew System::EventHandler(this, &Ustawienia::buttonSekundaZmieñ_Click);
			// 
			// buttonMinutaZmieñ
			// 
			this->buttonMinutaZmieñ->Location = System::Drawing::Point(292, 302);
			this->buttonMinutaZmieñ->Name = L"buttonMinutaZmieñ";
			this->buttonMinutaZmieñ->Size = System::Drawing::Size(75, 23);
			this->buttonMinutaZmieñ->TabIndex = 23;
			this->buttonMinutaZmieñ->Text = L"Zmieñ";
			this->buttonMinutaZmieñ->UseVisualStyleBackColor = true;
			this->buttonMinutaZmieñ->Click += gcnew System::EventHandler(this, &Ustawienia::buttonMinutaZmieñ_Click);
			// 
			// buttonGodzinaZmieñ
			// 
			this->buttonGodzinaZmieñ->Location = System::Drawing::Point(159, 302);
			this->buttonGodzinaZmieñ->Name = L"buttonGodzinaZmieñ";
			this->buttonGodzinaZmieñ->Size = System::Drawing::Size(75, 23);
			this->buttonGodzinaZmieñ->TabIndex = 24;
			this->buttonGodzinaZmieñ->Text = L"Zmieñ";
			this->buttonGodzinaZmieñ->UseVisualStyleBackColor = true;
			this->buttonGodzinaZmieñ->Click += gcnew System::EventHandler(this, &Ustawienia::buttonGodzinaZmieñ_Click);
			// 
			// buttonTarczaZmien
			// 
			this->buttonTarczaZmien->Location = System::Drawing::Point(27, 302);
			this->buttonTarczaZmien->Name = L"buttonTarczaZmien";
			this->buttonTarczaZmien->Size = System::Drawing::Size(75, 23);
			this->buttonTarczaZmien->TabIndex = 25;
			this->buttonTarczaZmien->Text = L"Zmieñ";
			this->buttonTarczaZmien->UseVisualStyleBackColor = true;
			this->buttonTarczaZmien->Click += gcnew System::EventHandler(this, &Ustawienia::buttonTarczaZmien_Click);
			// 
			// Ustawienia
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(548, 485);
			this->Controls->Add(this->buttonTarczaZmien);
			this->Controls->Add(this->buttonGodzinaZmieñ);
			this->Controls->Add(this->buttonMinutaZmieñ);
			this->Controls->Add(this->buttonSekundaZmieñ);
			this->Controls->Add(this->pictureBoxSekunda);
			this->Controls->Add(this->pictureBoxMinuta);
			this->Controls->Add(this->pictureBoxGodzina);
			this->Controls->Add(this->pictureBoxTarcza);
			this->Controls->Add(this->buttonAnuluj);
			this->Controls->Add(this->buttonUstaw);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->numericUpDownGodzina);
			this->Controls->Add(this->numericUpDownMinuta);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Ustawienia";
			this->Text = L"Ustawienia Zegara";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownMinuta))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownGodzina))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxTarcza))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGodzina))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMinuta))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSekunda))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void buttonUstaw_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void buttonTarczaZmien_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void buttonSekundaZmieñ_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void buttonMinutaZmieñ_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void buttonGodzinaZmieñ_Click(System::Object^  sender, System::EventArgs^  e);
		 System::Drawing::Bitmap ^ domyslnaTarczaZegara();
		 System::Drawing::Bitmap ^ domyslnaWskazowkaGodzinowa();
		 System::Drawing::Bitmap ^ domyslnaWskazowkaMinutowa();
		 System::Drawing::Bitmap ^ domyslnaWskazowkaSekundowa();
private: System::Void buttonAnuluj_Click_(System::Object^  sender, System::EventArgs^  e) {
}

};
}
