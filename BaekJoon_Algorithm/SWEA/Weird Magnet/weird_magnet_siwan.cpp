/*
문제 파악:
(1) 4개의 자석이 있고 K번 만큼 임의의 자석을 골라 시계 방향(1) 또는 반시계 방향(-1)으로 회전 할 수 있다.
(2) 자석은 기어가 8개 있는 톱니 모양으로 되어있고 각각의 기어는 N극 또는 S극을 띠게된다 .
(3) 어느 특정 자석 하나를 선택하여 회전 시킬때 이웃한 자석,  즉,서로 기어를 맞대고 있는 자석의 극성이 다르면 이웃한 자석은 반대로 회전하게 된다.
12시 방향을 가리키고 있는 기어의 극성이 N극이면 0 점, S극일 경우 좌측부터 차례로 2^(n-1) 의 점수를 갖게 된다.

magnet1 = 1,
magnet2 = 2,
magnet3 = 4,
magnet4 = 8,

결과: 회전이 끝난 후 4개의 자석이 갖는 점수의 합을 구하여라 .
-----------------------------------------------------------------------------------------------------
문제 해결 방안:
서로 맞대고 있는 자석의 극성이 같은지 아닌지를 확인하여 배열에 정보를 담는다.
회전 시킨다.
점수를 구한다.
-------------------------------------------------------------------------------------------------------
부가 설명:
std::ios_base::sync_with_stdio(false); c++은 C의 stdio 입/출력 방식과  동기화 되어 있는데 이를 해제하면 빨라진다.
std::cin.tie(NULL);
std::cout.tie(NULL);
입력과 출력이 서로 연결되어 있어 하나의 입력을 하면 하나의 결과가 출력된다.
위와 같이 tie(NULL) 처리를 해주면 컴파일러는 output을 모든 입력이 끝날때 까지 buffer 상태로 만들고
모든 입력이 끝난 뒤에 buffer 상태였던 output 값이 차례대로 출력된다.
(입력이 많아지면 즉, 알고리즘 문제를 풀때 testcase가 많아지면 버퍼가 터질수 있으니 상황에 맞게 써야한다는 점을 유의 하도록 하자.)
*/

#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int k, result = 0;
		std::cin >> k;
		int map[4][8];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 8; j++)
				std::cin >> map[i][j];

		for (int i = 0; i < k; i++)
		{
			int r[4] = {
				0,
			};
			int idx, dir;
			std::cin >> idx >> dir;

			idx--;
			r[idx] = dir;

			int a = idx - 1, b = dir;
			while (a > -1) // 왼쪽 탐색
			{
				b = -b;
				if (map[a + 1][6] != map[a][2])
					r[a] = b;
				else
					break;
				a--;
			}
			a = idx + 1, b = dir;
			while (a < 4) // 오른쪽 탐색
			{
				b = -b;
				if (map[a - 1][2] != map[a][6])
					r[a] = b;
				else
					break;
				a++;
			}
			for (int j = 0; j < 4; j++)
			{ //이제 r이라는 배열에 모든 움직임이 담겨있음.
				if (!r[j])
					continue;
				else if (r[j] == 1)
				{ //시계방향 회전일때
					int temp = map[j][7];
					for (int k = 6; k >= 0; k--)
						map[j][k + 1] = map[j][k];
					map[j][0] = temp;
				}
				else
				{ //반시계방향 회전일 때
					int temp = map[j][0];
					for (int k = 1; k <= 7; k++)
						map[j][k - 1] = map[j][k];
					map[j][7] = temp;
				}
			}
		}
		int d = 8; //총 합 구하기.
		for (int i = 3; i >= 0; i--)
		{
			if (map[i][0])
				result += d;
			d /= 2;
		}
		std::cout << "#" << tc << " " << result << "\n";
	}
	return 0;
}