#pragma once
#include "Kontakt.h"
#include "TTrain.h"
#include "TStation.h"
#include "TDisplay.h"
#include <msclr/marshal_cppstd.h> 
#include "SzczegolyPociagu.h"

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
		   Generic::List<Label^>^ lbl_dep_time = gcnew Generic::List<Label^>();
		   Generic::List<Label^>^ lbl_dep_stat = gcnew Generic::List<Label^>();
		   Generic::List<Label^>^ lbl_cur_stat = gcnew Generic::List<Label^>();
		   Generic::List<Label^>^ lbl_last_stat = gcnew Generic::List<Label^>();
	private: System::Windows::Forms::ToolStripMenuItem^ stacjaKoncowaToolStripMenuItem;
		   int pociagID = -1;
		   int pociagAmount = -1;
		   int time = 8 * 60;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ time_display;

	private:
		SzczegolyPociagu^ detailsWindow = nullptr;
		Kontakt^ kontaktWindow = nullptr;


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


	/*private: Void addTCup() {
		TCup* cup = new TCup(1000.0);
		cups_pnt.push_back(cup);
	}
		   void show_cup_info()
		   {
			   TCup* cup_pnt = cups_pnt[cupID];
			   std::string info = cup_pnt->info(cupID);

			   String^ info_cli = gcnew String(info.c_str());
			   MessageBox::Show(info_cli, "Program kalkulator",
				   MessageBoxButtons::OK, MessageBoxIcon::Information);
		   }

	private: Void addCup() {
		PictureBox^ pb = gcnew PictureBox();
		pb->Size = Drawing::Size(199, 319);
		pb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
		pb->Image = imageList1->Images[0];

		pb->Location = Point(12 + (10 + 199) * lbl_cups->Count, 41);
		pb->Name = L"cup" + Convert::ToString(cups->Count);

		this->Controls->Add(pb);
		cups->Add(pb);
	}*/

		private: Void addPociag() {
			PictureBox^ pb = gcnew PictureBox();
			pb->Size = Drawing::Size(308, 51);
			pb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			pb->Image = imageList1->Images[1];

			//pb->Location = Point(12, 41);
			pb->Location = Point(280, 41 + (35 + 41) * pociag->Count);
			pb->Name = L"pociag" + Convert::ToString(pociag->Count);
			
			pb->Tag = pociag->Count;

			pb->Click += gcnew System::EventHandler(this, &OknoPociagu::selectPociagImg);

			this->Controls->Add(pb);
			pociag->Add(pb);
		}
		
		//wyswietlanie etykiety pociagu
		private: Void addLblPociag() {
			TTrain* trainPtr = TrainExtern[lbl_pociag->Count];

			// name
			Label^ lbl = (gcnew System::Windows::Forms::Label());
			lbl->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			lbl->Size = System::Drawing::Size(308, 15);
			lbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			lbl->Location = System::Drawing::Point(280, 95 + (35 + 41) * lbl_pociag->Count);
			lbl->Name = L"lblPociag" + Convert::ToString(lbl_pociag->Count);
			//lbl->Text = L"pociag #" + Convert::ToString(lbl_pociag->Count);

			lbl->Font = gcnew System::Drawing::Font(L"Arial", 8, FontStyle::Bold);
			lbl->Tag = lbl_pociag->Count;

			lbl->Text = gcnew String(trainPtr->get_name().c_str());
			lbl->Click += gcnew System::EventHandler(this, &OknoPociagu::selectPociag);

			this->Controls->Add(lbl);
			lbl_pociag->Add(lbl);

			// dep time
			Label^ lbl_dep_stat_ = (gcnew System::Windows::Forms::Label());
			lbl_dep_stat_->Size = System::Drawing::Size(800, 70);
			lbl_dep_stat_->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			//lbl_dep_stat_->Font = System::Drawing::Font("Monospac821 BT", 28, 2);
			lbl_dep_stat_ ->Font = gcnew System::Drawing::Font(L"Arial", 10, FontStyle::Bold);
			lbl_dep_stat_->Location = System::Drawing::Point(600, 40 + (35 + 41) * lbl_dep_stat->Count);
			lbl_dep_stat_->Name = L"lbl_dep_station" + Convert::ToString(lbl_dep_stat->Count);
			//lbl->Text = L"pociag #" + Convert::ToString(lbl_pociag->Count);
			lbl_dep_stat_->Text = L"Obecna stacja: " + gcnew String(trainPtr->get_curr_station().get_name().c_str()) + L"\nNastêpna stacja: " + gcnew String(trainPtr->get_next_station().get_name().c_str()) + L"\nOstatnia stacja: " + gcnew String(trainPtr->get_last_station().get_name().c_str());

			this->Controls->Add(lbl_dep_stat_);
			lbl_dep_stat->Add(lbl_dep_stat_);
			UpdateTrains();

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


		//klikniecie pociagu i wyswietlenie informacji
		private: System::Void selectPociagImg(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			PictureBox^ pb = (PictureBox^)sender;

			int index =
				Convert::ToInt32(pb->Tag);

			selectPociag(
				lbl_pociag[index],
				e
			);
		}


		private: Void showTrain(int index)
		{
			if (index < 0 || index >= lbl_pociag->Count)
				return;

			selectPociag(
				lbl_pociag[index],
				gcnew System::EventArgs());

			pociagID = index;
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->time_display = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// show_button
			// 
			this->show_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->show_button->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->show_button->Location = System::Drawing::Point(20, 40);
			this->show_button->Name = L"show_button";
			this->show_button->Size = System::Drawing::Size(100, 25);
			this->show_button->TabIndex = 0;
			this->show_button->Text = L"wyswietl [D] ";
			this->show_button->UseVisualStyleBackColor = false;
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
			this->informacjeOPociagachToolStripMenuItem->Size = System::Drawing::Size(180, 26);
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
			this->kontaktToolStripMenuItem->Size = System::Drawing::Size(72, 26);
			this->kontaktToolStripMenuItem->Text = L"kontakt";
			this->kontaktToolStripMenuItem->Click += gcnew System::EventHandler(this, &OknoPociagu::kontaktToolStripMenuItem_Click);
			// 
			// zamknijToolStripMenuItem
			// 
			this->zamknijToolStripMenuItem->Name = L"zamknijToolStripMenuItem";
			this->zamknijToolStripMenuItem->Size = System::Drawing::Size(74, 26);
			this->zamknijToolStripMenuItem->Text = L"zamknij";
			this->zamknijToolStripMenuItem->Click += gcnew System::EventHandler(this, &OknoPociagu::zamknijToolStripMenuItem_Click);
			// 
			// zamknij
			// 
			this->zamknij->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->zamknij->Location = System::Drawing::Point(20, 200);
			this->zamknij->Name = L"zamknij";
			this->zamknij->Size = System::Drawing::Size(100, 25);
			this->zamknij->TabIndex = 2;
			this->zamknij->Text = L"zamknij [Z]";
			this->zamknij->UseVisualStyleBackColor = false;
			this->zamknij->Visible = false;
			this->zamknij->Click += gcnew System::EventHandler(this, &OknoPociagu::button_zamknij);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->Location = System::Drawing::Point(20, 80);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 25);
			this->button1->TabIndex = 3;
			this->button1->Text = L"kolejny [->]";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &OknoPociagu::button_kolejny);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button2->Location = System::Drawing::Point(20, 120);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 25);
			this->button2->TabIndex = 4;
			this->button2->Text = L"poprzedni [<-]";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &OknoPociagu::button_poprzedni);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button3->Location = System::Drawing::Point(20, 160);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 25);
			this->button3->TabIndex = 5;
			this->button3->Text = L"wiecej [w]";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &OknoPociagu::button_wiecej);
			// 
			// lista_pociagi
			// 
			this->lista_pociagi->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lista_pociagi->FormattingEnabled = true;
			this->lista_pociagi->ItemHeight = 16;
			this->lista_pociagi->Location = System::Drawing::Point(145, 49);
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
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &OknoPociagu::timer1_Tick);
			// 
			// time_display
			// 
			this->time_display->AutoSize = true;
			this->time_display->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->time_display->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->time_display->Location = System::Drawing::Point(30, 277);
			this->time_display->Name = L"time_display";
			this->time_display->Size = System::Drawing::Size(164, 56);
			this->time_display->TabIndex = 7;
			this->time_display->Text = L"08:11";
			// 
			// OknoPociagu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::Highlight;
			this->ClientSize = System::Drawing::Size(1701, 399);
			this->Controls->Add(this->time_display);
			this->Controls->Add(this->lista_pociagi);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->zamknij);
			this->Controls->Add(this->show_button);
			this->Controls->Add(this->menuStrip1);
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"OknoPociagu";
			this->Text = L"OknoPociagu";
			this->Load += gcnew System::EventHandler(this, &OknoPociagu::OknoPociagu_Load);
			this->Click += gcnew System::EventHandler(this, &OknoPociagu::OknoPociagu_Click);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &OknoPociagu::OknoPociagu_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::String^ timeToString(int tm)
	{
		if (tm % 60 < 10)
		{
			return gcnew String(Convert::ToString((tm - tm % 60) / 60) + ":0" + Convert::ToString(tm % 60));
		}
		else if (tm % 60 == 0)
		{
			return gcnew String(Convert::ToString((tm - tm % 60) / 60) + ":00" + Convert::ToString(tm % 60));
		}
		else
		{
			return gcnew String(Convert::ToString((tm - tm % 60) / 60) + ":" + Convert::ToString(tm % 60));
		}
	}

	private: Void UpdateTrains()
	{
		int temp_id = 0;
		TTrain* trainPtr = nullptr;
		for each (Label ^ lbl in lbl_dep_stat)
		{
			trainPtr = TrainExtern[temp_id];
			trainPtr->set_current_time(time);
			if (trainPtr->get_curr_station().get_name() == trainPtr->get_last_station().get_name())
			{
				lbl->Text = L"Poci¹g skoñczy³ bieg\n Stacja koñcowa: " + gcnew String(trainPtr->get_curr_station_disp(false).c_str());
			}
			else lbl->Text = L"Obecna stacja: " + gcnew String(trainPtr->get_curr_station_disp(true).c_str()) + L"\nNastêpna stacja: " + gcnew String(trainPtr->get_next_station_disp(true).c_str()) + L"\nStacja docelowa: " + gcnew String(trainPtr->get_last_station().get_name().c_str());
			//lbl->Text = L"Obecna stacja: " + gcnew String(trainPtr->get_curr_station().get_name().c_str()) + L"  odjazd: "+ timeToString(9*60+15) + L"\nNastêpna stacja: " + gcnew String(trainPtr->get_next_station().get_name().c_str()) + L"  odjazd: " + timeToString(9 * 60 + 15) + L"\nOstatnia stacja: " + gcnew String(trainPtr->get_last_station().get_name().c_str());
			
			if (trainPtr->get_time() + 15 < time)
			{
				trainPtr->build_station_list(max(min(rand() % (StationList.size() - 1), 20), 6), time + 30, trainPtr->get_last_station());
			}
			temp_id++;
		}
		std::string asdf = "a";

		this->time_display->Text = timeToString(time);	
	}

	private: Void createTrainEntry()
	{
		pociagAmount++;
		TTrain* train = new TTrain();
		TrainExtern.push_back(train);
		TrainExtern[pociagAmount]->build_station_list(max(min(rand() % (StationList.size() - 1),20),6), time+30);
		TrainExtern[pociagAmount]->set_current_time(time);

		//aktualizowanie listy pociagow
		lista_pociagi->Items->Add(
			gcnew String(
				TrainExtern[pociagAmount]->
				get_name().c_str()));
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (pociagAmount < 10)
		{
			addPociag();
			createTrainEntry();
			addLblPociag();
		}
		else
		{
			MessageBox::Show("Nie mo¿esz mieæ wiêcej poci¹gów >:(");
		}
	}

	private: System::Void button_zamknij(System::Object^ sender, System::EventArgs^ e) {
		// SprawdŸ, czy okno istnieje i czy nie zosta³o ju¿ usuniête
		if (detailsWindow != nullptr && !detailsWindow->IsDisposed)
		{
			detailsWindow->Close(); // Zamknij okno
		}
		this->zamknij->Visible = false;
	}
	

