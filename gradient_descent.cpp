#include "gradient_descent.h"

#include<bits/stdc++.h>
using namespace std;



long int dataset::no_rows()
{
return r_data.size();
}

void dataset::populate_data(string location,long int no_rows,long int no_columns)
{

ifstream fin;
fin.open("forest_fires.txt");
if(fin.is_open())
{
long int count_c=0;
long int count_r=0;
string str_no;
vector<double> tempe;
double temp;
while(!fin.eof())
{


if(count_c!=no_columns-1)
{
getline(fin,str_no,',');
stringstream converter(str_no);
converter >> temp;

tempe.push_back(temp);
count_c=count_c+1;

}
if(count_c==no_columns-1)
{

getline(fin,str_no,'\n');
stringstream converter(str_no);
converter >> temp;
r_data.push_back(temp);
f_data.push_back(tempe);
for(int i=0;i<tempe.size();i++){cout<<tempe[i]<<" ";}
tempe.clear();
count_r++;
count_c=0;

}
}
}
else
{
cout<<"could not open the file!";
}
}

void hypothesis::cost_calculation(dataset& data,long int rows)
{

for(int i=0;i<rows;i++)
{

h_thetha.push_back(inner_product(thetha.begin(),thetha.end(),data.f_data[i].begin(),0));
cout<<h_thetha[i];
}

//return h_thetha;
}

void hypothesis::check(double epsilon)
{
//cout<<abs(jn1-jn2);
if(abs(jn1-jn2)<=epsilon)
{
check_flag=true;
}
}







vector<double> hypothesis::grad_descent(double alpha,double eps, dataset& data,long int row,long int col)
{

for(long int i=0;i<data.r_data.size();i++)
{
thetha.push_back(0);
}
jn1=0;jn2=10000001;
check_flag=false;

//vector<double> h_thetha;

hypothesis::cost_calculation(data,row);
//vector<double> j_thetha;
cout<<"DDDDDDDDDDDD";
std::transform(h_thetha.begin(),h_thetha.end(),data.r_data.begin(),j_thetha.begin(),std::minus<int>());
vector<double> inter(j_thetha);
std::transform(j_thetha.begin(),j_thetha.end(),j_thetha.begin(), j_thetha.begin(), multiplies<double>());
jn1=std::accumulate(j_thetha.begin(), j_thetha.end(), 0);
jn1=jn1/(2*data.f_data.size());




check_flag=false;
while(check_flag==false)
{jn1=jn2;

for(long int i=0;i<thetha.size();i++)
{
double sum=0;
for(long int j=0;j<data.f_data.size();j++)
{
sum=sum+(inter[j]*data.f_data[j][i]);
}
thetha[i]=thetha[i]-(alpha*(sum));
}

h_thetha.clear();
hypothesis::cost_calculation(data,row);
j_thetha.clear();
std::transform(h_thetha.begin(),h_thetha.end(),data.r_data.begin(),j_thetha.begin(),std::minus<int>());
inter.clear();
copy(j_thetha.begin(),j_thetha.end(),inter.begin());
//inter(j_thetha);
std::transform(j_thetha.begin(),j_thetha.end(),j_thetha.begin(), j_thetha.begin(), multiplies<double>());
jn2=std::accumulate(j_thetha.begin(), j_thetha.end(), 0);
jn2=jn2/(2*data.f_data.size());
check(eps);
}
return thetha;
}

