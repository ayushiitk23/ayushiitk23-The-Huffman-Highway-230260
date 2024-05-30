#include <iostream>
using namespace std;

//Average
int average(int examScores[10]){
int m=0;
for(int i=0;i<10;i++){
    m+=examScores[i];
}
m=m/10;
return m;
}
//highest
int highest(int examScores[10]){
int m=examScores[0];
for(int i=0;i<10;i++){
    if(examScores[i]>m) m=examScores[i];
}
return m;
}


//lowest
int lowest(int examScores[10]){
    int m=examScores[0];
for(int i=0;i<10;i++){
    if(examScores[i]<m) m=examScores[i];
}
return m;
}

int main() {
 int examScores[10];
 
 cout<<"Input 10 integer exam scores\n";
 for(int i=0;i<10;i++){
     cin>>examScores[i];
     }
 cout<<"Average exam score "<<average(examScores)<<"\n";
 cout<<"Highest exam score"<<highest(examScores)<<"\n";
 cout<<"Lowest exam score" <<lowest(examScores)<<"\n";
 int count=0;
for(int i=0;i<10;i++){
    if (examScores[i]>average(examScores)) count++;
}
cout<<"Number of exam scores above the average "<<count<<"\n";
count=0;

for(int i=0;i<10;i++){
    if(examScores[i]<average(examScores)) count++;
}
cout<<"Number of exam scores below the average "<<count<<"\n";
    return 0;
}
