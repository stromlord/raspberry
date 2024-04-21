#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::ostream;
using std::vector;
using std::cout;
using std::endl;

class Employee{
public:
	void setValue(const string & n, double s){
		name = n; salary = s;
	}
	const string & getName() const {return name;}
	void print(ostream & out) const {
		out << name << " (" << salary << ")";
	}
	bool operator<(const Employee & rhs) const{
		return salary < rhs.salary;
	}

private:
	string name;
	double salary;
};

template <typename T>
const T & findMax(const vector<T> & a){
	int maxIndex = 0;
	for (int i=1; i<a.size(); i++){
		if (a[maxIndex] < a[i]){maxIndex = i;}
	}        
	return a[maxIndex];
}

ostream & operator<<(ostream & out, const Employee & rhs){
	rhs.print(out);
	return out;
}

int main(){
	vector<Employee> v(3);

	v[0].setValue("yinda", 400000.00);
	v[1].setValue("Bill Gates", 200000000.00);
	v[2].setValue("Dr. Phil", 13000000.00);
	cout << findMax(v) << endl;

	return 0;
}
