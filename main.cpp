#include <chrono>
#include <random>
#include <iostream>

using namespace std;

#define data_type unsigned long long
#define set_length 50000000

int main()
{
	data_type* arr = new data_type[set_length];
	srand(time(0));

	auto counter = set_length;
	auto generator_max = (data_type)(pow(2, sizeof(data_type) * 8) - 1);
	auto start = chrono::system_clock::now();
	unsigned short avg;

	cout << "Test array generation started.\n";

	for (auto i = 0; i < set_length; i++)
	{
		arr[i] = rand() % generator_max;
	}

	auto end = chrono::system_clock::now();
	auto diff = chrono::duration_cast<chrono::microseconds>(end - start).count();

	cout << "Test generation succeeded, " << diff << " usec\n\n";

	counter = 0;

	cout << "Testing started: mod 2\n";
	start = chrono::system_clock::now();

	for (auto i = 0; i < set_length; i++)
	{
		if (!(arr[i] % 2) && arr[i]) counter++;
		else continue;
	}

	end = chrono::system_clock::now();
	diff = chrono::duration_cast<chrono::microseconds>(end - start).count();

	avg = set_length / diff;

	cout << "Mod 2 testing succeeded, " << diff << " usec\n";
	cout << "Confirmed " << counter << " numbers of " << set_length << ";\n";
	cout << "Average speed = " << avg << " tests per usec\n\n";

	counter = 0;

	cout << "Testing started: n != 0 and !(n & 1)\n";
	start = chrono::system_clock::now();

	for (auto i = 0; i < set_length; i++)
	{
		if (!(arr[i] & 1) && arr[i]) counter++;
		else continue;
	}

	end = chrono::system_clock::now();
	diff = chrono::duration_cast<chrono::microseconds>(end - start).count();

	avg = set_length / diff;

	cout << "N != 0 and !(n & 1) testing succeeded, " << diff << " usec\n";
	cout << "Confirmed " << counter << " numbers of " << set_length << ";\n";
	cout << "Average speed = " << avg << " tests per usec\n\n";

	system("pause > 0");
	return 0;
}