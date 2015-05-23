/* 
 * File:   PersonData.h
 * Author: Owner
 *
 * Created on May 22, 2015, 7:03 PM
 */

#ifndef PERSONDATA_H
#define	PERSONDATA_H
using std::string;
class PersonData{
    private:
        string lastName;
        string firstName;
        string address;
        string city;
        string state;
        int zip;
        int phone;
    public:
        void setLName(string ln)
        {lastName = ln;}
        void setFName(string fn)
        {firstName = fn;}
        void setAddress(string a)
        {address = a;}
        void setCity(string c)
        {city = c;}
        void setState(string s)
        {state = s;}
        void setZip(int z)
        {zip = z;}
        void setPhone(int p)
        {phone = p;}
        string getLName(){return lastName;}
        string getFName(){return firstName;}
        string getAddress(){return address;}
        string getCity(){return city;}
        string getState(){return state;}
        int getZip(){return zip;}
        int getPhone(){return zip;}
};



#endif	/* PERSONDATA_H */

