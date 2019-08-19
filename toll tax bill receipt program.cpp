/* *******************************************************************************************************
********************TOLL TAX BILL RECEIPT AND RECORDS MANAGING SOFTWARE***********************************
**********************************************************************************************************
************************FOR CBSE 2017-18 12TH CLASS BOARD EXAMINATION*************************************
******************************************************************************************************* */
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<time.h>						//for time_t -> take time now
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<ctype.h>						//for toupper
#include<iomanip.h>
void curtime();
char *i8,*i7,*i6,*i5,*i4,*i3,*i2,*i1, *nowstring;
unsigned long mon[5];
class moneymanage												
{
	public:
		unsigned long monman[5];
		void moneyfile();
		~moneymanage()
		{
		}
}manager;
/*
***********************************
***Saving Payable amount to file***
***********************************
*/
void moneymanage :: moneyfile()
{
	for(int i=0;i<5;i++)
		monman[i] = mon[i];
	ofstream file[5];
	file[0].open("moneya.lst", ios::out | ios::trunc);
	file[1].open("moneyb.lst",ios:: out | ios::trunc);
	file[2].open("moneyc.lst",ios:: out | ios::trunc);
	file[3].open("moneyd.lst",ios:: out | ios::trunc);
	file[4].open("moneye.lst",ios:: out | ios::trunc);
	for(i=0; i<5; i++)
	{
		file[i]<<monman[i];
		file[i].close();
	}
}
/*
********************************
***RECORDS MANIPULATING CLASS***
********************************
*/
class manipulate
{
	private:
		char vehnum[15];
		char vehicle_type[25];
		char paymode[20];
		char toll_collector[15];
		unsigned long money;
		unsigned long lane_id;
		unsigned long transaction_id;
		unsigned long receipt_no;
	protected:
	public:
		void getmoney();
		void getvehnum();
		void lanetollfile();
		void filetomem();
		void moneymanip();
		void applychoose();
		void applyvehtype();
		unsigned long retmoney()
		{
			return money;
		}
		unsigned long retlane()
		{
			return lane_id;
		}
		unsigned long rettrans()
		{
			return transaction_id;
		}
		unsigned long retrecp()
		{
			return receipt_no;
		}
		char * retnum()
		{
		return vehnum;
		}
		char * rettype()
		{
			return vehicle_type;
		}
		char * retpay()
		{
			return paymode;
		}
		char * rettoll()
		{
			return toll_collector;
		}
		void inittran(unsigned long tran)
		{
			transaction_id = tran;
		}
		void initrecep(unsigned long recp)
		{
			receipt_no = recp;
		}
		void gettoll()
		{
			memset(toll_collector, ' ', 15);
			gets(toll_collector);
			for(int i = 0; i<strlen(toll_collector); i++)				
				toll_collector[i] = toupper(toll_collector[i]);
		}
		void getlane()
		{
			cin>>lane_id;
		}
		void gettrans()
		{
			cin>>transaction_id;
		}
		void getrecep()
		{
			cin>>receipt_no;
		}
		void applymoney(unsigned long pesa)
		{
			money = pesa;
		}
		void paym(char *payarr)
		{
			memset(paymode, ' ', 20);
			strcpy(paymode,payarr);
		}
		void veht(char *vehtype)
		{
			memset(vehicle_type, ' ', 25);
			strcpy(vehicle_type, vehtype);
		}
		manipulate()
		{
			lane_id = transaction_id = receipt_no = 0;				
		}
		~manipulate()
		{
		}
};
void manipulate :: applychoose()
{
	int choose;
	cout<<"\n 1. CASH \n 2. DEBIT / CREDIT CARD \n 3. PARTNERS \n";
	cout<<"Enter your choice for payment type (1/2/3) \n";
	cin>>choose; 
	switch(choose)
	{
		case 1: strcpy(paymode, "CASH");
				break;
		case 2: strcpy(paymode, "DEBIT/ CREDIT CARD");
				break;
		case 3: strcpy(paymode, "PARTNERS");
				break;
		default:cout<<"Worong choice. Select again(1/2/3) \n";
				applychoose();
				break;
	}
}
void manipulate :: applyvehtype()
{
	int choose;
	cout<<"1. Car/Jeep/Van \n";
	cout<<"2. Mini Bus/ Tempo \n";
	cout<<"3. Bus/ Truck \n";
	cout<<"4. 3 Axle Vehicle";
	cout<<"5. More than 3 Axle Vehicle \n";
	cout<<"Enter your choice for vehicle type (1/2/3/4/5) \n";
	cin>>choose;
	switch(choose)
	{
		case 1: strcpy(vehicle_type,"CAR/JEEP/VAN");
				break;
		case 2: strcpy(vehicle_type,"MINI BUS/ TEMPO");
				break;
		case 3: strcpy(vehicle_type,"BUS/ TRUCK");
				break;
		case 4: strcpy(vehicle_type,"3 AXLE VEHICLE");
				break;
		case 5: strcpy(vehicle_type,"MORE THAN 3 AXLE VEHICLE");
				break;
		default:cout<<"Wrong choice. Select again(1/2/3/4/5)";
				applyvehtype();
				break;
	}
}
void manipulate :: getmoney()
{
	cout<<i6<<" Payable amount \n \n \n ";
	cout<<i8<<" Car/Jeep/Van \t \t \t";
	cin>>mon[0];
	cout<<i8<<" Mini Bus/Tempo \t \t \t";
	cin>>mon[1];
	cout<<i8<<" Bus/ Truck \t \t \t \t";
	cin>>mon[2];
	cout<<i8<<" 3 Axle Vehicle \t \t \t";
	cin>>mon[3];
	cout<<i8<<" More than 3 Axle Vehicle \t \t";
	cin>>mon[4];
	manager.moneyfile();
}
void manipulate :: getvehnum()
{
	memset(vehnum, ' ', 15);
	cout<<endl;
	gets(vehnum);
	for(int i=0; i<strlen(vehnum); i++)
		vehnum[i] = toupper(vehnum[i]);
}
void manipulate :: lanetollfile()			
{
	ofstream file;
	file.open("lane.lst", ios::out | ios:: trunc);
	file<<lane_id;
	file.close();
	file.open("collector.lst", ios:: out | ios::trunc);
	file.write((char*)&toll_collector, sizeof(toll_collector));
	file.close();
}
/*
***************************************************
***SAVING LANE NUMBER AND COLLECTOR NAME TO FILE***
***************************************************
*/
void manipulate :: filetomem()					
{
	ifstream file;
	file.open("lane.lst", ios::in | ios::ate);
	file.seekg(0, ios::beg);
	file>>lane_id;
	file.close();
	file.open("collector.lst", ios::in | ios::ate);
	file.seekg(0, ios::beg);
	file.read((char*)&toll_collector, sizeof(toll_collector));
	file.close();
}
/*
************************************
***SAVING PAYABLE AMOUNT TO FILES***
************************************
*/
void manipulate :: moneymanip()
{
	ifstream file[5];
	file[0].open("moneya.lst", ios::in | ios::ate );
	file[1].open("moneyb.lst", ios::in | ios::ate );
	file[2].open("moneyc.lst", ios::in | ios::ate );
	file[3].open("moneyd.lst", ios::in | ios::ate );
	file[4].open("moneye.lst", ios::in | ios::ate );
	file[0].seekg(0, ios::beg);
	file[1].seekg(0, ios::beg);
	file[2].seekg(0, ios::beg);
	file[3].seekg(0, ios::beg);
	file[4].seekg(0, ios::beg);
	for(int i = 0; i<5 ;i++)
	{
		file[i]>>manager.monman[i];
		file[i].close();
	}
	for(i= 0; i<5; i++)
		mon[i] = manager.monman[i];						
}
/*
******************************
***RECORDS MANAGEMENT CLASS***
******************************
*/
class bill
{
	public:
		int condition;
		manipulate taker, *ptrtaker, temp;
		manipulate var1;
		char wisdom[20];
		char nameofplaza[50];
		int loophole;
		bill()
		{
			strings();
		}
		void strings()
		{
			i1 = "Vehicle Number";
			i2 = "Vehicle Type";
			i3 = "Paymode";
			i4 = "Toll Collector";
			i5 = "Lane Number";
			i6 = "Enter ";
			i7 = "Toll pay";
			i8 = "For";
		}
		void moneychart()
		{
			var1.getmoney();
		}
/*
*******************************
***SAVING PLAZA NAME TO FILE***
*******************************
*/
		void nameplaza()
		{
			memset(nameofplaza, ' ', 60);
			cout<<"Enter the name of Toll plaza. \n";
			gets(nameofplaza);
			for(int i = 0; i<strlen(nameofplaza); i++)				
				nameofplaza[i] = toupper(nameofplaza[i]);
			fileplaza();
			cout<<"\n Toll Plaza Name updated successfully.! \n";
			getch();
		}
		void fileplaza()
		{
			ofstream file;
			file.open("Plazan.lst", ios::out| ios::trunc | ios::binary);
			file.write((char*)&nameofplaza, sizeof(nameofplaza));
			file.close();
		}
		void constants();
		void getdata();
		void cond(int x);
		void transidgen();
		void recpidgen();
		void recordhandle();
		void billhandle(manipulate &gorg, int hole);
		void search();
		void choicesear(manipulate &x, int y);
		int displaydata(manipulate &getter);
		void alldisplay();
		void modify();
		void deleter();
		void tool();
		void dismoddelrecs(int x);
		void changedrec(int flag);
		void totaltax(unsigned long x);
		void showcoll();
		void showmon();
		~bill()
		{
			
		}
};
void bill:: constants()
{
	cout<<i6<<i4<<"\t \t";
	var1.gettoll();
	cout<<i6<<i5<<"\t \t";
	var1.getlane();
	var1.lanetollfile();
	cout<<"\n Given Information Updated successfully.! \n";
}
void bill :: getdata()
{
	int x = 0;
	char ch ;
	cout<<i6<<i1;
	var1.getvehnum();
	cout<<endl;
	cout<<i6<<i2;
	cond(x);
	cout<<endl;
	cout<<i6<<i3;
	cond(x+1);
	var1.filetomem();				
}
void bill :: cond(int x)
{
	clrscr();
	char payarr[20];
	char vehtype[25];
	memset(vehtype, ' ', 25);
	memset(payarr, ' ', 20);
	if(x==0)
	{
		cout<<"1. Car/Jeep/Van \n 2. Mini Bus/ Tempo \n 3. Bus/ Truck \n 4. 3 Axle Vehicle \n 5. More than 3 Axle Vehicle \n";
		cout<<"Enter your choice for vehicle type(1/2/3/4/5) \n";
		cin>>condition;
		var1.moneymanip();						
		switch(condition)
		{	case 1: strcpy(vehtype, "CAR/JEEP/VAN");
					var1.applymoney(mon[0]);
					break;
			case 2: strcpy(vehtype,"MINI BUS/ TEMPO");
					var1.applymoney(mon[1]);
					break;
			case 3: strcpy(vehtype,"BUS/ TRUCK");
					var1.applymoney(mon[2]);
					break;
			case 4: strcpy(vehtype,"3 AXLE VEHICLE");
					var1.applymoney(mon[3]);
					break;
			case 5: strcpy(vehtype,"MORE THAN 3 AXLE VEHICLE");
					var1.applymoney(mon[4]);
					break;
			default:cout<<"Wrong Input";
					clrscr();
					cond(x);
					break;
		}
		var1.veht(vehtype);
	}
	else if(x==1)
	{
		cout<<"1. CASH \n 2. DEBIT/CREDIT CARD \n 3. PARTNERS(Online payment applications) \n";  
		cout<<"Enter your choice for payment type(1/2/3) \n";
		cin>>condition;
		switch(condition)
		{
			case 1: strcpy(payarr, "CASH");
					break;
			case 2: strcpy(payarr, "DEBIT/CREDIT CARD");
					break;
			case 3:	strcpy(payarr, "PARTNERS");					
					break;
			default:cout<<"Wrong Input";
					clrscr();
					cond(x);
					break;
		}
		var1.paym(payarr);
	}
	else
		cout<<"Wrong input";
}
/*
**********************************************
***Creating Random Value And saving to file***
**********************************************
*/
void bill :: transidgen()			
{								
	randomize();
	ifstream file1;
	ofstream file2;
	int post = 0;
	struct jugaad
	{
		char a;
		unsigned long tran;		
		char b;
		jugaad()
		{
			a = 'a';
			b = 'b';
			tran = (rand() % (4294967295 - 10000000000)) + 10000000000 + 1;			//For maximum and minimum random value
		}
	}num1, num2;
	file2.open("transi.lst", ios::out | ios::app | ios::binary | ios::nocreate);
	if(!file2)
	{
		file2.close();
		file2.open("transi.lst", ios::in | ios::binary | ios::app);
		file2.write((char*)&num1, sizeof(jugaad));
		file2.close();
		post = 2;
	}
	else
	{
		post = 1;
	}
	file2.close();
	if(post == 1)
	{
		file1.open("transi.lst", ios::in | ios::binary);
		file1.seekg(0,ios::beg);
		file2.open("transi.lst",ios::out | ios::app | ios::binary);
		while(file1.read((char*)&num2, sizeof(jugaad)))
		{
			if(num1.tran == num2.tran)
			{
				num1.tran = (rand() % (4294967295 - 10000000000)) + 10000000000 + 1;
				file1.seekg(0,ios::beg);
			}
		}
		file2.seekp(0, ios::end);
		file2.write((char*)&num1, sizeof(jugaad));
	}
	file1.close();
	file2.close();
	var1.inittran(num1.tran);
}
//***Creating Successive Receipt Id***
void bill :: recpidgen()
{
	fstream file;
	unsigned long recep = 0;
	file.open("receipti.lst", ios::in | ios::out | ios::ate | ios::binary);
	if(file.tellg()>= 1)
	{
		file.seekg(0,ios::beg);
		file>>recep;
	}
	recep += 1;
	file.seekg(0,ios::beg);
	file<<recep;
	file.close();
	var1.initrecep(recep);
}
//***Saving Records To File***
void bill :: recordhandle()
{
	ofstream file;
	transidgen();
	recpidgen();
	file.open("Records.lst", ios:: out | ios::app | ios::binary);
	file.write((char*)&var1, sizeof(manipulate));
	file.close();
	billhandle(var1, 0);
}
/*
***************************
***Creating Bill Receipt***
***************************
*/
void bill :: billhandle(manipulate &gorg, int hole)		
{
	ofstream file;
	ifstream file1;
	if(hole == 0)
		file.open("Bill.docx", ios::out | ios::binary | ios::trunc);
	else if(hole == 1 || hole == 2)
		file.open("ChangedR.docx", ios::out | ios::binary | ios::app);
	else
		cout<<"Wrong parameter!";
	file<<"----------------------------------------------------------------- \n";
	file1.open("plazan.lst", ios::in | ios::binary);
	file1.seekg(0, ios::beg);
	file1.read((char*)&nameofplaza, sizeof(nameofplaza));
	file1.close();
	for(int k = 0; k<(30 - strlen(nameofplaza)/2); k++)
		file<<' ';
	for(int i =0; nameofplaza[i]!='\0';i++){file<<nameofplaza[i];}
	file<<'\n';
	curtime();
	file<<nowstring;
	file<<"\n\t Receipt Id: \t"<<gorg.retrecp()<<"\n";
	file<<"\n\t Transaction Id: "<<gorg.rettrans()<<"\n";
	file<<"\n\t Vehicle Number: \t"<<gorg.retnum()<<"\n";
	file<<"\n\t Vehicle Type: \t"<<gorg.rettype()<<"\n";
	file<<"\n\t Payment mode: \t"<<gorg.retpay()<<"\n";
	file<<"\n\t Toll Collector: \t"<<gorg.rettoll()<<"\n";
	file<<"\n\t Toll Tax: \t \t"<<gorg.retmoney()<<"\n";
	file<<"\n\t Lane number: \t"<<gorg.retlane()<<"\n";
	
	if(hole ==1 || hole == 2)
		file<<"\n Reason: \t \t"<<wisdom;
	if(hole == 1)
		file<<"\n \n \t \t \t \t Source: \t Modified \n \n";
	else if( hole == 2)
		file<<"\n \n \t \t \t \t Source: \t Deleted \n \n";
	file<<"----------------------------------------------------------------- \n \n";
	
	file.close();
}
/*
***************
***Searching***
***************
*/
void bill :: search()
{
	clrscr();
	int flag=0, flag1 = 0;
	int tell;
	int show=0;
	char conf = 'y';
	manipulate searcher;
	cout<<"Search by: \n";
	cout<<" 1. Transaction id \n 2. Receipt Id \n 3. Lane number \n 4. Toll collector \n 5. Paymode \n 6. Vehicle type \n 7. Vehicle number \n";
	cin>>condition;
	if(condition > 8 && condition < 1)
	{
		cout<<"Wrong Choice. Try Again";
		getch();
		search();
	}
	choicesear(searcher, condition);
	ifstream file;
	file.open("Records.lst", ios:: in | ios::binary);
	file.seekg(0, ios::end);
	tell = file.tellg();
	file.seekg(0, ios::beg);
	while(file.read((char*)&taker, sizeof(manipulate)))
	{
		switch(condition)
		{
			case 1: if(searcher.rettrans() == taker.rettrans())
					{
						show = displaydata(taker);
						flag++;
					}	
					break;
			case 2:	if(searcher.retrecp() == taker.retrecp())
					{
						show = displaydata(taker);
						flag++;
					}
					break;
			case 3:	if(searcher.retlane() == taker.retlane())
					{
						show = displaydata(taker);
						flag1 = 1;
					}
					else
						flag1 = 0;
					goto pahoch;
			case 4: if(strcmpi(searcher.rettoll() , taker.rettoll())==0)
					{
						show = displaydata(taker);
						flag1 = 1;
					}
					else
						flag1 = 0;
					goto pahoch;
			case 5: if(strcmpi(searcher.retpay() , taker.retpay())==0)
					{
						show = displaydata(taker);
						flag1 = 1;
					}	
					else
						flag1 = 0;
					goto pahoch;
			case 6: if(strcmpi(searcher.rettype() , taker.rettype())==0)
					{
						show = displaydata(taker);
						flag1 = 1;
					}	
					else
						flag1 = 0;
					goto pahoch;
			case 7: if(strcmpi(searcher.retnum() , taker.retnum())==0  )
					{
						show = displaydata(taker);
						flag1 = 1;
					}	
					else
						flag1 = 0;
					goto pahoch;
			default:file.close();
					cout<<"Wrong Choice. Try Again. \n";
					getch();
					search();
		}
		pahoch:
		if(flag1==1 || flag == 1)
			ptrtaker =& taker;
		if(flag1 == 1)
		{
			if(tell == file.tellg())
				break;
			cout<<"Do you want to show more? (y/n)";
			cin>>conf;
			if(conf == 'n')
				break;
		}
		if(flag == 1)
			break;
	}
	if(show != 999)
	{
		cout<<"No Record Found!";
		loophole = 1;
		getch();
	}
	file.close();
}
void bill :: choicesear(manipulate &x, int y)
{
	int choose;
	cout<<"Enter with which you want to search: \n";
	switch(y)
	{
		case 1: x.gettrans();
				break;
		case 2: x.getrecep();
				break;
		case 3: x.getlane();
				break;
		case 4: x.gettoll();
				break;
		case 5:	x.applychoose();
				break;
		case 6: x.applyvehtype();
				break;
		case 7: x.getvehnum();
				break;
		default:cout<<"No such record found.";
	}
}
//***Display Records***
int bill :: displaydata(manipulate &getter)
{
	clrscr();
	cout<<"\n \n \n \n \n \n ";
	cout<<"\t \t \t Transaction number: "<<'\t'<<getter.rettrans()<<endl<<endl;
	cout<<"\t \t \t Receipt number:"<<"\t"<<getter.retrecp()<<endl<<endl;
	cout<<"\t \t \t "<<i5<<"\t \t"<<getter.retlane()<<endl<<endl;
	cout<<"\t \t \t "<<i4<<"\t \t"<<getter.rettoll()<<endl<<endl;
	cout<<"\t \t \t "<<i3<<"\t \t"<<getter.retpay()<<endl<<endl;
	cout<<"\t \t \t "<<i2<<"\t \t"<<getter.rettype()<<endl<<endl;
	cout<<"\t \t \t "<<i1<<"\t \t"<<getter.retnum()<<endl<<endl;
	cout<<"\t \t \t "<<i7<<"\t \t"<<getter.retmoney()<<endl<<endl;
	getch();
	return (999);
}
//***Displaying All Records***
void bill :: alldisplay()
{
	ifstream file;
	int flag = 0;
	file.open("Records.lst", ios:: in | ios::binary);
	file.seekg(0,ios::end);
	if(file.tellg()== 0)
	{
		cout<<"No records found";
		getch();
	}
	else
	{
		file.seekg(0,ios::beg);
		manipulate displaymaster;
		char conf = 'y';
		for(;file.read((char*)&displaymaster,sizeof(manipulate));)
		{
			if (flag ==1)
			{
				if(!file.eof())
				{
					cout<<"Do you want to show more?(y/n) \n";
					cin>>conf;
					if(conf == 'n' || conf == 'N')
						break;
				}
			}
			displaydata(displaymaster);
			flag = 1;
		}	
	}
	file.close();
}
/*
***************
***Modifying***
***************
*/
void bill :: modify()
{
	search();
	int flag = 0;
	int size = sizeof(manipulate);
	char qwerty = 'y';
	size *= -1;
	fstream file;
	ofstream file1;
	file1.open("Mrecs.lst", ios::out | ios::app);					
	file.open("Records.lst", ios::out | ios::ate | ios::in | ios::binary );
	file.seekg(0, ios::beg);
	manipulate matcher;
	tool();
	if(loophole == 1)
	{
		cout<<"Record not found!";
		getch();
		goto label;
	}
	cout<<"Do you really want to modify this record?(y/n)\n";
	cin>>qwerty;
	if(qwerty != 'y')
		goto label;
	cout<<"\nOkay. Last record was selected for modifying \n";
	cout<<endl<<"Why do you want to modify?(max 20 char)";
	gets(wisdom);
	mod:
		cout<<"What do you want to modify?";
		cout<<endl<<"1. vehnum \n 2. vehicle type \n 3. payment mode \n 4. All of the above ";
		cin>>condition;
		switch(condition)
		{
			case 1: cout<<"Enter vehicle number \n";
					taker.getvehnum();
					break;
			case 2: cout<<"Enter for new vehicle type.";
					taker.applyvehtype();
					break;
			case 3: cout<<"Enter for new Pay mode.";
					taker.applychoose();
					break;
			case 4: cout<<"Enter vehicle number \n";
					taker.getvehnum();
					clrscr();
					cout<<"Enter vehicle type: \n";
					taker.applyvehtype();
					clrscr();
					cout<<"Enter pay mode: ";
					taker.applychoose();
					clrscr();
					break;
			default:cout<<"Wrong choice. Try Again.";
					goto mod;
		}
		while(file.read((char*)&matcher, sizeof(manipulate)))
		{
			if(matcher.retrecp()== temp.retrecp())
			{	
				file1.write((char*)&temp, sizeof(manipulate));
				file.seekg(size, ios::cur);
				file.write((char*)&taker, sizeof(manipulate));
				break;
			}
		}
		clrscr();
		cout<<"Record modified successfully!\n\n\n";
		cout<<"Press enter to show the new record: ";
		getch();
		displaydata(taker);
		getch();
		changedrec(flag);
		file1.close();
		file.close();
		label:	;
}
/*
**************
***Deleting***
**************
*/
void bill :: deleter()
{
	search();
	tool();
	int flag =1;
	char qwerty = 'y';
	fstream file, file1;
	ofstream filefile;
	filefile.open("Drecs.lst", ios::out | ios::app);
	file.open("Records.lst", ios::out | ios::ate | ios::in | ios::binary);
	file.seekg(0, ios::beg);
	file1.open("Deletedscenes.lst", ios:: out | ios::ate | ios::in| ios::binary);
	manipulate matcher;
	if(loophole == 1)
		goto label;
	cout<<"\n Do you really want to delete this record?(y/n) \n";
	cin>>qwerty;
	if(qwerty != 'y')
		goto label;
	cout<<"\n Okay. Last record was selected for deleting \n";
	cout<<"Why do you want to delete this record?";
	gets(wisdom);
	while(file.read((char*)&matcher, sizeof(manipulate)))
	{
		if (temp.retrecp() == matcher.retrecp())
		{
			filefile.write((char*)&temp, sizeof(manipulate));			
		}
		else
			file1.write((char*)&matcher, sizeof(manipulate));
	}
	clrscr();
	cout<<"\n Successfully Deleted the record! \n\n\n";
	getch();
	totaltax(temp.retmoney());
	file.close();
	filefile.close();
	file1.close();
	remove("Records.lst");
	rename("Deletedscenes.lst", "Records.lst");
	cout<<"Press enter to show the deleted record: ";
	getch();
	displaydata(temp);
	changedrec(flag);
	label:;
}
void bill :: tool()
{
	fstream file;
	file.open("Records.lst", ios::out | ios::ate | ios::in | ios::binary);
	file.seekg(0, ios::beg);
	while(file.read((char*)&temp, sizeof(manipulate)))
	{
		if(temp.rettrans() == ptrtaker->rettrans())
		{
			loophole = 0;
			break;
		}
		else 
			loophole = 1;
	}
	file.close();
}
//***Saving Changed Records***
void bill :: changedrec(int flag)					
{
	tool();
	billhandle(temp, flag+1);						
}
//***Displaying Changed Records***
void bill :: dismoddelrecs(int x)					
{
	ifstream file;
	manipulate nostalgia;
	int recnum;
	int flag = 0;
	char condition;
	if(x==0)
		file.open("Mrecs.lst", ios::in);
	else
		file.open("Drecs.lst", ios::in);
	if(!file)
	{
		cout<<"No record found!";
		getch();
	}	
	else
	{
		file.seekg(0, ios::end);
		int tell = file.tellg();
		cout<<"\nTotal records : "<<(tell/sizeof(manipulate));
		cout<<"\n\nWant to jump to specific record number?( 0 to not):\t";
		cin>>recnum;
		int size = ((recnum)*sizeof(manipulate));
		if(size>= file.tellg())
		{
			clrscr();
			cout<<"\n All records jumped!. Try again!";
			getch();
			dismoddelrecs(x);
		}
		file.seekg(size,ios::beg);
		while(file.read((char*)&nostalgia, sizeof(manipulate)))
		{
			if(flag == 1)
			{
				if(!file.eof())
				{
					cout<<"See more? (y/n)";
					cin>>condition;
					if(condition == 'n' || condition == 'N')
						break;
				}
			}
			displaydata(nostalgia);
			flag = 1;
		}
	}
	file.close();
	
}
//***Calculating Total Collection***
void bill :: totaltax(unsigned long x)
{
	clrscr();
	fstream file;
	int flag = 0;
	unsigned long tot = 0;
	file.open("totaltax.lst", ios::out | ios:: in | ios:: nocreate | ios::ate);
	if(file)
	{
		flag = 1;
	}
	else
	{
		file.close();
		file.open("totaltax.lst", ios:: in | ios:: out | ios:: ate);
		file<<var1.retmoney();
	}
	if(flag == 1)
	{
		file.seekg(0, ios::beg);
		file>>tot;
		if(x == 0)
			tot += var1.retmoney();
		else
			tot -= x;
		file.seekg(0, ios::beg);
		file<<tot;
	}
	file.close();
	
}
//***Dispalaying Total Collection***
void bill :: showcoll()
{
	clrscr();
	ifstream file;
	char choic = 'n';
	unsigned long tot = 0;
	file.open("totaltax.lst", ios::in | ios::nocreate);
	if(file)
	{
		file>>tot;
		cout<<"Your total Selling is:       "<<tot;
		cout<<"\n \n \n Do you want to flush this record? (y/n)";
		cin>>choic;
		file.close();
		if(choic == 'y' || choic == 'Y')
			remove("totaltax.lst");
		else
			cout<<"\nSure. No problem.";
	}
	else
		cout<<"\nNo Data Found!";
	getch();
}
//***Displaying Money Chart***
void bill :: showmon()
{
	clrscr();
	ifstream file[5];
	unsigned long arr[5];
	file[0].open("moneya.lst");
	file[1].open("moneyb.lst");
	file[2].open("moneyc.lst");
	file[3].open("moneyd.lst");
	file[4].open("moneye.lst");
	cout<<"\n \n \n\n\n\n\n";
	for(int i=0; i<5; i++)
	{
		if(file[i])
		{
		file[i].seekg(0,ios::beg);
		file[i]>>arr[i];
		cout<<"\t\t\tFor "<<i+1<<". \t\t"<<arr[i]<<"\n\n\n";
		}
		else
			cout<<"\t\t\tFor "<<i+1<<". \t\t"<<"No Data Found"<<"\n\n\n";
	}
	getch();
}
class menu
{
	public:
		char password[20];
		char hint[20];
		bill value;
		void mainmenu(int x);
		void passwordfunc(int x);
		void changepass();
		void creators();
		void encrypt(char * encry);
		void destroy();
		void secmenu(char* oper, unsigned long laneno, char * name);
		~menu()
		{
			cout<<"Thanks!";
		}
}REDMI;
/*
**************
***MADE BY:***
**************
*/
void menu :: creators()
{
	char creator1[] = {"SHOBHIT MAHESHWARI  "};
	char creator2[] = {"HARSHIT SHRISHRIMAL "};
	char creator3[] = {"SUDHANSHU CHAPERWAL "};
	char creator4[] = {"RAHUL JAISWAL       "};
	clrscr();
	cout<<"\n\n\n\t \t \t \t  MADE BY: \n \n \n \n \n \n";
	cout<<"\t  1. \t \t \t"<<creator1<<":-) \n \n \n";
	cout<<"\t  2. \t \t \t"<<creator2<<":-) \n \n \n";
	cout<<"\t  3. \t \t \t"<<creator3<<":-) \n \n \n";
	cout<<"\t  4. \t \t \t"<<creator4<<":-) \n \n \n";
	cout<<"Under the guidance of:\n \t\t Mr. Aniket Goswami (PGT Computer Science, VKV Hurda)";
	getch();	
}
void menu :: secmenu(char * oper, unsigned long laneno, char * name)
{
	int choice = 0;
	char conf[20];
	char hope= 0;
	for(;;)
	{
		clrscr();
		cout<<setw(40 + strlen(name)/2 )<<name;
		gotoxy(57,2);
		curtime();
		cout<<nowstring;
		cout<<"\n 1. DISPLAY MONEY CHART\n";
		cout<<"\n 2. DISPLAY ALL DATA\n";
		cout<<"\n 3. DISPLAY DELETED RECORDS\n";
		cout<<"\n 4. DISPLAY MODIFIED RECORDS\n";
		cout<<"\n 5. CHANGE PASSWORD \n";
		cout<<"\n 6. DESTROY ALL FILES \n";
		cout<<"\n 7. LOG OUT\n";
		cout<<"\n 8. GO BACK TO MAIN MENU\n";
		cout<<"\n 9. EXIT";
		cout<<"\n\tBILL,DELETED,MODIFIED DATA FOR PRINTING ARE PRESENT IN ROOT FOLDER.\n";
		cout<<setw(45)<<"\t Operator\t : ";
		puts(oper);
		cout<<setw(45)<<"\t On Lane Number  : "<<laneno<<"\n";
		cout<<"Enter your choice (1-9):     \t ";
		cin>>choice;
		if (choice == 9)
		{
			mainmenu(101);
			break;
		}
		if(choice == 1)
		{
			value.showmon();
		}
		else if(choice == 2)
		{
			clrscr();
			value.alldisplay();
		}
		else if(choice == 3)
		{
			clrscr();
			value.dismoddelrecs(1);
		}
		else if(choice == 4)
		{
			clrscr();
			value.dismoddelrecs(0);
		}
		else if(choice == 5)
		{
			clrscr();
			cout<<"Enter Current Password:";
			gets(conf);
			encrypt(conf);
			if(strcmp(conf,password)==0)
				changepass(); 					
			else
				cout<<"Wrong password Entered.";
			getch();
		}
		else if(choice == 6)
		{
			cout<<"Do you seriously want to wipe all data?(y/n)";
			cin>>hope;
			if(hope == 'y')
				passwordfunc(2);
			break;
		}
		else if(choice == 7)
		{
			passwordfunc(1);
			break;
		}
		else if(choice == 8)
		{
			mainmenu(0);
		}
		else if(choice == 9)
			mainmenu(101);
		else
			secmenu(oper, laneno, name);
	}
}
/*
***************
***Main Menu***
***************
*/
void menu :: mainmenu(int x)
{
	int choice;
	char conf[20];
	char name[60];
	char oper[20] = {"(NOT YET ENTERED)"};
	char hope;
	unsigned long laneno = 00000;
	ifstream file,file1, file2;
	file.open("plazan.lst", ios::in | ios::binary | ios::nocreate);
	if(!file)
		value.nameplaza();
	file.close();
	file.open("plazan.lst", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	file.read((char*)&name, sizeof(name));
	file1.open("collector.lst", ios::in | ios::nocreate);
	file2.open("lane.lst", ios::in);
	file1.seekg(0,ios::beg);
	file2.seekg(0,ios::beg);
	file1.read((char*)&oper, sizeof(oper));
	file2>>laneno;
	file1.close();
	file2.close();
	for(;;)
	{
		if(x==101)
			break;
		clrscr();
		cout<<setw(40 + strlen(name)/2 )<<name;
		gotoxy(56,2);
		curtime();
		cout<<nowstring;
		cout<<endl<<" 1. UPDATE NAME OF TOLL PLAZA\n";
		cout<<"\n 2. UPDATE NAME OF TOLL COLLECTOR AND LANE NUMBER\n";
		cout<<"\n 3. UPDATE MONEY CHART\n";
		cout<<"\n 4. ENTER ESSENTIAL DATA(CREATE BILL)\n";
		cout<<"\n 5. SEARCH\n";
		cout<<"\n 6. DELETE\n";
		cout<<"\n 7. MODIFY\n";
		cout<<"\n 8. SHOW TOTAL COLLECTION\n";
		cout<<"\n 9. DISPLAY SECTION AND ACCOUNT INFORMATION\n";
		cout<<"\n10. EXIT\n";
		cout<<setw(45)<<"\t Operator\t : ";
		puts(oper);
		cout<<setw(45)<<"\t On Lane Number  : "<<laneno<<"\n";
		cout<<"Enter your choice (1-10):     \t ";
		cin>>choice;
		if (choice==9)
			secmenu(oper, laneno, name);
		if(choice == 1)
		{
			clrscr();
			value.nameplaza();
			file.close();
			mainmenu(0);
			break;
		}
		else if(choice == 2)
		{
			clrscr();
			value.constants();
			mainmenu(0);
			break;
		}
		else if(choice == 3)
		{
			clrscr();
			value.moneychart();
		}	
		else if(choice == 4)
		{
			clrscr();
			value.getdata();
			value.recordhandle();
			value.totaltax(0);
			value.displaydata(value.var1);
		}
		else if(choice == 5)
			value.search();
		else if(choice == 6)
			value.deleter();
		else if(choice == 7)
			value.modify();
		else if(choice == 8)
			value.showcoll();
		else if(choice == 9)
			break;
		else if(choice == 10)
			break;	
		else
			continue;		
		if(choice == 10)
			break;
		file.close();
	}
}
//***PASSWORD PROTECTION***
void menu :: passwordfunc(int x)
{
	clrscr();
	cout<<"Welcome to The Toll Tax Records And Bill Management Programme \n";
	ifstream file;
	file.open("Password.lst", ios::nocreate | ios:: in);
	int flag =1;
	char iccha;
	char pass[20];
	memset(password, ' ', 20);
	memset(pass, ' ', 20);
	if(file)
		flag = 0;
	else
	{
		file.close();
		changepass();
		passwordfunc(1);
	}
	if(flag == 0)
	{
		file.seekg(0,ios::beg);
		file.read((char*)&pass,sizeof(pass));
		cout<<"Password Hint \n";
		file.close();
		file.open("hint.lst", ios::in | ios::nocreate);
		file.read((char*)&hint, sizeof(hint));
		puts(hint);
		cout<<"\n \n \nEnter password \n";
		gets(password);
		encrypt(password);
		if(strcmp(password, pass)==0)
		{
			if(x==1)
				mainmenu(0);
			else if(x==2)
				destroy();
		}
		else
		{
			cout<<"Password Incorrect!";
			cout<<"\nWanna enter again? (y/n) \n";
			cin>>iccha;
			if(iccha == 'y')
				passwordfunc(1);
			else
				cout<<"Hope to see you soon!";
		}
	}
}
//***CHANGE PASSWORD***
void menu :: changepass()
{
	ofstream file;
	file.open("Password.lst", ios::out | ios::trunc);
	char conf[20];
	clrscr();
	cout<<"Enter New Password: \n";
	gets(password);
	encrypt(password);
	cout<<"\nConfirm Password: \n";
	gets(conf);
	encrypt(conf);
	if(strcmp(password, conf)==0)
	{
		file.write((char*)&password, sizeof(password));
		cout<<"Password Updated successfully.";
		cout<<"\n \n Enter Password Hint:";
		gets(hint);
		file.close();
		file.open("hint.lst", ios::out | ios::trunc);
		file.write((char*)&hint,sizeof(hint));
		cout<<"Thanks!";
	}
	else
		cout<<"Not Matched.";
	file.close();
	getch();
}
//***Caesar Cipher Code***
void menu :: encrypt(char * encry)
{
	for(int i = 0; i< strlen(encry); i++)
	{
		if(isalpha(encry[i]) && isupper(encry[i]))
			encry[i] = ((encry[i]  -64 + 3)% 26) + 64;
		else if(isalpha(encry[i] && islower(encry[i])))
			encry[i] = ((encry[i] - 96 + 3)% 26) + 96;
 		else if(isalnum(encry[i]))
			encry[i] = ((encry[i] - 47 + 3)% 10) + 47;
		else
			encry[i] = encry[i];
	}
}
//***Destroying All Files***
void menu :: destroy()
{
	remove("Password.lst");
	remove("plazan.lst");
	remove("collector.lst");
	remove("lane.lst");
	remove("moneya.lst");
	remove("moneyb.lst");
	remove("moneyc.lst");
	remove("moneyd.lst");
	remove("moneye.lst");
	remove("transi.lst");
	remove("receipti.lst");
	remove("Records.lst");
	remove("Bill.docx");
	remove("ChangedR.docx");
	remove("MRecs.lst");
	remove("DRecs.lst");
	remove("hint.lst");
	remove("totaltax.lst");
	clrscr();
	cout<<"\n \n \n \n \n \n \n \n \n \t\t\t All Data Removed Successfully!";
	getch();
	
}
//***GET CURRENT TIME TO STRING***
void curtime()	
{
	time_t now = time(0);					 //get time now
	nowstring = ctime(&now); 				//convert current time in a string
}
void main()
{
	REDMI.passwordfunc(1);
	REDMI.creators();
	getch();
}

/*
Total files opened and maintained:
PASSWORD
PLAZA NAME
TOLL COLLECTOR NAME
LANE ID
MONEYA
MONEYB
MONEYC
MONEYD
MONEYE
TRANSACTION ID
RECEIPT ID
RECORDS
BILL
CHANGED RECORDS(MODIFIED + DELETED)
MREC
DREC
DELETED SCENES
PASSWORD HINT
TOTAL COLLECTION

TOTAL FILES : 19
*/