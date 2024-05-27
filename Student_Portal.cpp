#include<iostream>
#include<string>
#include<unistd.h>
#include<iomanip>
#include<fstream>
#include<sstream>
int l=-1,m=-1,n=-1,o=-1,check[1000],count=0,count1=0,n1[1000],n2[1000],fl=0,u=0;
using namespace std;

class Admin
{
public:
string Name,cnic,city,phon,i,p;
};

class Student
{
public:
string N,phone,city,Attendance[6],Type,id,password,cours[6],cod[6],crh[6],marks[6],day[6],slot[6],s;
int fee;
void view_a(string i,string p);
void view_m(string i,string p);
void view_fee(string i,string p);
};

class Faculty : public Student
{
public:
string Name,Phone,Office,course,code,crhr,ID,Password;

void Attendance(string i,string p);
void Test_Type(string i,string p);

};

Admin A;
Student S[1000];
Faculty M[1000];

void Admin_Data()
{
system("cls");
cout<<setw(90)<<"======================================================\n";
cout<<setw(90)<<"|WELCOME TO THE GRANDEST UNIVERSITY IN PAKISTAN PIEAS|\n";
cout<<setw(90)<<"======================================================\n";
cout<<"Enter Your Name : ";
cin>>A.Name;
cout<<"Enter Your CNIC # : ";
cin>>A.cnic;
cout<<"Enter Your City : ";
cin>>A.city;
cout<<"Enter Your Phone # : ";
cin>>A.phon;
cout<<"Enter Your ID and Password\n";
cin>>A.i>>A.p;
fl=1;
cout<<setw(80)<<right<<"--------------------------------------\n\n";
cin.ignore();
}

void Student_Data()
{
system("cls");
cout<<setw(90)<<"======================================================\n";
cout<<setw(90)<<"|WELCOME TO THE GRANDEST UNIVERSITY IN PAKISTAN PIEAS|\n";
cout<<setw(90)<<"======================================================\n";
int choice;
string c;
n++;
cout<<"Enter Your Name : ";
cin>>S[n].N;
cout<<"Enter Your Phone # : ";
cin>>S[n].phone;
cout<<"Enter Name OF City : ";
cin>>S[n].city;
cout<<"Enter Semester Type : ";
cin>>S[n].Type;
cout<<"Enter Semester # : ";
cin>>S[n].s;
cout<<"Following Courses You Are Allowed To Take\n";
for(int i=0;i<count1;i++)
{
cout<<"=>"<<M[i].course<<endl;
}
cout<<"How Many Courses You Want To Take : ";
cin>>n1[++l];
if(n1[l]>count1)
{
cout<<"Invalid Entry Again Try.\n";
cin>>n1[l];
}
cout<<"Enter The Course Titles OF The Given Courses\n";
for(int i=0;i<n1[l];i++)
{
cin>>c;
cin.ignore();
S[n].cours[i]=M[i].course;
S[n].cod[i]=M[i].code;
S[n].crh[i]=M[i].crhr;
}
cout<<"You Have Successfully Registered To Selected Courses\n";
cout<<"Enter What You Want.\n1. Hostel\n2. Transport\n";
cin>>choice;
if(choice==1)
S[n].fee=90000;
else if (choice==2)
S[n].fee=75000;
else
S[n].fee=60000;
cout<<"Enter Your Login ID : ";
cin>>S[n].id;
cout<<"Enter Your Password : ";
cin>>S[n].password;
count++;
cout<<setw(80)<<right<<"--------------------------------------\n\n";
cin.ignore();
}

void Student :: view_a(string i,string p)
{
system("cls");
cout<<setw(90)<<"==============================\n";
cout<<setw(90)<<"|WELCOME TO ATTENDANCE PORTAl|\n";
cout<<setw(90)<<"==============================\n";
string c;
fstream person;
person.open("Student.txt",ios::out);
cout<<"Following Are The Courses In Which You Are Enrolled.\n";
for(int j=0;j<count;j++)
{
if(S[j].id==i&&S[j].password==p)
{
for(int i=0;i<n2[o]||i<n1[j];i++)
cout<<"=>"<<S[j].cours[i]<<endl;
}
}
cout<<"Enter The Course Title To See Your Attendance : ";
cin>>c;
for(int j=0;j<count;j++)
{

for(int i=0;i<6;i++)
{
if(S[j].cours[i]==c)
{
cout<<"Student Name : "<<S[j].N<<endl<<"Course Name : "<<S[j].cours[i]<<endl;
cout<<"Course Code : "<<S[j].cod[i]<<endl<<"Course Credit-Hours : "<<S[j].crh[i]<<endl;
cout<<"Day  : "<<S[j].day[i]<<endl<<"Slot : "<<S[j].slot[i]<<endl<<"Attendance Status : "<<S[j].Attendance[i]<<endl;
cout<<setw(80)<<"--------------------------------------\n\n";
cin.ignore();
break;
}
}

}

}

