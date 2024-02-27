#include <Windows.h>
#include <iostream>
#include <string>
#include <codecvt> // for std::wstring_convert
#include <locale>  // for std::wstring_convert

std::wstring StringToWideString(const std::string &narrowString)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(narrowString);
}

// Function to open a folder
void OpenFolder(const std::string &folderPath)
{
    std::wstring widePath = StringToWideString(folderPath);
    ShellExecuteW(NULL, L"open", widePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

// Function to open an application
void OpenApplication(const std::string &appPath)
{
    std::wstring widePath = StringToWideString(appPath);
    ShellExecuteW(NULL, NULL, widePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

// Function to register a hotkey
bool RegisterHotkey(HWND hWnd, int id, UINT fsModifiers, UINT vk)
{

    return ::RegisterHotKey(hWnd, id, fsModifiers, vk);
}

// Function to process hotkey messages
void ProcessHotkey(int hotkeyID)
{
    switch (hotkeyID)
    {
    case 1:
        // Hotkey 1: Open folder for Clips
        OpenFolder("C:\\Medal\\Clips");
        break;
    case 2:
        // Hotkey 2: Open application, Steam
        OpenApplication("D:\\Steam\\steam.exe");
        break;
    case 3:
        // Hotkey 3: Open application, Obs
        OpenApplication("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\OBS Studio\\OBS Studio (64bit).lnk");
        break;
    case 4:
        // Hotkey 4: Open folder, Downloads
        OpenFolder("C:\\Users\\Jaynik Parsotomo\\Downloads");
        break;
    case 5:
        // Hotkey 5: Open application
        OpenApplication("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Firefox.lnk");
        break;
    }
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Register a hotkey (Ctrl + Alt + C) to open the clips folder
    if (!RegisterHotkey(NULL, 1, MOD_CONTROL | MOD_ALT, 'C'))
    {
        std::cerr << "Failed to register hotkey: " << GetLastError() << std::endl;
        return 1;
    }

    // Register a hotkey (Ctrl + Alt + S) to open Steam
    if (!RegisterHotkey(NULL, 2, MOD_CONTROL | MOD_ALT, 'S'))
    {
        std::cerr << "Failed to register hotkey: " << GetLastError() << std::endl;
        return 1;
    }

    // Register a hotkey (Ctrl + Alt + O) to open obs studio
    if (!RegisterHotkey(NULL, 3, MOD_CONTROL | MOD_ALT, 'O'))
    {
        std::cerr << "Failed to register hotkey: " << GetLastError() << std::endl;
        return 1;
    }

    // Register a hotkey (Ctrl + Alt + D) to open the dowload folder
    if (!RegisterHotkey(NULL, 4, MOD_CONTROL | MOD_ALT, 'D'))
    {
        std::cerr << "Failed to register hotkey: " << GetLastError() << std::endl;
        return 1;
    }

    // Register a hotkey (Ctrl + Alt + F) to open Firefox
    if (!RegisterHotkey(NULL, 5, MOD_CONTROL | MOD_ALT, 'F'))
    {
        std::cerr << "Failed to register hotkey: " << GetLastError() << std::endl;
        return 1;
    }

    std::cout << "Hotkey registered successfully!" << std::endl;

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (msg.message == WM_HOTKEY)
        {
            // Process hotkey message
            ProcessHotkey(msg.wParam);
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Unregister hotkeys before exiting
    UnregisterHotKey(NULL, 1);
    UnregisterHotKey(NULL, 2);

    return 0;
}