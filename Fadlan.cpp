#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main();
void menu();
void input();
void output();


	
	//datatype;
	int i, data;
	double C_D, C_M, C_YS, C_TS;

	ofstream outData;


	//structur data
	struct{
		char Material[50];
		double D;
		double ME;
		double YS;
		double TS;
		double PS;
	} metal[100];

	
int main(){
	
	 menu();
}


void menu(){
	

	int choice;
	do
	{
		cout << "\n\t============================  MENU  =============================\n\n";
		cout << endl
		<< " 1 - Input Data.\n"
		<< " 2 - Output Data.\n"	
		<< " 3 - Exit   \n\n\n"
		<< " Enter your choice and press return:  ";
		cin >> choice;

		switch (choice){

		case 1:
			system("cls");
			input();
			break;

		case 2:
			system("cls");
			output();
			break;

		case 3:
			system("cls");
			cout << "\n\n\tEnd of Program.\n";
			break;
			
		}

		system("pause");
		
	}while (choice !=3);

}


void input(){

	cout<<"INPUT AMOUNT OF DATA : "; cin>>data; cout<<"\n\n";
	
	for (i=0; i<data; i++)
	{		
			cout<<"Material ["<<i+1<<"] \n";
			cout<<"Material					: ";		cin>>metal[i].Material;
			cout<<"Density (gr/cm^3)		: ";		cin>>metal[i].D;
			cout<<"Modulus Elasticity (GPa)	: "; 		cin>>metal[i].ME;
			cout<<"Yield Strength (MPa)		: "; 		cin>>metal[i].YS;
			cout<<"Tensile Strength (MPa)	: ";		cin>>metal[i].TS;
			cout<<"Poisson Ratio			: ";		cin>>metal[i].PS;
			cout<<endl;
			
			
		}
	
	

			outData.open("outfile.csv",ios::app);
			outData<<"no"<<";"<<"material"<<";"<<"Density"<<";"<<"Modulus Elasticity"<<";"<<"Yield Strength"<<";"<<"Tensile Strengt"<<";"<<"Poisson Ratio\n";
		
			for (i=0; i<data; i++)
			{
				outData<<i+1<<";"<<metal[i].Material<<";"<<metal[i].D<<" gr/cm^3 "<<";"<<metal[i].ME<<" GPa "<<";"<<metal[i].YS<<" MPa "<<";"<<metal[i].TS<<" MPa "<<";"<<metal[i].PS;
				outData<<endl;
			}	
		
//		for (i=0; i<data; i++)
//		{
//			outData.open("outfile.csv",ios::app);
//			outData<<"Material ["<<i+1<<"] \n";
//			outData<<"Material				: "<<metal.Material<<"\n";
//			outData<<"Density				: "<<fixed<<setprecision(3)<<metal.D<<" gr/cm^3 "<<"\n";
//			outData<<"Modulus Elasticity 	: "<<fixed<<setprecision(3)<<metal.ME<<" GPa "<<"\n";
//			outData<<"Yield Strength		: "<<fixed<<setprecision(3)<<metal.YS<<" MPa"<<"\n";
//			outData<<"Tensile Strength		: "<<fixed<<setprecision(3)<<metal.TS<<" MPa "<<"\n";;
//			outData<<"Poisson Ratio			: "<<fixed<<setprecision(0)<<metal.PS;
//			outData<<"\n";
//			outData<<endl;
//		}	
		
		system("pause");
		
		system("cls");
		
		menu();
}


void output(){
	
	struct{
		string Material;
		string D;
		string ME;
		string YS;
		string TS;
		string PS;
	} metalString[100];
	
	ifstream ip;
	ip.open("outfile.csv");
	
	while(ip.good()){

		getline(ip,metalString[i].Material,',');
		getline(ip,metalString[i].D,',');
		getline(ip,metalString[i].ME,',');
		getline(ip,metalString[i].YS,',');
		getline(ip,metalString[i].TS,',');
		getline(ip,metalString[i].PS,',');
		
		cout<<"INPUT AMOUNT OF DATA \n\n";
	
		for (i=0; i<data; i++)
			{
				cout<<"Material ["<<i+1<<"] \n";
				cout<<"Material				: "<<metalString[i].Material<<"\n";
				cout<<"Density				: "<<metalString[i].D<<" gr/cm^3 "<<"\n";
				cout<<"Modulus Elasticity 	: "<<metalString[i].ME<<" GPa "<<"\n";
				cout<<"Yield Strength		: "<<metalString[i].YS<<" MPa"<<"\n";
				cout<<"Tensile Strength		: "<<metalString[i].TS<<" MPa "<<"\n";
				cout<<"Poisson Ratio		: "<<metalString[i].PS;
				cout<<"\n";
				cout<<endl;
			}	
	
	
		cout<<"RESULT OF CONVERTED VALUE \n\n";
		
		struct{
			double Material;
			double D;
			double ME;
			double YS;
			double TS;
			double PS;
			} metalDouble[100];
		
		istringstream(metalString[i].Material) >> metalDouble[i].Material;
		istringstream(metalString[i].D)  >> metalDouble[i].D;
		istringstream(metalString[i].ME) >> metalDouble[i].ME;
		istringstream(metalString[i].YS) >> metalDouble[i].YS;
		istringstream(metalString[i].TS) >> metalDouble[i].TS;
		istringstream(metalString[i].PS) >> metalDouble[i].PS;
		
		
		
		
		for (i=0; i<data; i++)
			{
				
				cout<<"Material ["<<i+1<<"] \n";
				cout<<"Material		: "<<metalDouble[i].Material<<"\n";
				C_D=metalDouble[i].D/27.679;
					cout<<"Density			: "<<C_D<<" lb/in^3"<<"\n";
				C_M=metalDouble[i].ME*145037.738;
					cout<<"Modulus Elasticity 	: "<<C_M<<" 10^6 Psi"<<"\n";
				C_YS=metalDouble[i].YS/6.895;
					cout<<"Yield Strength		: "<<C_YS<<" KSi "<<"\n";;
				C_TS=metalDouble[i].TS/6.895;
					cout<<"Tensile Strength	: "<<C_TS<<" KSi "<<"\n";;
				cout<<"Poisson Ratio		: "<<metalDouble[i].PS;
				cout<<"\n";
				cout<<endl;
				
			}		


	system("pause");
	
	system("cls");

	menu();
}
}
