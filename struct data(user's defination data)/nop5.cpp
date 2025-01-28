#include<iostream>
using namespace std;
struct NGAY
{
	int ngay;
	int thang;
	int nam;
};
bool checkNamNhuan(int nam)
{
	if(((nam%4==0)&&(nam%100!=0))||(nam%400==0))
		return true;
	return false;
}
int demNgayCuaThang(NGAY a, int thang)
{
	switch(thang)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:              	     	
		case 12:
				return 31;
		case 4:
		case 6:
		case 9:
		case 11:
				return 30;
		case 2:
			if(checkNamNhuan(a.nam))
			{
				return 29;
			}
			else
				return 28;			
	}
}
bool checkNGAYHopLe(NGAY a)
{
	if(a.ngay<=0||a.thang<=0||a.nam<=0||a.thang>12||(a.ngay>demNgayCuaThang(a, a.thang)))
		return false;
	return true;
}
void nhapNGAY(NGAY &a)
{
	cout<<"Nhap ngay: ";
	cin>>a.ngay;
	cout<<"Nhap thang: ";
	cin>>a.thang;
	cout<<"Nhap nam: ";
	cin>>a.nam;
	bool flag=true;//Gia su dung
	if(checkNGAYHopLe(a)==false)
	{
		flag=false;
	}
	while(flag==false)
	{
		cout<<"Nhap sai. Hay nhap lai! ";
		cout<<"\nNhap ngay: ";
		cin>>a.ngay;
		cout<<"Nhap thang: ";
		cin>>a.thang;
		cout<<"Nhap nam: ";
		cin>>a.nam;
		if(checkNGAYHopLe(a))
			flag=true;
	}
}
void xuatNGAY(NGAY a)
{
	cout<<a.ngay<<"/"<<a.thang<<"/"<<a.nam;
}

int demNgayTuNgay1_1_1(NGAY a)
{
	int dem=0;
	for(int i=1;i<a.nam;i++)
		if(checkNamNhuan(i))
			dem+=366;
		else
			dem+=365;
	for(int j=1;j<a.thang;j++)
		dem+=demNgayCuaThang(a,j);
	dem+=a.ngay;
	return dem;
}
void timNgayTruocDokNgay(NGAY a, int k)
{
	a.ngay=a.ngay-k;
	while(a.ngay<=0||a.thang<=0)
	{
		if(a.ngay<=0)
		{
			a.thang=a.thang-1;
			if(a.thang<=0)
			{
				a.nam=a.nam-1;
				a.thang=12+a.thang;
			}//Do ko co thang 0
			a.ngay=demNgayCuaThang(a,a.thang)+a.ngay;
		}	
	};
	cout<<"Ngay truoc do k ngay la: "<<a.ngay<<"/"<<a.thang<<"/"<<a.nam;
}
void timNgaySauDokNgay(NGAY a, int k)
{
	a.ngay=a.ngay+k;
	while(a.ngay>demNgayCuaThang(a,a.thang)||a.thang>12)
	{
		if(a.ngay>demNgayCuaThang(a,a.thang))
		{
			a.ngay=a.ngay%demNgayCuaThang(a,a.thang);
			a.thang++;
		}
		if(a.thang>12)
		{
			a.nam++;
			a.thang=a.thang%12;
		}
	}
	cout<<"Ngay sau do k ngay la: "<<a.ngay<<"/"<<a.thang<<"/"<<a.nam;
}
void khoangCachGiuaHaiNgay(NGAY a, NGAY b)
{
	cout<<"\nKhoang cach giua hai ngay: "<<demNgayTuNgay1_1_1(a)-demNgayTuNgay1_1_1(b)<<" ngay";
}
void soSanhHaiNgay(NGAY a, NGAY b)
{
	if(demNgayTuNgay1_1_1(a)>demNgayTuNgay1_1_1(b))
	cout<<"Ngay thu nhat gan ngay nay hon";
	else
		if(demNgayTuNgay1_1_1(a)<demNgayTuNgay1_1_1(b))
		cout<<"Ngay thu hai gan ngay nay hon";
		else
			cout<<"Hai ngay trung nhau";
}
int main(int argc, char *argv[])
{
	NGAY a;
	nhapNGAY(a);
	xuatNGAY(a);
	if(checkNamNhuan(a.nam)==false)
		cout<<"\nKhong la nam nhuan";
	else
		cout<<"\nLa nam nhuan";
		
	int demNgayTrongNam=0;
	for(int i=1;i<a.thang;i++)
		demNgayTrongNam+=demNgayCuaThang(a,i);
	demNgayTrongNam+=a.ngay;
	cout<<"\nSo thu tu ngay trong nam: "<<demNgayTrongNam;
	
	cout<<"\nThu tu ngay ke tu ngay 1/1/1: "<<demNgayTuNgay1_1_1(a);
	
	int k;
	cout<<"\nNhap k: ";
	cin>>k;
	timNgayTruocDokNgay(a,k);
	cout<<endl;
	timNgaySauDokNgay(a,k);
	
	NGAY b,c;
	cout<<"\nNhap ngay thu nhat! ";
	cout<<endl;
	nhapNGAY(b);
	xuatNGAY(b);
	cout<<"\nNhap ngay thu hai! ";
	cout<<endl;
	nhapNGAY(c);
	xuatNGAY(c);
	cout<<endl;
	
	khoangCachGiuaHaiNgay(b,c);
	cout<<endl;
	
	soSanhHaiNgay(b,c);
}
