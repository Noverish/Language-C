#include <string>
#include <iostream>

using namespace std;

#define WORDNUM 180

int main()
{
	string strs[1000][WORDNUM];
	int maxWord = 0, lineNum = 0;

	for (int i = 0; 1; i++) {
		string tmp;
		getline(std::cin,tmp);

		strs[i] = sc.nextLine().trim().split("[ ]+");

		maxWord = (maxWord >= (strs[i].size()) ? maxWord : (strs[i].size();

		lineNum = i + 1;
	}

	int wordLengths[WORDNUM];

	for (int i = 0; i<maxWord; i++) {
		for (int j = 0; j<lineNum; j++) {
			if (Array.getLength(strs[j]) >= (i + 1)) {
				wordLengths[i] = (wordLengths[i] > strs[j][i].length()) ? wordLengths[i] : strs[j][i].length();
			}
		}
	}

	for (int i = 0; i<lineNum; i++) {
		for (int j = 0; j<Array.getLength(strs[i]); j++) {
			int len = strs[i][j].length();

			System.out.print(strs[i][j]);

			for (int k = 0; k <= wordLengths[j] - len && (j != Array.getLength(strs[i]) - 1); k++)
				System.out.print(" ");
		}
		System.out.println();
	}
    return 0;
}
