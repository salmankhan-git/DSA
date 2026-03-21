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
        vector<int> temp;
        for (int i=0; i<n; i++){
            if(arr[i] != 0){
                temp.push_back(arr[i]);
            }
        }
        // filling the temporary array back to the original array
        for (int i=0; i<temp.size(); i++){
            arr[i] = temp[i];
        }
        // filling the zeroes at the end of the original array
        for (int i=temp.size(); i<n; i++){
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


        // Q4. Find union of sorted arrays

        int arr1[5] = {1, 1, 3, 5, 6};
        int arr2[5] = {2, 2, 3, 4, 5};
        
        
        
    return 0;

}