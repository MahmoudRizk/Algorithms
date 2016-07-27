#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
void print(int array[])
{
  for(int i=0;i<100;i++)
    cout<<array[i]<<" "<<endl;
  cout<<endl;
}

void print(vector<int> array)
{
  for(int i=0;i<array.size();i++)
    cout<<array[i]<<" "<<endl;
    cout<<endl;
}

void Bubble_sort(int array[])
{
  for(int i=0;i<100;i++)
    for(int j=0;j<99;j++)
      if(array[j]>array[j+1])
            swap(array[j],array[j+1]);
}
void Insertion_sort(int array[])
{
    for(int i=1;i<10;i++)
    {
        int j;
        j=i;
        while(j>0 && array[j-1]>array[j])
        {
            swap(array[j-1],array[j]);
            j--;
        }
   }
}

void Selection_sort(int array[])
{
  /*find the minimum element in the array, then place it at it's correct value*/
  for(int i=0;i<9;i++)
  {
    int min_index=i;
    int min_value=array[i];
    for(int j=i+1;j<10;j++)
    {
       if(array[j]<min_value)
       {
          min_index=j;
          min_value=array[j];
       }

    }
     swap(array[i],array[min_index]);
     //print(array);
     //cout<<endl;
  }

}

void Merge(vector<int> &arr1,vector<int> &arr2,vector<int> &array)
{

  int i=0;
  int j=0;
  int k=0;
  bool flag1=false, flag2=false;
  while(i<arr1.size() || j<arr2.size())
  {
    if(arr1[i]<arr2[j] && flag1==false)
    {
        array[k]=arr1[i];
        k++;
        if(i!=arr1.size()-1)
            i++;
        else
            flag1=true;
    }
    else if(arr1[i]>arr2[j] && flag2==false)
    {
      array[k]=arr2[j];
      k++;
      if(j!=arr2.size()-1)
            j++;
      else
            flag2=true;
    }
    else if(flag1==true)
    {
        for(j;j<arr2.size();j++)
        {
            array[k]=arr2[j];
            k++;
        }
         break;
    }
    else if(flag2==true)
    {
       for(i;i<arr1.size();i++)
       {
            array[k]=arr1[i];
            k++;
        }
         break;
    }

  }



}
void Merge_sort(vector<int>&array)
{
    vector<int> arr1;
    vector<int> arr2;
    int middle;
    int n=array.size();
    if(n>=2)
    {
    middle=n/2;

    if(n>2)  //splitting array into two arrays
    {
        for(int i=0;i<=middle;i++)
            arr1.push_back(array[i]);
        for(int j=middle+1;j<array.size();j++)
            arr2.push_back(array[j]);
    }
    else if(n==2) //splitting last two elements in the array into two arrays
    {
        for(int i=0;i<middle;i++)
            arr1.push_back(array[i]);
        for(int j=middle;j<array.size();j++)
            arr2.push_back(array[j]);
    }

    if(arr1.size()>1)   //splitting arr1 into two other arrays
        Merge_sort(arr1);
    if(arr2.size()>1)   //splitting arr2 into two other arrays
        Merge_sort(arr2);
    }

    Merge(arr1,arr2,array); //Merge function: merging two sorted arrays
}


int Partition(vector<int> &array, int start, int end)
{
  int pivot_value;
  int pivot_index;
  pivot_value=array[end-1];
  pivot_index=start;
  for(int i=start;i<end-1;i++)
  {
     if(array[i]<=pivot_value)
     {
       swap(array[i],array[pivot_index]);
       pivot_index++;
     }
  }
        swap(array[end-1],array[pivot_index]);
        return pivot_index;
}

void Quick_sort(vector<int> &array, int start, int end)
{

   //Not working well
   //from MycodeSchool
   int pivot_index;
   if(start<end)
   {
      pivot_index=Partition(array,start,end);
      Quick_sort(array, start, pivot_index-1);
      Quick_sort(array, pivot_index+1, end);
   }



}

void Quick_sort2(int array[],int left, int right)
{

    //working Fine
    int pivot_initial_index=(left+right)/2;
    int i=left;
    int j=right-1;
    int pivot_value=array[pivot_initial_index];
    while(left<j || i<right)
    {
        while(array[i]<pivot_value)
            i++;
        while(array[j]>pivot_value)
            j--;

         if(i<=j)
         {
               swap(array[i],array[j]);
               i++;
               j--;
         }
         else
         {
               if(left<j)
                    Quick_sort2(array,left,j);
               if(right>i)
                    Quick_sort2(array,i,right);
                return;
         }
     }

}

int Binary_search(int item,vector<int> array, int left_index, int right_index)
{
   if(left_index==right_index)
   {
        if(array[left_index]==item)
            return left_index;
        else
            return -1;
   }
   if(left_index>right_index)
        return -1;

   int mid_index=(left_index+right_index)/2;
   if(array[mid_index]==item)
            return mid_index;

    if(array[mid_index]<item)
        return Binary_search(item,array,mid_index+1,right_index);
    if(array[mid_index]>item)
         return Binary_search(item,array,left_index,mid_index-1);

}
int main()
{
    //int m=rand()%10;
    int array[100];
    for(int i=0;i<100;i++)
    {
      array[i]=rand()%100;
    }
    //Bubble_sort(array);
    //int array[10]={0,1,2,3,4,5,6,7,8,9};
    //Insertion_sort(array);
    //Selection_sort(array);
    //print(array);
    vector<int> array1;
    for(int i=0;i<100;i++)
       array1.push_back(array[i]);

    Merge_sort(array1);
    //print(array1);
    //cout<<endl<<endl;

    //Quick_sort2(array,0,100);
    //Merge_sort(array1);
    print(array1);
    //cout<<"The number:4 is at index "<<Binary_search(4,array1,0,10-1)<<endl;
    return 0;
}
