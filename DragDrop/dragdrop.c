/*@@ Wedit generated application. Written Fri Jan 15 10:11:54 2016
 @@header: c:\users\khjung\documents\lcc\dragdrop\dragdropres.h
 @@resources: c:\users\khjung\documents\lcc\dragdrop\dragdrop.rc
 Do not edit outside the indicated areas */
/*<---------------------------------------------------------------------->*/
/*<---------------------------------------------------------------------->*/
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <string.h>
#include "dragdropres.h"
/* --- The following code comes from C:\lcc\lib64\wizard\dlgbased.tpl. */
/*<---------------------------------------------------------------------->*/
#define APPNAME "File Drag & Drop."

#define FILE_FORMAT_STRING "File \"%s\"\r\n"
#define FOLDER_FORMAT_STRING "File /r \"%s\\*.*\"\r\n"


/*
Template for a dialog based application. The main procedure for this
template is the DialogFunc below. Modify it to suit your needs.
*/
/* prototype for the dialog box function. */
static BOOL CALLBACK DialogFunc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);
/*
Win main just registers a class of the same type that the dialog class, and
then calls DialogBox. Then it exits. The return value is the return value of
the dialog procedure.
*/

int APIENTRY WinMain(HINSTANCE hinst, HINSTANCE hinstPrev, LPSTR lpCmdLine, int nCmdShow)
{
#if 0
	WNDCLASS wc;
	INITCOMMONCONTROLSEX cc;

	memset(&wc,0,sizeof(wc));
	wc.lpfnWndProc = DefDlgProc;
	wc.cbWndExtra = DLGWINDOWEXTRA;
	wc.hInstance = hinst;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
	wc.lpszClassName = "dragdrop";
	RegisterClass(&wc);
	memset(&cc,0,sizeof(cc));
	cc.dwSize = sizeof(cc);
	cc.dwICC = 0xffffffff;
	InitCommonControlsEx(&cc);
#else
	InitCommonControls();
#endif

	return DialogBox(hinst, MAKEINTRESOURCE(IDD_MAINDIALOG), NULL, (DLGPROC) DialogFunc);

}

/*
You should add your initialization code here. This function will be called
when the dialog box receives the WM_INITDIALOG message.
*/
static int InitializeApp(HWND hDlg,WPARAM wParam, LPARAM lParam)
{
	return 1;
}

/*
This is the main function for the dialog. It handles all messages. Do what your
application needs to do here.
*/
HWND hLb;
static BOOL CALLBACK DialogFunc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
	/* This message means the dialog is started but not yet visible.
	   Do All initializations here 
        */
	case WM_INITDIALOG:
		InitializeApp(hwndDlg,wParam,lParam);
		SetWindowText(hwndDlg, APPNAME);
		hLb = GetDlgItem(hwndDlg, IDC_LIST);
		return TRUE;
	/* By default, IDOK means close this dialog returning 1, IDCANCEL means
           close this dialog returning zero
        */
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
			case IDOK:
//				EndDialog(hwndDlg,1);
			{
				// copy list
				char*data;
				// make variables big enough for worst case scenario
				char temp[(max(sizeof(FOLDER_FORMAT_STRING),sizeof(FILE_FORMAT_STRING))+MAX_PATH+1)],lvtext[MAX_PATH+1];
				HGLOBAL hg;
				DWORD len,i,n;
				
				n=SendMessage(hLb,LB_GETCOUNT,0,0);
				len = sizeof(temp)*n;

				hg = GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE|GMEM_ZEROINIT,len);
				if (hg == NULL)
				{
					MessageBox(hwndDlg, "GlobalAlloc() error!", APPNAME, MB_OK);
					return FALSE;
				}					
				
				data = (char*)GlobalLock(hg);

				for (i=0;i<n;i++)
				{
					SendMessage(hLb,LB_GETTEXT,i,(long)lvtext);
					
					if(GetFileAttributes(lvtext)&FILE_ATTRIBUTE_DIRECTORY)
					{
						wsprintf(temp, FOLDER_FORMAT_STRING, lvtext);
					}
					else
					{
						wsprintf(temp, FILE_FORMAT_STRING, lvtext);
					}

					lstrcat(data,temp);
				}

				MessageBox(hwndDlg, data, APPNAME, MB_OK);

				GlobalUnlock(hg);

				if (!OpenClipboard(hwndDlg))
				{
					GlobalFree(hg);
					MessageBox(hwndDlg, "Could not copy to clipboard!", APPNAME, MB_OK);
					return FALSE;
				}
					
				
				if (!EmptyClipboard())
				{
					GlobalFree(hg);
					CloseClipboard();
					MessageBox(hwndDlg, "Could not copy to clipboard!", APPNAME, MB_OK);
					return FALSE;
				}
				
				if (!SetClipboardData(CF_TEXT, hg))
				{
					CloseClipboard();
					GlobalFree(hg);
					MessageBox(hwndDlg, "Could not copy to clipboard!", APPNAME, MB_OK);
					return FALSE;
				}
				
				CloseClipboard();
				
				/* "The application can read the data, but must not 
				 free the handle or leave it locked" */

				break;
			}
				return 1;
			case IDCANCEL:
				EndDialog(hwndDlg,0);
				return 1;
		}
		break;
        /* By default, WM_CLOSE is equivalent to CANCEL */
	case WM_CLOSE:
		EndDialog(hwndDlg,0);
		return TRUE;
	case WM_DROPFILES:
#if 0
		{
			HANDLE hDrop=(HANDLE) wParam;
			DWORD len;
			char filename[MAX_PATH];
			UINT i,n;

			n=DragQueryFile(hDrop,0xFFFFFFFF,filename,MAX_PATH);
		
			for(i=0;i<n;i++)
			{					
				DragQueryFile(hDrop,i,filename,MAX_PATH);					
				SendMessage(hLb,LB_ADDSTRING,0,(long)filename);
			}
			
			DragFinish(hDrop);
		}
#else
		SendMessage(hLb,LB_ADDSTRING,0,(long)"c:\\Test");
#endif
		MessageBox(hwndDlg, "WM_DROPFILES Message!", APPNAME, MB_OK);
		break;
	
	}
	return FALSE;
}
