#include<iostream>
using namespace std;

class Counter{
    private:
        int count;
        int incsteps;
    public:
        Counter(){
            count=0;
            incsteps=1;
        }
    void setIncrementStep(int step){
    incsteps=step;
    }
    int getCount(){
        return count;
    }
    void increment(){
        count=count+incsteps;
    }
    void resetCount(){
        count=0;
    }
};

int main(){
    Counter counter;
    counter.setIncrementStep(3);
    counter.increment();
    cout<<"Count: "<<counter.getCount()<<endl;
    counter.increment();
    cout<<"Count: "<<counter.getCount()<<endl;
    counter.resetCount();
    cout<<"Count: "<<counter.getCount()<<endl;
}

