#include <windows.h>
#include <cstring>

#ifdef _M_IX86
#pragma comment(linker, "/EXPORT:DeadbydaylightWallpaper=_DeadbydaylightWallpaper@16")
#endif

extern "C" __declspec(dllexport)
void CALLBACK DeadbydaylightWallpaper(
    HWND hwnd,
    HINSTANCE hinst,
    LPSTR lpszCmdLine,
    int nCmdShow
)
{
    const char* wallpaper =
        "C:\\Users\\ees\\Pictures\\DeadbydaylightWallpaper.jpg";

    HKEY hKey;

    if (RegOpenKeyExA(
        HKEY_CURRENT_USER,
        "Control Panel\\Desktop",
        0,
        KEY_SET_VALUE,
        &hKey
    ) == ERROR_SUCCESS)
    {
        RegSetValueExA(
            hKey,
            "Wallpaper",
            0,
            REG_SZ,
            (const BYTE*)wallpaper,
            (DWORD)(strlen(wallpaper) + 1)
        );

        RegCloseKey(hKey);
    }

    SystemParametersInfoA(
        SPI_SETDESKWALLPAPER,
        0,
        (PVOID)wallpaper,
        SPIF_UPDATEINIFILE | SPIF_SENDCHANGE
    );
}