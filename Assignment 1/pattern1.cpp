#include <iostream>
using namespace std;
int main() {
   int n;
   cout<<"Input-";
   cin>>n;
   for(int i=1;i<=n;i++){  

       for(int j=1;j<=i;j++){
           cout<<j;
       }
        for(int j=2*n-2*i;j>=1;j--){
           cout<<" ";
       }
    if(n%2==0)  {
    for(int k=1;k<=(n-2)/2;k++){     
        for(int j=i;j>=1;j--){
           cout<<j;
       }
        for(int j=1;j<=i;j++){
           cout<<j;
       }
       for(int j=2*n-2*i;j>=1;j--){
           cout<<" ";
       }
    }
    for(int j=1;j<=i;j++){
           cout<<j;
       }
    }
     if(n%2!=0)  {
    for(int k=1;k<=(n-1)/2;k++){     
        for(int j=i;j>=1;j--){
           cout<<j;
       }
        for(int j=1;j<=i;j++){
           cout<<j;
       }
       for(int j=2*n-2*i;j>=1;j--){
           cout<<" ";
       }
    }
     }
   cout<<"\n";
   }
    return 0;
}
