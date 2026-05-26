#include<iostream>
using namespace std;
void diamond(int n, char op, char cfill);

int main()
{
	int n;
	cin >> n;
	diamond(n, '*', ' ');
}
void diamond(int n, char op, char cfill)
{
	
	
	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < n - j; k++)
		{
			cout << op;
		}
		for (int k = 0; k < j * 2; k++)
		{
			cout << cfill;
		}
		for (int k = 0; k < n - j; k++)
		{
			cout << op;
		}
		cout << endl;
	}
	for (int j = 1; j < n; j++)
	{
		for (int k = 0; k < j + 1; k++)
		{
			cout << op;
		}
		for (int k = 0; k < (n - j - 1) * 2; k++)
		{
			cout << cfill;
		}
		for (int k = 0; k < j + 1; k++)
		{
			cout << op;
		}
		cout << endl;
	}
	
}

