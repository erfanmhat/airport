#ifndef BASE_H
#define BASE_H

using namespace std;

char unsigned encrypter(unsigned char);
string encrypterInt(int);
string encrypterStr(string);

char unsigned decrypter(unsigned char);
int decrypterInt(string);
string encrypterStr(string);
/**?????????????????????????????????????*/
char unsigned encrypter(unsigned char ch)
{
	bool b[8],c[8];
	unsigned char re=0;
	for(int i=0;i<8;i++)
	{
		c[i]=0;
		b[i]=0;
	}
	for(int i=0;i<8;i++)
	{
		if(ch%2==0)b[i]=0;
		else b[i]=1;
		ch>>=1;
	}
	c[7]=b[5];
	c[6]=b[2];
	c[5]=b[7];
	c[4]=b[1];
	c[3]=b[6];
	c[2]=b[0];
	c[1]=b[4];
	c[0]=b[3];
	for(int i=0;i<8;i++)
	{
		re<<=1;
		if(c[7-i]==1)re++;
	}
	return re;
}
/*****************************************/
string encrypterInt(int n)
{
    bool b;
    unsigned char ch;
    string re="0000";
    for(int i=0;i<4;i++)
    {
        ch=0;
        for(int j=0;j<8;j++)
        {
            ch+=n%2*pow(2,j);
            n>>=1;
        }
        re[i]=encrypter(ch);
    }
    return re;
}
/*****************************************/
string encrypterStr(string str)
{
	string re;
	for(int i=0;i<str.length();i++)
	{
		re.push_back(encrypter(str[i]));
	}
	return re;
}
/*****************************************/
char unsigned decrypter(unsigned char ch)
{
	bool b[8],c[8];
	unsigned char re=0;
	for(int i=0;i<8;i++)
	{
		c[i]=0;
		b[i]=0;
	}
	for(int i=0;i<8;i++)
	{
		if(ch%2==0)b[i]=0;
		else b[i]=1;
		ch>>=1;
	}
	c[7]=b[5];
	c[6]=b[3];
	c[5]=b[7];
	c[4]=b[1];
	c[3]=b[0];
	c[2]=b[6];
	c[1]=b[4];
	c[0]=b[2];
	for(int i=0;i<8;i++)
	{
		if(i!=0)re<<=1;
		if(c[7-i]==1)re++;
	}
	return re;
}
/*****************************************/
int decrypterInt(string str)
{
    int re=0;
    unsigned char ch;
    for(int i=3;i>=0;i--)
    {
        ch=str[i];
        ch=decrypter(ch);
        re+=ch*pow(256,i);
    }
    return re;
}
/*****************************************/
string decrypterStr(string str)
{
	string re;
	for(int i=0;i<str.length();i++)
	{
		re.push_back(decrypter(str[i]));
	}
	return re;
}
/**?????????????????????????????????????*/
#endif // BASE_H
