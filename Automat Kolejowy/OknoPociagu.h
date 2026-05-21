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
	private: System::Windows::Forms::ToolStripMenuItem^ pociagToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ utworzToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ usunToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ zmodyfikujToolStripMenuItem;
	private: System::Windows::Forms::ListBox^ lista_pociagi;



	private: System::Windows::Forms::ToolStripMenuItem^ zamknijToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox1;




	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(OknoPociagu::typeid));
			this->show_button = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->informacjeOPociagachToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->godzinyOdjazduToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stacjaPoczatkowaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->opoznToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kontaktToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pociagToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->utworzToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->usunToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zmodyfikujToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zamknijToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zamknij = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->lista_pociagi = (gcnew System::Windows::Forms::ListBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->informacjeOPociagachToolStripMenuItem,
					this->kontaktToolStripMenuItem, this->pociagToolStripMenuItem, this->zamknijToolStripMenuItem
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
			this->informacjeOPociagachToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->godzinyOdjazduToolStripMenuItem,
					this->stacjaPoczatkowaToolStripMenuItem, this->opoznToolStripMenuItem
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
			// kontaktToolStripMenuItem
			// 
			this->kontaktToolStripMenuItem->Name = L"kontaktToolStripMenuItem";
			this->kontaktToolStripMenuItem->Size = System::Drawing::Size(72, 24);
			this->kontaktToolStripMenuItem->Text = L"kontakt";
			this->kontaktToolStripMenuItem->Click += gcnew System::EventHandler(this, &OknoPociagu::kontaktToolStripMenuItem_Click);
			// 
			// pociagToolStripMenuItem
			// 
			this->pociagToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->utworzToolStripMenuItem,
					this->usunToolStripMenuItem, this->zmodyfikujToolStripMenuItem
			});
			this->pociagToolStripMenuItem->Name = L"pociagToolStripMenuItem";
			this->pociagToolStripMenuItem->Size = System::Drawing::Size(69, 24);
			this->pociagToolStripMenuItem->Text = L"pociag";
			// 
			// utworzToolStripMenuItem
			// 
			this->utworzToolStripMenuItem->Name = L"utworzToolStripMenuItem";
			this->utworzToolStripMenuItem->Size = System::Drawing::Size(165, 26);
			this->utworzToolStripMenuItem->Text = L"utworz";
			// 
			// usunToolStripMenuItem
			// 
			this->usunToolStripMenuItem->Name = L"usunToolStripMenuItem";
			this->usunToolStripMenuItem->Size = System::Drawing::Size(165, 26);
			this->usunToolStripMenuItem->Text = L"usun";
			// 
			// zmodyfikujToolStripMenuItem
			// 
			this->zmodyfikujToolStripMenuItem->Name = L"zmodyfikujToolStripMenuItem";
			this->zmodyfikujToolStripMenuItem->Size = System::Drawing::Size(165, 26);
			this->zmodyfikujToolStripMenuItem->Text = L"zmodyfikuj";
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
			this->button1->Location = System::Drawing::Point(44, 125);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"kolejny";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(44, 171);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"poprzedni";
			this->button2->UseVisualStyleBackColor = true;
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
			this->lista_pociagi->Location = System::Drawing::Point(186, 48);
			this->lista_pociagi->Name = L"lista_pociagi";
			this->lista_pociagi->Size = System::Drawing::Size(152, 196);
			this->lista_pociagi->TabIndex = 6;
			this->lista_pociagi->SelectedIndexChanged += gcnew System::EventHandler(this, &OknoPociagu::listBox1_SelectedIndexChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(364, 52);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1337, 222);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &OknoPociagu::pictureBox1_Click);
			// 
			// OknoPociagu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(1701, 298);
			this->Controls->Add(this->pictureBox1);
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
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
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
};
}
