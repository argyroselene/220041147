#include<iostream>
using namespace std;
class Time{
    private:
       int hour;
       int minute;
       int second;
    public:
        Time(){
            hour=3;
            minute=45;
            second=47;
        }
         int hours(){
            return hour;
         }
         int minutes(){
            return minute;
         }
         int seconds(){
            return second;
         }
         void reset(int h,int m,int s){
            hour=h;
            minute=m;
            second=s;
         }
         void advance(int h,int m,int s){
            hour+=h;
            minute+=m;
            second+=s;
            if(second>=60){
                second=second-60;
                minute++;
            }
            if(minute>=60){
                minute=minute-60;
                hour++;
            }
            if(hour>=24){
                hour=hour-24;
            }
         }
         void print(){
            cout<<"Time is "<<hours()<<" hours";
            cout<<" "<<minutes()<<" minutes ";
            cout<<seconds()<<" seconds"<<endl;
         }

};

int main(){
    Time time;
    time.reset(6,34,7);
    time.advance(5,32,58);
    time.print();
}