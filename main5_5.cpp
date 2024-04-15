#include <iostream>
#include <fstream>



using namespace std;

int main() 
{

	fstream file(__FILE__); 
	
	cout.width(11);
	cout << "CHAR ";
	cout.width(15);
	cout << " NUMBER OF OCCURRENCES\n\n";

	if (file.is_open())
	{
		int letterCount[26] = { 0 };
		char letter;

		while (file.get(letter))
		{

			if (islower(letter)) 
			{
				letterCount[letter - 'a']++;
			}
		}

		for (int i = 0; i < 26; ++i)
		{
			cout.width(8);
			cout << char('a' + i);
			cout.width(10);
			cout << letterCount[i] << "\n";
		}

		file.close();
	}
	else
	{
		cout << "Error opening file";
	}

	return 0;
}