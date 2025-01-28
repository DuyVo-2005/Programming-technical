#include <iostream>
#include <vector>
#include <fstream>
#define max 20
#define maxC INT_MAX
using namespace std;

int c[max][max]; // c[] la de luu gia tien
int X[max]; // X[] de danh dau di qua thanh pho nao
int T[max];  //  luu chi phi tu X[1] --> X[i]
vector<int> BestWay; // BestWau[] de ghi nhan lai duong di
int visited[max]; // visited[] de danh dau thanh pho da di qua
int n, m, MinSpending = INT_MAX; 


void nhap();
void Try(int i);

int main ()
{
	int i,j,k;
    ifstream infile;
    infile.open("D:\\bai16in.txt");
    infile >> n >> m;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            if (i == j)  c[i][j] = 0;
            else    
                c[i][j] = maxC;
        }
    }
    for (k = 1; k <= m; k++){
        infile>>i>>j>>c[i][j];
        c[j][i] =c[i][j];
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
