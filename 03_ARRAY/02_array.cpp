#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //Q1. Left rotate an array by 1 positions

        int temp = arr[0];
        for (int i=1; i<n ;i++)
        {
            arr[i-1] = arr[i];
        }
        //or
        // for (int i=0; i<n-1 ;i++){
        //     arr[i] = arr[i+1];
        // }
        arr[n-1] = temp;
        // time complexity = O(n)
        // space complexity = O(1)
    
    
    // Q2(a). Left rotate an array by D positions

    // brute force approach (using temporary array )
        int d;
        cin>>d;

        //reducing d if it is greater than n
        d = d%n;
       
        // store the first d elements in a temporary array 
        vector<int> temp(d);
        for (int i=0; i<d; i++){
            temp[&i] = arr[i];
        }

        // shift the remaining n-d elements to the left by d positions
        for (int i=d; i<n; i++){
            arr[i-d] = arr[i];
        }

        // copy the d elements from the temporary array to the end of the original array
        for (int i=0; i<d; i++){
            arr[n-d+i] = temp[&i];
        }
        // time complexity = O(d) + O(n-d) + O(d) = O(n+d) = O(n)
        // space complexity = O(d)

        // optimal approach (using reverse method)
        auto reverser = [&](vector<int> &arr, int start, int end){
            while(start<=end){
                int temp = arr[start];
                arr[start++] = arr[end];
                arr[end--] = temp;
                // start++;
                // end--;
            }
        }
        ;
        // reverse the first d elements of the array
        reverser(arr, 0, d-1);
        // reverse the remaining elements of the array
        reverser(arr, d, n-1);
        // reverse the entire array
        reverser(arr, 0, n-1);

        // if(n == 0) return 0;  it is important to handle the case when n is 0 to avoid division by zero error in the line where we calculate d % n. If n is 0, we can simply return 0 since there are no elements to rotate.
        // d = ((d % n) + n) % n; this line is used to handle the case when d is negative. It ensures that d is always a non-negative value less than n, which is necessary for the rotation to work correctly. If d is negative, it will be converted to a positive equivalent by adding n to it before taking the modulus with n.
        // time complexity = O(d)+O(n-d)+O(n) = O(n)
        // space complexity = O(1)

        // Q2(b). right rotate an array by D positions

    // brute force approach (using temporary array )
       
       
        // store the first d elements in a temporary array 
        vector<int> temp(d);
        for (int i=n-d; i<n; i++){
            temp[&i-(n-d)] = arr[i];
        }

        // shift the remaining n-d elements to the right by d positions
        for (int i=n-d-1; i>=0; i--){
            arr[i+d] = arr[i];
        }

        // copy the d elements from the temporary array to the start of the original array
        for (int i=0; i<d; i++){
            arr[i] = temp[&i];
        }
        // time complexity = O(d) + O(n-d) + O(d) = O(n+d) = O(n)
        // space complexity = O(d)

        // optimal approach (using reverse method)
        auto reverserr = [&](vector<int> &arr, int start, int end){
            while(start<=end){
                int temp = arr[start];
                arr[start++] = arr[end];
                arr[end--] = temp;
                // start++;
                // end--;
            }
        }
        ;
        // reverse the entire array
        reverserr(arr, 0, n-1);
        // reverse the first d elements of the array
        reverserr(arr, 0, d-1);
        // reverse the remaining elements of the array
        reverserr(arr, d, n-1);

        // time complexity = O(n)+O(d)+O(n-d) = O(n)
        // space complexity = O(1)


        // Q3. Move all the zeroes to the end of the array
        
        // brute force approach (using temporary array )
        vector<int> temp1;
        for (int i=0; i<n; i++){
            if(arr[i] != 0){
                temp1.push_back(arr[i]);
            }
        }
        // filling the temporary array back to the original array
        for (int i=0; i<temp1.size(); i++){
            arr[i] = temp1[i];
        }
        // filling the zeroes at the end of the original array
        for (int i=temp1.size(); i<n; i++){
            arr[i] = 0;
        }

        //time complexity = O(n) + O(temp.size()) + O(n-temp.size()) = O(2n)
        // space complexity = O(temp.size())= O(n)
        

        // optimal approach (using two pointers)

        // finding the first zero in the array
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                j = i;
                break;
            }
        }

        // if no zero is found, the array is already optimal
        // if (j == -1) {
            // return 0;
        // }

        // move all non-zero elements to the left of the first zero
        for (int i = j + 1; i < n; i++) {
            if (arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
        // time complexity = O(x)+O(n-x) = O(n)
        // space complexity = O(1)


        // Q4(a). Find union of sorted arrays

        int arr1[] = {1, 1, 3, 5, 6};
        int arr2[] = {2, 2, 3, 4, 5};
        int n1 = sizeof(arr1)/sizeof(arr1[0]);
        int n2 = sizeof(arr2)/sizeof(arr2[0]);

        // Brute force by using set
        
        set<int> s;
        // inserting elements of both arrays into the set
        for (int i=0; i<n1; i++){
            s.insert(arr1[i]);
        }
        for (int i=0; i<n2; i++){
            s.insert(arr2[i]);
        }
        // printing the union of the two arrays
        //By using a array
        int union1[s.size()];
         int index = 0;
        for (auto it : s){
            union1 [index++] = it;
        }
        // Or by using a vector
        vector<int> unionv;
        for (auto it : s){
            unionv.push_back(it);
        }

        //time complexity = O(n1 log n) + O(n2 log n) + O(n1 + n2) = O((n1 + n2) log n)
        // space complexity = O(n1 + n2)+ O(n1 + n2) = O(n1 + n2)
   
        //optimal approach (using two pointers)

        int i = 0, j = 0;
        vector<int> unionv2;
        //using two pointer and checking accordingly
        while(i<n1 && j<n2){
            if(arr1[i] <= arr2[j]){
                if(unionv2.empty() || unionv2.back() != arr1[i]){
                    unionv2.push_back(arr1[i]);
                }
                i++;
            }
            else {
                if(unionv2.empty() || unionv2.back() != arr2[j]){ //.empty tell if the vector is empty or not and .back() return the last element of the vector
                    unionv2.push_back(arr2[j]);
                }
                j++;
            }
            
        }
        // checking for the remaining elements of the first array if any
        while(i<n1){
            if(unionv2.empty() || unionv2.back() != arr1[i]){
                unionv2.push_back(arr1[i]);
            }
            i++;
        }
        // checking for the remaining elements of the second array if any
        while(j<n2){
            if(unionv2.empty() || unionv2.back() != arr2[j]){
                unionv2.push_back(arr2[j]);
            }
            j++;
        }
        //printing the union of the two arrays
        for (int i=0; i<unionv2.size(); i++){
            cout<<unionv2[i]<<" ";
        }
        //or by using a range based for loop
        for (auto it : unionv2){
            cout<<it<<" ";
        }

        // time complexity = O(n1 + n2)
        // space complexity = O(n1 + n2)
        
        // Q4(b). Find intersection of sorted arrays


    return 0;

}