#include <iostream>
#include <math.h>
using namespace std;

float MyPow(float x, float n)
{
	float y = pow(x, n);
	return y;
}


int main() {
	float x, n, y;
	cout << "Введите x:" << endl;
	cin >> x;
	cout << "Введите n:" << endl;
	cin >> n;
	y = MyPow(x, n);
	cout << "Ваше число: " << y;


	return 0;
}
