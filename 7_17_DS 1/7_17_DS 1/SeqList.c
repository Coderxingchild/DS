
#include"SeqList.h"

int main()
{
	SeqList *slist;
	SeqListInit(&slist);
	SLDateType ret;
	int pos ;
	int select = 1;
	while (select) {
		printf("###########################################\n");
		printf("#  1.SeqListPushBack  2.SeqListPushFront  #\n");
		printf("#  3.SeqListPopFront  4.SeqListPopBack    #\n");
		printf("#  5.SeqListFind      6.SeqListInsert     #\n");
		printf("#  7.SeqListErase     0.exit system       #\n");
		printf("#############   8.SeqListPrint  ###########\n");
		printf("###########################################\n");
		printf("please enter your select:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select) {
		case 1:  //尾插
			printf("请输入你想要插入的数据<以 0 结束>:");
			while (scanf("%d", &ret), ret != 0) {
				SeqListPushBack(&slist, ret);
			}
			printf("尾部插入数据成功！\n");
			break;
		case 2:  //头插
			printf("请输入你想要插入的数据<以 0 结束>:");
			while (scanf("%d", &ret), ret != 0) {
				SeqListPushFront(&slist, ret);
			}
			printf("头部插入数据成功！\n");
			break;
		case 3:  //头删
			SeqListPopFront(&slist);
			printf("头删成功!\n");
			break;
		case 4: //尾删
			SeqListPopBack(&slist);
			printf("尾删成功！\n");
			break;
		case 5:  //查找
			printf("请输入你想要查找的数据:>");
			scanf("%d", &ret);
			pos = SeqListFind(&slist, ret);
			if (pos == -1) {
				printf("查找失败！\n");
			}
			else
				printf("查找成功！\n");
			break;
		case 6:  //按位置插入
			printf("请输入你想要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入你想要插入的元素:>");
			scanf("%d", &ret);
			SeqListInsert(&slist, pos, ret);
			printf("插入成功！\n");
			break;
		case 7: //按位置删除
			printf("请输入你想要删除的位置:>");
			scanf("%d", &pos);
			SeqListErase(&slist, pos);
			printf("删除成功！\n");
			break;
		case 8:  //打印
			SeqListPrint(&slist);
			break;
		default:
			printf("your select error!\n");
			break;
		}
		system("pause");
		system("cls");
	}
	SeqListDestory(&slist);
	return 0;
}