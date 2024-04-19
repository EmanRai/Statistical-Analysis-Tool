#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
class numberLandH
{
	public:
		int x[10];
		int lowest = 0;
		int highest = 0;
		void input()
		{
		    for (int i=0; i<10; i++)
		    {
			    cout <<"Enter the " << i+1 << " number: ";
			    cin >> x[i];
			   	if (x[i] > highest)
	    		{
	    			 highest = x[i];
				}
	    	}
	    	lowest = highest;
	        for (int i=0; i<10; i++)
		    {
			   	if (x[i] < lowest)
	    		{
	    			 lowest = x[i];
				}
	    	}
	    	
	    	
	    }
	    void low_high_Number()
	    {
	    	ofstream fout("input.txt", ios::app);
	    	cout <<"\n\nHighest Number: " << highest << endl;
	    	fout <<"\n\nHighest Number: " << highest << endl;
	    	cout <<"Lowest Number: " << lowest << endl <<endl;
	    	fout <<"Lowest Number: " << lowest << endl <<endl;
	    	fout.close();
		}
		
};
class Mean: public numberLandH
{
	public:
		int x[10] = {2,5,7,8,9,12,14,15,17,19};
		int f[10] = {1,5,4,2,7,8,9,5,6,3};
		double sum_fx = 0;
		double sum_f = 0;
		double sum =0;
		int n=0;
		double mean_ungroup;
		double mean_group;
		void mean_grouped()
		{
			ofstream fout("input.txt", ios::app);
			for (int i=0; i<10; i++)
	    	{
		    	sum_fx = sum_fx + (f[i] * x[i]);
		    	sum_f = sum_f + f[i];
	    	}
	    	mean_group = sum_fx / sum_f;
	    	cout <<"\nArithmetic Mean Grouped Data = " <<endl;
	    	fout <<"\nArithmetic Mean Grouped Data = " <<endl;
	    	fout <<"Arithmetic Mean Grouped Data = ";
	    	fout <<"Sum(fx)" << "/Sum(f) ==> " << sum_fx << "/" << sum_f << endl;
	    	cout <<"Arithmetic Mean: " << mean_group << endl;
	    	fout <<"Arithmetic Mean: " << mean_group << endl;
	    	fout.close();
		}
        void mean_ungrouped()
        {
        	ofstream fout("input.txt", ios::app);
		    for (int i=0; i<10; i++)
		    {
			    sum = sum + x[i];
			    n++;
		    }
		    mean_ungroup = (sum / n);
		    cout <<"\nArithmetic Mean Ungrouped Data = " <<endl;
		    fout <<"\nArithmetic Mean Ungrouped Data = " <<endl;
		   	fout <<"Arithmetic Mean Ungrouped Data = ";
	    	fout <<"Sum(x)" << "/n ==> " << sum << "/" << n << endl;
		    cout <<"Arithmetic Mean: " << mean_ungroup << endl;	
			fout <<"Arithmetic Mean: " << mean_ungroup << endl;	
			fout.close();    
        }
};
class Varience : public Mean
{
	   	public:
		double  sum1 = 0, sum2 = 0;
		double divide1, divide2, subtract, square, product;
		double varience;

