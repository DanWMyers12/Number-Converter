#include <iostream>
#include <string>

using namespace std;

const int maxArray = 100;
struct Cnumber {
	char numStart[maxArray];
	char numEnd[maxArray];
	int startBase;
	int base10;
	int endBase;
	int startArray;
	int endArray;
};

Cnumber base2base(Cnumber); // takes original base and num to base ten then finds conversion via mod divison

int charCoder(char a); // takes character of string and returns a base ten value

char charCoder(int a); // takes base ten value and return char for digit in new base

int ipow(int a, int b); //integer power function



int main()
{
	string input;
	Cnumber convertMe;
	convertMe.startBase = 0;
	convertMe.endBase = 0;
	char loop;

	
	// Get input from user
	// Continue loop
	do
	{
		//input validation loop
		do 
		{
			cout << endl << "  Please enter the original number base(2-16):  ";
			cin >> convertMe.startBase;
			cout << endl << "  Please enter the desired number base(2-16):  ";
			cin >> convertMe.endBase;
		} while ((convertMe.startBase > 1 && convertMe.startBase < 17)|| (convertMe.endBase > 1 && convertMe.endBase < 17));

		cout << endl << "  Please enter the number to convert:  ";
		cin >> input;

		//copy string into array for easy handling
		convertMe.startArray = input.length();
		strcpy_s(convertMe.numStart, input.c_str());

		//reverse array order so that array place matches digit^power
		for (int i = 0; i < convertMe.startArray / 2; i++)
		{
			char temp = convertMe.numStart[i];
			convertMe.numStart[i] = convertMe.numStart[(convertMe.startArray - 1) - i];
			convertMe.numStart[(convertMe.startArray - 1) - i] = temp;
		}
		convertMe = base2base(convertMe); //converts number

		//Print result
		cout << endl << endl << "The number ";

		for (int i = convertMe.startArray - 1; i >= 0; i--)
		{
			cout << convertMe.numStart[i];
		}

		cout << ", base " << convertMe.startBase << ", is expressed in base " << convertMe.endBase << " as ";

		for (int i = convertMe.endArray - 1; i >= 0; i--)
		{
			cout << convertMe.numEnd[i];
		}

		cout << endl << "Would you like to convert another Number? (y/n)  :";
		cin >> loop;
		
		//Continue validation loop
		while ((loop != 'y' && loop != 'Y') && (loop != 'N' && loop != 'n'))
		{
			cout << endl << endl << "I'm sorry, I didn't understand..." << endl;
			cout << "Would yo like to convert another Number? (y/n)  :";
			cin >> loop;
		}
		if (loop == 'N' || loop == 'n')
			cout << endl << endl << "Thanks for using Number Converter. GoodBye!";
	} while (loop != 'N' && loop != 'n');
	

	
	cout << endl << endl;
	system("PAUSE");

	return 0;
}

Cnumber base2base(Cnumber convertMe)
{
	//convert to base 10 from original
	convertMe.base10 = 0;
	for (int i = 0; i < convertMe.startArray; i++)
	{
		convertMe.base10 += charCoder(convertMe.numStart[i])*ipow(convertMe.startBase,i);
	}

	//convert to intended base from base 10
	int dividend = convertMe.base10; //object preservation
	int mod;
	convertMe.endArray = 0;//do while counter -- later serves to limit array readout
	do
	{
		mod = dividend % convertMe.endBase;
		convertMe.numEnd[convertMe.endArray] = charCoder(mod);
		if (dividend != 0)
		{
			dividend /= convertMe.endBase;
			++convertMe.endArray;
		}
		
	} while (dividend != 0);
	return convertMe;
}


int charCoder(char a) // takes character of string and returns a base ten value
{
	switch (a)
	{
	case '0':
		return 0;
		break;
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	case 'A':
	case 'a':
		return 10;
		break;
	case 'B':
	case 'b':
		return 11;
		break;
	case 'C':
	case 'c':
		return 12;
		break;
	case 'D':
	case 'd':
		return 13;
		break;
	case 'E':
	case 'e':
		return 14;
		break;
	case 'F':
	case 'f':
		return 15;
		break;
	}
}
char charCoder(int a) // takes character of string and returns a base ten value
{
		switch (a)
		{
		case 0:
			return '0';
			break;
		case 1:
			return '1';
			break;
		case 2:
			return '2';
			break;
		case 3:
			return '3';
			break;
		case 4:
			return '4';
			break;
		case 5:
			return '5';
			break;
		case 6:
			return '6';
			break;
		case 7:
			return '7';
			break;
		case 8:
			return '8';
			break;
		case 9:
			return '9';
			break;
		case 10:
			return 'A';
			break;
		case 11:
			return 'B';
			break;
		case 12:
			return 'C';
			break;
		case 13:
			return 'D';
			break;
		case 14:
			return 'E';
			break;
		case 15:
			return 'F';
			break;
		}

}
int ipow(int a, int b)
{
	int product = 1;
	for (b; b > 0; b--)
	{
		product *= a;
	}
	return product;
}
