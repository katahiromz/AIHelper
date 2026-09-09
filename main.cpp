// main.cpp --- AI Helper demo
// Author: katahiromz
// License: MIT
#include "AIHelper.h"

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
