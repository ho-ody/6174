#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string fix_to_4(int n) {
	string s = to_string(n);
	while (s.length() < 4)
		s.insert(0, "0");
	return s;
}

bool valid(string* in) {
	try	{
		*in = fix_to_4(stoi(*in));
	}
	catch (const std::exception&) {
		return false;
	}
	if (in->length() > 4)
		return false;
	if ((*in)[0] == (*in)[1] && (*in)[1] == (*in)[2] && (*in)[2] == (*in)[3])
		return false;
	return true;
}

int main() {
	string number;
	while (true) {
		getline(cin, number);
		if (valid(&number))
			while (number != "6174") {
				sort(number.begin(), number.end(), std::greater<>());
				int number1 = stoi(number);
				sort(number.begin(), number.end());
				int number2 = stoi(number);

				cerr << "----" << endl;
				cerr << fix_to_4(number1) << endl;
				cerr << fix_to_4(number2) << "-" << endl;
				cerr << "====" << endl;

				number = fix_to_4(number1 - number2);
				cerr << number << endl;
			}
		cerr << endl;
	}
	return 0x0;
}