		void varience_group()
		{
			ofstream fout("input.txt", ios::app);
			for (int i=0; i<10; i++)
			{
				sum1 = sum1 +(f[i] * x[i]);
				sum_f = sum_f + f[i];
			}
			for (int i=0; i<10; i++)
			{
				sum2 = sum2 +( f[i] * (x[i] * x[i]) );
			}   
	    		divide1 = sum1 / sum_f;
        		square = pow(divide1, 2);
         		divide2 = sum2 / sum_f;
         		cout <<"\nVarience Grouped Data = " <<endl;
         		fout <<"\nVarience Grouped Data = " <<endl;
        		fout <<"Varience =  sum(fx^2)/sum(f) -( sum(fx)/sum(f) )^2  ==> ";
        		fout <<sum2 <<"/" <<sum_f << " - " <<"(" <<sum1 <<"/"<<sum_f <<")^2"  << endl;
        		varience = divide2 - square;
        		cout <<"Varience =  " << varience << endl; 
				fout <<"Varience =  " << varience << endl; 
				fout.close();	
		}	
		void varience_ungroup()
		{
			sum =0;
			ofstream fout("input.txt", ios::app);
			for (int i=0; i<10; i++)
			{
				sum = sum + x[i];
				n++;
			}
			for (int i=0; i<10; i++)
			{
				product = product + (x[i] * x[i]);
			}   
	    		divide1 = sum / n;
        		square = pow(divide1, 2);
         		divide2 = product / n;
         		cout <<"\nVarience Ungrouped Data = " <<endl;
         		fout <<"\nVarience Ungrouped Data = " <<endl;
        		fout <<"Varience =  sum(x^2)/n -(sum(x)/n)^2  ==> ";
        		fout <<product <<"/" <<n << " - " <<"(" <<sum <<"/"<<n <<")^2"  << endl;
        		varience = divide2 - square;
        		cout <<"Varience =  " << varience << endl; 	
        		fout <<"Varience =  " << varience << endl;
        		fout.close();
		}	
};
class standardDeviation : public Varience
{	
	public:
		double S_D;
		void sd_group()
		{
			ofstream fout("input.txt", ios::app);
			sum =0, sum2= 0;
			for (int i=0; i<10; i++)
			{
				sum = sum +(f[i] * x[i]);
				sum_f = sum_f + f[i];
			}
			for (int i=0; i<10; i++)
			{
				sum2 = sum2 +( f[i] * (x[i] * x[i]) );
			}   
	    		divide1 = sum / sum_f;
        		square = pow(divide1, 2);
         		divide2 = sum2 / sum_f;
         		cout <<"\nStandard Deviation Grouped Data = " <<endl;
         		fout <<"\nStandard Deviation Grouped Data = " <<endl;
        		fout <<"S.D = ( sum(fx^2)/sum(f) -( sum(fx)/sum(f) )^2 )^1/2  ==> ";
        		fout <<"( "<<sum2 <<"/" <<sum_f << " - " <<"(" <<sum <<"/"<<sum_f <<")^2 )1/2" << endl;
        		subtract= divide2 - square;
        		fout <<"S.D = " <<"("<<subtract <<")^1/2"  << endl;
        		S_D = pow(subtract, 0.5);
        		cout <<"S.D =  " << S_D << endl; 
				fout <<"S.D =  " << S_D << endl;
				fout.close();	
		}
			void sd_ungroup()
		{
			ofstream fout("input.txt", ios::app);
			sum =0, sum2 = 0;
			for (int i=0; i<10; i++)
			{
				sum = sum + x[i];
				n++;
			}
			for (int i=0; i<10; i++)
			{
				sum2 = sum2 + (x[i] * x[i]);
			}   
	    		divide1 = sum / n;
        		square = pow(divide1, 2);
         		divide2 = sum2 / n;
         		cout <<"\nStandard Deviation Ungrouped Data = " <<endl;
         		fout <<"\nStandard Deviation Ungrouped Data = " <<endl;
        		fout <<"S.D =  ( sum(x^2)/n -(sum(x)/n)^2 )^1/2  ==> ";
        		fout <<sum2<<"/" <<n << " - " <<"(" <<sum <<"/"<<n <<")^2" << endl ;
        		subtract = divide2 - square;
        		fout <<"S.D = " << "( " <<subtract <<" )^1/2" <<endl; 
        		S_D = pow(subtract, 0.5);
        		cout <<"S.D =  " << S_D << endl; 
				fout <<"S.D =  " << S_D << endl;
				fout.close();	
		}		
		
};
int main()
{
	standardDeviation prob;
	prob.input();
	prob.low_high_Number();
	prob.mean_grouped();
	prob.mean_ungrouped();
	prob.varience_group();
	prob.varience_ungroup();
	prob.sd_group();
	prob.sd_ungroup();
}
