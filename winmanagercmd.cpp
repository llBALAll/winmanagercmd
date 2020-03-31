#include <Windows.h>
#include <iostream>


void correctPath (char* pathIn) {
	int i=0,c=0;
	char temp [MAX_PATH];

	for (i=0;pathIn[i] != '\0';i++) {
		temp[i+c] = pathIn[i];
		if (pathIn[i] == '\\') {
			c++;
			temp[i+c] = '\\';
		}
	}
	temp[i+c] = '\0';

	for (i=0;temp[i] != '\0';i++) {
		pathIn[i] = temp[i];
	}
	pathIn[i] = '\0';
}


int main(int argc, char** argv) {

	char programPath [MAX_PATH];
	char argumentPath [MAX_PATH];
	char programTitle [MAX_PATH];
	char Xpos [10];
	char Ypos [10];
	char Wwindow [10];
	char Hwindow [10];

	if (argc != 8) {
		printf ("\nThis program runs an application and set position/size of the program window.\n");
		printf ("\n Usage:\twinmanagercmd PROGRAM_PATH PROGRAM_ARG WINDOW_TITLE X_POSITION Y_POSITION WIDTH HEIGHT\n");
		printf ("\n Ex: winmanagercmd.exe c:\\windows\\notepad.exe c:\\teste.txt \"teste.txt - Bloco de notas\" 200 200 500 500\n");
		printf (" Obs: Case PROGRAM_PATH, PROGRAM_ARG or WINDOW_TITLE have spaces put in quotes;\n");
		printf ("      Verify the title of program window with your specific file opened to put correctly on the command line;\n");
		printf ("      It's possible to use a batch file with some command lines to open many programs with self configs of size and position;\n");
		return 1;
	}

	strcpy (programPath, argv[1]);
	strcpy (argumentPath, argv[2]);

	correctPath(programPath);
	correctPath(argumentPath);

	ShellExecuteA(NULL, "open", programPath, argumentPath, NULL, SW_SHOW);

	Sleep(500); //wait the program starts

	strcpy (programTitle, argv[3]);
	strcpy (Xpos, argv[4]);
	strcpy (Ypos, argv[5]);
	strcpy (Wwindow, argv[6]);
	strcpy (Hwindow, argv[7]);

	HWND myHandle = FindWindowA(NULL, programTitle);

	SetWindowPos(myHandle, HWND_TOP, atoi(Xpos), atoi(Ypos), atoi(Wwindow), atoi(Hwindow), SWP_SHOWWINDOW);

    return 0;
}


