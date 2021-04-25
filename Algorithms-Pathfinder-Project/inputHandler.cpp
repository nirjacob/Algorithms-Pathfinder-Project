#include "GlobalHeader.h"
using namespace input;
void inputHandler::read(char* fileName){
	int numOfVertices;
	ifstream inFile;
	inFile.open(fileName);
	if (!inFile) {
		cout << "Error opening file"<<endl;
		exit(1);
	}
	inFile >> numOfVertices;
	while(!inFile.eof()){
		if(!inFile.good()){
			cout << "Error reading" << endl;
			exit(1);
		}
		//Read	
	}
	inFile.close();
}


