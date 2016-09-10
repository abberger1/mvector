#include "mvector.cpp"


int main()
{
    int SIZE = 10;

    vector<double> a;
    vector<double> b;

    a.resize(SIZE);
    b.resize(SIZE);

    for (int x=1; x<a.size()+1; x++){
	a[x-1] = x;
	b[x-1] = -x;
    } cout << '\n';

    MVector<double> mvec_a(a);
    MVector<double> mvec_b(b);
    MVector<double> mvec_c(SIZE);

    // test operator +
    MVector<double> mvec_d = mvec_a + mvec_b;
    // test operator -
    MVector<double> mvec_e = mvec_a - mvec_a;
    // test operator *
    MVector<double> mvec_f = mvec_a * mvec_c;
    // test operator /
    MVector<double> mvec_g = mvec_a / mvec_a;

    cout << "Dot: ";
    // test dot
    if (mvec_a.dot(mvec_b) == -385){
	cout << "Success";
    } else{ cout << "Failed: (" << mvec_a.dot(mvec_b) << ") ";
    } cout << '\n';

    cout << "Norm: ";
    // test dot
    cout << "(" << mvec_a.norm(mvec_b) << ") " << '\n';

    cout << "Mean: ";
    // test mean
    if (mvec_a.mean() == 5.0){
	cout << "Success";
    } else{ cout << "Failed: (" << mvec_a.mean() << ") ";
    } cout << '\n';
	
    cout << "Median: ";
    // test median
    if (mvec_a.median() == 5.0){
	cout << "Success";
    } else{ cout << "Failed: (" << mvec_a.median() << ") ";
    } cout << '\n';

    cout << "Variance: ";
    // test var
    if (mvec_a.var() == 8.5){
	cout << "Success";
    } else{ cout << "Failed: (" << mvec_a.var() << ") ";
    } cout << '\n';

    cout << "StDev: (";
    // test var
    cout << mvec_a.std() << ") " << '\n';

    cout << "Push Back: ";
    // test push_back
    for (int x=0; x<a.size(); x++){
	mvec_a.push_back(x);
	mvec_b.push_back(-x);
    }
    if (mvec_a.size() == (a.size() * 2)){
	cout << "Success";
    } else{ cout << "Failed: (" << mvec_a.size() << ") ";
    } cout << '\n';

    cout << "==: ";
    // test operator ==
    if (mvec_c == mvec_d){
	cout << "Success";
    } else{ cout << "Failed: (" << mvec_c[0] << "/" << mvec_d[0] << ") ";
    } cout << '\n';
}
