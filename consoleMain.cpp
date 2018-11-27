#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	//랜덤시드 초기화
	srand(time(NULL));

	int number[10] = {};			//0 ~ 9번까지 숫자
	int comNumber[3] = {};		//컴퓨터숫자 3개
	int myNumber[3] = {};		//내숫자 3개
	int temp, dest, sour = 0;	//셔플용 변수들

	int ballCount = 0;		//볼 카운트
	int strikeCount = 0;	//스트라이크 카운트
	int gameCount = 0;		//게임 카운트

	//0 ~ 9번까지 숫자 초기화
	for (int i = 0; i < 10; i++)
	{
		number[i] = i;
		//number[0] = 0, number[1] = 1, ... number[9] = 9;
	}

	//100번 섞는다
	for (int i = 0; i < 100; i++)
	{
		dest = rand() % 10;
		sour = rand() % 10;
		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}

	//컴퓨터 숫자 3개 뽑는다
	for (int i = 0; i < 3; i++)
	{
		comNumber[i] = number[i];
	}

	//치트기
	cout << "치트키: ";
	//cout << comNumber[0] << ", " << comNumber[1] << ", " << comNumber[2] << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << comNumber[i] << ". ";
	}
	cout << endl;

	//무한루프
	while (true)
	{
		cout << "0 ~ 9까지의 숫자를 입력해라~" << endl;

		//내가 입력할 숫자를 입력받는다
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << "번째 숫자를 입력해라: ";
			cin >> myNumber[i];
		}

		//게임카운트 증가시킨다
		gameCount++;

		//볼, 스트라이크 카운트를 0으로 초기화 해준다
		//초기화 해주지 않으면 카운트가 계속증가한다
		ballCount = 0;
		strikeCount = 0;
		//ballCount = strikeCount = 0;

		//숫자 야구게임의 핵심 알고리즘
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//컴퓨터 숫자와 내가 선택한 숫자가 같냐?
				if (comNumber[i] == myNumber[j])
				{
					//자리가 같냐?
					if (i == j) strikeCount++;
					else ballCount++;
				}
			}
		}

		cout << ballCount << "볼, " << strikeCount << "스트라이크" << endl;

		//스트라이크 카운트가 3이면 게임 종료
		if (strikeCount == 3)
		{
			cout << "야!! 너" << gameCount << "번 만에 맞췄다" << endl;
			break;
		}
	
	}//end of while (true)
}