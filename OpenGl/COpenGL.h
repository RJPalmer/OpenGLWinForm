#pragma once

#include <windows.h>

#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library



using namespace System::Windows::Forms;

namespace OpenGLForm
{
	
    public ref class COpenGL: 
      public System::Windows::Forms::NativeWindow
		  {
			public:
				COpenGL(System::Windows::Forms::Form ^ parentForm, 
				GLsizei iWidth, GLsizei iHeight)
				{
					CreateParams^ cp = gcnew CreateParams;

					
						
					
					// Set the position on the form

					cp->X = 0;
					cp->Y = 0;
					cp->Height = iHeight;
					cp->Width = iWidth;

					// Specify the form as the parent.

					cp->Parent = parentForm->Handle;

					// Create as a child of the specified parent

					// and make OpenGL compliant (no clipping)

					cp->Style = WS_CHILD | WS_VISIBLE | 
								WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

					
					/*
						FromHandle(this->Handle.ToPointer())

					*/
					
					// Create the actual window
					this->CreateHandle(cp);

					m_hDC = GetDC((HWND)this->Handle.ToPointer());

					if(m_hDC)
						MySetPixelFormat(m_hDC);
				}
				
		static float theta = 0.00f;
		virtual System::Void Render(System::Void)
		{
			// Clear the color and depth buffers.

			glClearColor(0.0f, 0.0f, 0.0f, 0.0f) ;
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glPushMatrix ();
					glRotatef (theta, 0.0f, 0.0f, 1.0f);
					glBegin (GL_TRIANGLES);
					glColor3f (1.0f, 0.0f, 0.0f);   glVertex2f (0.0f, 1.0f);
					glColor3f (0.0f, 1.0f, 0.0f);   glVertex2f (0.87f, -0.5f);
					glColor3f (0.0f, 0.0f, 1.0f);   glVertex2f (-0.87f, -0.5f);
					glEnd ();
					glPopMatrix ();

					theta += 1.0f;

		}
		System::Void Redraw(System::Windows::Forms::Form ^ parentForm, GLsizei width, GLsizei height)
		{

			if (height==0)										// Prevent A Divide By Zero By
				{
					height=1;										// Making Height Equal One
				}

			
			glViewport(0,0,width,height);						// Reset The Current Viewport

			//glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix

			// Calculate The Aspect Ratio Of The Window
			gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();

			if(this)SetWindowPos((HWND)this->Handle.ToPointer(), NULL, 0, 0, width, height, SWP_NOZORDER | SWP_NOACTIVATE);	
			
		}
		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC) ;
		}
		private:
				HDC m_hDC;
				HGLRC m_hglrc;
				
		protected:
				~COpenGL(System::Void)
    {
        this->DestroyHandle();
    }

	GLint MySetPixelFormat(HDC hdc)
    {
        PIXELFORMATDESCRIPTOR pfd = { 
            sizeof(PIXELFORMATDESCRIPTOR),    // size of this pfd 

            1,                                // version number 

            PFD_DRAW_TO_WINDOW |              // support window 

            PFD_SUPPORT_OPENGL |              // support OpenGL 

            PFD_DOUBLEBUFFER,                 // double buffered 

            PFD_TYPE_RGBA,                    // RGBA type 

            24,                               // 24-bit color depth 

            0, 0, 0, 0, 0, 0,                 // color bits ignored 

            0,                                // no alpha buffer 

            0,                                // shift bit ignored 

            0,                                // no accumulation buffer 

            0, 0, 0, 0,                       // accum bits ignored 

            32,                               // 32-bit z-buffer     

            0,                                // no stencil buffer 

            0,                                // no auxiliary buffer 

            PFD_MAIN_PLANE,                   // main layer 

            0,                                // reserved 

            0, 0, 0                           // layer masks ignored 

        }; 
    
        GLint  iPixelFormat; 
     
        // get the device context's best, available pixel format match 

        if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
        {
            MessageBox::Show("ChoosePixelFormat Failed");
            return 0;
        }
         
        // make that match the device context's current pixel format 

        if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
        {
            MessageBox::Show("SetPixelFormat Failed");
            return 0;
        }
    
        if((m_hglrc = wglCreateContext(m_hDC)) == NULL)
        {
            MessageBox::Show("wglCreateContext Failed");
            return 0;
        }
        
        if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
        {
            MessageBox::Show("wglMakeCurrent Failed");
            return 0;
        }
    
        return 1;
    }

		};
}
