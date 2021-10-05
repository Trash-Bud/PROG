#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <Windows.h>
#include <stdlib.h> 
#include <time.h>


using namespace std;

#ifndef POOl_H
#define POOL_H
class Pool
{
public:
	Pool(vector <char> vec);
	int showNumber();
	char givePiece();
	void addToPool(char letter);
	

private:

	vector<char> chars;
	
};
#endif