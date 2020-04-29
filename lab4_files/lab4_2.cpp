#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

void CallChild(char tr[], int n);
void LongText(string str, int n);
void ShortText(string str, int n);

int main (int argc, char *argv[])
{
	cout << "Input your text here" << endl;
	string str;
	getline(cin, str);
	int n = str.length();

	if (n > 10)
		LongText(str, n);
	else
		ShortText(str, n);

	exit(0);
}

void CallChild(char tr[], int n)
{
	int* n_ptr = &n;
	int pid = fork();
        if (pid <  0)
        {
                cout << "Error" << endl;
                exit (1);
        }
        else if (pid > 0)
        {
                int status;
                waitpid(pid, &status, 0); //wait 4 child 2 change st8
        }
        else
        {
                execl("lab4_1", tr, n_ptr, NULL);
        }
}

void LongText(string str, int n)
{
	int s = 0;
	int c = 9;
	for (int i = 9; i < n; i++)
	{
		c++;
		if (c == 1)
			s = i;
		if ((str[i] == ' ' && c > 9) || i == n - 1)
		{
			char* arr = new char[c];
			int k = 0;
			for (int j = s; j <= i; j++)
			{
				arr[k] = str[j];
				k++;
			}
			CallChild(arr, c);
			c = 0;
			delete[] arr;
		}
	}
} 

void ShortText(string str, int n)
{
	char* arr = new char[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = str[i];
	}
	CallChild(arr, n);
	delete[] arr;
}
