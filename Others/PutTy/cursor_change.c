#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable : 4996)

void init_dcb(DCB *dcbSerialParams);
void init_timeouts(COMMTIMEOUTS *timeouts);
void do_normal(HANDLE *hSerial, INPUT_RECORD *rec, DWORD *dw);
void do_click(HANDLE *hSerial);

int main() {
	HANDLE hSerial;
	INPUT_RECORD rec;
	DWORD dw;
	DCB dcbSerialParams = { 0 };
	COMMTIMEOUTS timeouts = { 0 }; // exam_4 & exam_5

	hSerial = CreateFile(L"COM2", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hSerial == INVALID_HANDLE_VALUE) {
		if (GetLastError() == ERROR_FILE_NOT_FOUND)
			printf("ERROR!! COM2 PORT NOT FOUND\n");
		printf("ERROR!! FAIIED TO ACCESS TO COM2 SUCCESSFULLY\n");
	}

	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	if (!GetCommState(hSerial, &dcbSerialParams)) //Parameter Error
		printf("ERROR!! FAIIED TO GET SERIAL PARAMETERS\n");

	init_dcb(&dcbSerialParams);
	if (!SetCommState(hSerial, &dcbSerialParams))  // When the Port is not established well
		printf("ERROR, Setting serial port state");

	init_timeouts(&timeouts);
	if (!SetCommTimeouts(hSerial, &timeouts)) { //timeout
		printf("ERROR!! Time Out\n");
		return (1);
	}
	while (1) {// during normal operations?
		do_normal(&hSerial, &rec, &dw);
		if (rec.EventType == MOUSE_EVENT && (rec.Event.MouseEvent.dwEventFlags & DOUBLE_CLICK))
			do_click(&hSerial);
	}
	CloseHandle(hSerial);
	return 0;
}

void init_dcb(DCB *dcbSerialParams){
	dcbSerialParams->BaudRate = CBR_57600;
	dcbSerialParams->ByteSize = 8;
	dcbSerialParams->Parity = NOPARITY;
	dcbSerialParams->StopBits = ONESTOPBIT;
}

void init_timeouts(COMMTIMEOUTS *timeouts){
	timeouts->ReadIntervalTimeout = 50;
	timeouts->ReadTotalTimeoutConstant = 5000; // �̰� �ʹ� ª���� �̻��� ���� �Էµ�
	timeouts->ReadTotalTimeoutMultiplier = 10;
	timeouts->WriteTotalTimeoutConstant = 50;
	timeouts->WriteTotalTimeoutMultiplier = 10;
}

void do_normal(HANDLE *hSerial, INPUT_RECORD *rec, DWORD *dw) {
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE); // exam_3
	char cor_x[5] = { 0, };
	char cor_y[5] = { 0, };
	POINT a;
	unsigned long bytes_written;
	GetCursorPos(&a); // POINT's Position
	sprintf(cor_x, "%d", a.x); // sprintf() : int �� ��ǥ���� ���ڿ��� �ʱ�ȭ����
	sprintf(cor_y, "%d", a.y); // sprintf() : int �� ��ǥ���� ���ڿ��� �ʱ�ȭ����

	WriteFile(hSerial, "Xpos : ", 8, &bytes_written, NULL);
	for (int i = 0; i < 4; i++)
		WriteFile(hSerial, &cor_x[i], 1, &bytes_written, NULL); // ���ڿ��� ��ǥ���� ������ ������ ���ڿ��� ���� �ϳ��� ���

	WriteFile(hSerial, " Ypos : ", 9, &bytes_written, NULL);
	for (int i = 0; i < 4; i++)
		WriteFile(hSerial, &cor_y[i], 1, &bytes_written, NULL); // ���ڿ��� ��ǥ���� ������ ������ ���ڿ��� ���� �ϳ��� ���

	WriteFile(hSerial, "\n\r", 4, &bytes_written, NULL); // \n\r �ؾ� �� �ٲ��� ��!!
	Sleep(500); // �ʹ� ������ ���ͼ� ��ǻ�� �߰ſ������ �߰�

	DWORD Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hIn, Mode))
		printf("ERROR at SetConsoleMode\n");
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hIn, Mode))
		printf("ERROR at SetConsoleMode\n");

	ReadConsoleInput(hIn, rec, 1, dw); 
}

void do_click(HANDLE *hSerial){
	unsigned long bytes_read, bytes_written;
	WriteFile(hSerial, "Input your * location\n\r", 24, &bytes_written, NULL);
	WriteFile(hSerial, "Xpos : ", 7, &bytes_written, NULL);
	
	char x_input, y_input;
	COORD tmp;
	tmp.X = 0; tmp.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmp);

	while (1) { //x_input
		ReadFile(hSerial, &x_input, 1, &bytes_read, NULL);
		WriteFile(hSerial, &x_input, 1, &bytes_written, NULL);
		if (bytes_read == 1 && x_input >= '0' && x_input <= '9')
			tmp.X = (tmp.X * 10) + (x_input - '0');
		else
			break;
	}

	WriteFile(hSerial, "Ypos : ", 7, &bytes_written, NULL);

	while (1) { //y_input
		ReadFile(hSerial, &y_input, 1, &bytes_read, NULL);
		WriteFile(hSerial, &y_input, 1, &bytes_written, NULL);
		if (bytes_read == 1 && y_input >= '0' && y_input <= '9') 
			tmp.Y = (tmp.Y * 10) + (y_input - '0');
		else
			break;
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmp);

	WriteFile(hSerial, "\n\r", 4, &bytes_written, NULL);
	fputc('*', stdout);
}