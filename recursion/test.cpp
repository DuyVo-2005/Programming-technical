/*
    MSSV:23110201
    Ho Ten:Tran Le Quoc Dai
    Ngay sinh:27/04/2005
    Lop: PRTE230385_04
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <fstream>
#define MAX 20
#define VC 10000
using namespace std;

int c[MAX][MAX]; // c[] la de luu gia tien
int X[MAX]; // X[] de danh dau di qua thanh pho nao
int T[MAX];  //  luu chi phi tu X[1] --> X[i]
vector<int> BestWay; // BestWau[] de ghi nhan lai duong di
int visited[MAX]; // visited[] de danh dau thanh pho da di qua
int n, m, MinSpending = INT_MAX; 


void nhap();
void Try(int i);

int main ()
{
    ifstream infile;
    infile.open("D:\\bai16in.txt");
    infile >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j)  c[i][j] = 0;
            else    
                c[i][j] = VC;
        }
    }
    for (int k = 1; k <= m; k++){
        int tmp1, tmp2, tmp3; // tmp1, tmp2 la khoang cach 2 diem, tmp3 la gia tien
        infile >> tmp1 >> tmp2 >> tmp3;
        c[tmp1][tmp2] = tmp3;
        c[tmp2][tmp1] = tmp3;
    }
    infile.close();
    for (int i = 1; i <= n; i++){
        visited[i] = 0;
    }
    visited[1] = 1, X[1] = 1, T[1] = 0;
    Try(2);
    /* for (int i = 0; i <= BestWay.size(); i++){
         cout << BestWay[i] << "->" << " ";
     }*/
    ofstream outfile;
    outfile.open("D:\\Bai16_output.txt");
    
    for (int i = 0; i < BestWay.size(); i++){
        outfile << BestWay[i] << "->" << " ";
    }
    outfile << "1" << endl;
    outfile << "Cost: " << MinSpending;

    
}
void Try(int i)
{
    for (int j=2;j<=n;j++){
        if (visited[j] == 0){
            X[i] = j;
            T[i] = T[i-1] + c[X[i-1]][j];
            if (T[i] < MinSpending){
                if (i < n)
                {
                    visited[j] = 1;
                    Try(i+1);
                    visited[j] = 0;
                }
                else{
                    if (T[n] + c[X[n]][1] < MinSpending){
                        MinSpending = T[n] + c[X[n]][1];
                        BestWay.clear(); // dam bao rang lun chua duong di tot nhat
                        for(int k = 1; k <= n; k++)
                            BestWay.push_back(X[k]);
                    }
                }

            }


        }
    }
}
