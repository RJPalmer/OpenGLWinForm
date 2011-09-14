#pragma once

#include "COpenGL.h"

namespace OpenGl {

	using namespace OpenGLForm;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
			this->timer1->Interval = 20;
			this->timer1->Start();
			openGL = gcnew COpenGL(this->panelGraphics, this->panelGraphics->Location.X, 
				this->panelGraphics->Location.Y,
				this->panelGraphics->Width, this->panelGraphics->Height);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
			 COpenGL ^openGL;
			 
	protected: 
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Panel^  panelGraphics;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::Panel^  panelOptions;
	private: System::Windows::Forms::Button^  btnRotateLeft;
	private: System::Windows::Forms::Button^  btnRotateRight;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		static float theta = 0.0f;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelGraphics = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panelOptions = (gcnew System::Windows::Forms::Panel());
			this->btnRotateLeft = (gcnew System::Windows::Forms::Button());
			this->btnRotateRight = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->panelOptions->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// panelGraphics
			// 
			this->panelGraphics->BackColor = System::Drawing::SystemColors::Desktop;
			this->panelGraphics->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panelGraphics->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelGraphics->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelGraphics->Location = System::Drawing::Point(0, 0);
			this->panelGraphics->Margin = System::Windows::Forms::Padding(1);
			this->panelGraphics->MinimumSize = System::Drawing::Size(536, 208);
			this->panelGraphics->Name = L"panelGraphics";
			this->panelGraphics->Padding = System::Windows::Forms::Padding(1);
			this->panelGraphics->Size = System::Drawing::Size(732, 376);
			this->panelGraphics->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(732, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->ToolTipText = L"Menu Operations";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::W));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// panelOptions
			// 
			this->panelOptions->Controls->Add(this->btnRotateRight);
			this->panelOptions->Controls->Add(this->btnRotateLeft);
			this->panelOptions->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panelOptions->Location = System::Drawing::Point(0, 276);
			this->panelOptions->Name = L"panelOptions";
			this->panelOptions->Size = System::Drawing::Size(732, 100);
			this->panelOptions->TabIndex = 1;
			this->panelOptions->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			// 
			// btnRotateLeft
			// 
			this->btnRotateLeft->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnRotateLeft->Location = System::Drawing::Point(39, 26);
			this->btnRotateLeft->Name = L"btnRotateLeft";
			this->btnRotateLeft->Size = System::Drawing::Size(183, 50);
			this->btnRotateLeft->TabIndex = 0;
			this->btnRotateLeft->Text = L"Rotate Left";
			this->btnRotateLeft->UseVisualStyleBackColor = true;
			this->btnRotateLeft->Click += gcnew System::EventHandler(this, &Form1::btnRotateLeft_Click);
			// 
			// btnRotateRight
			// 
			this->btnRotateRight->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnRotateRight->Location = System::Drawing::Point(480, 26);
			this->btnRotateRight->Name = L"btnRotateRight";
			this->btnRotateRight->Size = System::Drawing::Size(183, 50);
			this->btnRotateRight->TabIndex = 1;
			this->btnRotateRight->Text = L"Rotate Right";
			this->btnRotateRight->UseVisualStyleBackColor = true;
			this->btnRotateRight->Click += gcnew System::EventHandler(this, &Form1::btnRotateRight_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(732, 376);
			this->Controls->Add(this->panelOptions);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->panelGraphics);
			this->Name = L"Form1";
			this->Text = L"OpenGL WinForm";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResizeBegin += gcnew System::EventHandler(this, &Form1::Form1_ResizeEnd);
			this->ResizeEnd += gcnew System::EventHandler(this, &Form1::Form1_ResizeEnd);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_ResizeEnd);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panelOptions->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 openGL->Render();
				 openGL->SwapOpenGLBuffers();
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				
				openGL->theta += theta;
				this->Invalidate();
			 }
	private: System::Void Form1_ResizeEnd(System::Object^  sender, System::EventArgs^  e) {
				 openGL->Redraw(this->panelGraphics, this->panelGraphics->Location.X, 
				this->panelGraphics->Location.Y,
				this->panelGraphics->Width, this->panelGraphics->Height);
				 
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 //InitializeComponent();
			 }
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void btnRotateLeft_Click(System::Object^  sender, System::EventArgs^  e) {
				theta = 0.5f;
				//this->Invalidate();
		 }
private: System::Void btnRotateRight_Click(System::Object^  sender, System::EventArgs^  e) {
				theta = -0.5f;
				this->Invalidate();
		 }
};
}

