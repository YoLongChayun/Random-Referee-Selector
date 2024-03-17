#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int totalPeople, peopleToSelect, i, selected, scanResult;

    // ��ʼ�������������
    srand((unsigned)time(NULL));

    while (1) {
        printf("������������ (������0��������): ");
        scanResult = scanf_s("%d", &totalPeople);

        // ��������Ƿ�Ϊ����
        if (scanResult != 1) {
            printf("�������������һ��������\n");
            // ������������
            while (getchar() != '\n');
            continue;
        }

        if (totalPeople == 0) {
            printf("�����ѽ�����\n");
            break; // �û�����0����������
        }

        printf("��������Ҫ��ȡ������ (������0��������): ");
        scanResult = scanf_s("%d", &peopleToSelect);

        // ��������Ƿ�Ϊ����
        if (scanResult != 1) {
            printf("�������������һ��������\n");
            // ������������
            while (getchar() != '\n');
            continue;
        }

        if (peopleToSelect == 0) {
            printf("�����ѽ�����\n");
            break; // �û�����0����������
        }

        if (peopleToSelect > totalPeople) {
            printf("��ȡ���������ܳ��������������������롣\n");
            continue; // ����ѭ����ʼ����������
        }

        printf("��ѡ�еı��Ϊ: ");

        int* selections = malloc(totalPeople * sizeof(int)); // ��̬��������
        if (selections == NULL) {
            printf("�ڴ����ʧ�ܡ�\n");
            return 1; // ����ڴ����ʧ�ܣ����˳�����
        }
        for (i = 0; i < totalPeople; i++) {
            selections[i] = 0; // ��ʼ��Ϊδ��ѡ��
        }

        for (i = 0; i < peopleToSelect; i++) {
            do {
                selected = rand() % totalPeople; // ���������ѡ����Ա
            } while (selections[selected] == 1); // ����ѱ�ѡ�У�������ѡ��

            selections[selected] = 1; // ���Ϊ��ѡ��
            printf("%d ", selected + 1); // �����ѡ�е���Ա��ţ���Ŵ�1��ʼ
        }

        printf("\n");
        free(selections); // �ͷŶ�̬������ڴ�
    }

    return 0;
}
