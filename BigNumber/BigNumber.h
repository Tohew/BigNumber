#pragma once
class CBigNum
{
protected:
	string x;
public:
	//Nhom phuong thuc khoi tao
	CBigNum();
	CBigNum(const CBigNum&);
	CBigNum(string);
	void Nhap();
	friend istream& operator >> (istream&, CBigNum&);
	
	//Nhom phuong thuc cung cap thong tin
	string getX();
	void Xuat();
	friend ostream& operator << (ostream&, CBigNum&);

	//Nhom phuong thuc cap nhat thong tin
	void setX(string);
	CBigNum& operator=(const CBigNum&);
	
	//Nhom phuong thuc xu ly
	int compareBigNum(CBigNum);
	int toNumber(char);
	char toChar(int);

	CBigNum addBigNum(CBigNum);
	CBigNum subBigNum(CBigNum);

	CBigNum mulBigNum(long);
	CBigNum mulBigNum(CBigNum);

	CBigNum divBigNum(long);
	long modBigNum(long);

	CBigNum divBigNum1(CBigNum);
	CBigNum divBigNum2(CBigNum);

	CBigNum modBigNum1(CBigNum);
	CBigNum modBigNum2(CBigNum);
	
};

//Nhom phuong thuc khoi tao
CBigNum::CBigNum()
{
	x = "";
}

CBigNum::CBigNum(const CBigNum& y)
{
	x = y.x;
}

CBigNum::CBigNum(string s)
{
	x = s;
}

void CBigNum::Nhap()
{
	cin >> x;
}

istream& operator >> (istream& is, CBigNum& a)
{
	is >> a.x;
	return is;
}

//Nhom phuong thuc cung cap thong tin
string CBigNum::getX()
{
	return x;
}

ostream& operator << (ostream& os, CBigNum& a)
{
	os << a.x;
	return os;
}

void CBigNum::Xuat()
{
	cout << x;
}

//Nhom phuong thuc cap nhat thong tin
void CBigNum::setX(string xx)
{
	x = xx;
}
CBigNum& CBigNum::operator=(const CBigNum& a)
{
	x = a.x;
	return *this;
}

//Nhom phuong thuc xu ly
int CBigNum::compareBigNum(CBigNum y)
{
	while (x.size() < y.x.size())
		x = '0' + x;
	while (x.size() > y.x.size())
		y.x = '0' + y.x;
	if (x > y.x)
		return 1;
	if (x < y.x)
		return -1;
	return 0;
}

int CBigNum::toNumber(char c) 
{
	return ((int)c - (int)'0');
}

char CBigNum::toChar(int n)
{
	return char(int('0') + n);
}

CBigNum CBigNum::addBigNum(CBigNum y)
{
	while (x.size() < y.x.size()) x = '0' + x;
	while (x.size() > y.x.size()) y.x = '0' + y.x;

	int carry = 0;
	CBigNum temp;
	temp.x = "";
	for (int i = x.size() - 1; i >= 0; i--)
	{
		int xx = toNumber(x[i]);
		int yy = toNumber(y.x[i]);
		int ss = xx + yy + carry;

		temp.x = toChar(ss % 10) + temp.x;
		carry = ss / 10;
	}
	if (carry > 0)
		temp.x = "1" + temp.x;
	return temp;
}

CBigNum CBigNum::subBigNum(CBigNum y)
{
	while (x.size() < y.x.size()) x = '0' + x;
	while (x.size() > y.x.size()) y.x = '0' + y.x;

	int borrow = 0;
	CBigNum temp;
	temp.x = "";

	for (int i = x.size() - 1; i >= 0; i--)
	{
		int xx = toNumber(x[i]);
		int yy = toNumber(y.x[i]);
		int ss = xx - yy - borrow;
		if (ss < 0)
		{
			ss = ss + 10;
			borrow = 1;
		}
		else
			borrow = 0;
		temp.x = toChar(ss) + temp.x;
	}
	while (temp.x.size() > 1 && temp.x[0] == '0')
		temp.x.erase(0, 1);
	return temp;
}