void Student :: view_m(string i,string p)
{
system("cls");
cout<<setw(90)<<"==============================\n";
cout<<setw(90)<<"   |WELCOME TO MARKS PORTAl|  \n";
cout<<setw(90)<<"==============================\n";
string c;
fstream person;
person.open("Student.txt",ios::out);
cout<<"Following Are The Courses In Which You Are Enrolled.\n";
for(int j=0;j<count;j++)
{
if(S[j].id==i&&S[j].password==p)
{
for(int i=0;i<n2[o]||i<n1[j];i++)
cout<<"=>"<<S[j].cours[i]<<endl;
}
}
cout<<"Enter The Course Title To See Your Marks : ";
cin>>c;
for(int j=0;j<count;j++)
{

for(int i=0;i<6;i++)
{
if(S[j].cours[i]==c)
{
cout<<"Student Name : "<<S[j].N<<endl<<"Course Name : "<<S[j].cours[i]<<endl;
cout<<"Course Code : "<<S[j].cod[i]<<endl<<"Course Credit-Hours : "<<S[j].crh[i]<<endl;
cout<<"Marks Obtained  : "<<S[j].marks[i]<<endl;
cout<<setw(80)<<"--------------------------------------\n\n";
cin.ignore();
break;
}
}

}

}

void Student::view_fee(string id,string pa)
{
system("cls");
cout<<setw(90)<<"=================================\n";
cout<<setw(90)<<"|WELCOME TO FEE STRUCTURE PORTAl|\n";
cout<<setw(90)<<"=================================\n";
for(int i=0;i<count;i++)
{

if(S[i].id==id&&S[i].password==pa)
{
cout<<"Name OF The Student : "<<S[i].N<<endl<<"City OF Student : "<<S[i].city<<endl;
cout<<"Tution Fee : 45000\nLibrary Charges : 6000\nAdmission Fee : 15000\nSecurity Fee : 40000\nHostel Charges : 12000\nTransport Charges : 14000\n";
cout<<"Total Fee Including (Transport/Hostel) Charges : "<<S[i].fee<<endl;
cout<<setw(80)<<right<<"--------------------------------------\n\n";
cin.ignore();
break;
}

}
}

void Faculty_Data(void)
{
system("cls");
cout<<setw(90)<<"======================================================\n";
cout<<setw(90)<<"|WELCOME TO THE GRANDEST UNIVERSITY IN PAKISTAN PIEAS|\n";
cout<<setw(90)<<"======================================================\n";
m++;
cout<<"Enter Your Name Sir : ";
cin>>M[m].Name;
cout<<"Enter Your Phone # Sir : ";
cin>>M[m].Phone;
cout<<"Enter Your Office # : ";
cin>>M[m].Office;
cout<<"Enter Your ID # : ";
cin>>M[m].ID;
cout<<"Enter Your Password Sir : ";
cin>>M[m].Password;
cout<<"Enter Assigned Course Name : ";
cin>>M[m].course;
cout<<"Enter Course Code : ";
cin>>M[m].code;
cout<<"Enter No. OF Credit-Hours : ";
cin>>M[m].crhr;
count1++;
cout<<setw(80)<<right<<"--------------------------------------\n\n";
cin.ignore();
}

