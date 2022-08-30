using namespace std;
#include <iostream>
#include <string.h>
class Staff
{
    private:
    int staff_id,password;
    public:
    Staff()
    {}
    Staff(int staff_id,int password)
    {
        this->staff_id=staff_id;
        this->password=password;
    }
    int get_id()
    {
        return staff_id;
    }
    int get_password()
    {
        return password;
    }
};
class Patient
{
    private:
    int patient_id;
    string patient_name;
    string doctor_name;
    string disease_name;
    public:
    int getid()
    {
        return patient_id;
    }
    void input()
    {
        cout<<"\nEnter the ID of the patient: ";
        cin>>patient_id;
        cin.ignore();
        cout<<"\nEnter the name of the patient: ";
        getline(cin,patient_name);
        cout<<"\nEnter the name of the doctor: ";
        getline(cin,doctor_name);
        cout<<"\nEnter the name of the disease: ";
        getline(cin,disease_name);
    }
    void display()
    {
        cout<<"\nPatient ID:"<<patient_id;
        cout<<"\nPatient Name:"<<patient_name;
        cout<<"\nConsulting doctors name: "<<doctor_name;
        cout<<"\nName of the disease being diagnosed: "<<disease_name;
    }
};
class Admitted_patient:public Patient
{
    private:
    int ward_no;
    string type_ward;
    string days;
    public:
    void input()
    {
        Patient::input();
        cout<<"\nEnter the ward number: ";
        cin>>ward_no;
        cout<<"\nEnter the type of ward: ";
        cin>>type_ward;
        cout<<"\nEnter the number of days of stay: ";
        cin>>days;
    }
    void display()
    {
        Patient::display();
        cout<<"\nWard Number: "<<ward_no;
        cout<<"\nType of ward: "<<type_ward;
        cout<<"\nDays of stay: "<<days;
    }
};
class Normal_patient:public Patient
{
    private:
    string next_appt;
    public:
    void input()
    {
        Patient::input();
        cout<<"\nEnter the date of the next appointment: ";
        getline(cin,next_appt);
    }
    void display()
    {
        Patient::display();
        cout<<"Next appointment date: "<<next_appt;
    }
};
class Bill
{
    private:
    int price[100];
    string product[100];
    int total=0,bill_id,num;
    float cgst,sgst;
    float grand_total;
    public:
    void getItem()
    {
        cout<<"\nEnter the number of medicines to be bought [Max 100 Products]: ";
        cin>>num;
    } 
    void input()
    {
        cout<<"\nEnter the bill ID: ";
        cin>>bill_id;
        cin.ignore();
        for (int i=0;i<num;i++)
        {
            cout<<"\nEnter the product name: ";
            getline(cin,product[i]);
            cout<<"\nEnter the price of the product: ";
            cin>>price[i];
        }
    }
    void calculate()
    {
        for (int i=0;i<num;i++)
        {
            total=total+price[i];
        }
        cgst=total*0.04;
        sgst=total*0.05;
        grand_total=total+cgst+sgst;
    }
    void display(Admitted_patient ap)
    {
        cout<<"--------------------------------------------------BILL-----------------------------------------------";
        ap.display();
        for (int i=0;i<num;i++)
        {
            cout<<"\nProduct Name: "<<product[i]<<"\tProduct Price: "<<price[i];
        }
        cout<<"\nTotal: "<<total;
        cout<<"\nCGST: "<<cgst;
        cout<<"\nSGST: "<<sgst;
        cout<<"\nGrand Total: "<<grand_total;
    }
    void display(Normal_patient np)
    {
        cout<<"-----------------------------------------------BILL-------------------------------------------------";
        np.display();
        for (int i=0;i<num;i++)
        {
            cout<<"\nProduct Name: "<<product[i]<<"\tProduct Price: "<<price[i];
        }
        cout<<"\nTotal: "<<total;
        cout<<"\nCGST: "<<cgst;
        cout<<"\nSGST: "<<sgst;
        cout<<"\nGrand Total: "<<grand_total;
    }
};
int main()
{
    int num,ch,i,x=0,y=0,a=0;
    int temp_id,temp_password;
    Staff staff[100];
    Bill bill[100];
    int staff_index;
    Normal_patient np[100];
    Admitted_patient ap[100];
    cout<<"\nEnter the number of Staff you want to register: ";
    cin>>num;
    for (i=0;i<num;i++)
    {
        cout<<"\nEnter the ID for the Employee: ";
        cin>>temp_id;
        cout<<"\nEnter the password: ";
        cin>>temp_password;
        Staff temp(temp_id,temp_password);
        staff[i]=temp;
    }
    cout<<"----------------------------------------------RUGVED HOSPITAL------------------------------------";
    cout<<"----------------------------------------------STAFF LOG IN-----------------------------------------";
    cout<<"\nEnter your ID: ";
    cin>>temp_id;
    for (i=0;i<num;i++)
    {
        if (staff[i].get_id()==temp_id)
        {
            staff_index=i;
            break;
        }
    }
    cout<<"\nEnter your password: ";
    cin>>temp_password;
    if (staff[staff_index].get_password()==temp_password)
    {
        while(1)
        {
            cout<<"\nPress 1 to Admit a New patient\nPress 2 to Check out and get Bill of the patient\nPress 3 to exit";
            cout<<"\nEnter your choice: ";
            cin>>ch;
            if (ch==1)
            {
                cout<<"\nPress 1 to for Admitting a patient\nPress 2 for a normal patient";
                cout<<"\nEnter your choice: ";
                cin>>ch;
                if (ch==1)
                {
                    ap[x].input();
                    cout<<"\n--------------------------------------------------------------------------------------------------\n";
                    ap[x].display();
                    cout<<"\n=======================================DATA SAVED SUCCESSFULLY!=====================================";
                    x++;
                }
                else if (ch==2)
                {
                    np[y].input();
                    cout<<"\n----------------------------------------------------------------------------------------------------\n";
                    np[y].display();
                    cout<<"\n=========================================DATA SAVED SUCCESSFULLY!=======================================";
                    y++;
                }
                else
                {
                    cout<<"\nInvalid input!";
                }
            }
            else if (ch==2)
            {
                cout<<"\nPress 1 for admitted patient\nPress 2 for Normal patient";
                cin>>ch;
                if (ch==1)
                {
                    cout<<"\nEnter the ID of the patient: ";
                    cin>>temp_id;
                    for (i=0;i<x;i++)
                    {
                        if (ap[i].getid()==temp_id)
                        {
                            staff_index=i;
                            break;
                        }
                    }
                    bill[a].getItem();
                    bill[a].input();
                    bill[a].calculate();
                    bill[a].display(ap[staff_index]);
                    a++;
                }
                else if (ch==2)
                {
                    cout<<"\nEnter the ID of the patient: ";
                    cin>>temp_id;
                    for (i=0;i<y;i++)
                    {
                        if (np[i].getid()==temp_id)
                        {
                            staff_index=i;
                            break;
                        }
                    }
                    bill[a].getItem();
                    bill[a].input();
                    bill[a].calculate();
                    bill[a].display(np[staff_index]);
                    a++;
                }
            }
            else if (ch==3)
            {
                exit(0);
            }
            else
            {
                cout<<"\nInvalid input!";
            }
        }
    }
    else 
    {
        cout<<"\nInvalid login credentials!";
    }
    return 0;
}
