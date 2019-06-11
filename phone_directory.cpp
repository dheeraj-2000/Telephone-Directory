//Telephone Directory

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;
class phoneBook{
    char name[20],phno[15];
    public:
    void getdata();
    void showdata();
    char *getname(){ return name; }
    char *getphno(){ return phno; }
    void update(char *nm,char *telno){
        strcpy(name,nm);
        strcpy(phno,telno);
    }
};

void phoneBook :: getdata(){
    cout<<"\nEnter New record Details";
    cout<<"\nEnter New Name : ";
    cin>>name;
    cout<<"Enter New Telephone Number : ";
    cin>>phno;
}

void phoneBook :: showdata(){
    cout<<"\n";
    cout<<setw(20)<<name;
    cout<<setw(15)<<phno;
}


int main(){
    phoneBook rec;
    int flag;
    fstream file;
    char ch,nm[20],telno[15];
    int choice,found=0;
    while(1){
        cout<<"\n\t*****PHONE BOOK*****\n";
        cout<<"1) Add New Record\n";
        cout<<"2) Display All Records\n";
        cout<<"3) Search Telephone Number\n";
        cout<<"4) Search Person's Name\n";
        cout<<"5) Update Telephone Number\n";
        cout<<"6) Delete Telephone Number\n";
        cout<<"7) Exit\n\n";
        cout<<"Select your choice : ";
        cin>>choice;
        switch(choice){
            case 1 : //New Record
                  file.open("/home/dheeraj/Desktop/c++project/phonebk.dat", ios::out | ios::app|ios::binary);
                  rec.getdata();
                  rec.showdata();
                  file.write((char *) &rec, sizeof(rec));
                  file.close();
                  break;

            case 2 : //Display All Records
                  file.open("/home/dheeraj/Desktop/c++project/phonebk.dat", ios::in|ios::binary);
                  char ch,nm[20],telno[6];
                  file.seekg(0,ios::beg);
                  cout<<"\n\nRecords in Phone Book\n\n";
                  while(file.read((char *) &rec, sizeof(rec))){
                        rec.showdata();
                  }
                  file.close();
                  break;

            case 3 : //Search Tel. no. when person's name is known.
                  file.open("/home/dheeraj/Desktop/c++project/phonebk.dat", ios::in|ios::binary);
                  cout<<"\n\nEnter Name of the Person : ";
                  cin>>nm;
                  file.seekg(0,ios::beg);
                  found=0;
                  while(file.read((char *) &rec, sizeof(rec))){
                    if(strcmp(nm,rec.getname())==0){
                        found=1;
                        rec.showdata();
                    }
                  }
                  file.clear();
                  if(found==0)
                     cout<<"\n\tWARNING: Record Not found \n\n";
                  getchar();
                  file.close();
                  break;

            case 4 : //Search name on basis of tel. no
                 file.open("/home/dheeraj/Desktop/c++project/phonebk.dat", ios::in|ios::binary);
                 cout<<"\n\nEnter Telephone Number of the person : ";
                 cin>>telno;
                 file.seekg(0,ios::beg);
                 found=0;
                 while(file.read((char *) &rec, sizeof(rec))){
                    if(strcmp(telno,rec.getphno())==0){
                        found=1;
                        rec.showdata();
                    }
                 }
                 file.clear();
                 if(found==0)
                    cout<<"\n\tWARNING: Record Not found \n\n";
                 getchar();
                 file.close();
                 break;

            case 5 : //Update Telephone No.
                 file.open("/home/dheeraj/Desktop/c++project/phonebk.dat", ios::in|ios::out|ios::binary|ios::ate);
                 cout<<"\n\nEnter Name : ";
                 cin>>nm;
                 file.seekg(0);
                 while(file.read((char *) &rec, sizeof(rec)))
                 {
                    if(strcmp(nm,rec.getname())==0)
                    {
                        cout<<"Enter New Telephone Number"<<endl;
                        cin>>telno;
                        file.seekp(-sizeof(rec),ios::cur);
                        rec.update(nm,telno);
                        file.write((char *) &rec, sizeof(rec));
                    }
                 }
                 file.clear();
                 file.close();
                 break;

            case 6 :{//Delete
                  fstream temp1;
                  temp1.open("/home/dheeraj/Desktop/c++project/tempbk.dat", ios::out|ios::binary|ios::app);
                  file.open("/home/dheeraj/Desktop/c++project/phonebk.dat", ios::in|ios::binary);
                  cout<<"\n\nEnter Name You want to Delete : ";
                  cin>>nm;
                  file.seekg(0);
                  while(1){
                    flag=0;
                    file.read((char *) &rec, sizeof(rec));
                    if(file.eof()) break;
                    if(strcmp(nm,rec.getname())==0){
                      flag++;
                    }
                    if(!flag)
                          temp1.write((char *) &rec, sizeof(rec));
                  }
                  file.close();
                  temp1.close();
                  remove("/home/dheeraj/Desktop/c++project/phonebk.dat");
                  rename("/home/dheeraj/Desktop/c++project/tempbk.dat","/home/dheeraj/Desktop/c++project/phonebk.dat");
                  break;}

               case 7 : //file.close();
                      exit (0);

             default : std::cout << "\n\t wrong choice !" << '\n';
        }
    }
return 0;
}