void Faculty :: Attendance(string i,string p)
{
system("cls");
cout<<setw(90)<<"============================================\n";
cout<<setw(90)<<"|WELCOME TO ATTENDANCE PORTAL OF University|\n";
cout<<setw(90)<<"============================================\n";
int flag=0;
if(n!=-1)
{
string c;
cout<<"Following Are The Courses Sir.\n";
for(int j=0;j<count1;j++)
{
if(i==M[j].ID&&M[j].Password==p)
cout<<"=> "<<M[j].course<<endl;
}
cout<<"Enter Course Name For Attendance : ";
cin>>c;
for(int j=0;j<count;j++)
{
for(int i=0;i<6;i++)
{
if(c==S[j].cours[i])
{
cout<<"Student Name : "<<S[j].N<<endl<<"Course Name : "<<S[j].cours[i]<<endl;
cout<<"Course Code : "<<S[j].cod[i]<<endl<<"Course Credit-Hours : "<<S[j].crh[i]<<endl;
cout<<"Enter Day  : ";
cin>>S[j].day[i];
cout<<"Enter Slot : ";
cin>>S[j].slot[i];
cout<<"Attendance Status : ";
cin>>S[j].Attendance[i];
cin.ignore();
cout<<setw(80)<<right<<"--------------------------------------\n\n";
cin.ignore();
flag=1;
break;
}
}
}

}
if(flag==0)
{
cout<<"No Students Has Been Enrolled In That Course.\n\n";
cout<<setw(80)<<right<<"--------------------------------------\n\n";
cin.ignore();
}
}

void Faculty :: Test_Type(string i,string p)
{
system("cls");
cout<<setw(90)<<"============================================\n";
cout<<setw(90)<<"|WELCOME TO ATTENDANCE PORTAL OF University|\n";
cout<<setw(90)<<"============================================\n";
int flag=0;
if(n!=-1)
{
string c;
cout<<"Following Are The Courses Sir.\n";
for(int j=0;j<count1;j++)
{
if(i==M[j].ID&&M[j].Password==p)
cout<<"=> "<<M[j].course<<endl;
}
cout<<"Enter Course Name For Attendance : ";
cin>>c;
for(int j=0;j<count;j++)
{
for(int i=0;i<6;i++)
{
if(c==S[j].cours[i])
{
cout<<"Student Name : "<<S[j].N<<endl<<"Course Name : "<<S[j].cours[i]<<endl;
cout<<"Course Code : "<<S[j].cod[i]<<endl<<"Course Credit-Hours : "<<S[j].crh[i]<<endl;
cout<<"Enter Marks OF Student : ";
cin>>S[j].marks[i];
cout<<setw(80)<<right<<"--------------------------------------\n\n";
cin.ignore();
flag=1;
break;
}
}
}

}
if(flag==0)
{
cout<<"No Students Has Been Enrolled In That Course.\n\n";
cout<<setw(80)<<right<<"--------------------------------------\n\n";
cin.ignore();
}
}

void Entry(void)
{
FILE* fil   = fopen("Admin.txt", "a");
FILE* dat   = fopen("Faculty.txt","a");
FILE* perso = fopen("Student.txt","a");
ifstream file("Admin.txt");
file.seekg(0,std::ios::end);
if(file.tellg()!=0)
{
file.close();
fstream file;
file.open("Admin.txt",ios::in);
while(!file.eof())
{
getline(file,A.Name);
getline(file,A.cnic);
getline(file,A.city);
getline(file,A.phon);
getline(file,A.i);
getline(file,A.p);
}
file.close();
}
else
Admin_Data();
if(fl==0)
{
ifstream data("Faculty.txt");
data.seekg(0,std::ios::end);
if(data.tellg()!=0)
{
fstream data;
data.open("Faculty.txt",ios::in);
while(!data.eof())
{
m++;
getline(data,M[m].Name);
getline(data,M[m].Phone);
getline(data,M[m].Office);
getline(data,M[m].ID);
getline(data,M[m].Password);
getline(data,M[m].course);
getline(data,M[m].code);
getline(data,M[m].crhr);
count1++;
}
data.close();
}
ifstream person("Student.txt");
person.seekg(0,std::ios::end);
if(person.tellg()!=0)
{
person.close();
string c;
fstream person;
person.open("Student.txt",ios::in);
while(!person.eof())
{
n++;
getline(person,S[n].N);
getline(person,S[n].phone);
getline(person,S[n].city);
getline(person,S[n].Type);
getline(person,S[n].s);
getline(person,c);
stringstream(c)>>n2[++o];
getline(person,S[n].id);
getline(person,S[n].password);
for(int i=0;i<n2[o];i++)
{
getline(person,S[n].cours[i]);
getline(person,S[n].cod[i]);
getline(person,S[n].crh[i]);
getline(person,S[n].day[i]);
getline(person,S[n].slot[i]);
getline(person,S[n].Attendance[i]);
getline(person,S[n].marks[i]);
}
count++;
}
person.close();

}

}
}


