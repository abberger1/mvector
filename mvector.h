#ifndef MVECTOR_H
#define MVECTOR_H

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
	MVector();
	MVector(int size, M_type value=0);
	MVector(const vector<M_type> &mvector);
	~MVector();
	const int size();
	const void push_back(M_type i);
	bool check_length(MVector &other);
	const double mean();
	const M_type median();
	const double var();
	const M_type std();
	const double dot(MVector &other);
	const double norm(MVector &other);
	bool operator==(MVector &other);
	MVector operator/(MVector &other);
	MVector operator*(MVector &other);
	MVector operator+(MVector &other);
	MVector operator-(MVector &other);
	M_type operator[](int i);
	const void display();
};
#endif


template <class M_type> MVector<M_type>::MVector(){};

template <class M_type> MVector<M_type>::~MVector(){};

template <class M_type> MVector<M_type>::MVector(int size, M_type value){
    v.resize(size);
    for (int x=0; x<size; x++){
	v[x] = value;
    }
}

template <class M_type> MVector<M_type>::MVector(const vector<M_type> &mvector) : v(mvector){
    v.resize(mvector.size());
    for (int x=0; x<size(); x++){
	v[x] = mvector[x];
    }
}

template <class M_type> const void MVector<M_type>::display(){
    for (int x=0; x<size(); x++){
	cout << "v (" << x << "): " << v[x] << '\n';
    } cout << '\n';
}

template <class M_type> const int MVector<M_type>::size(){
    return v.size();
}

template <class M_type> const void MVector<M_type>::push_back(M_type i){
    v.push_back(i);
}

template <class M_type> bool MVector<M_type>::check_length(MVector &other) {
    return (size() == other.size());
}

template <class M_type> M_type MVector<M_type>::operator[](int i){
    return v[i];
}

template <class M_type> const double MVector<M_type>::dot(MVector &other){
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

template <class M_type> const double MVector<M_type>::norm(MVector &other){
    if (check_length(other) == true){
	double norm = sqrt(abs(dot(other)));
	return norm;
    }else{
	return 0;
    }
}

template <class M_type> const double MVector<M_type>::mean(){
    int sum = 0;
    for (int x=0; x<size(); x++){
	sum += v[x];
    }
    double _mean = sum / size();
    return _mean;
}

template <class M_type> const M_type MVector<M_type>::median(){
    M_type _median = 0;
    for (int x=0; x<(size()/2); x++){
	_median = v[x];		
    }
    return _median;
}

template <class M_type> const double MVector<M_type>::var(){
    M_type sum = 0;
    double _mean = mean();
    for (int x=0; x<size(); x++){
	sum += pow((v[x] - _mean), 2);
    }
    double _var = sum / size();
    return _var;
}

template <class M_type> const M_type MVector<M_type>::std(){
    M_type _var = var();
    return sqrt(_var);
}

template <class M_type> MVector<M_type> MVector<M_type>::operator+(MVector &other){
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
    } else {
	return MVector();
    }
}

template <class M_type> MVector<M_type> MVector<M_type>::operator-(MVector &other){
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
    } else {
	return MVector();
    }
}

template <class M_type> MVector<M_type> MVector<M_type>::operator*(MVector &other){
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
    } else {
	return MVector();
    }
}

template <class M_type> MVector<M_type> MVector<M_type>::operator/(MVector &other){
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
	    } else {
		new_[x] = a / b;
	    }
	}
	return MVector(new_);
    }else{
	return MVector();
    }
}

template <class M_type> bool MVector<M_type>::operator==(MVector &other){
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
    } else {
	return false;
    }
}

template class MVector<int>;
template class MVector<float>;
template class MVector<double>;
template class MVector<unsigned long long>;