private: System::Void kontaktToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (kontaktWindow != nullptr && !kontaktWindow->IsDisposed)
	{
		kontaktWindow->BringToFront();
		return; // Przerywamy, nie tworzymy nowego okna!
	}

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
	{
		Application::Exit();
	}
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void informacjeOPociagachToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_poprzedni(System::Object^ sender, System::EventArgs^ e) {
	//przejscie do poprzedniego pociagu
	if (pociag->Count == 0)
		return;

	int prev = pociagID - 1;

	if (prev < 0)
		prev = pociag->Count - 1;

	showTrain(prev);
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
	

	int index =
		Convert::ToInt32(lbl->Tag);

	pociagID = index;

	button3->Visible = true;
}


private: System::Void OknoPociagu_Click(System::Object^ sender, System::EventArgs^ e) {
	cleanLblPociag();
}
private: System::Void button_kolejny(System::Object^ sender, System::EventArgs^ e) {
	//przejscie do kolejnego pociagu
	if (pociag->Count == 0)
		return;

	int next = pociagID + 1;

	if (next >= pociag->Count)
		next = 0;

	showTrain(next);
}
private: System::Void button_wiecej(System::Object^ sender, System::EventArgs^ e) {
	TTrain* train_ptr = TrainExtern[pociagID];
	if (pociagID < 0)
	{
		MessageBox::Show(
			"Wybierz pociag");
		return;
	}

	if (detailsWindow == nullptr ||
		detailsWindow->IsDisposed)
	{
		detailsWindow = gcnew SzczegolyPociagu(train_ptr);
		detailsWindow->TopMost = true; //zeby okno bylo zawsze na wierzchu
		detailsWindow->Show();
	}
	else
	{
		detailsWindow->updateTrain(train_ptr);

		detailsWindow->BringToFront();
	}
	this->zamknij->Visible = true;
	this->button3->Visible = false;
	this->Focus();


}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
{
	time++;
	UpdateTrains();
	if (detailsWindow != nullptr && !detailsWindow->IsDisposed && pociagID>=0)
	{
		TTrain* train_ptr = TrainExtern[pociagID];
		detailsWindow->updateTrain(train_ptr);
	}
}


