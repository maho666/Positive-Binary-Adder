#include <iostream>
#include <math.h>
using namespace std;


long long int to_binary(int decimal_number)
{
    if (decimal_number == 0)
        return 0;
    else
    {
        long long int x = (decimal_number % 2 + 10 * to_binary(decimal_number / 2));
        return x;
    }
}

int to_decimal(long long int binary_number)
{
    if(binary_number==0)
        return 0;
    else
        return (binary_number% 10 + 2* to_decimal(binary_number / 10));
}

long long int binary_adder(long long int A,long long int B,long long int C,long long int N)
{
    {
    long long int sum, A_res, B_res ,D;
    if(A==0 && B==0 && C==0)
    {
        return 0;
    }
    else
    {
        A_res = A%2;/////材计緇计
        B_res = B%2;/////材计緇计
        D = (A_res + B_res + C) / 2;//緇计埃2眔秈0┪1
        N++;
        long long int newsum = ((A_res + B_res + C) % 2) * (pow(10, N - 2));//Τpower(double篈)┮穝long long钡
        return (newsum + binary_adder(A / 10, B / 10, D, N));
    }
}
}

int accumulation(int sum_d, long long int sum_b)
{
    int new_number,counter=3,sum_d_new;
    long long int new_binary,sum_b_new;
    do{
        if(counter == 3)
        {
            cout <<"Please enter the 3rd number in decimal: ";
        }
        else if(counter > 3)
        {
            cout <<"Please enter the "<<counter<<"th number in decimal: ";
        }
    cin>> new_number;
    while((new_number != -1)&&(new_number<0 || new_number>524287||(sum_d_new=sum_d+new_number)>524287||(sum_d_new=sum_d+new_number)<0))
    {
        if(new_number<0 || new_number>524287)
        {
            if(counter == 3)
            {
                cout << "The decimal number you entered is out of range. Please enter the 3rd decimal number again: ";
            }
            else
            {
                cout <<"The decimal number you entered is out of range. Please enter the "<<counter<<"th decimal number again: ";
            }
        }
        else if((sum_d_new=sum_d+new_number)>524287||(sum_d_new=sum_d+new_number)<0)
        {
            if(counter == 3)
            {
                cout <<"The partial sum is out of range. Please enter the 3rd decimal number again: ";
            }
            else
            {
                cout <<"The partial sum is out of range. Please enter the "<<counter<<"th decimal number again: ";
            }
        }

    cin >> new_number;
    }
    new_binary = to_binary(new_number); /////convert to binary
    sum_b_new = binary_adder(sum_b,new_binary,0,1); ////add the binary
    sum_d_new = to_decimal(sum_b_new);   ////convert sum to decimal
    if(new_number == -1)
        {
            break;
        }


    cout <<"Calculating... "<<sum_b<<" + "<<new_binary<<" = ";
    cout<<sum_b_new<<endl;
    cout <<"Partial Sum: "<<sum_d_new<<endl;
    sum_b = sum_b_new;
    sum_d = sum_d_new;
    cout<<endl;
    counter++;
    }while(new_number != -1);
    return 1;
}


int main()
{
    int decimal_number ;
    cout << "*** Welcome to Positive Binary adder ***"<<endl;
    int first_number,second_number,done,sum_decimal;
    do{

    cout <<"Please enter the 1st number in decimal: ";
    cin>> first_number;
    if(first_number == -1)
    {
        break;
    }
    while(first_number != -1 && (first_number<0 || first_number>524287))
    {
    cout << "The decimal number you entered is out of range. Please enter the 1st decimal number again: ";
    cin >> first_number;
    }

    cout <<"Please enter the 2nd number in decimal: ";
    cin>> second_number;
    if(second_number == -1)
    {
        break;
    }
    while((second_number != -1)&&second_number<0 || second_number>524287||(sum_decimal=first_number+second_number)>524287||(sum_decimal=first_number+second_number)<0)
    {
        if(second_number<0 || second_number>524287)
        {
            cout << "The decimal number you entered is out of range. Please enter the 2nd decimal number again: ";
        }
        else if((sum_decimal=first_number+second_number)>524287||(sum_decimal=first_number+second_number)<0)
        {
            cout <<"The partial sum is out of range. Please enter the 2nd decimal number again: ";
        }

    cin >> second_number;
    }

    long long int sum_binary, first_binary, second_binary;
    first_binary = to_binary(first_number); /////convert to binary
    second_binary = to_binary(second_number);
    sum_binary = binary_adder(first_binary,second_binary,0,1); ////add the binary
    sum_decimal = to_decimal(sum_binary);   ////convert sum to decimal

    cout <<"Calculating... "<<first_binary<<" + "<<second_binary<<" = "<<sum_binary<<endl;
    cout <<"Partial Sum: "<<sum_decimal<<endl;
    cout<<endl;
    done = accumulation(sum_decimal, sum_binary);
    //cout << done<<endl;
    if(done == 1)
    {
        break;
    }

    }while(first_number != -1 || done != 1);
    cout << "Bye";


    return 0;
}

