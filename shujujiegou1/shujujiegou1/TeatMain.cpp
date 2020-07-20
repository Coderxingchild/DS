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
		case 1:  //β��
			printf("������Ҫ���������<��-1����>:");
			while (scanf("%d", &item),item != -1) {
				SeqListPushBack(&list, item);
			}
			printf("β���������ݳɹ�!\n");
			break;
		case 2:  //ͷ��
			printf("������Ҫ���������<��-1����>:");
			while (scanf("%d", &item), item != -1) {
				SeqListPushFront(&list, item);
			}
			printf("ͷ���������ݳɹ�!\n");
			break;
		case 3:  //��ʾ���
			SeqListShow(&list);
			break;
		case 4:  //βɾ
			SeqListPopBack(&list);
			printf("β��ɾ�����ݳɹ�!\n");
			break;
		case 5:   //ͷɾ
			SeqListPopFront(&list);
			printf("ͷ��ɾ�����ݳɹ�!\n");
			break;
		case 6:   //��λ�ò���
			printf("����������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("����������Ҫ�����Ԫ��:>");
			scanf("%d", &item);
			flag = SeqListInsertByPos(&list, pos, item);
			if (flag) 
				printf("��λ�ò���ɹ���\n");
			else
				printf("��λ�ò���ʧ�ܣ�\n");
			break;
		case 7:   //��ֵ����----����
			printf("����������Ҫ���������:>");
			scanf("%d", &item);
			SeqListSort(&list);
			SeqListInsertByVal(&list,item);
			printf("��ֵ����ɹ���\n");
			break;
		case 8:   //��λ��ɾ��
		    printf("����������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			SeqListPopByPos(&list, pos);
			printf("��λ��ɾ���ɹ���\n");
			break;
		case 9:   //��ֵɾ��
			printf("����������Ҫɾ��������:>");
			scanf("%d", &item);
			SeqListEraseByVal(&list, item);
			printf("��ֵɾ���ɹ���\n");
			break;
		case 10:   //����
			printf("��������Ҫ���ҵ�����:>");
			scanf("%d", &item);
			pos = SeqListFind(&list, item);
			if (pos == -1)
				printf("���ݲ���ʧ��\n");
			else
				printf("���ݲ��ҳɹ�\n");
			break; 
		case 11:   //�󳤶�
			printf("SeqList  Length:%d\n", SeqListLength(&list));
			break;
		case 12:   //������
			printf("SeqList  Capacity:%d\n", SeqListCapacity(&list));
			break;
		case 13:   //����
			SeqListSort(&list);
			printf("˳�������ɹ���\n");
			break;
		case 14:   //����
			SeqListReverse(&list);
			printf("˳������óɹ���\n");
			break;
		case 15:   //���
			SeqListClear(&list);
			printf("˳�����ճɹ���\n");
			break;
		case 16:  //��Ԫ��
			GetFront(&list);
			break;
		case 17:  //βԪ��
			 GetBack(&list);
			break;
		case 18: //���ֲ���
			printf("��������Ҫ���ҵ�����:>");
			scanf("%d", &item);
			SeqListSort(&list);
			pos = Binary_Find(&list, item);
			if (pos == -1)
				printf("���ݲ���ʧ��\n");
			else
				printf("���ݲ��ҳɹ�\n");
			break;
		case 19: //ɾ��������ͬԪ��
			printf("����������Ҫɾ��������:>");
			scanf("%d", &item);
			pos = Erase_All(&list, item);
			if (pos == -1)
				printf("ɾ��ʧ�ܣ�\n");
			else
			    printf("ɾ���ɹ���\n");
			break;
		default:
			printf("�����������������:>\n");
			break;
		}
		system("pause");
		system("cls");
	}
	SeqListDestory(&list);
	return 0;
}


