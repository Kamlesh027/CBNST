#include<bits/stdc++.h>
using namespace std;
 double round(double n){
    return ((int )(n*100+0.5))/100.0;
 }
 int main(){
    double true_val,obs_val;
    cout<<"Enter the  ture value :"<<endl;
    cin>>true_val;
     cout<<"Enter the obs value :"<<endl;
     cin>>obs_val;
     double abs_eroor=true_val-obs_val;
     double real_error=abs_eroor/true_val;
     double pre_error=real_error*100;
     cout<<"abs error "<<abs_eroor<<endl;
     cout<<"realtive_error: "<<real_error<<endl;
     cout<<"pre_error: "<<pre_error<<endl;
     cout<<"Round off abs: "<<round(abs_eroor)<<endl;
     cout<<"Round off real error: "<<round(real_error)<<endl;
     cout<<"pre error is: "<<round(pre_error)<<endl;
 }