CBigNum CBigNum::mulBigNum(long y)
{
	long carry = 0;
	CBigNum temp;
	temp.x = "";

	for (int i = x.size() - 1; i >= 0; i--)
	{
		int xx = toNumber(x[i]);
		long ss = xx * y + carry;

		temp.x = toChar(ss % 10) + temp.x;
		carry = ss / 10;
	}
	if (carry > 0)
		temp.x = to_string(carry) + temp.x;

	return temp;
}

CBigNum CBigNum::mulBigNum(CBigNum y)
{
	CBigNum temp;
	CBigNum zero;

	for (int i = x.size() - 1; i >= 0; i--)
	{
		long xx = toNumber(x[i]);
		CBigNum ss = y.mulBigNum(xx);
		
		ss.x = ss.x + zero.x;
		zero.x = zero.x + '0';
		temp = temp.addBigNum(ss);
	}
	return temp;
}

CBigNum CBigNum::divBigNum(long y)
{
	CBigNum temp;

	long hold = 0;
	long ss = 0;
	for (int i = 0; i < x.size(); i++)
	{
		hold = hold * 10 + toNumber(x[i]);
		ss = hold / y;
		hold = hold % y;
		temp.x = temp.x + toChar(ss);
	}
	while (temp.x.size() > 1 && temp.x[0] == '0')
		temp.x.erase(0, 1);

	return temp;
}

long CBigNum::modBigNum(long y)
{
	long hold = 0;
	for (int i = 0; i < x.size(); i++)
	{
		hold = hold * 10 + toNumber(x[i]);
		hold = hold % y;
	}
	return hold;
}

CBigNum CBigNum::divBigNum1(CBigNum y)
{
	CBigNum temp;
	CBigNum left;
	CBigNum right = *this;
	CBigNum one;
	one.x = "1";

	while (left.compareBigNum(right) != 1)
	{
		CBigNum mid = (left.addBigNum(right)).divBigNum(2);
		if ((mid.mulBigNum(y)).compareBigNum(*this) <= 0)
		{
			temp = mid;
			left = mid.addBigNum(one);
		}
		else
			right = mid.subBigNum(one);
	}

	return temp;
}

CBigNum CBigNum::divBigNum2(CBigNum y)
{
	CBigNum temp;
	CBigNum ky[11];
	ky[0].x = "0";

	for (int i = 1; i <= 10; i++)
	{
		ky[i] = ky[i - 1].addBigNum(y);
	}

	CBigNum hold;

	for (int i = 0; i < x.size(); i++)
	{
		hold.x = hold.x + x[i];
		int k = 0;
		while (hold.compareBigNum(ky[k + 1]) != -1)
			k++;
		temp.x = temp.x + toChar(k);
		hold = hold.subBigNum(ky[k]);
	}
	
	while (temp.x.size() > 1 && temp.x[0] == '0')
		temp.x.erase(0, 1);
	
	return temp;

}

CBigNum CBigNum::modBigNum1(CBigNum y)
{
	CBigNum temp;
	temp = ((*this).divBigNum1(y)).mulBigNum(y);
	temp = (*this).subBigNum(temp);

	return temp;
}

CBigNum CBigNum::modBigNum2(CBigNum y)
{
	CBigNum ky[11];
	ky[0].x = "0";

	for (int i = 1; i <= 10; i++)
	{
		ky[i] = ky[i - 1].addBigNum(y);
	}

	CBigNum hold;

	for (int i = 0; i < x.size(); i++)
	{
		hold.x = hold.x + x[i];
		int k = 0;
		while (hold.compareBigNum(ky[k]) != -1)
			k++;
		hold = hold.subBigNum(ky[k-1]);
	}

	return hold;
}