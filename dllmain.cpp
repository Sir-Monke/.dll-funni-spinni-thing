#include <iostream>
#include <windows.h>
#include "pch.h"

using namespace std;

struct Player {
	char unknown1[0x4];
	float x;
	float y;
	float z;
	char unknown2[0x30];
	float yaw;
	float pitch;
};

Player* player = NULL;

void mainThread() {
	while (true) {
		DWORD* playerBase = (DWORD*)(0X50F4F4);
		player = (Player*)(*playerBase);
		player->yaw++;
	}
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)mainThread, NULL, 0, NULL);
		MessageBoxW(NULL,NULL,NULL,NULL);
	}
	return true;
}

