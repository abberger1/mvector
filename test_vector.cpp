#include "mvector.cpp"


int main()
{
    int SIZE = 10;

    vector<int> a;
    vector<int> b;

    a.resize(SIZE);
    b.resize(SIZE);

    for (int x=1; x<a.size()+1; x++){
	a[x-1] = x;
	b[x-1] = -x;
    }
    cout << '\n';

    MVector<int> mvec_a(a);

    MVector<int> mvec_b(b);
    MVector<int> mvec_c(SIZE);
    // test operator +
    MVector<int> mvec_d = mvec_a + mvec_b;
    // test operator -
    MVector<int> mvec_e = mvec_a - mvec_a;
    // test operator *
    MVector<int> mvec_f = mvec_a * mvec_c;

    // test operator /
    MVector<int> mvec_g = mvec_a / mvec_a;

    // test push_back
    for (int x=0; x<a.size(); x++){
	mvec_a.push_back(x);
	mvec_b.push_back(-x);
    }
	
    // test operator ==
    if (mvec_c == mvec_d){
	cout << "Success" << '\n';
    }else{
        cout << "Failed" << '\n';
    }
}
