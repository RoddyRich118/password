#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string password = "PineapplePen";
	string enteredPassword;
	string choice;
	string line;
	int attempts = 0;
	bool unlocked = false;

	cout << "Welcome to my Secret Archive!" << endl;
	cout << "Do you wish to access the archive? (yes/no): ";
	cin >> choice;

	if (choice == "yes")
	{
		// Allow up to three password attempts
		while (attempts < 3 && !unlocked)
		{
			cout << "Enter the archive password: ";
			cin >> enteredPassword;

			if (enteredPassword == password)
			{
				unlocked = true;
				cout << "Access granted! Welcome in." << endl;
			}
			else
			{
				attempts++;
				cout << "Incorrect password." << endl;

				if (attempts < 3)
				{
					cout << "Attempts remaining: "
						<< 3 - attempts << endl;
				}
			}
		}

		if (unlocked)
		{
		
			ifstream file("SecretArchive.txt");

			if (file.is_open())
			{
				cout << "\n--- SECRET ARCHIVE ---" << endl;

				while (getline(file, line))
				{
					cout << line << endl;
				}

				file.close();
			}
			else
			{
				cout << "Error: Could not open SecretArchive.txt"
					<< endl;
			}
		}
		else
		{
			cout << "Too many incorrect attempts. Access denied."
				<< endl;
		}
	}
	else
	{
		cout << "Archive cancelled. Goodbye!" << endl;
	}

	return 0;
}