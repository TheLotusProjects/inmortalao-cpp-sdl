#pragma once
#include "personaje.h"
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Cliente{
	public ref class frmMain : public Form
	{
	public:

		frmMain(void)
		{
			InitializeComponent();
		}


	protected:

		~frmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  picCerrar;
	public:

	private: System::Windows::Forms::PictureBox^  picMin;
	public: System::Windows::Forms::PictureBox^  picMiniMap;
	private:
	public:


	//public: System::ComponentModel::ComponentResourceManager^ resources;
	private: personaje* pj;
	private: System::Windows::Forms::RichTextBox^  rhtxtConsola;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  lblNombre;
	private: System::Windows::Forms::Label^  posicionMapa;
	private: int key;
	private: System::Windows::Forms::Label^  lblSalud;
	private: System::Windows::Forms::Label^  lblMana;
	private: System::Windows::Forms::Label^  lblHambre;
	private: System::Windows::Forms::Label^  lblSed;




	private: System::Windows::Forms::Label^  lblEne;

	private: System::Windows::Forms::PictureBox^  picDialogo;
	private: System::Windows::Forms::PictureBox^  picEne;


	protected:

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMain::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->picMin = (gcnew System::Windows::Forms::PictureBox());
			this->picMiniMap = (gcnew System::Windows::Forms::PictureBox());
			this->rhtxtConsola = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->lblNombre = (gcnew System::Windows::Forms::Label());
			this->posicionMapa = (gcnew System::Windows::Forms::Label());
			this->lblSalud = (gcnew System::Windows::Forms::Label());
			this->lblMana = (gcnew System::Windows::Forms::Label());
			this->lblHambre = (gcnew System::Windows::Forms::Label());
			this->lblSed = (gcnew System::Windows::Forms::Label());
			this->lblEne = (gcnew System::Windows::Forms::Label());
			this->picDialogo = (gcnew System::Windows::Forms::PictureBox());
			this->picEne = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMiniMap))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picDialogo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picEne))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->Location = System::Drawing::Point(13, 137);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(544, 416);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// picCerrar
			// 
			this->picCerrar->Location = System::Drawing::Point(767, 12);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(22, 17);
			this->picCerrar->TabIndex = 1;
			this->picCerrar->TabStop = false;
			// 
			// picMin
			// 
			this->picMin->Location = System::Drawing::Point(753, 12);
			this->picMin->Name = L"picMin";
			this->picMin->Size = System::Drawing::Size(19, 17);
			this->picMin->TabIndex = 2;
			this->picMin->TabStop = false;
			// 
			// picMiniMap
			// 
			this->picMiniMap->BackColor = System::Drawing::SystemColors::ControlText;
			this->picMiniMap->Location = System::Drawing::Point(682, 491);
			this->picMiniMap->Name = L"picMiniMap";
			this->picMiniMap->Size = System::Drawing::Size(90, 95);
			this->picMiniMap->TabIndex = 3;
			this->picMiniMap->TabStop = false;
			// 
			// rhtxtConsola
			// 
			this->rhtxtConsola->BackColor = System::Drawing::SystemColors::InfoText;
			this->rhtxtConsola->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rhtxtConsola->DetectUrls = false;
			this->rhtxtConsola->ForeColor = System::Drawing::SystemColors::Info;
			this->rhtxtConsola->Location = System::Drawing::Point(14, 11);
			this->rhtxtConsola->Name = L"rhtxtConsola";
			this->rhtxtConsola->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->rhtxtConsola->Size = System::Drawing::Size(544, 100);
			this->rhtxtConsola->TabIndex = 4;
			this->rhtxtConsola->TabStop = false;
			this->rhtxtConsola->Text = L"Hola\nComo\nVa\nasd\nasd\nas";
			this->rhtxtConsola->TextChanged += gcnew System::EventHandler(this, &frmMain::rhtxtConsola_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::InfoText;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->ForeColor = System::Drawing::SystemColors::Info;
			this->textBox1->Location = System::Drawing::Point(13, 115);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(501, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->TabStop = false;
			this->textBox1->Visible = false;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmMain::textBox1_KeyDown);
			// 
			// lblNombre
			// 
			this->lblNombre->BackColor = System::Drawing::Color::Transparent;
			this->lblNombre->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNombre->ForeColor = System::Drawing::Color::White;
			this->lblNombre->Location = System::Drawing::Point(576, 16);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->Size = System::Drawing::Size(175, 25);
			this->lblNombre->TabIndex = 6;
			this->lblNombre->Text = L"Lotus";
			this->lblNombre->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// posicionMapa
			// 
			this->posicionMapa->BackColor = System::Drawing::Color::Transparent;
			this->posicionMapa->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posicionMapa->ForeColor = System::Drawing::Color::White;
			this->posicionMapa->Location = System::Drawing::Point(576, 468);
			this->posicionMapa->Name = L"posicionMapa";
			this->posicionMapa->Size = System::Drawing::Size(207, 17);
			this->posicionMapa->TabIndex = 7;
			this->posicionMapa->Text = L"Mapa desconocido";
			this->posicionMapa->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->posicionMapa->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::posicionMapa_MouseMove);
			// 
			// lblSalud
			// 
			this->lblSalud->AutoSize = true;
			this->lblSalud->BackColor = System::Drawing::Color::Transparent;
			this->lblSalud->Location = System::Drawing::Point(586, 387);
			this->lblSalud->Name = L"lblSalud";
			this->lblSalud->Size = System::Drawing::Size(24, 13);
			this->lblSalud->TabIndex = 8;
			this->lblSalud->Text = L"0/0";
			// 
			// lblMana
			// 
			this->lblMana->AutoSize = true;
			this->lblMana->BackColor = System::Drawing::Color::Transparent;
			this->lblMana->Location = System::Drawing::Point(589, 417);
			this->lblMana->Name = L"lblMana";
			this->lblMana->Size = System::Drawing::Size(24, 13);
			this->lblMana->TabIndex = 9;
			this->lblMana->Text = L"0/0";
			// 
			// lblHambre
			// 
			this->lblHambre->AutoSize = true;
			this->lblHambre->BackColor = System::Drawing::Color::Transparent;
			this->lblHambre->Location = System::Drawing::Point(687, 415);
			this->lblHambre->Name = L"lblHambre";
			this->lblHambre->Size = System::Drawing::Size(24, 13);
			this->lblHambre->TabIndex = 10;
			this->lblHambre->Text = L"0/0";
			// 
			// lblSed
			// 
			this->lblSed->AutoSize = true;
			this->lblSed->BackColor = System::Drawing::Color::Transparent;
			this->lblSed->Location = System::Drawing::Point(692, 444);
			this->lblSed->Name = L"lblSed";
			this->lblSed->Size = System::Drawing::Size(24, 13);
			this->lblSed->TabIndex = 11;
			this->lblSed->Text = L"0/0";
			// 
			// lblEne
			// 
			this->lblEne->BackColor = System::Drawing::Color::Transparent;
			this->lblEne->Font = (gcnew System::Drawing::Font(L"Tahoma", 6.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEne->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblEne->Location = System::Drawing::Point(583, 444);
			this->lblEne->Name = L"lblEne";
			this->lblEne->Size = System::Drawing::Size(91, 9);
			this->lblEne->TabIndex = 12;
			this->lblEne->Text = L"0/0";
			this->lblEne->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// picDialogo
			// 
			this->picDialogo->BackColor = System::Drawing::Color::Transparent;
			this->picDialogo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picDialogo.Image")));
			this->picDialogo->Location = System::Drawing::Point(520, 114);
			this->picDialogo->Name = L"picDialogo";
			this->picDialogo->Size = System::Drawing::Size(37, 20);
			this->picDialogo->TabIndex = 13;
			this->picDialogo->TabStop = false;
			this->picDialogo->Visible = false;
			this->picDialogo->MouseLeave += gcnew System::EventHandler(this, &frmMain::picDialogo_MouseLeave);
			this->picDialogo->MouseHover += gcnew System::EventHandler(this, &frmMain::picDialogo_MouseHover);
			// 
			// picEne
			// 
			this->picEne->BackColor = System::Drawing::Color::Yellow;
			this->picEne->Location = System::Drawing::Point(583, 446);
			this->picEne->Name = L"picEne";
			this->picEne->Size = System::Drawing::Size(91, 9);
			this->picEne->TabIndex = 14;
			this->picEne->TabStop = false;
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(801, 598);
			this->Controls->Add(this->picDialogo);
			this->Controls->Add(this->lblEne);
			this->Controls->Add(this->lblSed);
			this->Controls->Add(this->lblHambre);
			this->Controls->Add(this->lblMana);
			this->Controls->Add(this->lblSalud);
			this->Controls->Add(this->posicionMapa);
			this->Controls->Add(this->lblNombre);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->rhtxtConsola);
			this->Controls->Add(this->picMiniMap);
			this->Controls->Add(this->picMin);
			this->Controls->Add(this->picCerrar);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->picEne);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"frmMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"InmortalAO";
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmMain::frmMain_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &frmMain::frmMain_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMiniMap))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picDialogo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picEne))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmMain_Load(System::Object^  sender, System::EventArgs^  e) {
				 //pictureBox1->KeyDown();
	}
	private: System::Void frmMain_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
				 if (!pj->estaCaminando())
				 {
					 switch (e->KeyCode)
					 {
					 case (Keys::Down) :
						 key = 40;
						 break;
					 case (Keys::Up) :
						 key = 38;
						 break;
					 case (Keys::Left) :
						 key = 37;
						 break;
					 case (Keys::Right) :
						 key = 39;
						 break;
					 case (Keys::Return):
						 textBox1->Visible = true;
						 textBox1->Focus();
						 break;
					 }
					 posicionMapa->Text = "Posición: " + pj->getNroMapa() + ", " + pj->getPossX() + ", " + pj->getPossY();
				 }
	}

	public: int getKey()
	{
				return key;
	}

	public: void setPersonaje(personaje* pjParam)
	{
				pj = pjParam;
				
	}


	private: System::Void posicionMapa_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{

	}

	private: System::Void frmMain_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
				 key = -1;
	}
private: System::Void rhtxtConsola_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Return)
	{
		textBox1->Visible = false;
		std::string texto;
		texto = msclr::interop::marshal_as<std::string>(textBox1->Text);
		pj->setNroMapa(atoi(texto.c_str()));
		this->Focus();
	}
}
	private: System::Void picDialogo_MouseHover(System::Object^  sender, System::EventArgs^  e) {
				 picDialogo->Visible = true;
	}

	private: System::Void picDialogo_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
				 picDialogo->Visible = false;
	}


};

}