void Exit(void)
{
fstream file;
file.open("Admin.txt",ios::out|ios::trunc);
for(int i=0;i<1;i++)
{
file<<A.Name<<endl<<A.cnic<<endl<<A.city<<endl<<A.phon<<endl<<A.i<<endl<<A.p;
}
file.close();
fstream data;
data.open("Faculty.txt",ios::out|ios::trunc);
for(int i=0;i<count1;i++)
{
data<<M[i].Name<<endl<<M[i].Phone<<endl<<M[i].Office<<endl<<M[i].ID<<endl<<M[i].Password<<endl<<M[i].course<<endl<<M[i].code<<endl<<M[i].crhr<<endl;
}
data.close();
fstream person;
person.open("Student.txt",ios::out|ios::trunc);
for(int i=0;i<count;i++)
{
person<<S[i].N<<endl<<S[i].phone<<endl<<S[i].city<<endl<<S[i].Type<<endl<<S[i].s<<endl<<n1[l]<<endl<<S[i].id<<endl<<S[i].password<<endl;
for(int j=0;j<n1[l];j++)
{
person<<S[i].cours[j]<<endl<<S[i].cod[j]<<endl<<S[i].crh[j]<<endl;
person<<S[i].day[j]<<endl<<S[i].slot[j]<<endl<<S[i].Attendance[j]<<endl<<S[i].marks[j]<<endl;
}
}
person.close();
exit(0);
}

int main()
{
Entry();
while(1)
{
cout<<setw(90)<<"======================================================\n";
cout<<setw(90)<<"|WELCOME TO THE GRANDEST UNIVERSITY IN PAKISTAN PIEAS|\n";
cout<<setw(90)<<"======================================================\n";
string id,pa;
int choice;
cout<<endl<<endl<<endl;
cout<<setw(60)<<"Enter Login-ID : ";
cin>>id;
cout<<setw(60)<<"Enter Password : ";
cin>>pa;
if(A.i==id&&A.p==pa)
{
cout<<"1. To Enter Faculty Member Data.\n2. To Offer Semester To A Student.\nPlease Enter One OF The Following Options : ";
cin>>choice;
if(choice==1)
Faculty_Data();
else if(choice==2)
Student_Data();
else
cout<<"Wrong Data Entry. Please Try Again.\n";
}
for(int j=0;j<count||j<count1;j++)
{
if(id==S[j].id&&pa==S[j].password)
{
Student s;
int choice;
cout<<"1. To View Attendance\n2. To View Marks In Assesments\n3. To Print Fee Challan\n";
cin>>choice;
if(choice==1)
{
s.view_a(id,pa);
cout<<"You Want To Exit.\nPress 1 For Yes 0 For No :  ";;
int c;
cin>>c;
if(c==1)
Exit();
}
else if(choice==2)
{
s.view_m(id,pa);
cout<<"You Want To Exit.\nPress 1 For Yes 0 For No :  ";;
int c;
cin>>c;
if(c==1)
Exit();
}
else
{
s.view_fee(id,pa);
cout<<"You Want To Exit.\nPress 1 For Yes 0 For No :  ";;
int c;
cin>>c;
if(c==1)
Exit();
}
}
else if(id==M[j].ID&&pa==M[j].Password)
{
Faculty f;
int choice;
cout<<"1. To Enter Attendance \n2. To Enter Marks In Assesments.\n";
cin>>choice;
if(choice==1)
{
f.Attendance(id,pa);
cout<<"You Want To Exit.\nPress 1 For Yes 0 For No :  ";
int c;
cin>>c;
if(c==1)
Exit();
}
else
{
f.Test_Type(id,pa);
cout<<"You Want To Exit.\nPress 1 For Yes 0 For No :  ";;
int c;
cin>>c;
if(c==1)
Exit();
}
}

}
}
return 0;
}
