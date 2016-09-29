/* NOTE: Don't #define WIN32_LEAN_AND_MEAN */
#include <windows.h>
#include "resource.h"

/* Dialog procedure prototype */
INT_PTR CALLBACK TheDialogProc(HWND, UINT, WPARAM, LPARAM);

/* Entrypoint for the Win32 app */
int WINAPI WinMain(HINSTANCE inst, HINSTANCE prev_inst, LPSTR cmd_line, int show_cmd)
{
	/* Run the dialog, blocking until it calls EndDialog */
	DialogBox(NULL, MAKEINTRESOURCE(IDD_DROPTEST), NULL, TheDialogProc);
	return 0;
}

/* Dialog procedure */
INT_PTR CALLBACK TheDialogProc(HWND hdialog, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
		{
			/* Return TRUE: System should select focus */
			return TRUE;
		}
	case WM_CLOSE:
		{
			/* Close request: Terminate the dialog box */
			EndDialog(hdialog, 0);
			return TRUE;
		}
	case WM_COMMAND:
		{
			if (HIWORD(wparam) == BN_CLICKED && LOWORD(wparam) == IDCANCEL)
			{
				/* "Close" button was clicked. */
				SendMessage(hdialog, WM_CLOSE, 0, 0);
				return TRUE;
			}
			break;
		}
	}
	/* Return FALSE, i.e. the system's default handler should take this message */
	return FALSE;
}
