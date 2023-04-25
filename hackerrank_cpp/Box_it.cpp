#include<bits/stdc++.h>

using namespace std;
class Box{
    private:
        int l, b, h;
    
    public:
        Box() {
            l = 0;
            b = 0;
            h = 0;
        }
        
        Box(const Box& b): l(b.l), b(b.b), h(b.h) {};
        
        Box(int l, int b, int h) {
            this->l = l;
            this->b = b;
            this->h = h;
        }
        
        int getLength() {return this->l;}
        int getBreadth() {return this->b;}
        int getHeight() {return this->h;}
        
        long long CalculateVolume() {
            return (long long) l * b * h;
        }
        
        bool operator<(Box& otherBox) {
            if (this->l < otherBox.l)
                return true;
            else if (this->b < otherBox.b && this->l == otherBox.l)
                return true;
            else if (this->h < otherBox.h && this->b == otherBox.b && this->l == otherBox.l)
                return true;
            else 
                return false;            
        };
        
        friend ostream& operator <<(ostream& out, Box& box) {
            out << box.l << " " << box.b << " " << box.h;
            return out;
        }
};


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
