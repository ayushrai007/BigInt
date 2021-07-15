	

#include<bits/stdc++.h>
#define Max 4000
#define base 10
using namespace std;


struct bigInt{
	int len;
	int data[Max];
	bigInt (){
		memset(data,0,sizeof(data));
		len=0;
	}
		int check (const bigInt &a,const bigInt &b){
		if(a.len>b.len)return(0);
		if(b.len>a.len)return(1);
		for(int i=a.len;i>=1;--i){
			if(a.data[i]<b.data[i])return(1);
			if(b.data[i]<a.data[i])return(0);
		}
		return 2;
	}
		void clear(){
		for(int i=len;i>=1;--i)data[i]=0;
		len=0;
	}
		bigInt operator=(const bigInt &x){
		for(int i=x.len+1;i<=len;++i)data[i]=0;
		for(int i=1;i<=x.len;++i)data[i]=x.data[i];
		len=x.len;
		return *this;
	}
	
	bool operator > (const bigInt &b){ return(check(*this,b)==0);}
	
	bool operator <=(const bigInt &b){ return(check(*this,b)>=1);}
	
	bool operator >=(const bigInt &b){ return(check(*this,b)%2==0);}
	
		bigInt operator +(int x){
		bigInt tmp; tmp=*this;
		tmp.data[1]+=x;
		for(int i=1;i<=len&&tmp.data[i]>=base;++i){tmp.data[i+1]+=tmp.data[i]/base;tmp.data[i]%=base;}
		while(tmp.data[tmp.len+1])tmp.len++;
		return tmp;
	}
	
		bigInt operator /(int x){
		int i;
		bigInt tmp;
		int y=0;
		for(i=len;i>=1;--i){
			y=y*base+data[i];
			tmp.data[i]=y/x;
			y%=x;
		}
		tmp.len=len;
		while(tmp.data[tmp.len]==0&&tmp.len>1)tmp.len--;
		return tmp;
	}
		bigInt operator -(int x){
		bigInt tmp; tmp=*this;
		tmp.data[1]-=x;
		for(int i=1;i<=len&&tmp.data[i]<0;++i){
			tmp.data[i+1]+=(tmp.data[i]+1)/base-1;
			tmp.data[i]=(tmp.data[i]+1)%base+base-1;
		}
		while(!tmp.data[tmp.len]&&tmp.len>1)tmp.len--;
		return tmp;
	}
		bigInt operator *(int x){
		int i;
		bigInt tmp;
		for(i=1;i<=len;++i)tmp.data[i]=data[i]*x;
		tmp.len=len;
		for(i=1;i<=len;++i){
			tmp.data[i+1]+=tmp.data[i]/base;
			tmp.data[i]%=base;
			if(tmp.data[i+1]&&i+1>tmp.len)tmp.len++;
		}
		return tmp;
	}
	
		bigInt operator -(const bigInt &b){
		int i;
		bigInt tmp;
		for(i=1;i<=len;++i)tmp.data[i]=data[i]-b.data[i];
		for(i=1;i<=len;++i){
			if(tmp.data[i]<0){tmp.data[i]+=base;tmp.data[i+1]--;}
		}
		tmp.len=len;
		while(tmp.data[tmp.len]==0&&tmp.len>1)tmp.len--;
		return tmp;
	}
	
	bigInt operator *(const bigInt &b){
		int i,j;
		bigInt tmp;
		for(i=1;i<=len;++i)if(data[i]!=0)
			for(j=1;j<=b.len;++j)if(b.data[j]!=0){
				tmp.data[i+j-1]+=data[i]*b.data[j];
				tmp.data[i+j]+=tmp.data[i+j-1]/base;
				tmp.data[i+j-1]%=base;
			}
		tmp.len=len+b.len-1;
		while(tmp.data[tmp.len+1])tmp.len++;
		return tmp;
	}

	

		bigInt operator /(const bigInt &b){
		
		int i,l1=(len-1),l2=(b.len-1);
		int x=data[len],y=b.data[b.len];
		
		bigInt tmp,Divdnt,divsr;
		Divdnt=*this; divsr=b;
		

		for(i=1;i<=(l1-l2);++i)divsr=divsr*10;
		for(i=l1-l2;i>=0;--i){
			x=0;
			while(Divdnt>=divsr)
			{
			Divdnt=Divdnt-divsr;x++;
			}
			tmp.data[i+1]=tmp.data[i+1]*10+x;
			divsr=divsr/10;
		}
		tmp.len=(l1-l2)+1;
		while(tmp.len>=1 && !tmp.data[tmp.len])tmp.len--;
		return tmp;
	}

		bigInt operator %(const bigInt &b){
		
		int i,l1=(len-1),l2=(b.len-1);
		int x=data[len],y=b.data[b.len];
		
		bigInt Divdnt,divsr;
		Divdnt=*this; divsr=b;
		

		for(i=1;i<=(l1-l2);++i)divsr=divsr*10;
		for(i=l1-l2;i>=0;--i)
		{
			while(Divdnt>=divsr)
			Divdnt=Divdnt-divsr;
			
		divsr=divsr/10;
		}
		return Divdnt;
	}
	
	

		void read(){
		string c;
		cin>>c;
		int l=c.length();
		(*this).clear();
		int x;
		for(int i=l-1;i>=0;i--){
			
			data[++len]=c[i]-'0';
		}
	}
	void write(){
	
		for(int i=len;i>0;i--)
			cout<<data[i];
	}
	}a,b,gcd;

	bigInt GCD(bigInt &a, bigInt &b){
	 bigInt x=a;
	 bigInt y=b;
	 bigInt temp;
	
	 while(!(y.data[1]==0 && y.len==1)){
	 temp=x%y;
	 x=y;
	 y=temp;
	 
	 
	 }
	 return x;



	}
	
	bigInt fact(bigInt &A)
	{
	bigInt f,b;
	b.len=b.len+1;
	f.len=f.len+1;
	f=f+1;
	b=b+1;
	for(;b<=A;b=b+1){
	
	f=f*b;
	}
	return f;
	}

	bigInt Expo(bigInt &A, int n)
	{
	bigInt x=A;
	bigInt temp;
	temp.data[1]=1;
	temp.len=1;
	
	while(n>0)
	{
	if(n%2==1)
	temp=temp*x;
	
	x=x*x;
	n=n/2;
	}
	
	return temp;
	
	}
	
	
	
	
	int main()
	{
		int p;
		long int m,q;
		
		cin>>q;
		while(q--){
		
		
		cin>>m;
		switch(m)
		{
		case 1:
		b.read();
		cin>>p;
		Expo(b,p).write();
		cout<<"\n";
		break;
		
		case 2:
		a.read();
		b.read();
		GCD(a,b).write();
		cout<<"\n";
		break;
		
		case 3:
		
		a.read();
		
		fact(a).write();
		cout<<"\n";
		break;
		

		default:
		cout<<"Option not available";
		}
		
		}
		//a.read();
		//cin>>p;
		//b.read();

		//GCD(a,b).write();
		//fact(a).write();
		//(a*b).write();
		
		//Expo(a,p).write();

		
		return 0;
	}
