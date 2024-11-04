
using namespace std;

ll a[200010];
ll f1(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f2(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f3(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f4(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f5(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f6(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f7(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f8(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f9(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f10(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f11(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f12(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f13(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f14(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f15(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f16(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f17(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f18(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f19(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f20(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f21(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f22(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f23(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
ll f24(ll h,ll n,int x,int y)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]>1&&h>a[i])
		{
			h+=a[i]/2;
		}
		else if(a[i]>1&&h<=a[i])
		{
			if(6*h>a[i]&&x>=1&&y>=1)
			{
				x-=1;y-=1;h*=6;h+=a[i]/2;
			}
			else if(3*h>a[i]&&y>=1)
			{
				y-=1;h*=3;h+=a[i]/2;
			}
			else if(2*h>a[i]&&x>=1)
			{
				x-=1;h*=2;h+=a[i]/2;
			}
			else if(4*h>a[i]&&x>=2)
			{
				x-=2;h*=4;h+=a[i]/2;
			}
			else if(12*h>a[i]&&x>=2&&y>=1)
			{
				x-=2;y-=1;h*=12;h+=a[i]/2;
			}
			else
				break;
		}
	}
	return i;
}
int main()
{
	ll t,n,h,i,j;
	scanf("%lld",&t);
	for(j=0;j<t;j++)
	{
		ll ma=0;
		scanf("%lld%lld",&n,&h);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		sort(a,a+n);
		ll b[]={f1(h,n,2,1),f2(h,n,2,1),f3(h,n,2,1),f4(h,n,2,1),f5(h,n,2,1),f6(h,n,2,1),f7(h,n,2,1),f8(h,n,2,1),f9(h,n,2,1),f10(h,n,2,1),f11(h,n,2,1),f12(h,n,2,1),f13(h,n,2,1),f14(h,n,2,1),f15(h,n,2,1),f16(h,n,2,1),f17(h,n,2,1),f18(h,n,2,1),f19(h,n,2,1),f20(h,n,2,1),f21(h,n,2,1),f22(h,n,2,1),f23(h,n,2,1),f24(h,n,2,1)};
		for(i=0;i<24;i++)
			if(b[i]>ma)
				ma=b[i];
		printf("%lld\n",ma);
	}
}