private: System::Void OknoPociagu_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	// Naciœniêcie klawisza 'W' wywo³uje akcjê pokazywania (Wiêcej)
	if (e->KeyCode == Keys::W)
	{
		// Wywo³ujemy istniej¹c¹ logikê przycisku "Wiêcej"
		if (pociag != nullptr && pociag->Count > 0 && pociagID >= 0 && pociagID < pociag->Count)
		{
			button_wiecej(sender, e);
		}
	}

	// Naciœniêcie klawisza 'Z' zamyka okno (jeœli przycisk zamknij jest widoczny)
	if (e->KeyCode == Keys::Z)
	{		
		if (detailsWindow != nullptr && !detailsWindow->IsDisposed)
		{
			button_zamknij(sender, e);
		}
			// Jeœli masz przycisk na oknie g³ównym, ukrywamy go
			//this->zamknij->Visible = false;
	}
	if (e->KeyCode == Keys::Right)
	{
		// Wywo³ujemy Twój istniej¹cy kod dla kolejnego poci¹gu
		button_kolejny(sender, e);
	}
	if (e->KeyCode == Keys::Left)
	{
		// Wywo³ujemy Twój istniej¹cy kod dla poprzedniego poci¹gu
		button_poprzedni(sender, e);
	}
	if (e->KeyCode == Keys::Escape)
	{ 
		zamknijToolStripMenuItem_Click(sender, e);
	}
	if (e->KeyCode == Keys::D)
	{
		button1_Click(sender, e);
	}
}
	   

};
}
