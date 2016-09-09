#include <iostream>
#include <vector>
using namespace std;


template <class M_type> class MVector
{

    private:
	vector<M_type> v;

    public:
	MVector(){};
	MVector(int size){
	    v.resize(size);
	    for (int x=0; x<size; x++){
		v[x] = 0;
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
	    }
	    cout << '\n';
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
