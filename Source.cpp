#include "BitField.h"
#include <string>
#include <sstream>

unsigned int BITFIELD_SIZE = 2;

void CorrectInput(int left_index, int right_index);
void Interface();
void InputRow(BitField& obj);
void OutputRow(BitField& obj);

void main()
{
	int option = 6;
	BitField field1(BITFIELD_SIZE);
	BitField field2(BITFIELD_SIZE);
	BitField field_result(BITFIELD_SIZE);

	do
	{
		Interface();
		std::cin >> option;

		switch (option)
		{
		case 1:

			InputRow(field1);
			break;

		case 2:

			unsigned int ind, val;

			do
			{
				std::cout << "Input index: ";
				std::cin >> ind;
			} while (ind > field1.reserved_ints || ind < 0);

			do
			{
				std::cout << "Input value: ";
				std::cin >> val;
			} while (val != 0 && val != 1);

			if (val == 0)
			{
				field1.TurnOff(ind);
			}
			else if (val == 1)
			{
				field1.TurnOn(ind);
			}

			if (field1.used_bits <= ind)
			{
				field1.used_bits = ind + 1;
			}

			break;

		case 3:

			unsigned int ind, val;

			do
			{
				std::cout << "Input index: ";
				std::cin >> ind;
			} while (ind > field1.reserved_ints || ind < 0);

			std::cout << "Bit with an index " << ind << " equals to " << field1.CheckState(ind) << std::endl;

			break;

		case 4:

			std::cout << "\nInput second bitfield: ";
			InputRow(field2);

			field_result = (field1 | field2);

			OutputRow(field_result);
			break;

		case 5:

			std::cout << "\nInput second bitfield: ";
			InputRow(field2);

			field_result = (field1 & field2);

			OutputRow(field_result);
			break;

		}
	} while (option != 6 && option < 1 && option > 6);

}

void Interface()
{
	std::cout << "1. Input a bitfitfield as a row";
	std::cout << "2. Change a single bit of a bitfield\n";
	std::cout << "3. Check state of a bit\n";
	std::cout << "4. Test | operator\n";
	std::cout << "5. Test & operator\n";
	std::cout << "6. Exit\n";
}

void InputRow(BitField& obj)
{
	std::string input;
	std::getline(std::cin, input);

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == 1)
		{
			obj.TurnOn(i);
			obj.used_bits += 1;
		}
		else if (input[i] == 0)
		{
			obj.TurnOff(i);
			obj.used_bits += 1;
		}
		else
		{
			break;
		}
	}
}

void OutputRow(BitField& obj)
{
	std::string output;

	for (int i = 0; i < obj.used_bits; i++)
	{
		output[i] = (obj.CheckState(i));
	}

	std::cout << std::endl << output << std::endl;
}
