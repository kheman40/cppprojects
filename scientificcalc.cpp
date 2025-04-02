#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// base class for basic operation 
class BasicCalculator{
    public:
    // Method for addition
    double add(double a, double b){
        return a+b;
    }
    // Method for substraction 
    double subtract(double a, double b){
        return a-b;
    }
    //Method for multiplication
    double multiply(double a, double b){
        return a*b;
    
    }
    // Method for division
    double divide(double a, double b){
        if(b !=0){
            return a /b;
        }else{
            cout<<"error : division by zero!"<<endl;
            return 0;
        }
    }
};
// Derived class for scientific operations 
class scientificCalculator : public BasicCalculator{
    public:
    // Method for square root 
    double squareRoot(double a){
        return sqrt(a);
    }
    // Method for power 
    double power(double a, double b){
        return pow(a,b);
    }
    // Method for sine 
    double sine(double a){
        return sin(a);
    }
    // Method for cosine 
    double cosine(double a){
        return cos(a);
    }
    // method for tan 
    double tangent(double a){
        return tan(a);
    }
    //Method for logarithmic function
    double logBase10(double a){
        return log10(a);
    }
};
// Function to print results to a file 
void logResult(string operation, double result){
    ofstream file;
    file.open("calculator_log.txt",ios::app);//open the file in append mode
    if(file.is_open()){
        file<<operation<<" = "<<result<<endl;
        file.close();
    }else{
        cout<<"Unable to open file!"<<endl;
    }
}
int main(){
    scientificCalculator sc;
    int choice;
    double num1 , num2, result;
    cout<<"scientific Calculator\n";
    cout<<"1. Addition\n";
    cout<<"2. Subtraction\n";
    cout<<"3. Multiplication\n";
    cout<<"4. Division\n";
    cout<<"5. Square Root\n";
    cout<<"6. Power\n";
    cout<<"7. sine\n";
    cout<<"8. cosine\n";
    cout<<"9. Tangent\n";
    cout<<"10. Logarithm(base 10)\n";
    cout<<"11. Enter your choice (1-10):";
    cin>>choice;

switch(choice)
{
case 1:
cout<<"Enter two number :";
cin>>num1>>num2;
result = sc.add(num1,num2);
cout<<"Result :"<<result<<endl;
logResult("Addition", result);
break;
case 2:
cout<<"Enter two numbers :";
cin>>num1>>num2;
result = sc.subtract(num1, num2);
cout<<"Result :"<<result<<endl;
logResult("Subtraction",result);
break;
case 3:
cout<<"Enter two number";
cin>>num1>>num2;
result = sc.multiply(num1,num2);
cout<<"Result :"<<result<<endl;
logResult("Multiplication", result);
break;
case 4:
cout<<"Enter two number :";
cin>>num1>>num2;
result = sc.divide(num1,num2);
cout<<"Result :"<<result<<endl;
logResult("Division",result);
break;
case 5:
cout<<"Enter a number: ";
cin>>num1;
result = sc.squareRoot(num1);
cout<<"Result :"<<result<<endl;
logResult("Square Root",result);
break;
case 6:
cout<<"Enter two number :";
cin>>num1>>num2;
result = sc.power(num1, num2);
cout<<"Result :"<<result<<endl;
logResult("Power", result);
break;
case 7:
cout<<"Enter a number :"; 
cin>>num1;
result = sc.sine(num1);
cout<<"Result :"<<result<<endl;
logResult("sine",result);
break;
case 8:
cout<<"Enter a number :";
cin>>num1;
result = sc.cosine(num1);
cout<<"Result :"<<result<<endl;
logResult("Cosine",result);
break;
case 9:
cout<<"Enter a number :";
cin>>num1;
result = sc.tangent(num1);
cout<<"Result :"<<result<<endl;
logResult("Tangent",result);
break;
case 10:
cout<<"Enter a number :";
cin>>num1;
result = sc.logBase10(num1);
cout<<"Result :"<<result<<endl;
logResult("Logarithm (base10)",result);
break;
default:
cout<<"Invalid choice!"<<endl;
break;
}
return 0;
}
