#include <iostream>
#include "hash.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	char dummy;

	string aabb = "aabb";
	string aacc = "aacc";
	string baba = "baba";
	string ccaa = "ccaa";

	cout << "Now hashing: an std::string containing: aabb | " << hash(aabb) << endl;
	cout << "Now hashing: an std::string containing: aacc | " << hash(aacc) << endl;
	cout << "Now hashing: an std::string containing: baba | " << hash(baba) << endl;
	cout << "Now hashing: an std::string containing: ccaa | " << hash(ccaa) << endl << endl;
	cout << "Now hashing: a c-string containing: aabb | " << hash("aabb", 5) << " (Should match line 1)." << endl<< endl; // Should be the same as string aabb.
	cout << "Now hashing: an int containing: 4 | " << hash(4) << endl << endl;
	cout << "Now hashing: a char containing: h | " << hash('h') << endl;
	cout << "Now hashing: a char containing: E | " << hash('E') << endl << endl;

	tHashmap<string, int> favoriteNumbersByName;
	cout << "Created Hashmap favoriteNumbersByName (FNBN)." << endl;

	favoriteNumbersByName["Terry"] = 5;
	favoriteNumbersByName["Jay"] = 4;
	favoriteNumbersByName["Kami"] = 52;
	cout << "Assigning key 'Terry' to be 5 in FNBN." << endl;
	cout << "Assigning key 'Jay' to be 4 in FNBN." << endl;
	cout << "Assigning key 'Kami' to be 52 in FNBN." << endl << endl;

	cout << "CHECK (FNBN):" << endl;
	cout << "Terry: " << favoriteNumbersByName["Terry"] << endl; // 5
	cout << "Jay: " << favoriteNumbersByName["Jay"] << endl; // 4
	cout << "Kami: " << favoriteNumbersByName["Kami"] << endl << endl; // 52

	tHashmap<string, int> testCopy(favoriteNumbersByName);
	cout << "Created Hashmap testCopy as a copy of FNBN." << endl;

	cout << "CHECK (testCopy):" << endl;
	cout << "Terry: " << testCopy["Terry"] << endl; // 5
	cout << "Jay: " << testCopy["Jay"] << endl; // 4
	cout << "Kami: " << testCopy["Kami"] << endl << endl; // 52

	favoriteNumbersByName["Kami"] = 7;
	cout << "Editing key 'Kami' to be 7 in FNBN." << endl << endl;

	cout << "CHECK (FNBN):" << endl;
	cout << "Kami: " << favoriteNumbersByName["Kami"] << endl << endl; // 7
	cout << "CHECK (testCopy):" << endl;
	cout << "Kami: " << testCopy["Kami"] << endl << endl; // 52



	cout << ">> Press any lettered key and enter to close this window <<" << endl;
	cin >> dummy;

	return 0;
}