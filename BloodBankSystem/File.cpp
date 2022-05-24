#include "File.h"
#include <vector>
#include "Recipient.h"
#include"Donor.h"
#include<algorithm>
#include<iostream>

using namespace std;

File::File() {
   
}

void File::fill_VDRequst() {
    fstream file;
    file.open("donation.txt", ios::in);
    char donor[30],type[30], Quantity[30], r_d_day[30], r_d_month[30], r_d_year[30], e_d_day[30], e_d_month[30], e_d_year[30];

    while (!file.eof())
    {
        file.getline(donor, 30, '|');
        file.getline(type, 30, '|');
        file.getline(Quantity, 30, '|');
        file.getline(r_d_day, 30, '-');
        file.getline(r_d_month, 30, '-');
        file.getline(r_d_year, 30, '|');
        file.getline(e_d_day, 30, '-');
        file.getline(e_d_month, 30, '-');
        file.getline(e_d_year, 30, '|');
        DonationRequest d = DonationRequest();
        d.type = type; d.Quantity = Quantity;
        d.received_date = date(r_d_day, r_d_month, r_d_year);
        d.expiry_date = date(e_d_day, e_d_month, e_d_year);
        d.donor= donor;
        DRequst.push_back(d);
    }

    file.close();
}

void File::fill_DRequstFile() {
    fstream Rfile;
    Rfile.open("donation.txt", ofstream::out | std::ofstream::trunc);
    Rfile.close();
    Rfile.open("donation.txt", ios::app);
    for (int i = 0; i < DRequst.size()-1; i++)
    {
        Rfile << DRequst[i].donor << '|' << DRequst[i].type << '|' << DRequst[i].Quantity<< '|' << DRequst[i].received_date.day << '-' << DRequst[i].received_date.month << '-' << DRequst[i].received_date.year << '|';
        Rfile << DRequst[i].expiry_date.day << '-' << DRequst[i].expiry_date.month << '-' << DRequst[i].expiry_date.year<<'|';
    }
    Rfile.close();
}

void File::fill_VDonor() {
    fstream file;
    file.open("data.txt", ios::in);
     
    char  mail[30], password[30], name[30],  gender[30], blood_type[30],disease[30], other_disease[30],id[30], age[30], day[30], month[30], year[30], day2[30], month2[30], year2[30];
    while (!file.eof())
    {
        file.getline(mail, 30, '|');
        file.getline(password, 30, '|');
        file.getline(name, 30, '|');
        file.getline(id, 30, '|');
        file.getline(age, 30, '|');
        file.getline(gender, 30, '|');
        file.getline(blood_type, 30, '|');
        file.getline(day, 30, '-');
        file.getline(month, 30, '-');
        file.getline(year, 30, '|');
        file.getline(day2, 30, '-');
        file.getline(month2, 30, '-');
        file.getline(year2, 30, '|');
        file.getline(disease, 30, '|');
        file.getline(other_disease, 30);

        Donor d = Donor();
        d.mail = mail;
        d.password = password;
        d.name = name;
        d.id =id;
        d.age = age;
        d.gender = gender;
        d.blood_type = blood_type;
        d.Date.day =day;
        d.Date.month = month;
        d.Date.year =year;
        d.Date_donation.day = day2;
        d.Date_donation.month = month2;
        d.Date_donation.year = year2;

        d.disease = disease;
        d.other_disease = other_disease;
        VDonor.push_back(d);
    }

    file.close();
}

void File::fill_VRecipient() {
    fstream file;
    file.open("recdata.txt", ios::in);
    char  mail[30], password[30], name[30], id[30], age[30], gender[30], blood_type[30], hospital[30], case_doctor[30];

    while (!file.eof())
    {
        file.getline(mail, 30, '|');
        file.getline(password, 30, '|');
        file.getline(name, 30, '|');
        file.getline(id, 30, '|');
        file.getline(age, 30, '|');
        file.getline(gender, 30, '|');
        file.getline(blood_type, 30, '|');
        file.getline(hospital, 30, '|');
        file.getline(case_doctor, 30, '|');

        Recipient R = Recipient();
        R.mail = mail;
        R.password = password;
        R.name = name;
        R.id = id;
        R.age = age;
        R.gender = gender;
        R.blood_type = blood_type;
        R.hospital = hospital;
        VRecipient.push_back(R);
    }

    file.close();
}

void File::fill_DFile() {
    fstream file;
    file.open("data.txt", ofstream::out | std::ofstream::trunc);//delete
    file.close();
    file.open("data.txt", ios::app);
    for (int i = 0; i < VDonor.size()-1; i++)
    {
        file << VDonor[i].mail << '|' << VDonor[i].password << '|' << VDonor[i].name << '|' 
            << VDonor[i].id << '|' << VDonor[i].age << '|' << VDonor[i].gender << '|'<< VDonor[i].blood_type << '|' 
            << VDonor[i].Date.day<< '-' << VDonor[i].Date.month << '-' << VDonor[i].Date.year << '|' 
            << VDonor[i].Date_donation.day << '-' << VDonor[i].Date_donation.month << '-' << VDonor[i].Date_donation.year << '|'
            << VDonor[i].disease << '|' << VDonor[i].other_disease;
        file << endl;
    }
    
    file.close();
}

void File::fill_RFile() {
    fstream Rfile;
    Rfile.open("recdata.txt", ofstream::out | std::ofstream::trunc);
    Rfile.close();
    Rfile.open("recdata.txt", ios::app );
    for (int i = 0; i < VRecipient.size()-1; i++)
    {
        Rfile << VRecipient[i].mail << '|' << VRecipient[i].password << '|' << VRecipient[i].name << '|' << VRecipient[i].id << '|' << VRecipient[i].age << '|' << VRecipient[i].gender << '|';
        Rfile << VRecipient[i].blood_type << '|' << VRecipient[i].hospital << '|' << VRecipient[i].case_doctor;
    }
    Rfile.close();
}

File::~File() {

}
