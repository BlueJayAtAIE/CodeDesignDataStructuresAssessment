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
	cout << "Now hashing: a c-string containing: aabb | " << hash("aabb", 5) << endl<< endl; // Should be the same as string aabb.
	cout << "Now hashing: an int containing: 4 | " << hash(4) << endl << endl;
	cout << "Now hashing: a char containing: h | " << hash('h') << endl << endl;

	cout << ">> Press any lettered key and enter to close this window <<" << endl;
	cin >> dummy;

	return 0;
}