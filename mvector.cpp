#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
using namespace std;


template <class M_type> class MVector
{

    private:
	vector<M_type> v;

    public:
	MVector(){};
	MVector(int size, M_type value=0){
	    v.resize(size);
	    for (int x=0; x<size; x++){
		v[x] = value;
	    }
	}

	MVector(const vector<M_type> &mvector) : v(mvector){
	    v.resize(mvector.size());
	    for (int x=0; x<size(); x++){
		v[x] = mvector[x];
	    }
	}
	~MVector(){};

	const void display(){
	    for (int x=0; x<size(); x++){
		cout << "v (" << x << "): " << v[x] << '\n';
	    } cout << '\n';
	}
	
	const int size(){
	    return v.size();
	}

	const void push_back(M_type i){
	    v.push_back(i);
	}

	bool check_length(MVector &other) {
	    return (size() == other.size());
	}

	M_type operator[](int i){
	    return v[i];
	}

	const double dot(MVector &other){
	    if (check_length(other) == true){
		M_type a, b; 
		double sum = 0.0;
		for (int x=0; x<size(); x++){
		    a = v[x];
		    b = other[x];
		    sum += (a * b);
		}
		return sum;
	    }else{
		return 0;
	    }
	}

	const double norm(MVector &other){
	    if (check_length(other) == true){
		double norm = sqrt(abs(dot(other)));
		return norm;
	    }else{
		return 0;
	    }
	}

	const double mean(){
	    int sum = 0;
	    for (int x=0; x<size(); x++){
		sum += v[x];
	    }
	    double _mean = sum / size();
	    return _mean;
	}

	const M_type median(){
	    M_type _median = 0;
	    for (int x=0; x<(size()/2); x++){
		_median = v[x];		
	    }
	    return _median;
	}

	const double var(){
	    M_type sum = 0;
	    M_type diff = 0;
	    double _var = 0.0;
	    double _mean = mean();
	    for (int x=0; x<size(); x++){
		diff = v[x] - _mean;
		sum += pow(diff, 2);
	    }
	    _var = sum / size();
	    return _var;
	}

	const M_type std(){
	    M_type _var = var();
	    return sqrt(_var);
	}

	MVector operator+(MVector &other){
	    if (check_length(other) == true){
		M_type a, b; 
		vector<M_type> new_;
		new_.resize(size());
		for (int x=0; x<size(); x++){
		    a = v[x];
		    b = other[x];
		    new_[x] = a + b;
		}
		return MVector(new_);
	    }else{
		return MVector();
	    }
	}

	MVector operator-(MVector &other){
	    if (check_length(other) == true){
		M_type a, b; 
		vector<M_type> new_;
		new_.resize(size());
		for (int x=0; x<size(); x++){
		    a = v[x];
		    b = other[x];
		    new_[x] = a - b;
		}
		return MVector(new_);
	    }else{
		return MVector();
	    }
	}

	MVector operator*(MVector &other){
	    if (check_length(other) == true){
		M_type a, b; 
		vector<M_type> new_;
		new_.resize(size());
		for (int x=0; x<size(); x++){
		    a = v[x];
		    b = other[x];
		    new_[x] = a * b;
		}
		return MVector(new_);
	    }else{
		return MVector();
	    }
	}

	MVector operator/(MVector &other){
	    if (check_length(other) == true){
		M_type a, b; 
		vector<M_type> new_;
		new_.resize(size());
		for (int x=0; x<size(); x++){
		    a = v[x];
		    b = other[x];
		    if (b == 0){
			cout << "Cannot divide by zero" << '\n';
			return MVector();
		    }else{
		    	new_[x] = a / b;
		    }
		}
		return MVector(new_);
	    }else{
		return MVector();
	    }
	}

	bool operator==(MVector &other){
	    if (check_length(other) == true){
		M_type a, b; 
		vector<M_type> new_;
		new_.resize(size());
		for (int x=0; x<size(); x++){
		    a = v[x];
		    b = other[x];
		    if (a == b){
			continue;
		    }else{
			return false;
		    }
		}
		return true;
	    }else{
		return false;
	    }
	}
};
