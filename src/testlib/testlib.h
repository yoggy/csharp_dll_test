#pragma once

#ifdef TESTLIB_EXPORTS
#define TESTLIB_DLL_API __declspec(dllexport)
#else
#define TESTLIB__DLL_API __declspec(dllimport)

#ifdef _WIN64
#ifdef _DEBUG
#pragma comment(lib, "testlib_x64D.lib")
#else
#pragma comment(lib, "testlib_x64.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment(lib, "testlilb_x86D.lib")
#else
#pragma comment(lib, "testlilb_x86.lib")
#endif
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

	TESTLIB_DLL_API void PrintDebugInfo();
	TESTLIB_DLL_API char * CreateBuffer(UINT32 size);
	TESTLIB_DLL_API void FillBuffer(char * buf, UINT32 size);
	TESTLIB_DLL_API void SetBuffer(char * buf, int size, char c);
	TESTLIB_DLL_API void PrintBuffer(char * buf, UINT32 size);
	TESTLIB_DLL_API void ReleaseBuffer(char *buf);

#ifdef __cplusplus
}
#endif