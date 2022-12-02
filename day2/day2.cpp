#include <iostream>
#include <fstream> 
#include <string>
#define stone 'A'
#define paper 'B'
#define scis 'C'

int added_score(char played)
{
	if (played == stone)
		return (1);
	if (played == paper)
		return (2);
	return (3);
}

int main(void)
{
	std::ifstream readfile;
	std::string line;
	int your_score;
	int their_score;
	char their_hand;
	char your_hand;

	readfile.open("input.txt");
	while (getline(readfile, line))
	{
		their_hand = line[0];
		your_hand = line[2] - 23;
		std::cout << your_hand << std::endl;
		if (their_hand == your_hand)
		{
			your_score += 3;
			their_score += 3;
		}
		else if ((their_hand == paper && your_hand == stone) || (their_hand == stone && your_hand == scis) || (their_hand == scis && your_hand == paper))
			their_score += 6;
		else
			your_score += 6;
		their_score += added_score(their_hand);
		your_score += added_score(your_hand);
		std::cout << "my score = " << your_score << "\ntheir score = " << their_score << std::endl;
	}
}