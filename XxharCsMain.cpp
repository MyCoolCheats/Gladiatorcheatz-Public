#include <Windows.h>
#include "Install.hpp"

BOOL __stdcall DllMain(HINSTANCE mod, DWORD dwReason, LPVOID res)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:

		DisableThreadLibraryCalls(mod);

		installSF();

		break;

	case DLL_PROCESS_DETACH:

		uninstallSF();

		break;
	}
	return TRUE;
}
