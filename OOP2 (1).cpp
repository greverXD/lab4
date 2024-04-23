#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void print();
int power(float number, float step);

class Power
{
public:
	float first;
	float second;
	double result;

	int power(float number, float step)
	{
		first = number;
		second = step;
		result = pow(number, step);
		return result;
	}

	int make_Power(float number, float step)
	{
		first = number;
		second = step;
		if (number<0)
		{
			cout << "Некорректные данные!" << endl;
			return 0;
		}
		
		return power(number, step);
	}

	void print()
	{
		cout << result << endl;
	}

};

int main()
{
	setlocale(LC_ALL, "RU");
	Power SA;
	SA.make_Power(1.5f,6.897f);
	SA.print();

}