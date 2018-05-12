#include "gradient_descent.h"
#include<bits/stdc++.h>
int main()
{
double alp=0.0001;
double epsil=10;
string addr="/home/vamsi/Desktop/Machine Learning 101/forest_fires.txt";
dataset d;
d.populate_data(addr,10,13);

hypothesis foo;
vector<double> final;

final=foo.grad_descent(alp,epsil,d,10,13);


for(int i=0;i<final.size();i++)
{
cout<<final[i]<<"\n";
}
return 0;
}
