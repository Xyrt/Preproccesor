#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
	WIN32_FIND_DATAA found;
	HANDLE findResult = FindFirstFileA("D:\\ll\\*.*", &found);

	if (findResult == INVALID_HANDLE_VALUE)
	{
		printf("file not found\n");
		return 1;
	}

	do
	{
		if (strcmp(found.cFileName, ".") == 0 || strcmp(found.cFileName, "..") == 0)
		{
			continue;
		}

		bool isDirectory = found.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
		printf("%d directory found ", (isDirectory ? "Folder" : "File"));
		printf("file found: \"%s\".\n", found.cFileName);

	} while (FindNextFileA(findResult, &found));
	FindClose(findResult);
}

/*#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
	WIN32_FIND_DATAA found;
	HANDLE findResult =
		FindFirstFileA(
			"d:\\ll\\*.recipe",
			&found);

	if (findResult == INVALID_HANDLE_VALUE)
	{
		printf("Files not found.");
		return 1;
	}
	do
	{
		if (strcmp(found.cFileName, ".") == 0 ||
			strcmp(found.cFileName, "..") == 0)
		{
			continue;
		}

		SYSTEMTIME time;
		FileTimeToSystemTime(
			&found.ftLastAccessTime, &time);
		printf("[%d.%d.%d] ", time.wDay, time.wMonth, time.wYear);
		bool isDirectory =
			found.dwFileAttributes &
			FILE_ATTRIBUTE_DIRECTORY;
		printf("%s found: \"%s\".\n",
			(isDirectory ? "Folder" : "File"),
			found.cFileName);
	} while (FindNextFileA(findResult,
		&found));

	FindClose(findResult);
}*/

/*#define НАЧАЛО_ПРОГРАММЫ int main()
#define НАЧАЛО_БЕСПРЕДЕЛА {
#define КОНЕЦ_БЕСПРЕДЕЛА }
#define ЦИКЛ_ЦИКЛ_МОТОЦИКЛ while
#define ПРАВДИВОСТЬ true
#define НАПИСАТЬ_КАКУ printf
#define СКОБКА_ЛЕВО (
#define СКОБКА_ПРАВО )
#define О_ПРИВЕТ "Hello"
#define АМИНЬ ;



НАЧАЛО_ПРОГРАММЫ
НАЧАЛО_БЕСПРЕДЕЛА
 ЦИКЛ_ЦИКЛ_МОТОЦИКЛ СКОБКА_ЛЕВО ПРАВДИВОСТЬ СКОБКА_ПРАВО
	НАЧАЛО_БЕСПРЕДЕЛА
		НАПИСАТЬ_КАКУ СКОБКА_ЛЕВО О_ПРИВЕТ СКОБКА_ПРАВО АМИНЬ
КОНЕЦ_БЕСПРЕДЕЛА
КОНЕЦ_БЕСПРЕДЕЛА

#include <stdbool.h>
#include <Windows.h>

// arg (foo) -> #arg = "foo"

#define LOG_FN_START printf("[%d] %s\n", time(0), "foo start");
#define LOG_FN_FINISH printf("[%d] %s\n", time(0), "foo end");

void foo();
void foo1();

void foo()
{
	LOG_FN_START

	Sleep(1000);
	foo1();

	LOG_FN_FINISH
}

void foo1()
{
	LOG_FN_START

	Sleep(1000);

	LOG_FN_FINISH
}

int main()
{
	LOG_FN_START

	foo();

	LOG_FN_FINISH
}

