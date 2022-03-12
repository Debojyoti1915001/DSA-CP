#include<iostream>
using namespace std;

class ShopItem
{
    int id;
    float price;
    public:
        void setData(int a, float b){
            id = a;
            price = b;
        }
        void getData(void){
            cout<<"Code of this item is "<< id<<endl;
            cout<<"Price of this item is "<<price<<endl;
        }
};
// int main(){
//     ShopItem* ptr=new ShopItem[3];
//     ShopItem* tempPtr=ptr;
//     for(int i=0;i<3;i++){
//         ptr->setData(i,i+5);
//         // ptr->getData();
//         ptr++;
//     }
//     for(int i=0;i<3;i++){
//         // tempPtr->setData(i,i+5);
//         tempPtr->getData();
//         tempPtr++;
//     }
// }
int main(){
    int size = 3;
    ShopItem *ptr = new ShopItem [size];
    ShopItem *ptrTemp = ptr;
    int p, i;
    float q;
    for (i = 0; i < size; i++)
    {
        cout<<"Enter Id and price of item "<< i+1<<endl;
        cin>>p>>q;
        // (*ptr).setData(p, q);
        ptr->setData(p, q);
        ptr++; 
    }

    for (i = 0; i < size; i++)
    {
        cout<<"Item number: "<<i+1<<endl;
        ptrTemp->getData();
        ptrTemp++;
    }
    
    
    return 0;
}
