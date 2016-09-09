#include <iostream>
#include <vector>
using namespace std;


template <class M_type> class MVector
{
    private:
	vector<M_type> v;
    public:
	MVector(){};
	MVector(const vector<M_type> &mvector) : v(mvector){
	    v.reserve(mvector.capacity());
	    for (int x=0; x<length(); x++){
		v[x] = mvector[x];
	    }
	}
	~MVector(){};

	void display(){
	    for (int x=0; x<length(); x++){
		cout << v[x] << '\n';
	    }
	}
	
	int length(){
	    return v.capacity();
	}

	M_type get_item(int &i){
	    return v[i];
	}

	bool check_length(MVector &other) {
	    return (length() == other.length());
	}

	vector<M_type> _combine(MVector &other){
	    check_length(other);	
	    M_type a, b; 
	    for (int x=0; x<length(); x++){
		a = v.at(x);
		b = other.at(x);
	    }
	    return v;
	}

	vector<M_type> apply(void (&f)(M_type)){
	    M_type a;
	    for (int x=0; x<length(); x++){
		a = v.at(x);
		v.at(x) = f(a);
	    }
	    return v;
	}

	M_type operator[](int i){
	    return v[i];
	}

	MVector operator+(MVector &other){
	    if (check_length(other) == true){
		M_type a, b; 
		vector<M_type> new_;	
		new_.reserve(length());
		for (int x=0; x<length(); x++){
		    a = v[x];
		    b = other[x];
		    new_[x] = a + b;
		}
		return MVector(new_);
	    }else{
		return MVector();
	    }
	}
};

void add_one(int &i){
    i = i + 1;
}


int main(int argc, char* argv [])
{
    int SIZE = 10;
    vector<int> a;
    vector<int> b;
    vector<int> c;

    a.reserve(SIZE);
    b.reserve(SIZE);
    c.reserve(SIZE);

    for (int x=0; x<a.capacity(); x++){
	a[x] = x;
	b[x] = -x;
    }
    MVector<int> mvec_a(a);
    MVector<int> mvec_b(b);
    MVector<int> mvec_c = mvec_a + mvec_b;
    mvec_c.display();
     
//  mvector = mvector.apply(add_one);
//  mvector.display();
}
