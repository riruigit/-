#include<iostream>
using namespace std;
typedef int ElemType;//用ElemType代替了int
typedef bool Status;//用Status代替了bool

#define MAXSIZE 100			//顺序表可能达到的最大长度
typedef struct {
	ElemType *elem; //存储空间的基地址
	int length; //当前长度
} SqList;

//算法2.1顺序表的初始化
Status InitList(SqList &L) { //算法2.1 顺序表的初始化
	//构造一个空的顺序表L
	L.elem = new ElemType[MAXSIZE]; //为顺序表分配一个大小为MAXSIZE的数组空间
	if (!L.elem)
		return false; //存储分配失败退出
	L.length = 0; //空表长度为0
	return true;
}


void inputList(SqList &L) { //向顺序表里面输入值
	int a,i=0;
	while(cin>>a) {
		if(a==-1)break;
		if(L.length==MAXSIZE) {
			cout<<"error";
		}
		L.elem[i++]=a;
		L.length++;
	}
}

Status GetElem(SqList L, int i ,ElemType &e) {//算法2.2　顺序表的取值
//外面传进来不用&,结构体里面传出去要& 
	if (i < 1 || i > L.length)
		return false; //判断i值是否合理，若不合理，返回ERROR
	e = L.elem[i - 1]; //elem[i-1]单元存储第i个数据元素
	return true;
}


int LocateElem_Sq(SqList L, ElemType e) { //算法2.3 顺序表的查找
//顺序表的查找
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e)
			return i + 1;//查找成功，返回序号i+1
	return 0;//查找失败，返回0
}

bool ListInsert_Sq(SqList &L, int i, ElemType e) { //算法2.4 顺序表的插入
//在顺序表L中第i个位置之前插入新的元素e
//i值的合法范围是1<=i<=L.length+1
	if ((i < 1) || (i > L.length + 1))
		return false; //i值不合法
	if (L.length == MAXSIZE)
		return false; //当前存储空间已满
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j]; //插入位置及之后的元素后移
	L.elem[i - 1] = e; //将新元素e放入第i个位置
	++L.length; //表长增1
	return true;
}

bool ListDelete_Sq(SqList &L, int i,ElemType &a) { //算法2.5 顺序表的删除
//在顺序表L中删除第i个元素，并用e返回其值
//i值的合法范围是1<=i<=L.length
	if ((i < 1) || (i > L.length))
		return false; //i值不合法
	
	for (int j = 1; j <= i; j++)
	a=L.elem[j - 1] ;	
		
	for (int j = i; j <= L.length; j++)
		L.elem[j - 1] = L.elem[j]; //被删除元素之后的元素前移
	--L.length; //表长减1
	return true;
}


void print(SqList L) { //输出顺序表
	for(int j=0; j<L.length; j++)
		cout<<L.elem[j]<<" ";
}

int main() {
	int choose;
	ElemType q,w,r,t,y,u,o;
	cout << "                1. 初始化                \n";
	cout << "                2. 输入                \n";
	cout << "                3. 取值                \n";
	cout << "                4. 查找                \n";
	cout << "                5. 插入                \n";
	cout << "                6. 删除                \n";
	cout << "                7. 输出                \n";
	cout << "                0. 退出                \n\n";

	choose = -1;
	while (choose != 0) {
		cout<< "请选择:"<<endl;
		cin >> choose;
		switch (choose) {
			case 1://创建顺序表
				SqList myl;
				InitList(myl);
				cout<<"初始化成功" <<endl;
				break;

			case 2: //顺序表信息输入
				cout<<"输入整数，-1 结束" <<endl;
				inputList(myl);
				break;

			case 3://顺序表的取值
				cout<<"顺序表的取值，获取表中的第i个元素数据元素的值"<<endl;
				cin>>r;
				if(GetElem(myl, r ,u))
					cout<<u<<endl;
				else cout<<"不存在这个元素"<<endl;
				break;

			case 4: //顺序表的查找
				cout<<"顺序表的查找，返回该元素在表中的位置"<<endl;
				cin>>y;
				if(LocateElem_Sq(myl, y)!=0)
					cout<<LocateElem_Sq(myl, y);
				else cout<<"没有这个元素"<<endl;
				break;

			case 5: //顺序表的插入
				cout<<"顺序表的插入，在第i个位置插入一个新的数据"<<endl;
				cin>>q>>w;
				ListInsert_Sq(myl, q, w);
				break;

			case 6: //顺序表的删除
				cout<<"顺序表的删除，将表中第i个元素删除"<<endl;
				cin>>t;
				if(	ListDelete_Sq(myl, t,o))
					cout<<"删除成功第"<<t<<"个元素  "<<o<<endl;
				else 	cout<<"删除失败,不存在这个元素"<<endl;
				break;

			case 7: //顺序表的输出
				print(myl);
				cout<<endl;
				break;
		}
	}
	return 0;
}
