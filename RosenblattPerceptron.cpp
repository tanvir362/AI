/**
Created on Fri Jul  5 21:55:04 2019
@author: TANVIR
**/
#include<iostream>
using namespace std;
class Perceptron{
private:
    float w1;
    float w2;
    float b;
    float lr;
    int dset[4][3];
    void update(int x1, int x2, int e)
    {
        w1 = w1 + (lr*e*x1);
        w2 = w2 + (lr*e*x2);
        b = b + (-lr*e);
    }
public:
    Perceptron(float W1, float W2, float B, float LR)
    {
        w1 = W1;
        w2 = W2;
        b = B;
        lr = LR;
        cout<<"Enter training dataset:"<<endl;
        int i,j;
        for(i=0;i<4;i++){
            for(j=0;j<3;j++){
                cin>>dset[i][j];
            }
        }
    }
    void training()
    {
        cout<<"Model is learning.."<<endl;
        float net;
        int i,t,y,e,x1,x2,itr=100000;
        while(itr--){
            for(i=0;i<4;i++){
                x1 = dset[i][0];
                x2 = dset[i][1];
                t = dset[i][2];
                net = w1*x1 + w2*x2 - b;
                //cout<<net<<" ";
                if(net>0.00000000000000) y = 1;
                else y = 0;
                e = t - y;
                if(e == 0){
                    //cout<<"ok"<<endl;
                }
                else{
                    //cout<<"updating"<<endl;
                    update(x1,x2,e);
                    i--;
                }
            }
        }
        cout<<"Learning completed!"<<endl;
        cout<<w1<<"  "<<w2<<"  "<<b<<endl;
    }
    int test(int x1, int x2)
    {
        float net;
        int y;
        net = w1*x1 + w2*x2 - b;
        if(net>0) y = 1;
        else y = 0;
        return y;
    }

};
int main(void)
{
    int x1,x2;
    Perceptron obj = Perceptron(0.5,0.5,0.2,0.1);
    obj.training();
    cout<<"Enter test data to test the model:"<<endl;
    while(cin>>x1>>x2){
        cout<<obj.test(x1,x2)<<endl;
    }
    return 0;
}
