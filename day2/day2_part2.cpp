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
		your_hand = line[2];
		if (your_hand == 'Y')
		{
			your_score += (3 + added_score(their_hand));
			their_score += 3;
		}
		if (your_hand == 'X')
		{
			their_score += 6;
			if (their_hand == paper)
				your_score +=(added_score(stone));
			if (their_hand == stone)
				your_score +=(added_score(scis));
			if (their_hand == scis)
				your_score +=(added_score(paper));
		}
		if (your_hand == 'Z')
		{
			if (their_hand == paper)
				your_score +=(6 + added_score(scis));
			if (their_hand == stone)
				your_score += 6 + (added_score(paper));
			if (their_hand == scis)
				your_score += 6 + (added_score(stone));
		}
		their_score += added_score(their_hand);
	}
	std::cout << "my score = " << your_score << "\ntheir score = " << their_score << std::endl;
}