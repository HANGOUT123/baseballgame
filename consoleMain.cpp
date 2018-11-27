#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	//�����õ� �ʱ�ȭ
	srand(time(NULL));

	int number[10] = {};			//0 ~ 9������ ����
	int comNumber[3] = {};		//��ǻ�ͼ��� 3��
	int myNumber[3] = {};		//������ 3��
	int temp, dest, sour = 0;	//���ÿ� ������

	int ballCount = 0;		//�� ī��Ʈ
	int strikeCount = 0;	//��Ʈ����ũ ī��Ʈ
	int gameCount = 0;		//���� ī��Ʈ

	//0 ~ 9������ ���� �ʱ�ȭ
	for (int i = 0; i < 10; i++)
	{
		number[i] = i;
		//number[0] = 0, number[1] = 1, ... number[9] = 9;
	}

	//100�� ���´�
	for (int i = 0; i < 100; i++)
	{
		dest = rand() % 10;
		sour = rand() % 10;
		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}

	//��ǻ�� ���� 3�� �̴´�
	for (int i = 0; i < 3; i++)
	{
		comNumber[i] = number[i];
	}

	//ġƮ��
	cout << "ġƮŰ: ";
	//cout << comNumber[0] << ", " << comNumber[1] << ", " << comNumber[2] << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << comNumber[i] << ". ";
	}
	cout << endl;

	//���ѷ���
	while (true)
	{
		cout << "0 ~ 9������ ���ڸ� �Է��ض�~" << endl;

		//���� �Է��� ���ڸ� �Է¹޴´�
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << "��° ���ڸ� �Է��ض�: ";
			cin >> myNumber[i];
		}

		//����ī��Ʈ ������Ų��
		gameCount++;

		//��, ��Ʈ����ũ ī��Ʈ�� 0���� �ʱ�ȭ ���ش�
		//�ʱ�ȭ ������ ������ ī��Ʈ�� ��������Ѵ�
		ballCount = 0;
		strikeCount = 0;
		//ballCount = strikeCount = 0;

		//���� �߱������� �ٽ� �˰���
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//��ǻ�� ���ڿ� ���� ������ ���ڰ� ����?
				if (comNumber[i] == myNumber[j])
				{
					//�ڸ��� ����?
					if (i == j) strikeCount++;
					else ballCount++;
				}
			}
		}

		cout << ballCount << "��, " << strikeCount << "��Ʈ����ũ" << endl;

		//��Ʈ����ũ ī��Ʈ�� 3�̸� ���� ����
		if (strikeCount == 3)
		{
			cout << "��!! ��" << gameCount << "�� ���� �����" << endl;
			break;
		}
	
	}//end of while (true)
}