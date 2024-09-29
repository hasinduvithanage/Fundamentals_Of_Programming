/*
Name: Hasindu
Student ID: 104824660
*/

#include <iostream>
using namespace std;


//function prototypes
void find_sum1(int array[], int size, int *sum);
void find_sum2(int array[], int size, int *sum);



//keep a counter to mantain the count for each digit entered

/*
step 1: 
get the input from user into an input array with max size 20, transfer these data into a different array whilst confirming the
size of the array. This second array will be used.

step 2:
2 loops to handle odd and even / or an if 
double values, if the doubled value is 2 digit (>=10), then modulus the number, when you modulus the remainder is the last digit , 
then first digit plus second digit.
Then get sum.

Step 3:
Sum all the other numbers (sum2)

Step 4:
find total of sum1 and sum2

*/

int main()
{
    int MAX_SIZE = 20;
    int input_array[MAX_SIZE];
    int user_input;
    int SIZE = 0;
    int counter = 0;
    int sum1;
    int sum2;
    int checksum;
    

    cout<<"Enter a number for your Pin (Enter -1 when you are done): "<<endl;
    do
    {

        
        cin>>user_input;
        if(user_input != -1)
        {
            input_array[counter] = user_input;
            counter++;
        }

    }while(user_input != -1);

    SIZE = counter;

    int cred_array[SIZE];

    

    for(int i = 0; i<(SIZE); i++)
    {
        cred_array[i] = input_array[i]; //tranfer the input to cred_array[] whilst confirming the size of the array 
    }


    //printing the array
    cout<<endl<<endl;

    cout<<"Credit card number is ";
    for(int i = 0; i < SIZE; i++)
    {
        cout<<cred_array[i]<<"";
    }    

    cout<<endl<<endl;
    
    find_sum1(cred_array, SIZE, &sum1);
    
    cout<<endl<<endl;

    find_sum2(cred_array, SIZE, &sum2);

    cout<<endl<<endl;

    int cal_value = (sum1 + sum2) * 9;

    checksum = cal_value % 10; //extracts the rightmost digit

    cout<<"Check sum is "<<checksum;

    cout<<endl<<endl;
 
    cout<<"Last digit on the credit card is "<<cred_array[SIZE - 1];

    cout<<endl<<endl;

    if(checksum == cred_array[SIZE - 1])
    {
        cout<<"Check sum "<<checksum<<" and the last digit "<<cred_array[SIZE - 1]<<" are the same: Valid credit card number!"<<endl;

    }
    else
    {
        cout<<"Check sum "<<checksum<<" and the last digit "<<cred_array[SIZE - 1]<<" are not the same: Invalid credit card number!"<<endl;

    }

    
}

//function definitions
void find_sum1(int array[], int size, int *sum)
{
    *sum = 0;
    int first_digit; //in two-digit number, the first digit
    int second_digit; //in two-digit number, the second digit
    int double_num; //the doubled number

    if((size % 2) == 0 ) //even (ignoring the check digit, it's odd)
    {
        cout<<"Numbers for sum1 are ";
        for(int i = 0; i < size/2 ; i++)
        {
            cout<<array[(2*i)]<<" "; //gets every other digit except the rightmost digit

            double_num = array[(size - 2) - (2*i)] * 2; //gets every other digit except the rightmost digit and doubles it

            if(double_num >=10) //if the doubled value is a 2-digit number
            {
                first_digit = double_num / 10; //gets first digit
                second_digit = double_num % 10; //gets second digit
                double_num = first_digit + second_digit;
            }
            *sum = *sum + double_num;
        }
    } 
    else //odd (ignoring the check digit, it's even)
    {
        cout<<"Numbers for sum1 are ";
        for(int i = 0; i < (size - 1)/2 ; i++)
        {
            cout<<array[(2*i + 1)]<<" "; //gets every other digit except the rightmost digit

            double_num = array[(size - 2) - (2*i)] * 2; //gets every other digit except the rightmost digit and doubles it

            if(double_num >=10)//if the doubled value is a 2-digit number
            {
                first_digit = double_num / 10; //gets first digit
                second_digit = double_num % 10; //gets second digit
                double_num = first_digit + second_digit;
            }
            *sum = *sum + double_num;

        }
    }


    cout<<endl;
    cout<<"Sum 1 is "<<*sum;
}

void find_sum2(int array[], int size, int *sum)
{
    *sum = 0;


    if((size % 2) == 0 ) //even (ignoring the check digit, it's odd)
    {
        cout<<"Numbers for sum2 are ";
        for(int i = 0; i < (size/2 - 1) ; i++)
        {
            cout<<array[(2*i + 1)]<<" "; //gets every other digit except the rightmost digit

            *sum = *sum + array[(2*i + 1)];
        }
    } 
    else //odd (ignoring the check digit, it's even)
    {
        cout<<"Numbers for sum2 are ";
        for(int i = 0; i < (size - 1)/2 ; i++)
        {
            cout<<array[(2*i)]<<" "; //gets every other digit except the rightmost digit
            *sum = *sum + array[(2*i)];
        }
    }


    cout<<endl;
    cout<<"Sum 2 is "<<*sum;
}