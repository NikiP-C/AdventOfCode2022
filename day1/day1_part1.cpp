#include <iostream>
#include <fstream> 
#include <string>

int main(void)
{
	std::ifstream readfile;
	std::string line;
	int tmp = 0;
	int highest_1 = 0;
	int highest_2 = 0;
	int highest_3 = 0;

	readfile.open("input.txt");
	while (getline(readfile, line))
	{
		if (!line.compare(""))
		{
 			if (tmp > highest_3)
			{
				if (tmp < highest_2)
				{
					highest_3 = tmp;
				}
				else if (tmp < highest_1)
				{
					highest_3 = highest_2;
					highest_2 = tmp;
				}
				else
				{
					highest_3 = highest_2;
					highest_2 = highest_1;
					highest_1 = tmp;
				}
			}
			tmp = 0;
		}
		else 
		{
			tmp += stoi(line);
		}
	}
	std::cout << highest_1 << " " << highest_2 << " " << highest_3 << std::endl;
	int total = highest_1 + highest_2 + highest_3;
	std::cout << "total = " << total << std::endl;
}