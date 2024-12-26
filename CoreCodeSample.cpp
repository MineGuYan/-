#include<vector>
using namespace std;

struct Point
{
	int x, y;
};

int Score[19][19] = {};//��¼����
vector<Point> Gobang;//��¼����

void AI()
{
	int k;

	//������������
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			//�жϣ�i��j�����Ƿ�������
			for (k = 0; k < Gobang.size(); k++)
			{
				if (Gobang[k].x == i + 1 && Gobang[k].y == j + 1)break;
			}

			//��ʼ���˴��ķ���Ϊ0
			Score[i][j] = 0;

			//����i��j����δ���ӣ������˴�����
			if (k == Gobang.size())CalculateScore(i + 1, j + 1);
		}
	}

	//����ֺ�����������̣�Ѱ�ҷ�����ߴ�
	int tem = 0;
	vector<Point>max;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (tem == Score[i][j])max.push_back({ i + 1,j + 1 });
			else if (tem < Score[i][j])
			{
				tem = Score[i][j];
				max.clear();
				max.push_back({ i + 1,j + 1 });
			}
		}
	}

	//����
	if (Gobang.size() == 0)Gobang.push_back({ 10,10 });//��������ʱ��Ĭ�������м�
	else Gobang.push_back(max[rand() % max.size()]);//������ߵ�λ���ж��ʱ�����ѡ��һ������
}
void CalculateScore(int x, int y)
{
	//���������ķ���
	Point Vector[] = { {1,0},{0,1},{1,1},{1,-1} };

	int j, counter, w = 10;
	for (int k = 0; k < 4; k++)
	{
		//�����÷������м�������
		counter = 1;
		//������������
		for (int i = 1; i <= 5; i++)
		{
			//�ж��Ƿ񵽱߽�
			if (x - i * Vector[k].x == 0 || y - i * Vector[k].y == 0 || x - i * Vector[k].x == 20 || y - i * Vector[k].y == 20)break;
			
			//�жϴ˴��Ƿ�����
			for (j = 0; j < Gobang.size(); j++)
			{
				if (Gobang[j].x == x - i * Vector[k].x && Gobang[j].y == y - i * Vector[k].y)break;
			}

			if (j < Gobang.size())//�˴�����
			{
				if (j % 2)break;//�˴�Ϊ����
				else Score[x - 1][y - 1] += pow(w, counter++);//�˴�Ϊ����
			}
			else//�˴�����
			{
				Score[x - 1][y - 1] += 5;
				break;
			}
		}
		//������������
		for (int i = 1; i <= 5; i++)
		{
			//�ж��Ƿ񵽱߽�
			if (x + i * Vector[k].x == 0 || y + i * Vector[k].y == 0 || x + i * Vector[k].x == 20 || y + i * Vector[k].y == 20)break;
			
			//�жϴ˴��Ƿ�����
			for (j = 0; j < Gobang.size(); j++)
			{
				if (Gobang[j].x == x + i * Vector[k].x && Gobang[j].y == y + i * Vector[k].y)break;
			}

			if (j < Gobang.size())//�˴�����
			{
				if (j % 2)break;//�˴�Ϊ����
				else Score[x - 1][y - 1] += pow(w, counter++);//�˴�Ϊ����
			}
			else//�˴�����
			{
				Score[x - 1][y - 1] += 5;
				break;
			}
		}

		//�����÷������м�������
		counter = 1;
		//������������
		for (int i = 1; i <= 5; i++)
		{
			//�ж��Ƿ񵽱߽�
			if (x - i * Vector[k].x == 0 || y - i * Vector[k].y == 0 || x - i * Vector[k].x == 20 || y - i * Vector[k].y == 20)break;

			//�жϴ˴��Ƿ�����
			for (j = 0; j < Gobang.size(); j++)
			{
				if (Gobang[j].x == x - i * Vector[k].x && Gobang[j].y == y - i * Vector[k].y)break;
			}

			if (j < Gobang.size())//�˴�����
			{
				if (j % 2)Score[x - 1][y - 1] += pow(w, counter++);//�˴�Ϊ����
				else break;//�˴�Ϊ����
			}
			else//�˴�����
			{
				Score[x - 1][y - 1] += 5;
				break;
			}
		}
		//������������
		for (int i = 1; i <= 5; i++)
		{
			//�ж��Ƿ񵽱߽�
			if (x + i * Vector[k].x == 0 || y + i * Vector[k].y == 0 || x + i * Vector[k].x == 20 || y + i * Vector[k].y == 20)break;

			//�жϴ˴��Ƿ�����
			for (j = 0; j < Gobang.size(); j++)
			{
				if (Gobang[j].x == x + i * Vector[k].x && Gobang[j].y == y + i * Vector[k].y)break;
			}

			if (j < Gobang.size())//�˴�����
			{
				if (j % 2)Score[x - 1][y - 1] += pow(w, counter++);//�˴�Ϊ����
				else break;//�˴�Ϊ����
			}
			else//�˴�����
			{
				Score[x - 1][y - 1] += 5;
				break;
			}
		}
	}
}