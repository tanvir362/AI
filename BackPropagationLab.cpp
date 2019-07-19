/**
Created on Wed Jul  10 21:55:04 2019

@author: TANVIR
**/

#include<iostream>
#include<math.h>
using namespace std;
class Node
{
public:
    float w1;
    float w2;
    float x1;
    float x2;
    float b;
    float y;
    Node(float W1, float W2, float B)
    {
        w1 = W1;
        w2 = W2;
        b = B;
    }
    Node()
    {
        //cout<<"Use parameterized constructor!"<<endl;
    }
    float calculate_net()
    {
       return x1*w1 + x2*w2 + b;
    }
    float activation(float x)
    {
        y = 1/(1+ exp(-x));
        return y;
    }
};
class BackPropagation{
public:
    float lr;
    float dset[4][3];
    Node nd1;
    Node nd2;
    Node nd3;
    BackPropagation(float w11, float w12, float w21, float w22, float w13, float w23, float b1, float b2, float b3, float LR)
    {
        nd1 = Node(w11,w21,b1);
        nd2 = Node(w12,w22,b2);
        nd3 = Node(w13,w23,b3);
        lr = LR;
        cout<<"Enter training dataset:"<<endl;
        int i,j;
        for(i=0;i<1;i++){
            for(j=0;j<3;j++){
                cin>>dset[i][j];
            }
        }
    }
    void update(float e)
    {
        nd3.w1 = nd3.w1 + lr*e*nd3.x1;
        nd3.w2 = nd3.w2 + lr*e*nd3.x2;
        nd3.b = nd3.b + lr*e;

        nd2.w1 = nd2.w1 + lr*e*nd2.x1;
        nd2.w2 = nd2.w2 + lr*e*nd2.x2;
        nd2.b = nd2.b + lr*e;

        nd1.w1 = nd1.w1 + lr*e*nd1.x1;
        nd1.w2 = nd1.w2 + lr*e*nd1.x2;
        nd1.b = nd1.b + lr*e;
    }

    void training()
    {
        cout<<"Model is learning.."<<endl;

        int i,itr=100000;
        float y,t,e;
        while(itr--){
            for(i=0;i<1;i++){
                nd1.x1 = dset[i][0];
                nd1.x2 = dset[i][1];
                nd2.x1 = dset[i][0];
                nd2.x2 = dset[i][1];
                nd3.x1 = nd1.activation(nd1.calculate_net());
                nd3.x2 = nd2.activation(nd2.calculate_net());
                y = nd3.activation(nd3.calculate_net());
                t = dset[i][2];
                e = (t - y)*y*(1-y);
                if(e == 0){
                    //cout<<"ok"<<endl;
                }
                else{
                    //cout<<"updating"<<endl;
                    update(e);
                    //i--;
                }
            }
        }
        cout<<"Learning completed!"<<endl;
    }
    float test(float x1, float x2)
    {
        float y;
        nd1.x1 = x1;
        nd1.x2 = x2;
        nd2.x1 = x1;
        nd2.x2 = x2;
        nd3.x1 = nd1.activation(nd1.calculate_net());
        nd3.x2 = nd2.activation(nd2.calculate_net());
        y = nd3.activation(nd3.calculate_net());
        cout<<nd1.w1<<"  "<<nd1.w2<<endl;
        cout<<nd2.w1<<"  "<<nd2.w2<<endl;
        cout<<nd3.w1<<"  "<<nd3.w2<<endl;
        return y;
    }

};
int main(void)
{
    float x1,x2;
    BackPropagation obj = BackPropagation(0.1,0.3,0.2,0.4,0.5,0.6,0.1,0.2,0.3,0.1);
    obj.training();
    cout<<"Enter test data to test the model:"<<endl;
    while(cin>>x1>>x2){
        cout<<obj.test(x1,x2)<<endl;
    }
    return 0;
}

