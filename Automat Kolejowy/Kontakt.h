#pragma once

namespace AutomatKolejowy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Kontakt
	/// </summary>
	public ref class Kontakt : public System::Windows::Forms::Form
	{
	public:
		Kontakt(void)
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
		~Kontakt()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ dane_kont;
	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dane_kont = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// dane_kont
			// 
			this->dane_kont->Location = System::Drawing::Point(33, 44);
			this->dane_kont->Multiline = true;
			this->dane_kont->Name = L"dane_kont";
			this->dane_kont->ReadOnly = true;
			this->dane_kont->Size = System::Drawing::Size(186, 152);
			this->dane_kont->TabIndex = 0;
			this->dane_kont->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->dane_kont->TextChanged += gcnew System::EventHandler(this, &Kontakt::textBox1_TextChanged);
			// 
			// Kontakt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Controls->Add(this->dane_kont);
			this->Name = L"Kontakt";
			this->Text = L"Kontakt";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
		   dane_kont->Text = "\r\n\r\nKONTAKT\r\nW razie problemó, pytañ, w¹tpliwoœci, prosimy o kontakt\n";
	}
	};
}
