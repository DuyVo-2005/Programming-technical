#include <iostream>
#include <vector>
#include <fstream>
#define max 20
#define maxC INT_MAX
using namespace std;

int c[max][max]; // c[] la de luu gia tien
int X[max]; // X[] de danh dau di qua thanh pho nao
int T[max];  //  luu chi phi tu X[1] --> X[i]
vector<int> BestWay; // BestWay[] de ghi nhan lai duong di
bool visited[max]; // visited[] de danh dau thanh pho da di qua
int n, m, MinSpending = INT_MAX; 


void nhap();
void Try(int i);

int main ()
{
	int i,j,k;
    ifstream infile;
    infile.open("D:\\bai16in1.txt");
    infile >> n >> m;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
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
    for (int i = 0; i < n; i++){
        visited[i] = true;
    }
    visited[0] = false, X[0] = 0, T[0] = 0;
    Try(1);
    /* for (int i = 0; i <= BestWay.size(); i++){
         cout << BestWay[i] << "->" << " ";
     }*/
    ofstream outfile;
    outfile.open("D:\\Bai16_output.txt");
    
    for (int i = 0; i < BestWay.size(); i++){
        outfile << BestWay[i] << "->" << " ";
    }
    outfile << "0" << endl;
    outfile << "Cost: " << MinSpending;

    
}
void Try(int i)
{
    for (int j=1;j<n;j++){
        if (visited[j] == true){
            X[i] = j;
            T[i] = T[i-1] + c[X[i-1]][j];
            if (T[i] < MinSpending){
                if (i < n-1)
                {
                    visited[j] = false;
                    Try(i+1);
                    visited[j] = true;
                }
                else{
                    if (T[n-1] + c[X[n-1]][0] < MinSpending){
                        MinSpending = T[n-1] + c[X[n-1]][0];
                        BestWay.clear(); // dam bao rang lun chua duong di tot nhat
                        for(int k = 0; k < n; k++)
                            BestWay.push_back(X[k]);
                    }
                }

            }


        }
    }
}
