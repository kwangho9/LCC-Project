/* Weditres generated include file. Do NOT edit */
#include <windows.h>
#include <lfc.h>
#define	IDD_MAINDIALOG	100
#define	IDC_LIST	101
#define	IDC_REMOVE	102
#define	IDC_STATIC	106
/*@ Prototypes @*/
#ifndef WEDIT_PROTOTYPES
#define WEDIT_PROTOTYPES
/*
 * Structure for dialog Dlg100
 */
struct _Dlg100 {
	ST_STATIC *idc_static;
	ST_BUTTON *idc_remove;
	ST_LISTBOX *idc_list;
	ST_BUTTON *idok;
	ST_BUTTON *idcancel;
	HWND hwnd;
	WPARAM wParam;
	LPARAM lParam;
};


#endif
void SetDlgBkColor(HWND,COLORREF);
BOOL APIENTRY HandleCtlColor(UINT,DWORD);
/*
 * Callbacks for dialog Dlg100
 */
HWND StartDlg100(HWND parent);
int RunDlg100(HWND parent);
void AddGdiObject(HWND,HANDLE);
BOOL WINAPI HandleDefaultMessages(HWND hwnd,UINT msg,WPARAM wParam,DWORD lParam);
/* Control: IDCANCEL*/
long Dlg100CancelSelected(ST_BUTTON *,struct _Dlg100 *);
/* Control: IDOK*/
BOOL Dlg100OkValidate(HWND hwnd);
/* Control: IDOK*/
long Dlg100OkSelected(ST_BUTTON *,struct _Dlg100 *);
/* Control: IDC_REMOVE*/
long Dlg100Push_button102Selected(ST_BUTTON *,struct _Dlg100 *);
long Dlg100Init(ST_DIALOGBOX *,struct _Dlg100 *);
void CenterWindow(HWND,int);
HFONT SetDialogFont(HWND hwnd,char *name,int size,int type);
BOOL APIENTRY Dlg100(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
extern void *GetDialogArguments(HWND);
extern char *GetDico(int,long);
/*@@ End Prototypes @@*/
