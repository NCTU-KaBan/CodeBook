template<typename T>
struct point{
	T x,y;
	point(){}
	point(const T&dx,const T&dy):x(dx),y(dy){}
	inline const point operator-(const point &b)const{
		return point(x-b.x,y-b.y);
	}
	inline const T dot(const point &b)const{
		return x*b.x+y*b.y;
	}
	inline const T abs2()const{/*向量長度的平方*/
		return dot(*this);
	}
	static bool x_cmp(const point<T>& a,const point<T>& b){
		return a.x<b.x;
	}
	static bool y_cmp(const point<T>& a,const point<T>& b){
		return a.y<b.y;
	}
};
#define INF LLONG_MAX/*預設是long long最大值*/
template<typename T>
T closest_pair(vector<point<T> >&v,vector<point<T> >&t,int l,int r){
	T dis=INF,tmd;
	if(l>=r)return dis;
	int mid=(l+r)/2;
	if((tmd=closest_pair(v,t,l,mid))<dis)dis=tmd;
	if((tmd=closest_pair(v,t,mid+1,r))<dis)dis=tmd;
	t.clear();
	for(int i=l;i<=r;++i)
		if((v[i].x-v[mid].x)*(v[i].x-v[mid].x)<dis)t.push_back(v[i]);
	sort(t.begin(),t.end(),point<T>::y_cmp);/*如果用merge_sort的方式可以O(n)*/
	for(int i=0;i<(int)t.size();++i)
		for(int j=1;j<=3&&i+j<(int)t.size();++j)
			if((tmd=(t[i]-t[i+j]).abs2())<dis)dis=tmd;
	return dis;
}
template<typename T>
inline T closest_pair(vector<point<T> > &v){
	vector<point<T> >t;
	sort(v.begin(),v.end(),point<T>::x_cmp);
	return closest_pair(v,t,0,v.size()-1);/*最近點對距離*/
}
