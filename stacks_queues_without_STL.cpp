Stacks
#include<iostream>
using namespace std;
const int n=15;
class Stacks
{
public:
    int stack[n];
    int top;
    Stacks()
    {
        top=-1;
    }
    void push(int x)
    {
        if(n-1==top)
        {
            cout<<"Overflow"<<endl;
        }
    else
        {
            top=top+1;
            stack[top]=x;
        }
    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"Underflow"<<endl;
        }
        else
        {
            top=top-1;
        }
    }
    void display()
    {
        while(top!=-1)
        {
            cout<<stack[top]<<", ";
            top=top-1;
        }
        cout<<endl;
    }
    int size()
    {
        return top+1;
    }

    int topElement()
    {
        return stack[top];
    }
    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stacks s1,s2,s3,s4,temp;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    int a=s1.size()-1;
    int b=a/2;
    int c=a-b;

    while(!s1.isEmpty())
    {
        int t=s1.topElement();
        if(a<=b)
        {
            s2.push(t);
        }
        else
        {
            s3.push(t);
        }
        s1.pop();
        a--;
    }
    while(!s3.isEmpty())
    {
        int t=s3.topElement();
        s1.push(t);
        s3.pop();
    }
    while(!s2.isEmpty())
    {
        int t=s2.topElement();
        s1.push(t);
        s2.pop();
    }
    s1.display();
}


Queue
#include<iostream>
using namespace std;
const int n=15;
class Queue
{
public:
    int queue[n];
    int front;
    int back;
    Queue()
    {
        front=-1;
        back=-1;
    }
    void push(int x)
    {
        if(front==0 && back==n-1)
        {
            cout<<"Overflow"<<endl;
        }
        else
        {
            if(front==-1)
            {
                front=0;
            }
            back=back+1;
            queue[back]=x;


        }
    }

    void pop()
    {
        if(front==-1)
        {
            cout<<"Underflow"<<endl;
        }
        else
        {

            queue[front]=0;
            if(front==back)
            {
                front=-1;
                back=-1;
            }
            else
            {
                front=front+1;
            }
        }
    }
    int size()
    {
        return back-front;
    }

    int frontElement()
    {
        return queue[front];
    }
    bool isEmpty()
    {
        if(front==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Queue s1,s2,s3,s4,temp;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.pop();
    int i;
    for(i=s1.front; i<=s1.back; i++)
    {
        cout << s1.queue[i] << "\t";

    }
    cout<<endl;

}



Merge Sort
#include<iostream>
using namespace std;

void mergee(int a[],int lo,int mid,int hi)
{
    int b[hi+1];
    int i,j,k;
    i=lo;
    j=mid+1;
    k=lo;
    while(i<=mid && j<=hi)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }

    }
    while(i<=mid)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=hi)
    {
        b[k]=a[j];
        k++;
        j++;
    }
    for (int i = lo; i <= hi; i++)
    {
        a[i] = b[i];
    }

}

void mergesort(int a[],int l,int h)
{
    int mid;
    if(l<h)
    {

        mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        mergee(a,l,mid,h);
    }

}



int main()
{
    int a[]={5,3,6,7,23,12};
    mergesort(a,0,5);
    int i;
    for(i=0;i<=5;i++)
    {
        cout<<a[i]<<",";
    }
    cout<<endl;

}


Quicksort
#include<iostream>
using namespace std;



int partition(int A[],int l,int h)
{
    int p=A[l];
    int i=l,j=h;
    do
    {
        do
        {
            i++;
        }while(A[i]<=p);

        do
        {
            j--;
        }while(A[j]>p);

        if(i<j)
        {
            swap(A[i],A[j]);
        }
    }while(i<j);

    swap(A[l],A[j]);
    return j;

}

void quicksort(int a[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=partition(a,l,h);
        quicksort(a,l,mid-1);
        quicksort(a,mid+1,h);
    }
}

int main()
{
    int a[]={5,3,6,7,23,12};
    quicksort(a,0,6);
    int i;
    for(i=0;i<=5;i++)
    {
        cout<<a[i]<<",";
    }
    cout<<endl;
}


radix sort
#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

int main()
{
    int a[]={124,436,562,22,1,26,799};
    int max=a[0],n=7,i;
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    int c=0,d;
    while(max>0)
    {
        max=max/10;
        c++;
    }
    node *b[10];
    int t,j,index,k;

    t=1;
    for(i=0;i<c;i++)
    {

        //cout<<t;
        for(d=0;d<10;d++)
        {
            b[d]=NULL;
        }
        for(j=0;j<n;j++)
        {
            index=(a[j]/t)%10;
            node *ptr=new node;
            ptr->data=a[j];
            ptr->next=NULL;
            if(b[index]==NULL)
            {
               b[index]=ptr;

            }
            else
            {
                node *h=b[index];
                while(h->next!=NULL)
                {
                    h=h->next;
                }
                h->next=ptr;

            }
        }
        k=0;
        for(j=0;j<10;j++)
        {
            node *h=b[j];
            while(h!=NULL)
            {
                a[k]=h->data;
                h=h->next;
                k++;
            }

        }
        t=10*t;

    }
    for(j=0;j<n;j++)
    {
        cout<<a[j]<<",";
    }

}

