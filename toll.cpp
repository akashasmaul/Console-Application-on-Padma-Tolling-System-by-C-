#include <iostream>
#include<time.h>        //just to add current time
#include <string.h>     //to compare 2 string

using namespace std;

// Akash, Asmaul Hossain  id: 20-44209-3
class toll
{
public:
    time_t _tm =time(NULL );
    struct tm * curtime = localtime ( &_tm );
    string currentTime = asctime(curtime); //asctime() function takes a pointer tm object as its parameter and returns a text representation for calendar time
    string date = currentTime;
    char car_no[10];
    int ticket_no;
    void vehicleDetails(); //Add vehicle Details
    int searchVehi(char []); //Search a vehicle by registration number
    void printdetails();//prints the details of the vehicle
};

void toll::vehicleDetails()
{
    cout<<"Enter Vehicle Registration Number: ";
    fflush(stdin); //clear the buffer inputs
    cin.getline(car_no,10); //getline() take the char array and its size
    ticket_no+=rand() +700;
    cout<<"Ticket Number: "<<ticket_no<<endl;
    cout<<"Date: "<<date;
}
int toll::searchVehi(char s[]) ////Search a vehicle by registration number
{
    if(strcmp(car_no,s)) //strcmp returns 0 is two strings are same
        return 0;
    else
        return 1;
}
void toll::printdetails() //function defination
{
    cout<<"\t\tPadma Toll Plaza\n"<<endl;
    cout<<"\tDate: "<<date;
    cout<<"\tVehicle Registration Number: "<<car_no<<endl;
    cout<<"\tTicket No: "<<ticket_no<<endl;
    cout<<endl;
}
class proccess : public toll
{
public:

    toll count[100];
    int count_t=0,choice,temp;
    char car_no[10];
    int hd_cost=0,md_cost=0,ld_cost=0,i;

    void host(); // for main menu
    void tollTake(); // toll taking fuction
};
void proccess::tollTake()
{

    cout<<"1.Heavy Duty\n2.Medium Duty\n3.Light Duty\n"<<endl;
    cout<<"Enter the vehicle type: ";
    fflush(stdin); //clear the buffer inputs
    cin>>choice;
    cout<<endl;
    while(1)
    {
        switch(choice)
        {
        case 1:
            count[count_t].vehicleDetails();
            hd_cost +=700;
            count_t++; //this keep on increasing counts the total number of vehicle
            host();
            break;
        case 2:
            count[count_t].vehicleDetails();
            md_cost += 400;
            count_t++;
            host();
            break;
        case 3:
            count[count_t].vehicleDetails();
            ld_cost +=200;
            count_t++;
            host();
            break;

        default:
            cout<<"\tWrong input, try again!"<<endl;;
            tollTake();

        }
    }
}

void proccess::host()
{
    cout<<"\tMain Menu\n";
    cout<<"\n1. Proceed to Toll\n2. Search Vehicle\n3. Toll collection \n4. Emergency Increase Ticket Capacity \n0. Exit \n";
    cout<<"\tSelect option: ";
    int op;
    cin>>op;
    cout<<endl;
    if (op==1)
    {
        tollTake();
        cout<<"\tToll transaction successful"<<endl<<endl;
        host();
    }

    else if(op==2)
    {
        cout<<"Enter Vehicle Registration No: ";
        fflush(stdin); //clears the buffer input
        cin.getline(car_no,10);

        for( i=0; i<=count_t ; i++)
        {
            if(count[i].searchVehi(car_no)) //searches each element
            {
                count[i].printdetails();
                host();
            }
            else
            {
                cout<<"\tNo Information Found\n"<<endl;
                host();
            }
        }
    }
    else if (op==3)
    {
        cout<<"Select Which Sector you Want to See\n"<<endl;
        cout<<"1. Heavy Duty\n2. Medium Duty\n3. Light Duty\n4. Total\n\t :"; //prints the total tax collection
        cin>>temp;
        if(temp==1)
        {
            cout<<"Total Heavy Duty Tax collection:"<<hd_cost<<endl;
            host();
        }
        else if(temp==2)
        {
            cout<<"Total Medium Duty Tax collection:"<<md_cost<<endl;
            host();
        }
        else if(temp==3)
        {
            cout<<"Total Light Duty Tax collection:"<<ld_cost<<endl;
            host();
        }
        else if (temp==4)
        {
            cout<<"Total Toll collection: "<<ld_cost+md_cost+hd_cost<<endl;
            host();
        }
        else
        {
            cout<<"Enter a correct option!"<<endl;
            host();
        }
    }
    else if (op==4)
    {
        cout<<"Enter Numbers of new index: ";
        int size;
        fflush(stdin);
        cin>>size;
        int arrSize=sizeof(count);
        toll *tempArray=new toll[arrSize];
        tempArray[i]= count[i];
        int newSize = arrSize+size;
        toll count[newSize];
        for(int i=0; i<arrSize; i++)
        {
            count[i]=tempArray[i];
        }
        cout<<"\tCapacity Increased"<< endl<<endl;
        host();
    }
    else if (op==0)
    {
        cout<<"\t\t\nExiting"<<endl<<endl;
        cout<<"\t\t\nCreated by Asmaul Hossain Akash."<<endl<<endl;
        exit(0);

    }
    else
    {
        cout<<"\tEnter a correct choice!\n"<<endl;;
        host();
    }
}



int main()
{
    proccess p;

    cout<<"\t\tWelcome to Padma Toll Plaza"<<endl;
    cout<<"\t\tDate: "<<p.date<<endl;

    p.host();
}
