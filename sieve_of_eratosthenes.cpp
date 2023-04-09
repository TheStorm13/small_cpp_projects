#include <iostream>

int main(){
    int n;
    std::cin>>n;
    int *arr=new int[n+1];
    for (int i = 0; i < n+1; ++i)
        arr[i]=i;

    for (int i = 2; i < n+1; ++i) {
        if (arr[i])
            for (int j = 2*i; j < n+1; j+=i) {
                arr[j]=0;
            }
    }
    for (int i = 0; i < n+1; ++i)
        if (arr[i])
            std::cout<<arr[i]<<" ";

    return 0;
}