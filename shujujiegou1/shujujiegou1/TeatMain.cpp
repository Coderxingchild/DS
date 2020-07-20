#include "seqlist.h"

int main()
{
	SeqList list;
	SeqListInit(&list);
	ElemType item;
	int pos;
	bool flag;
	int select = 1;
	while (select) {
		printf("#########################################\n");
		printf("#   1.pushu_back        2.push.front    #\n");
		printf("#   3.show_list         0.quit_system   #\n");
		printf("#   4.pop_back          5.pop_front     #\n");
		printf("#   6.insert_pos        7.insert_val    #\n");
		printf("#   8.erase_pos         9.erase_val     #\n");
		printf("#   10.find             11.length       #\n");
		printf("#   12.capacity         13.sort         #\n");
		printf("#   14.reverse          15.clear        #\n");
		printf("#   16.front            17.back         #\n");
		printf("#   18.binary_find      19.erase_all    #\n");
		printf("##########################################\n");
		printf("please enter your select:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch(select ) {
		case 1:  //尾插
			printf("请输入要插入的数据<以-1结束>:");
			while (scanf("%d", &item),item != -1) {
				SeqListPushBack(&list, item);
			}
			printf("尾部插入数据成功!\n");
			break;
		case 2:  //头插
			printf("请输入要插入的数据<以-1结束>:");
			while (scanf("%d", &item), item != -1) {
				SeqListPushFront(&list, item);
			}
			printf("头部插入数据成功!\n");
			break;
		case 3:  //显示面板
			SeqListShow(&list);
			break;
		case 4:  //尾删
			SeqListPopBack(&list);
			printf("尾部删除数据成功!\n");
			break;
		case 5:   //头删
			SeqListPopFront(&list);
			printf("头部删除数据成功!\n");
			break;
		case 6:   //按位置插入
			printf("请输入你想要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入你想要插入的元素:>");
			scanf("%d", &item);
			flag = SeqListInsertByPos(&list, pos, item);
			if (flag) 
				printf("按位置插入成功！\n");
			else
				printf("按位置插入失败！\n");
			break;
		case 7:   //按值插入----排序
			printf("请输入你想要插入的数据:>");
			scanf("%d", &item);
			SeqListSort(&list);
			SeqListInsertByVal(&list,item);
			printf("按值插入成功！\n");
			break;
		case 8:   //按位置删除
		    printf("请输入你想要删除的位置:>");
			scanf("%d", &pos);
			SeqListPopByPos(&list, pos);
			printf("按位置删除成功！\n");
			break;
		case 9:   //按值删除
			printf("请输入你想要删除的数据:>");
			scanf("%d", &item);
			SeqListEraseByVal(&list, item);
			printf("按值删除成功！\n");
			break;
		case 10:   //查找
			printf("请输入你要查找的数据:>");
			scanf("%d", &item);
			pos = SeqListFind(&list, item);
			if (pos == -1)
				printf("数据查找失败\n");
			else
				printf("数据查找成功\n");
			break; 
		case 11:   //求长度
			printf("SeqList  Length:%d\n", SeqListLength(&list));
			break;
		case 12:   //求容量
			printf("SeqList  Capacity:%d\n", SeqListCapacity(&list));
			break;
		case 13:   //排序
			SeqListSort(&list);
			printf("顺序表排序成功！\n");
			break;
		case 14:   //逆置
			SeqListReverse(&list);
			printf("顺序表逆置成功！\n");
			break;
		case 15:   //清空
			SeqListClear(&list);
			printf("顺序表清空成功！\n");
			break;
		case 16:  //首元素
			GetFront(&list);
			break;
		case 17:  //尾元素
			 GetBack(&list);
			break;
		case 18: //二分查找
			printf("请输入你要查找的数据:>");
			scanf("%d", &item);
			SeqListSort(&list);
			pos = Binary_Find(&list, item);
			if (pos == -1)
				printf("数据查找失败\n");
			else
				printf("数据查找成功\n");
			break;
		case 19: //删除所有相同元素
			printf("请输入你想要删除的数据:>");
			scanf("%d", &item);
			pos = Erase_All(&list, item);
			if (pos == -1)
				printf("删除失败！\n");
			else
			    printf("删除成功！\n");
			break;
		default:
			printf("命令出错，请重新输入:>\n");
			break;
		}
		system("pause");
		system("cls");
	}
	SeqListDestory(&list);
	return 0;
}


