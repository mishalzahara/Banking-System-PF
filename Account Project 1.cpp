#include<iostream>
#include<fstream>
#include<cstring>
#include<limits>
using namespace std;

struct account
{
	int password[10];
	long double balance[10];
	string acc[50],name[50];
};
//structure

void design()
{
	int i;
			
		for(i=1;i<=119;i++)
	{
		if(i%2==0)
		{
			cout<<"^";
		}
		else
		{
			cout<<"-";
		}
	}
		cout<<endl;
	//Function design
		
}

void transfer(int pass)
{
	design();
	            //design
	            int temp=0,amount,i,count=0,j;
	            int trans=0,num=0;
	            char fund[20];
	            cout<<"Enter Account No. To Transfer "<<endl;
	            cin>>fund;
			
			    account a;
			    fstream acc_fin("New_data.txt",ios::in| ios::out| ios::binary);
//			    adding file

	          for(i=0;i<10;i++)
	     	{
	         	acc_fin>>a.name[i]>>a.password[i]>>a.acc[i]>>a.balance[i]; 
		    }
		        for(i=0;i<10;i++)
		        {
		        	if(fund==a.acc[i])
//		        	checking account number
		        	{
			cout<<"Enter amount You Want to Transfer "<<endl;
				cin>>amount;
				for(j=0;j<10;j++)
				{
				
		        if(pass==a.password[j])
		    {
		    	
		    	temp=a.balance[j]-amount;
			a.balance[j]=temp;
//			cancel amount from original
			
			if(a.balance[j]>=0)
			{ 
			
			trans=a.balance[i]+amount;
			a.balance[i]=trans;
//			adding amount for transfer
			cout<<"You have Successfully Transfered the Fund "<<amount<<"Rs/-"<<endl;
		    }
		    else
		    {
		    	cout<<"ERROR ! insuficient balance "<<endl;
			}
			break;
		    }
		     else
				     {
				     	count++;
					 }
		    }
		    }
		    else
		    {
		    	num++;
			}
				    
				}
		       if(count==10||num==10)
		       {
		       	cout<<"\n\nPlease Try Again! ERROR DETECTED\n\n "<<endl;
			   }
			   acc_fin.seekg(0);
			   
			   for(j=0;j<10;j++)
			   {
			   	if(a.balance>=0)
			   	{
			   	acc_fin<<a.name[j]<<" "<<a.password[j]<<" "<<a.acc[j]<<" "<<a.balance[j]<<endl;
			    }
			   }  
			               
			acc_fin.close();
				
}
  //fund transfer function
  
int main()

