
// Fibonacci_AppDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "Fibonacci_App.h"
#include "Fibonacci_AppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Fibonacci.h"
#include <string>
#include "Convertidor.h"

using namespace std;


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedIncrementar();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDIncrementar, &CAboutDlg::OnBnClickedIncrementar)
END_MESSAGE_MAP()


// Cuadro de diálogo de CFibonacciAppDlg

Fibonacci fibo;
Convertidor convertidor;

CFibonacciAppDlg::CFibonacciAppDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_FIBONACCI_APP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CFibonacciAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFibonacciAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CFibonacciAppDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDIncrementar, &CFibonacciAppDlg::OnBnClickedIncrementar)
	ON_BN_CLICKED(IDecrementar, &CFibonacciAppDlg::OnBnClickedecrementar)
END_MESSAGE_MAP()


// Controladores de mensajes de CFibonacciAppDlg

BOOL CFibonacciAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CFibonacciAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CFibonacciAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CFibonacciAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAboutDlg::OnBnClickedIncrementar()
{
		 
}


void CFibonacciAppDlg::OnBnClickedOk()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	CDialogEx::OnOK();
}


void CFibonacciAppDlg::OnBnClickedIncrementar()
{
	fibo.siguiente();
	string binario = convertidor.aBinario(fibo.getvalor());
	string hexadecimal = convertidor.aHexadecimal(fibo.getvalor());
	CString cadenaB(binario.c_str());
	SetDlgItemText(IDBinario, cadenaB);
	CString cadenaH(hexadecimal.c_str());
	SetDlgItemText(IDHexadecimal, cadenaH);
	
	// TODO: Agregue aquí su código de controlador de notificación de control
}


void CFibonacciAppDlg::OnBnClickedecrementar()
{
	fibo.anterior();
	string binario = convertidor.aBinario(fibo.getvalor());
	string hexadecimal = convertidor.aHexadecimal(fibo.getvalor());
	CString cadenaB(binario.c_str());
	SetDlgItemText(IDBinario, cadenaB);
	CString cadenaH(hexadecimal.c_str());
	SetDlgItemText(IDHexadecimal, cadenaH);
}

	// TODO: Agregue aquí su código de controlador de notificación de control

