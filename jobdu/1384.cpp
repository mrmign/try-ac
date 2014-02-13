/*
 * 1384.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 *
 * 二维数组中的查找
 *
 */

/*
 * 这个版本超时，不要用cin,cout,建议用scan,printf
 *
 * 用二分查找
 */
//#include <iostream> 
//using namespace std;
//#define MAX 1000
//int matrix[MAX*MAX];
//bool find(int matrix[], int rows, int cols, int t);
//int main(int argc, char *argv[])
//{
//    int m, n;
//    int t;
//    while(cin>>m>>n){
//        cin>>t;
//        int total = m*n;
//        int i = 0;
//        while(i<total){
//            cin>>matrix[i];
//            i++;
//        }
//        bool res = find(matrix, m, n, t);
//        if(res)
//            cout<<"Yes"<<endl;
//        else
//            cout<<"No"<<endl;
//    }
//    return 0;
//}


//bool find(int matrix[], int rows, int cols, int t)
//{
//    bool found = false;
//    if(matrix != NULL && rows > 0 && cols > 0){
//        int row = 0;
//        int col = cols - 1;
//        while(row < rows && col >= 0){
//            if(matrix[row * cols + col] == t){
//                found = true;
//                break;
//            }
//            else if(matrix[row*cols + col] > t)
//                col--;
//            else
//                row++;
//        }
//    }
//    return found;
//}

/*
 * new version
 */

#include <cstdio>
using namespace std;
const int MAX = 1000;
int matrix[MAX][MAX];
bool find(int matrix[][MAX], int rows, int cols, int t);
int main(int argc, char *argv[])
{
    int m, n, t;    
    while(scanf("%d %d", &m, &n) != EOF){
        scanf("%d", &t);
        for(int i=0; i < m; i++)
            for(int j = 0; j<n; j++)
                scanf("%d", &matrix[i][j]);
        bool ret = find(matrix, m, n, t);
        if(ret)
            printf("Yes\n");
        else
            printf("No\n");

    }
    return 0;
}

bool find(int matrix[][MAX], int rows, int cols, int t)
{
    bool found = false;
    int col = cols - 1;
    for(int i = 0; !found && i<rows; i++){
        if(matrix[i][0] > t){
            break;
        }
        else if(matrix[i][col] < t)
            continue;
        else{
            int low(0), high(col);
            while(low <= high){
                int mid = (low + high)/2;
                if(matrix[i][mid] == t){
                    found = true;
                    break;
                }
                else if(matrix[i][mid] < t){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
    }
    return found;
}
