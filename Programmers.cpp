#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;


class Programmer
{
public:
	enum ProgrammerType
	{
		Junior,
		Middle,
		Senior,
		TeamLeader,
		ProjectManager,
		MAX_PROGRAMMER_TYPES
	};

private:
	int m_year;
	string m_name;
	ProgrammerType m_type;

public:
	Programmer(ProgrammerType type, string name, int year)
	{
		m_year = year;
		m_name = name;
		m_type = type;
	}

	string getTypeString() const
	{
		switch (m_type)
		{
		case Junior:
			return "Junior";

		case Middle:
			return "Middle";

		case Senior:
			return "Senior";

		case TeamLeader:
			return "Team Leader";

		case ProjectManager:
			return "Project manager";
		}
		return "Error!";
	}

	void print()
	{
		cout << "TYPE OF PROGRAMMER: " << getTypeString() << endl << "NAME OF PROGRAMMER: " << m_name << endl << "YEARS OF PROGRAMMER: " << m_year << endl;
	}
};


class ProgrammerGenerater
{
public:
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	static Programmer generateProgrammer()
	{
		Programmer::ProgrammerType type = static_cast<Programmer::ProgrammerType>(getRandomNumber(0, Programmer::MAX_PROGRAMMER_TYPES - 1));
		int year = getRandomNumber(18, 65);

		static string s_names[6]{ "John", "Brad", "Alex", "Ivan", "Jake", "Egor" };
		return Programmer(type, s_names[getRandomNumber(0, 5)], year);
	}
};


int main()
{
	auto start = chrono::high_resolution_clock::now();

	srand(static_cast<unsigned int>(time(0)));
	rand();

	Programmer p = ProgrammerGenerater::generateProgrammer();
	p.print();

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duraction = end - start;
	cout << "----------------------------------------" << endl;
	cout << "Duraction: " << duraction.count() << " second" << endl;
	system("pause");
}