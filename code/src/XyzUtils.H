#include <random>
#include"XyzRandData.H"


int getRandomNumber(int startNumParm,
                    int endNumParm)
{
    std::random_device sRandomDevice;
    std::mt19937 sRandomNumberGenerator(sRandomDevice());
    std::uniform_int_distribution<int> sGenerate(startNumParm, endNumParm);
    int sRandomNumber = sGenerate(sRandomNumberGenerator);
    return sRandomNumber;
}

string getRandomName() {
	string name = first_names[getRandomNumber(0,3)] + last_names[getRandomNumber(0,3)];
	cout << name << endl;
	return name;
}

unsigned int getRandomGender() {
	return getRandomNumber(0,1);
}

unsigned int getRandomEmpType() {
	return getRandomNumber(0,2);
}

string getRandomEmpId(unsigned int idParm, unsigned int empTypeParm) {
	string sType = "\0";
	if(empTypeParm == FULLTIMER)
		sType = "F";
	else if(empTypeParm == CONTRACTOR)
		sType = "C";
	else if(empTypeParm == INTERN)
		sType = "I";
	return "Xyz" + to_string(idParm) + sType;
}
