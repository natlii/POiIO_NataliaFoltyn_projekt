#pragma once

#include "TTrain.h"

namespace AutomatKolejowy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o SzczegolyPociagu
	/// </summary>
	public ref class SzczegolyPociagu : public System::Windows::Forms::Form
	{
	private:
		TTrain* train;

	public:
		SzczegolyPociagu(TTrain* t)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			train = t;
			updateTrain(train);


			label1->Text =
				L"Nazwa pociagu: " +
				gcnew String(train->get_name().c_str()) +

				//L"\n\nObecna stacja: " +
				gcnew String(
					train->get_station_list().c_str());
			
			label1->Font =
				gcnew System::Drawing::Font(L"Arial", 14, FontStyle::Bold);
		}


	public:

		Void updateTrain(TTrain* train)
		{
			label1->Text =

				L"Nazwa pociagu: " +
				gcnew String(train->get_name().c_str()) + L" - " +
				gcnew String(train->get_id_przewoznik().c_str()) +

				//L"\n\nObecna stacja: " +
				gcnew String(
					train->get_station_list().c_str());

				//L"\nNastepna stacja: " +
				//gcnew String(
				//	train->get_next_station().get_name().c_str()) +

				//L"\nOstatnia stacja: " +
				//gcnew String(
				//	train->get_last_station().get_name().c_str());
		}

	private:
		Label^ label1;

		void InitializeComponent(void)
		{
			this->label1 = gcnew Label();

			this->label1->Location = Drawing::Point(20, 20);
			this->label1->Size = Drawing::Size(800, 600);

			this->Controls->Add(label1);

			this->Text = L"Szczegoly pociagu";
			this->Size = Drawing::Size(800, 600);
		}


	};
}
