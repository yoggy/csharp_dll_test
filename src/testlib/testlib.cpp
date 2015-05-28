#pragma once

#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include "testlib.h"

TESTLIB_DLL_API void PrintDebugInfo()
{
#ifdef _WIN64
#ifdef _DEBUG
	printf("PrintDebugInfo() : 64bit, debug\n");
#else
	printf("PrintDebugInfo() : 64bit, release\n");
#endif
#else
#ifdef _DEBUG
	printf("PrintDebugInfo() : 32bit, debug\n");
#else
	printf("PrintDebugInfo() : 32bit, release\n");
#endif
#endif
}

TESTLIB_DLL_API char * CreateBuffer(UINT32 size)
{
	char *buf = (char*)malloc(size);

	printf("FillBuffer() ret=%p\n", buf);
	return buf;
}

TESTLIB_DLL_API void FillBuffer(char * buf, UINT32 size)
{
	printf("FillBuffer() buf=%p, size=%d\n", buf, size);

	if (buf == NULL) return;
	SetBuffer(buf, size, 0);
}

TESTLIB_DLL_API void SetBuffer(char * buf, int size, char c)
{
	printf("SetBuffer() buf=%p, size=%d, c=%02x\n", buf, size, c);

	if (buf == NULL) return;
	for (int i = 0; i < size; ++i) {
		buf[i] = c;
	}
}

TESTLIB_DLL_API void PrintBuffer(char * buf, UINT32 size)
{
	printf("PrintBuffer() buf=%p\n", buf);

	if (buf == NULL) return;
	for (unsigned int i = 0; i < size; ++i) {
		printf("  %d : %02x\n", i, buf[i]);
	}
}

TESTLIB_DLL_API void ReleaseBuffer(char *buf)
{
	printf("ReleaseBuffer() buf=%p\n", buf);

	if (buf == NULL) return;
	free(buf);
}
