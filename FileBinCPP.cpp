#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>
using namespace std;
class Contact{
    private: 
    string name;
    string telegram;
    int year,month,day;
    public:
    Contact(string n,string t,int y,int m,int d)
    :year(y),month(m),day(d){
        name = n;
        telegram = t;
    }
    Contact():Contact("","" ,0,0,0){} //constrictor  delegation
    friend ostream&operator<<(ostream&os,const Contact&c);
    friend istream &operator>>(istream &is, Contact &c);
    
    void writeToFile(ofstream&fout){
        int len = name.length();
        fout.write((char*)&len,sizeof(int));
        fout.write(name.c_str(),sizeof(char)*len);

        len = telegram.length();
        fout.write((char*)&len,sizeof(int));
        fout.write(telegram.c_str(),sizeof(char)*len);

        fout.write((char*)&year,sizeof(int));
        fout.write((char*)&month,sizeof(int));
        fout.write((char*)&day,sizeof(int));
    }
    void readFromFile(ifstream&fin){
      int len;
        fin.read((char*)&len,sizeof(int));
        char *str = new char[len+1]{0};
        fin.read(str,sizeof(char)*len);
        name = str;
        
        fin.read((char*)&len,sizeof(int));
        str = new char[len+1]{0};
        fin.read(str,sizeof(char)*len);
        telegram = str;
        fin.read((char*)&year,sizeof(int));
        fin.read((char*)&month,sizeof(int));
        fin.read((char*)&day,sizeof(int));
    }

};
int main(){
    // ofstream fout("contacts2.txt", ios::out|ios::binary);
    // if(fout){
    //     Contact c("Dara","012365478",2000,12,21);
    //     c.writeToFile(fout);
    //     fout.close();
    // }
    ifstream fin("contacts2.txt",ios::in|ios::binary);
    if(fin){
        Contact c;
        c.readFromFile(fin);
        cout<<c<<endl;
       fin.close();
    }else cout<<"Unable to open file"<<endl;

    return 0;
}

ostream &operator<<(ostream &os, const Contact &c)
{
    os  << c.name<<endl
        << c.telegram<<endl
        << c.year<<endl
        << c.month<<endl
        << c.day<<endl;
    return os;
}

istream &operator>>(istream &is, Contact &c)
{
    is>>c.name;//getline(is,c.name);//name contains spaces
    is>>c.telegram;
    is>>c.year>>c.month>>c.day;
    return is;
}