//main function starting 
{
	char chose;
	bool continueProgram =true;
	while(continueProgram)
//	program starts to run untill loop breaks
	{
	int choice,i,j,pin,count=0;
	int pass,num=0,amount;
//	declare & initialization

	for(i=1;i<=55;i++)
	{
		if(i%2==0)
		{
			cout<<"^";
		}
		else
		{
			cout<<"-";
		}
	}
	cout<<"WELCOME";
	
	for(i=1;i<=55;i++)
	{
		if(i%2==0)
		{
			cout<<"^";
		}
		else
		{
			cout<<"-";
		}
	}
		cout<<endl;   
		// designing material
//	main program starting point

		cout<<"Enter Password ";
//		checking of password
		while (!(cin>>pass)||pass<1000||pass>9999)
		{
			
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"Error :input must be of 4 digits ";
			
		}
		
		ifstream acc_fout("New_data.txt"); 
		account a;
		for(i=0;i<10;i++)
		
			{
			    acc_fout>>a.name[i]>>a.password[i]>>a.acc[i]>>a.balance[i];
		         if(pass==a.password[i])
				 	
{	
	cout<<"ENter Your Choice:  "<<endl<<endl;
		cout<<endl;
	cout<<"1- Account Details \n ";
    	cout<<endl;
	cout<<"2- PIN Change \n ";
		cout<<endl;
	cout<<"3- Funds Transfer \n ";
		cout<<endl;
	cout<<"4- Balance Inquiry \n ";
		cout<<endl;
	cout<<"5- Cash Withdrawal \n ";
		cout<<endl;
	cout<<"6- Cancel \n ";
		cout<<endl;
		//end of menu ...
		
    design();
	//design
		
	cin>>choice;
	cout<<"\n\n\n\n\n\n\n\n";
	switch(choice)
	
	{
		case 1:
			{
		design();
	//design
	            cout<<"\n\n\n";
				ifstream acc_fout("New_data.txt"); 
			    account a;
			    for(i=0;i<10;i++)
			    {
			    	
			    	acc_fout>>a.name[i]>>a.password[i]>>a.acc[i]>>a.balance[i];
			    	if(pass==a.password[i])
			    	{
			    
				
					cout<<"NAME :"<<a.name[i]<<"\n"<<endl;
					cout<<"PASSWORD :"<<a.password[i]<<"\n"<<endl;
					cout<<"ACCOUNT NO. :"<<a.acc[i]<<"\n"<<endl;
					cout<<"CURRENT BALANCE :"<<a.balance[i]<<"\n"<<endl;
					  }
				     else
				     {
				     	count++;
					 }
		       }
		       if(count==10)
		       {
		       	cout<<"Please Try Again! ERROR DETECTED "<<endl;
			   }
			   cout<<"\n\n";
			acc_fout.close();
			break;
			}
			//First case solved account details
			
		case 2:
			design();
//			design
			{
				cout<<"\n\n";
				string act;
				cout<<"Are You Sure to Change Your Password \n"<<endl;
				cout<<"1- Yes \n"<<endl;
                cout<<"2- Cancel \n"<<endl;
                cout<<"\n\n";
                design();
//                design
				cin>>choice;
//				nested switch
				switch(choice)
				{
					case 1:
					{
						int pass1;
						cout<<"\n\n\nEnter Your account number :"<<endl;
						cin>>act;
						if(act.length()!=10)
						{
							cout<<"\n\n\nError : Must Contain Only 10 characters "<<endl;
							break;
						}
						else if(act.length()==10)
						{
                        
                        account a;
			    fstream acc_fin("New_data.txt",ios::in| ios::out);
			    
	          for(i=0;i<10;i++)
	     	{
	         	acc_fin>>a.name[i]>>a.password[i]>>a.acc[i]>>a.balance[i]; 
		    }
		        for(i=0;i<10;i++)
		        {
		        if(act==a.acc[i])
		    {
		    	if(pass==a.password[i])
		    	{
			  cout<<"\n\nEnter NEW PassWord :"<<endl;
			  while (!(cin>>pass1)||pass1<1000||pass1>9999)
		{
			
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"Error :input must be of 4 digits "<<endl;
			
		}
			  a.password[i]=pass1;
			  cout<<"\n\nPassword Changed To "<<a.password[i]<<" Successfully\n "<<endl;
			  
//             password changed

			 break;
		       }
		       else
		       {
		       	count++;
			   }
		    }
				     else
				     {
				     	count++;
					 }
				}
		       if(count==10)
		       {
		       	cout<<"\n\nPlease Try Again! ERROR DETECTED Wrong ID"<<endl;
			   }
			   acc_fin.seekg(0);
			   for(j=0;j<10;j++)
			   {
			   	acc_fin<<a.name[j]<<" "<<a.password[j]<<" "<<a.acc[j]<<" "<<a.balance[j]<<endl;
			   }              
			acc_fin.close();
			
			
			break;
					}}
					
//					nested switch case 1 completed
					case 2:
						
					design();
	                //design
			{
				cout<<"THANK YOU FOR VISITING ^_^ \n\n\n\n\n\n\n\n "<<endl;
				break;
			}
//			nested switch case 2 completed
				}
				break;
			}
		case 3:
			{
								design();
//				design
				int choice1,choice2;
				cout<<"\n\nEnter choice\n\n"<<endl;
				cout<<"1: To Bank Transfer \n"<<endl;
				cout<<"2: To Mobile Account\n"<<endl;
				cin>>choice1;
				switch(choice1)
//				nested switch
				{
					case 1:
					{
						design();
//						design 
						cout<<"1: Allied Bank \n"<<endl;
						cout<<"2: Bank Al Habib \n"<<endl;
						cout<<"3: Bank Alfalah \n"<<endl;
						cout<<"4: Habib Bank Limited \n"<<endl;
						cout<<"5: PAYMAX \n"<<endl;
						cout<<"6: MCB Bank Limited \n"<<endl;
						cout<<"7: Cancel Transaction \n"<<endl;
						cin>>choice2;
						switch(choice2)
//						second nested switch
						{
							case 1:
								{
									transfer(pass);
									break;
								}
							case 2:
							    {
									transfer(pass);
									break;
								}
							case 3:
							    {
									transfer(pass);
									break;
								}
							case 4:
							    {
									transfer(pass);
									break;
								}
							case 5:
							    {
									transfer(pass);
									break;
								}
							case 6:
							    {
									transfer(pass);
									break;
								}
							case 7:
							    {
							    	design();
									cout<<"\n\n\nThank You For Visiting *_* \n\n\n"<<endl;
									break;
								}
						}
						break;
					}
//					1st nested switch solved

					case 2:
						
					{
						design();
						cout<<"1: To JazzCash \n"<<endl;
						cout<<"2: To Easypaisa \n"<<endl;
						cout<<"3: To Upaisa \n"<<endl;
						cout<<"4: Cancel Transaction \n"<<endl;
						cin>>choice2;
						switch(choice2)
//						third nested switch
						{
							case 1:
								{
									transfer(pass);
									break;
								}
							case 2:
								{
									transfer(pass);
									break;
								}
							case 3:
								{
									transfer(pass);
									break;
								}
							case 4:
								{
									design();
									cout<<"\n\n\nThank You For Visiting *_* \n\n\n"<<endl;
									break;
								}	
						}
						
						break;
					}
//					2nd nested case solved
				}
				break;
			}
			//Third case solved Funds Transfer 
			
		case 4:
			{
				
				design();
				ifstream acc_fout("New_data.txt");
//				attachment of file 
			    account a;
			    for(i=0;i<10;i++)
			    {
			    	acc_fout>>a.name[i]>>a.password[i]>>a.acc[i]>>a.balance[i];
			    	
			    	if(pass==a.password[i])
			    	{
					cout<<"\n\nCURRENT BALANCE :"<<a.balance[i]<<endl;
					}
				    
		       }
		       
			acc_fout.close();
			break;
			}
			//Forth case solved balance inquiry
			
		case 5:
			{
				design();
	            //design
	            int temp=0;
				cout<<"\n\nEnter amount You Want to Withdraw : ";
				cin>>amount;
				cout<<endl;
			    account a;
			    fstream acc_fin("New_data.txt",ios::in| ios::out| ios::binary);
//			    file reading
	          for(i=0;i<10;i++)
	     	{
	         	acc_fin>>a.name[i]>>a.password[i]>>a.acc[i]>>a.balance[i]; 
		    }
		        for(i=0;i<10;i++)
		        {
		        	
		        if(pass==a.password[i])
		    {
			if(amount<=a.balance[i])
			{
			
			temp=a.balance[i]-amount;
			a.balance[i]=temp;
			cout<<"Your Have Successfully Withdraw The Amount :"<<amount<<"Rs/-"<<endl;
			break;
		    }
		    else
				{
					cout<<"Error Insuficient Balance ! ^_^"<<endl;
				}
		    
		    }	     
				}
				
			   acc_fin.seekg(0);
			   for(j=0;j<10;j++)
			   {
			   	acc_fin<<a.name[j]<<" "<<a.password[j]<<" "<<a.acc[j]<<" "<<a.balance[j]<<endl;
			   }              
			acc_fin.close();	
			break;	
			}
			
//			case 5 coding cash withdrawl

		case 6:
		design();
	//design
			{
				cout<<"THANK YOU FOR VISITING ^_^ \n\n\n\n\n\n\n\n "<<endl;
				break;
			}
			//Six case solved Exit
    }
	
}
else
 {
 	num++;
 }
}
//new if statement
if(num==10)
{
	cout<<"Wrong Password.....Try Again \n \n\n\n\n\n\n"<<endl;
}
design();

//program continue

  cout<<"Do You Want to continue ? \n \n \n \n \n \n"<<endl;
  
  cin>>chose;
  if(chose=='n'||chose=='N')
  {
  	continueProgram=false;
  }
}

return 0;

}
//end  