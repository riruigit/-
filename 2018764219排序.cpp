#include<iostream>
using namespace std;
#define MAXSIZE 500
typedef int ElemType;

typedef struct {
	ElemType key;
} RedType;
typedef struct {

	RedType *r;
	ElemType length;
} SqList;

InitList(SqList &L) { //算法2.1顺序表的初始化
//构建一个空的顺序表L
	L.r = new RedType[MAXSIZE];
	L.length=0;
}

void inputList(SqList &L) { //向顺序表里面输入值
	int a,i=1;

	while(cin>>a) {
		if(a==-1) break;
		if(L.length==MAXSIZE) {
			cout<<"error";
		}
		L.r[i++].key=a;
		L.length++;
	}
}

void InsertSort(SqList &L) {
	//对顺序表L做直接插入排序
	int i,j;
	for(i=2; i<=L.length; ++i)
		if(L.r[i].key<L.r[i-1].key) {
			//"<"，需将r[i]插入有序子表
			L.r[0]=L.r[i];				 			//将待插入的记录暂存到监视哨中
			L.r[i]=L.r[i-1];	            		//r[i-1]后移
			for(j=i-2; L.r[0].key<L.r[j].key; --j)			//从后向前寻找插入位置
				L.r[j+1]=L.r[j];					//记录逐个后移，直到找到插入位置
			L.r[j+1]=L.r[0];						//将r[0]即原r[i]，插入到正确位置
		}											//if
}													//InsertSort

void BInsertSort(SqList &L) {
	//对顺序表L做折半插入排序
	int i,j,low,high,m;
	for(i=2; i<=L.length; ++i) {
		L.r[0]=L.r[i];          					//将待插入的记录暂存到监视哨中
		low=1;
		high=i-1;        					//置查找区间初值
		while(low<=high) {
			//在r[low..high]中折半查找插入的位置
			m=(low+high)/2;             			//折半
			if(L.r[0].key<L.r[m].key)  high=m-1;	//插入点在前一子表
			else  low=m+1;					   		//插入点在后一子表
		}//while
		for(j=i-1; j>=high+1; --j)  L.r[j+1]=L.r[j];	//记录后移
		L.r[high+1]=L.r[0];							//将r[0]即原r[i]，插入到正确位置
	}												//for
}													//BInsertSort

void BubbleSort(SqList &L) {
	//对顺序表L做冒泡排序
	int m,j,flag;
	RedType t;
	m=L.length-1;
	flag=1; 				//flag用来标记某一趟排序是否发生交换
	while((m>0)&&(flag==1)) {
		flag=0;           				//flag置为0，如果本趟排序没有发生交换，则不会执行下一趟排序
		for(j=1; j<=m; j++)
			if(L.r[j].key>L.r[j+1].key) {
				flag=1;					//flag置为1，表示本趟排序发生了交换
				t=L.r[j];
				L.r[j]=L.r[j+1];
				L.r[j+1]=t;	//交换前后两个记录
			}							//if
		--m;
	}									//while
}

void SelectSort(SqList &L) {
	//对顺序表L做简单选择排序
	int i,j,k;
	RedType t;
	for(i=1; i<L.length; ++i) {
		//在L.r[i..L.length] 中选择关键字最小的记录
		k=i;
		for(j=i+1; j<=L.length; ++j)
			if(L.r[j].key<L.r[k].key)  k=j;			//k指向此趟排序中关键字最小的记录
		if(k!=i) {
			t=L.r[i];    //交换r[i]与r[k]
			L.r[i]=L.r[k];
			L.r[k]=t;
		}
	}												//for
}


int Partition(SqList &L,int low,int high) {
	//对顺序表L中的子表r[low..high]进行一趟排序，返回枢轴位置
	int pivotkey;
	L.r[0]=L.r[low];                    	//用子表的第一个记录做枢轴记录
	pivotkey=L.r[low].key;		   			//枢轴记录关键字保存在pivotkey中
	while(low<high) {
		//从表的两端交替地向中间扫描
		while(low<high&&L.r[high].key>=pivotkey) --high;
		L.r[low]=L.r[high];					//将比枢轴记录小的记录移到低端
		while(low<high&&L.r[low].key<=pivotkey) ++low;
		L.r[high]=L.r[low];					//将比枢轴记录大的记录移到高端
	}//while
	L.r[low]=L.r[0];						//枢轴记录到位
	return  low;							//返回枢轴位置
}//Partition

void QSort(SqList &L,int low,int high) {
	//调用前置初值：low=1; high=L.length;
	//对顺序表L中的子序列L.r[low..high]做快速排序
	int pivotloc;
	if(low<high) {
		//长度大于1
		pivotloc=Partition(L,low,high); 		//将L.r[low..high]一分为二，pivotloc是枢轴位置
		QSort(L,low,pivotloc-1);				//对左子表递归排序
		QSort(L,pivotloc+1,high);        	//对右子表递归排序
	}
}
void QuickSort(SqList &L) {
	//对顺序表L做快速排序
	QSort(L,1,L.length);
}



void print(SqList L) {//打印顺序表
	int i;
	for(i=1; i<=L.length; i++)
		cout<<L.r[i].key<<"   ";
}

int main() {
	RedType q,w,r,t,y;
	SqList myl;
	InitList(myl);
	cout<<"输入整数，-1 结束" <<endl;
	inputList(myl);

	cout<<endl;
	cout<<"插入排序"<<endl;
	InsertSort(myl);
	print(myl);
	cout<<endl;
	cout<<"折半插入排序"<<endl;
	BInsertSort(myl);
	print(myl);
	cout<<endl;
	cout<<"冒泡排序"<<endl;
	BubbleSort(myl);
	print(myl);
	cout<<endl;
	cout<<"快速排序"<<endl;
	QuickSort(myl);
	print(myl);
	cout<<endl;
	cout<<"选择排序"<<endl;
	SelectSort(myl);
	print(myl);
	cout<<endl;
}
//1 7 9 3 6 4 2 8 5 10 -1
