#include "Debug.h"
#include <iomanip>


DebugStatus Debug::Status = StdOut;

ofstream fout("debug.txt");
Debug::Debug(){
	fileName = "debug.txt";
	noEnter = 0;
	floatDigit = 2;
}
Debug::~Debug(){
	if (Status == Off) return;
	if (!noEnter) sout << endl;
	if (Status == StdOut){
		cout << sout.str();
	}
	if (Status == FileOut){
		//ff.open(fileName);
//		if (!ff.is_open()){
//			cout << "[ERROR] debug file cannot open!";
//		}
		if (!fout.is_open()){
			cout << "[ERROR] debug file cannot open!";	
		}
		fout << sout.str();// << endl;
		//cout << sout.str(); pause();
		//fout.close();
	}
}

void Debug::setStatus(DebugStatus a){
	Status = a;
}
void Debug::pause(){
	if (Status == StdOut){
		system("pause");
	}
}

void Debug::changeDebugFileName(string name){
	fileName = name;
}
Debug& Debug::operator<< (DebugCommand a){
	if (Status == Off) return *this;
	if (a == NoEnter){
		noEnter = 1;
	}
	return *this;
}
Debug& Debug::operator << (Vec3b a){
	if (Status == Off) return *this;
	sout << "(" << int(a[0]) << "," << int(a[1]) <<","<<int(a[2])<< ")";
	return *this;
}

Debug& Debug::operator << (Geometry::Point a){
	if (Status == Off) return *this;
	sout << "(" << a.x<< "," << a.y << ")";
	return *this;
}

Debug& Debug::operator<< (float a){
	if (Status == Off) return *this;
	sout << setprecision(2) << fixed << a;
	return *this;
}
