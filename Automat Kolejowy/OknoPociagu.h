#pragma once
#include "Kontakt.h"

namespace AutomatKolejowy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o OknoPociagu
	/// </summary>
	public ref class OknoPociagu : public System::Windows::Forms::Form
	{
	private:
			Generic::List<PictureBox^>^ pociag = gcnew Generic::List<PictureBox^>();
	private: System::Windows::Forms::ImageList^ imageList1;
		   Generic::List<Label^>^ lbl_pociag = gcnew Generic::List<Label^>();
	private: System::Windows::Forms::ToolStripMenuItem^ stacjaKoncowaToolStripMenuItem;
		   int pociagID = -1;
	public:
		OknoPociagu(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~OknoPociagu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ show_button;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ informacjeOPociagachToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ godzinyOdjazduToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ stacjaPoczatkowaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ opoznToolStripMenuItem;
	private: System::Windows::Forms::Button^ zamknij;
	private: System::Windows::Forms::ToolStripMenuItem^ kontaktToolStripMenuItem;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;




	private: System::Windows::Forms::ListBox^ lista_pociagi;



	private: System::Windows::Forms::ToolStripMenuItem^ zamknijToolStripMenuItem;





	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		//wyswietalnie pociagu
		private: Void addPociag() {
			PictureBox^ pb = gcnew PictureBox();
			pb->Size = Drawing::Size(308, 51);
			pb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			pb->Image = imageList1->Images[1];

			//pb->Location = Point(12, 41);
			pb->Location = Point(280, 41 + (35 + 41) * pociag->Count);
			pb->Name = L"pociag" + Convert::ToString(pociag->Count);
			
			//pb->Click += gcnew System::EventHandler(this, &OknoPociagu::selectPociagImg);

			this->Controls->Add(pb);
			pociag->Add(pb);
		}
		
		//wyswietlanie etykiety pociagu
		private: Void addLblPociag() {
			Label^ lbl = (gcnew System::Windows::Forms::Label());
			lbl->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			lbl->Size = System::Drawing::Size(308, 15);
			lbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;


			lbl->Location = System::Drawing::Point(280, 95 + (35 + 41) * lbl_pociag->Count);
			lbl->Name = L"lblPociag" + Convert::ToString(lbl_pociag->Count);
			lbl->Text = L"pociag #" + Convert::ToString(lbl_pociag->Count);

			lbl->Click += gcnew System::EventHandler(this, &OknoPociagu::selectPociag);

			this->Controls->Add(lbl);
			lbl_pociag->Add(lbl);
		}


		//odznaczanie etykiety
		private: Void cleanLblPociag() {
			for each(Label ^ lbl in lbl_pociag)
			{
				lbl->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8,
					System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(23)));
				lbl->ForeColor = System::Drawing::Color::FromArgb(0, 0, 0);
			}
			pociagID = -1;
		}





		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(OknoPociagu::typeid));
			this->show_button = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->informacjeOPociagachToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->godzinyOdjazduToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stacjaPoczatkowaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->opoznToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stacjaKoncowaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kontaktToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zamknijToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zamknij = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->lista_pociagi = (gcnew System::Windows::Forms::ListBox());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// show_button
			// 
			this->show_button->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->show_button->Location = System::Drawing::Point(44, 36);
			this->show_button->Name = L"show_button";
			this->show_button->Size = System::Drawing::Size(75, 23);
			this->show_button->TabIndex = 0;
			this->show_button->Text = L"wyswietl";
			this->show_button->UseVisualStyleBackColor = true;
			this->show_button->Click += gcnew System::EventHandler(this, &OknoPociagu::button1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->informacjeOPociagachToolStripMenuItem,
					this->kontaktToolStripMenuItem, this->zamknijToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1701, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &OknoPociagu::menuStrip1_ItemClicked);
			// 
			// informacjeOPociagachToolStripMenuItem
			// 
			this->informacjeOPociagachToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->godzinyOdjazduToolStripMenuItem,
					this->stacjaPoczatkowaToolStripMenuItem, this->opoznToolStripMenuItem, this->stacjaKoncowaToolStripMenuItem
			});
			this->informacjeOPociagachToolStripMenuItem->Name = L"informacjeOPociagachToolStripMenuItem";
			this->informacjeOPociagachToolStripMenuItem->Size = System::Drawing::Size(180, 24);
			this->informacjeOPociagachToolStripMenuItem->Text = L"informacje o pociagach";
			this->informacjeOPociagachToolStripMenuItem->Click += gcnew System::EventHandler(this, &OknoPociagu::informacjeOPociagachToolStripMenuItem_Click);
			// 
			// godzinyOdjazduToolStripMenuItem
			// 
			this->godzinyOdjazduToolStripMenuItem->Name = L"godzinyOdjazduToolStripMenuItem";
			this->godzinyOdjazduToolStripMenuItem->Size = System::Drawing::Size(214, 26);
			this->godzinyOdjazduToolStripMenuItem->Text = L"godziny odjazdu";
			// 
			// stacjaPoczatkowaToolStripMenuItem
			// 
			this->stacjaPoczatkowaToolStripMenuItem->Name = L"stacjaPoczatkowaToolStripMenuItem";
			this->stacjaPoczatkowaToolStripMenuItem->Size = System::Drawing::Size(214, 26);
			this->stacjaPoczatkowaToolStripMenuItem->Text = L"stacja poczatkowa";
			// 
			// opoznToolStripMenuItem
			// 
			this->opoznToolStripMenuItem->Name = L"opoznToolStripMenuItem";
			this->opoznToolStripMenuItem->Size = System::Drawing::Size(214, 26);
			this->opoznToolStripMenuItem->Text = L"opoznienia";
			// 
			// stacjaKoncowaToolStripMenuItem
			// 
			this->stacjaKoncowaToolStripMenuItem->Name = L"stacjaKoncowaToolStripMenuItem";
			this->stacjaKoncowaToolStripMenuItem->Size = System::Drawing::Size(214, 26);
			this->stacjaKoncowaToolStripMenuItem->Text = L"stacja koncowa";
			// 
			// kontaktToolStripMenuItem
			// 
			this->kontaktToolStripMenuItem->Name = L"kontaktToolStripMenuItem";
			this->kontaktToolStripMenuItem->Size = System::Drawing::Size(72, 24);
			this->kontaktToolStripMenuItem->Text = L"kontakt";
			this->kontaktToolStripMenuItem->Click += gcnew System::EventHandler(this, &OknoPociagu::kontaktToolStripMenuItem_Click);
			// 
			// zamknijToolStripMenuItem
			// 
			this->zamknijToolStripMenuItem->Name = L"zamknijToolStripMenuItem";
			this->zamknijToolStripMenuItem->Size = System::Drawing::Size(74, 24);
			this->zamknijToolStripMenuItem->Text = L"zamknij";
			this->zamknijToolStripMenuItem->Click += gcnew System::EventHandler(this, &OknoPociagu::zamknijToolStripMenuItem_Click);
			// 
			// zamknij
			// 
			this->zamknij->Location = System::Drawing::Point(44, 76);
			this->zamknij->Name = L"zamknij";
			this->zamknij->Size = System::Drawing::Size(75, 23);
			this->zamknij->TabIndex = 2;
			this->zamknij->Text = L"zamknij";
			this->zamknij->UseVisualStyleBackColor = true;
			this->zamknij->Click += gcnew System::EventHandler(this, &OknoPociagu::button1_Click_1);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(44, 117);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"kolejny";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(44, 158);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"poprzedni";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &OknoPociagu::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(44, 209);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"wiecej";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// lista_pociagi
			// 
			this->lista_pociagi->FormattingEnabled = true;
			this->lista_pociagi->ItemHeight = 16;
			this->lista_pociagi->Location = System::Drawing::Point(147, 52);
			this->lista_pociagi->Name = L"lista_pociagi";
			this->lista_pociagi->Size = System::Drawing::Size(152, 196);
			this->lista_pociagi->TabIndex = 6;
			this->lista_pociagi->SelectedIndexChanged += gcnew System::EventHandler(this, &OknoPociagu::listBox1_SelectedIndexChanged);
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Turquoise;
			this->imageList1->Images->SetKeyName(0, L"pociag.png");
			this->imageList1->Images->SetKeyName(1, L"pociag.png");
			// 
			// OknoPociagu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(1701, 298);
			this->Controls->Add(this->lista_pociagi);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->zamknij);
			this->Controls->Add(this->show_button);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"OknoPociagu";
			this->Text = L"OknoPociagu";
			this->Load += gcnew System::EventHandler(this, &OknoPociagu::OknoPociagu_Load);
			this->Click += gcnew System::EventHandler(this, &OknoPociagu::OknoPociagu_Click);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		addPociag();
		addLblPociag();
	}

	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void kontaktToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Kontakt^ dane_kont = gcnew Kontakt();
	dane_kont->Show();
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void OknoPociagu_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void zamknijToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult answer;
	answer = MessageBox::Show("Czy napewno chcesz zamkn¹æ aplikacjê?",
		"Program kubeczki", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

	if (answer == System::Windows::Forms::DialogResult::Yes)
		Application::Exit();
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void informacjeOPociagachToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
}

	   //akcja po przyciesnieciu etykiety
private: System::Void selectPociag(System::Object^ sender, System::EventArgs^ e) {
	cleanLblPociag();

	Label^ lbl = (Label^)sender;
	lbl->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
	lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8,
		System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(23)));
	lbl->ForeColor = System::Drawing::Color::FromArgb(255, 0, 150);
	
}

//	//po przycisnieciu pociagu
//private: System::Void selectPociagImg(System::Object^ sender, System::EventArgs^ e) {
//	cleanLblPociag();
//
//	Label^ lbl = (Label^)sender;
//	lbl->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
//	lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8,
//		System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//		static_cast<System::Byte>(23)));
//	lbl->ForeColor = System::Drawing::Color::FromArgb(255, 0, 150);
//
//}

private: System::Void OknoPociagu_Click(System::Object^ sender, System::EventArgs^ e) {
	cleanLblPociag();
}
};
}
