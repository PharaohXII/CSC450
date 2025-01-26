#include <iostream>
#include <string>
using namespace std;

int main() {
	//declare variable to hold user inputs
	string firstString, secondString, concatenatedString;

	cout << "Welcome to the Concatenation Program\n";

	//loop three times to take input and process
	for (int i=1; i <=3; ++i) {
		cout << "\nInput pair " << i << "\n";

		//prompt for the first string
		cout << "enter the first string: " ;
		getline(cin, firstString);

		//prompt user for the second string
		cout << "enter the second string: ";
		getline(cin,secondString);

		//concatenate the two together
		concatenatedString = firstString + " " + secondString;

		//print the concatenated result
		cout << "the concatenate string is: " << concatenatedString << "\n";
	}

	cout << "\nThanks for using the Concatenation Program\n";

	return 0;
}
