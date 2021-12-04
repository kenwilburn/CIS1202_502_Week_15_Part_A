/*
 * Kenneth Wilburn
 * CIS1202.502
 * 12/05/2021
 * Week 15 - Exceptions, Templates And Standard Template Library (STL) - Assignment #15a
 */

#include <iostream>

using namespace std;

// Class To Handle Invalid Character Exceptions
class InvalidCharacterException_C {

};

// Class To Handle Invalid Range Exceptions
class InvalidRangeException_C {

};

// Class To Handle Case Conversion Exception
class CaseTransitionException_C {

};

// Function Prototype
char Character_Offset(char, int);

// The "main" Function
int main() {
	cout << Character_Offset('a', 1) << endl << endl;
	cout << Character_Offset('a', -1) << endl << endl;
	cout << Character_Offset('Z', -1) << endl << endl;
	cout << Character_Offset('Z', 1) << endl << endl;
	cout << Character_Offset('?', 5) << endl << endl;
	cout << Character_Offset('A', 32) << endl << endl;
	cout << Character_Offset('K', 11) << endl << endl;
	cout << Character_Offset('w', -16) << endl << endl;
	system("pause");
	return 0;
}

// Function To Determine The Character Offset Value
char Character_Offset(char providedCharacter, int offsetValue) {
	int providedCharacterAsciiValue = int(providedCharacter);
	int offsetAsciiValue = providedCharacterAsciiValue + offsetValue;
	cout << "Character: '" << providedCharacter << "' | Offset Value: " << offsetValue << " | Produces: ";

	try {
		if (providedCharacterAsciiValue < 65 || (providedCharacterAsciiValue > 90 && providedCharacterAsciiValue < 97) || providedCharacterAsciiValue > 122) {
			throw InvalidCharacterException_C();
		}
		else if (offsetAsciiValue < 65 || (offsetAsciiValue > 90 && offsetAsciiValue < 97) || offsetAsciiValue > 122) {
			throw InvalidRangeException_C();
		}
		else if ((offsetAsciiValue >= 65 && offsetAsciiValue <= 90 && providedCharacterAsciiValue >= 95 && providedCharacterAsciiValue <= 122) || (offsetAsciiValue >= 95 && offsetAsciiValue <= 122 && providedCharacterAsciiValue >= 65 && providedCharacterAsciiValue <= 90)) {
			throw CaseTransitionException_C();
		}
		else {
			return char(offsetAsciiValue);
		}
	}
	catch (InvalidCharacterException_C) {
		cout << "Invalid Character Exception!";
		return ' ';
	}
	catch (InvalidRangeException_C) {
		cout << "Invalid Range Exception!";
		return ' ';
	}
	catch (CaseTransitionException_C) {
		cout << "Case Changes Are Not Allowed!";
		return ' ';
	}
}