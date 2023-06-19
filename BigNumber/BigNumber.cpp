#include<iostream>
#include<string>
using namespace std;
#include"BigNumber.h"

int main()
{
	CBigNum a, b;
	
	cout << "Nhap so lon thu nhat: ";
	cin >> a;
	cout << "Nhap so lon thu hai: ";
	cin >> b;

	cout << "\nSo lon thu nhat: ";
	cout << a;
	cout << "\nSo lon thu hai: ";
	cout << b;

	if (a.compareBigNum(b) == 1)
		cout << "\nSo thu nhat lon hon";
	else
		cout << "\nSo thu nhat khong lon hon so thu hai";

	CBigNum kq = a.addBigNum(b);

	cout << "\nTong hai so lon la: " << kq;
	
	kq = a.subBigNum(b);
	cout << "\nHieu hai so lon la: " << kq;

	kq = a.mulBigNum(12);
	cout << "\nTich cua so lon voi so nho: " << a << " * " << 12 << " = " << kq;
	
	kq = a.mulBigNum(b);
	cout << "\nTich cua 2 so lon: " << a << " * " << b << " = " << kq;

	kq = a.divBigNum(12);
	cout << "\nPhep chia so lon voi so nho: " << a << " / " << 12 << " = " << kq;
	
	long kq1 = a.modBigNum(12);
	cout << "\nPhep chia du so lon voi so nho: " << a << " % " << 12 << " = " << kq1;

	kq = a.divBigNum1(b);
	cout << "\nPhep chia so lon voi so lon " << a << " / " << b << " = " << kq;
	
	kq = a.divBigNum2(b);
	cout << "\nPhep chia so lon voi so lon " << a << " / " << b << " = " << kq;

	kq = a.modBigNum2(b);
	cout << "\nPhep chia du so lon voi so lon " << a << " % " << b << " = " << kq;

	kq = a.modBigNum2(b);
	cout << "\nPhep chia du so lon voi so lon " << a << " % " << b << " = " << kq;


	cout << "\n\n\nKet thuc";

	return 0;
}