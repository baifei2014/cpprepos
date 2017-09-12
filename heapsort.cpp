#include<iostream>
using namespace std;
#define MAXSIZE 20
typedef int KeyType;
typedef struct{
    KeyType key;
}RedType;
typedef struct{
    RedType r[MAXSIZE+1];
    int length;
}SqList;
void HeapAdjust(SqList &L,int s,int m)
{
	int j;
    RedType rc;
    rc = L.r[s];
    for (j = 2*s; j <= m; j*=2)
    {
        if(j<m && L.r[j].key < L.r[j+1].key) ++j;
        if(rc.key >= L.r[j].key) break;
        L.r[s] = L.r[j]; s = j;
    }
    L.r[s] = rc;
}
void CreateHeap(SqList &L)
{
	int i,n;
    n=L.length;
    for (i = n/2; i > 0; --i)
    {
        HeapAdjust(L,i,n);
    }
}
void HeapSort(SqList &L)
{
	int i;
	RedType x;
    CreateHeap(L);
    for (i = L.length; i > 1; --i)
    {
        x = L.r[1];
        L.r[1] = L.r[i];
        L.r[i] = x;
        HeapAdjust(L,1,i-1);
    }
}
int main(){
    SqList L = {{49, 38, 65, 97, 76, 13, 27, 49}, 8};
	HeapSort(L);
	for (int i = L.length; i > 1; --i)
    {
        cout<<L.r[i].key<<endl;
    }
    return 0;
}
