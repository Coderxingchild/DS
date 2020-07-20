
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
		case 1:  //β��
			printf("����������Ҫ���������<�� 0 ����>:");
			while (scanf("%d", &ret), ret != 0) {
				SeqListPushBack(&slist, ret);
			}
			printf("β���������ݳɹ���\n");
			break;
		case 2:  //ͷ��
			printf("����������Ҫ���������<�� 0 ����>:");
			while (scanf("%d", &ret), ret != 0) {
				SeqListPushFront(&slist, ret);
			}
			printf("ͷ���������ݳɹ���\n");
			break;
		case 3:  //ͷɾ
			SeqListPopFront(&slist);
			printf("ͷɾ�ɹ�!\n");
			break;
		case 4: //βɾ
			SeqListPopBack(&slist);
			printf("βɾ�ɹ���\n");
			break;
		case 5:  //����
			printf("����������Ҫ���ҵ�����:>");
			scanf("%d", &ret);
			pos = SeqListFind(&slist, ret);
			if (pos == -1) {
				printf("����ʧ�ܣ�\n");
			}
			else
				printf("���ҳɹ���\n");
			break;
		case 6:  //��λ�ò���
			printf("����������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("����������Ҫ�����Ԫ��:>");
			scanf("%d", &ret);
			SeqListInsert(&slist, pos, ret);
			printf("����ɹ���\n");
			break;
		case 7: //��λ��ɾ��
			printf("����������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			SeqListErase(&slist, pos);
			printf("ɾ���ɹ���\n");
			break;
		case 8:  //��ӡ
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