Bucket Sort
#include<iostream>
#include<vector>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

int main()
{
    float a[]={0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68};
    int n=10,k,i,j;
    float t;
    vector<float>b[n];
    for(i=0;i<n;i++)
    {
        k=a[i]*n;
        b[k].push_back(a[i]);
    }

    for(i=0;i<n;i++)
    {
        int x=b[i].size();
        for(j=0;j<x-1;j++)
        {
            for(k=j+1;k!=-1;k--)
            {
                if(b[i][k]<b[i][k-1])
                {
                    t=b[i][k];
                    b[i][k]=b[i][k-1];
                    b[i][k-1]=t;
                }
            }
        }
    }
    int d=0;
    for(i=0;i<n;i++)
    {
        int x=b[i].size();
        for(j=0;j<x;j++)

bubble sort
int a[]={5,7,3,2,9,1};
    int n=6;
    int t,i,j;
    for(i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<",";
    }

Insertion sort
int a[]={5,7,3,2,9,1};
    int n=6;
    int t,i,j;
    for(i=0;i<n;i++)
    {
        int k=a[i];
        for (j=i;j!=0;j--)
        {
            if(a[j]<a[j-1])
            {
                t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<",";
    }

count sort
int a[]={5,7,3,2,9,1};
    int n=6;
    int t,i,j;
    int k=a[0];
    for(i=0;i<n;i++)
    {
        if(k<a[i])
        {
            k=a[i];
        }
    }
    k=k+1;
    int b[k];
    for(i=0;i<k;i++)
    {
        b[i]=0;
    }
    for(j=0;j<n;j++)
    {
        b[a[j]]++;
    }
    j=0;
    for(i=0;i<k;i++)
    {
        while(b[i]!=0)
        {
            a[j]=i;
            j++;
            b[i]--;
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<",";
    }

Selection sort
int a[]={8,0,7,1,3};
    int n=5,i,j,t;
    for(i=0;i<n-1;i++)
    {
        int k=a[i];
        int index;
        for(j=i;j<n;j++)
        {
            if(k>a[j])
            {
                k=a[j];
                index=j;
            }
        }
        t=a[index];
        a[index]=a[i];
        a[i]=t;

    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<",";
    }


Median search
#include<iostream>
using namespace std;

int mediansearch(int a[],int l,int r,int k)
{
    int i,j=0,n=0,m=0;
    int ind=r-l+1;
    int index=rand()%ind;
    int b1[10],b2[1],b3[10];
    for(i=0;i<=r;i++)
    {
        if(a[i]<a[index])
        {
            b1[j]=a[i];
            j++;
        }
        else if(a[i]==a[index])
        {
            b2[n]=a[i];
            n++;
        }
        else
        {
            b3[m]=a[i];
            m++;
        }
    }
    if(j>=k)
    {
        mediansearch(b1,0,j-1,k);
    }
    else if((j+n)>=k)
    {
        return a[index];
    }
    else
    {
        mediansearch(b3,0,m-1,k-(j+n));
    }


}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15, 8, 12,6};
    int n = sizeof(arr)/sizeof(arr[0]), t = 4;
    int element=mediansearch(arr, 0, n-1, t);
    cout << "K'th smallest element is "<<element;
    return 0;
}


interpolation search


#include <bits/stdc++.h>
using namespace std;

int interpolationSearch(int arr[], int lo, int hi, int x)
{
	int pos;

	if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {

		pos = lo
			+ (((double)(hi - lo) / (arr[hi] - arr[lo]))
				* (x - arr[lo]));

		if (arr[pos] == x)
			return pos;

		if (arr[pos] < x)
			return interpolationSearch(arr, pos + 1, hi, x);


		if (arr[pos] > x)
			return interpolationSearch(arr, lo, pos - 1, x);
	}
	return -1;
}

int main()
{

	int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21,
				22, 23, 24, 33, 35, 42, 47 };

	int n = sizeof(arr) / sizeof(arr[0]);

	int x = 18;
	int index = interpolationSearch(arr, 0, n - 1, x);

	if (index != -1)
		cout << "Element found at index " << index;
	else
		cout << "Element not found.";

	return 0;
}

