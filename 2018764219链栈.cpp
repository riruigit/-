/***链栈的实现***/
#include<iostream>
using namespace std;
typedef char SElemType;
typedef bool Status;

typedef struct StackNode {
	SElemType data;
	struct StackNode *next;
} StackNode, *LinkStack;

//算法3.5　链栈的初始化
Status InitStack(LinkStack &S) { // 构造一个空栈 S，栈顶指针置空
	S = NULL;
	return true;
}

//算法3.6　链栈的入栈
Status Push(LinkStack &S, SElemType e) {//在栈顶插入元素e
	LinkStack p;
	p = new StackNode; //生成新结点
	p->data = e; //将新结点数据域置为e
	p->next = S; //将新结点插入栈顶
	S = p; //修改栈顶指针为p
	return true;
}

//算法3.7　链栈的出栈
Status Pop(LinkStack &S, SElemType &e) {//删除S的栈顶元素，用e返回其值
	LinkStack p;
	if (S == NULL)
		return false; //栈空
	e = S->data; //将栈顶元素赋给e
	p = S; //用p临时保存栈顶元素空间，以备释放
	S = S->next; //修改栈顶指针
	delete p; //释放原栈顶元素的空间
	return true;
}
//算法3.8　取链栈的栈顶元素
SElemType GetTop(LinkStack S) {//返回S的栈顶元素，不修改栈顶指针
	if (S != NULL) //栈非空
		return S->data; //返回栈顶元素的值，栈顶指针不变
}

int main() {
	LinkStack s;
	int choose, flag = 0;
	SElemType j, t;
	cout <<"\t***********链栈的操作***********"<<endl;
	cout <<"\t*         1.链栈初始化         *"<<endl;
	cout <<"\t*         2.链栈的入栈         *"<<endl;
	cout <<"\t*         3.读栈顶的元素       *"<<endl;
	cout <<"\t*         4.链栈的出栈         *"<<endl;
	cout <<"\t*         0.退出程序           *"<<endl;
	cout <<"\t********************************"<<endl;
	choose = -1;
	while (choose != 0) {
		cout << "请选择:";
		cin >> choose;
		switch (choose) {
			case 1://算法3.5　链栈的初始化
				if (InitStack(s)) {
					flag = 1;
					cout << "成功对栈进行初始化\n\n";
				} else
					cout << "初始化栈失败\n\n";
				break;
			case 2: {//算法3.6　链栈的入栈
				if (flag) {
					flag = 1;
					cout << "进栈元素依次为：(#号结束)\n";
					while(cin>>j) {
						if(j=='#') break;
						Push(s,j);
					}
					cout << endl;
				} else
					cout << "栈未建立，请重新选择\n\n";
			}
			break;
			case 3://算法3.8　取链栈的栈顶元素
				if (flag != -1 && flag != 0)
					cout << "栈顶元素为：\n" << GetTop(s) << endl << endl;
				else
					cout << "栈中无元素，请重新选择\n" << endl;
				break;
			case 4://算法3.7　链栈的出栈
				if (flag != -1 && flag != 0) {
					cout << "依次弹出的栈顶元素为:\n";
					while (Pop(s, t)) {
						flag=-1;
						cout << t << "  ";
					}
					cout << endl << endl;
				} else
					cout << "栈中无元素，请重新选择\n" << endl;
				break;
		}
	}
	return 0;
}