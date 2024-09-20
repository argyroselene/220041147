#include<iostream>
#include<string>
using namespace std;

class Temperature{
    private:
        double temp;
        string type;

        bool valid(const string &u){
            return (u=="Celsius" || u=="Farenheit" || u=="Kelvin");
        }
    bool notabszero(double val, const string& u) {
        if (u == "Celsius" && val >= -273.15) return true;
        if (u == "Fahrenheit" && val >= -459.67) return true;
        if (u == "Kelvin" && val >= 0) return true;
        return false;
    }
    public:
    void assign(double temperature,const string &unit){
        if(!valid(unit)){
            cout<<"Invalid unit"<<endl;
        }
        if(!notabszero(temperature,unit)){
            cout<<"Below absolute zero"<<endl;
        }
        temp=temperature;
        type=unit;
    }
    double convert(const string &targetUnit){
        if(!valid(targetUnit)){
            cout<<"Invalid Unit"<<endl;
            return temp;
        }
        double result=temp;
        if (type == "Celsius") {
            if (targetUnit == "Fahrenheit") {
                result = temp * 9 / 5 + 32;
            } else if (targetUnit == "Kelvin") {
                result = temp + 273.15;
            }
        } else if (type == "Fahrenheit") {
            if (targetUnit == "Celsius") {
                result = (temp - 32) * 5 / 9;
            } else if (targetUnit == "Kelvin") {
                result = (temp - 32) * 5 / 9 + 273.15;
            }
        } else if (type == "Kelvin") {
            if (targetUnit == "Celsius") {
                result = temp - 273.15;
            } else if (targetUnit == "Fahrenheit") {
                result = (temp - 273.15) * 9 / 5 + 32;
            }
        }
        return result;

    }
    void print() {
        cout << "The temperature is " <<temp << " " << type << endl;
    }
};

int main(){
    Temperature temp;
    temp.assign(98.4,"Fahrenheit");
    temp.print();
    double convertedtemp=temp.convert("Celsius");
    cout<<"Temperature in celcius "<<convertedtemp<<endl;
    temp.assign(100,"Celsius");
    temp.print();
    convertedtemp=temp.convert("Kelvin");
    cout<<"Temperature in kelvin "<<convertedtemp<<endl;
}