// main.cpp --- AI Helper demo
// Author: katahiromz
// License: MIT
#include <windows.h>
#include <string>
#include <map>
#include <vector>
#include "AIHelper.h"

WCHAR xg_szUIFont[LF_FACESIZE] = L"";

BOOL XgIsUserJapanese(VOID) noexcept
{
	return (PRIMARYLANGID(GetUserDefaultLangID()) == LANG_JAPANESE);
}

INT WINAPI
WinMain(HINSTANCE   hInstance,
        HINSTANCE   hPrevInstance,
        LPSTR       lpCmdLine,
        INT         nCmdShow)
{
	xg_hAIHelperInst = hInstance;

	if (!Helper_Open(nullptr))
	{
		MessageBoxA(nullptr, "AI Helper failed.", nullptr, MB_ICONERROR);
		return 0;
	}

	MSG msg;
	while (GetMessageW(&msg, nullptr, 0, 0))
	{
		if (xg_hwndAIHelper && IsDialogMessageW(xg_hwndAIHelper, &msg))
			continue;
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return 0;
}
