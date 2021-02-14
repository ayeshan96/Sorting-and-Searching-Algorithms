#include<iostream>
#include<fstream>

using namespace std;

int finalsortted[5][20];

class MySearch
{
public:
	int linear(int array[], int count, int number);

	int binary(int array[],int count,int number,int left,int right,int comparison);

	int interpolation(int array[], int count, int number, int left, int right);
	
	int jump(int array[],int count,int number);


};

int MySearch::linear(int array[], int count, int number)
{
	int comparison = 0;
	
	for (int i = 0; i < count;)
	{
		comparison = comparison + 1;
		if (array[i] != number)
		{
			i = i + 1;
			
		}
		else
		{	
			break;
		}
	}
	
	return comparison;
	

}


int MySearch::binary(int array[], int count, int number, int left, int right, int comparison)
{
	
	if (left <= right)
	{
		
		comparison = comparison + 1;
		int middle = left + ((right - left) / 2);

		if (array[middle] == number)
		{
			goto t;
		}
		else if (array[middle] > number)
		{
			binary(array, count, number, left, middle - 1, comparison);
		}
		else if (array[middle] < number)
		{
			binary(array, count, number, middle + 1, right, comparison);
		}
		
	}
	else
	{
		t:
		return comparison;
	}
}

int MySearch::interpolation(int array[], int count, int number, int left, int right)
{
	int x = left + (right - left)*((number - array[left]) / (array[right] - array[left]));
	return 1 ;
}
int MySearch::jump(int array[], int count, int number)
{
	int comparison = 0;
	int beg = 0;
	int end = sqrt(count);

	while (end < count && array[end] <= number)
	{
		comparison = comparison + 1;
		beg = end;
		end = end + sqrt(count);

		if (end > count - 1)
		{
			end = count;
		}
	}
	for (int i = beg; i < end; i++)
	{
		comparison = comparison + 1;
		if (array[i] == number)
		{
			break;
		}
	}
	return comparison;

}



int sort(int *array, int count)
{
	int count1 = 0;
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = count - 1; j > i; j--)
		{
			if (array[j] < array[j - 1])
			{
				swap(array[j], array[j - 1]);
			}
			count1 = count1 + 1;
		}
	}
	return *array;

}

void file()
{
	ifstream text1;
	text1.open("Set1.txt");
	if (text1.fail())
	{
		cout << "There is an error in open the file set1\n\n\n\n";
	}

	else
	{
		int n1, n2, n3, n4;
		cin >> n1 >> n2 >> n3 >> n4;
		int count1 = 0;
		int a;
		text1 >> a;
		while (text1.good())
		{
			count1 = count1 + 1;
			text1 >> a;
		}

		text1.close();
		text1.open("Set1.txt");
		int *array1 = new int[count1];
		int *array11 = new int[count1];
		int i = 0;
		int b;

		while (text1.good())
		{
			text1 >> b;
			array1[i] = b;

			i = i + 1;
		}
		for (int i = 0; i < count1; i++)
		{
			array11[i] = array1[i];
		}

		sort(array1, count1);

		int n = n1;
		int r = 0;
		int x = 0;
		for ( x ; x < 20;)
		{
		z:
			MySearch liu;
			finalsortted[r][x] = liu.linear(array11, count1, n);
			x = x + 1;

			MySearch lis;
			finalsortted[r][x] = lis.linear(array1, count1, n);
			x = x + 1;

			MySearch bi;
			finalsortted[r][x] = bi.binary(array1, count1, n, 0, count1-1, 0);
			x = x + 1;

			MySearch in;
			finalsortted[r][x] = in.interpolation(array1, count1, n, 0, count1);
			x = x + 1;

			MySearch ju;
			finalsortted[r][x] = ju.jump(array1, count1, n);
			if (x == 4)
			{
				n = n2;
				
			}
			else if (x == 9)
			{
				n = n3;
				
			}
			else if (x == 14)
			{
				n = n4;
				
			}

			x = x + 1;
			if (x < 20)
			{
				goto z;
			}
		}

	}

	ifstream text2;
	text2.open("Set2.txt");
	if (text2.fail())
	{
		cout << "There is an error in open the file set2\n\n\n\n";
	}

	else
	{
		int n1, n2, n3, n4;
		cin >> n1 >> n2 >> n3 >> n4;
		int count2 = 0;
		int a;
		text2 >> a;
		while (text2.good())
		{
			count2 = count2 + 1;
			text2 >> a;
		}
		text2.close();
		text2.open("Set2.txt");
		int *array2 = new int[count2];
		int *array22 = new int[count2];
		int i = 0;
		int b;
		text2 >> b;
		while (text2.good())
		{
			text2 >> b;
			array2[i] = b;

			i = i + 1;
		}

		for (int i = 0; i < count2; i++)
		{
			array22[i] = array2[i];
		}

		sort(array2, count2);

		int n = n1;
		int r = 1;
		int x = 0;
		for (x; x < 20;)
		{

			MySearch liu;
			finalsortted[r][x] = liu.linear(array22, count2, n);
			x = x + 1;

			MySearch lis;
			finalsortted[r][x] = lis.linear(array2, count2, n);
			x = x + 1;

			MySearch bi;
			finalsortted[r][x] = bi.binary(array2, count2, n, 0, (count2 - 1), 0);
			x = x + 1;

			MySearch in;
			finalsortted[r][x] = in.interpolation(array2, count2, n, 0, count2);
			x = x + 1;

			MySearch ju;
			finalsortted[r][x] = ju.jump(array2, count2, n);
			if (x == 4)
			{
				n = n2;
				x = x + 1;
			}
			else if (x == 9)
			{
				n = n3;
				x = x + 1;
			}
			else if (x == 14)
			{
				n = n4;
				x = x + 1;
			}


		}

	}

	ifstream text3;
	text3.open("Set3.txt");
	if (text3.fail())
	{
		cout << "There is an error in open the file set3\n\n\n\n";
	}

	else
	{
		int n1, n2, n3, n4;
		cin >> n1 >> n2 >> n3 >> n4;
		int count3 = 0;
		int a;
		text3 >> a;
		while (text3.good())
		{
			count3 = count3 + 1;
			text3 >> a;
		}
		text3.close();
		text3.open("Set3.txt");
		int *array3 = new int[count3];
		int *array33 = new int[count3];

		int i = 0;
		int b;
		text3 >> b;
		while (text3.good())
		{
			text3 >> b;
			array3[i] = b;

			i = i + 1;
		}

		for (int i = 0; i < count3; i++)
		{
			array33[i] = array3[i];
		}

		sort(array3, count3);

		int n = n1;
		int r = 2;
		int x = 0;
		for (x; x < 20;)
		{

			MySearch liu;
			finalsortted[r][x] = liu.linear(array33, count3, n);
			x = x + 1;

			MySearch lis;
			finalsortted[r][x] = lis.linear(array3, count3, n);
			x = x + 1;

			MySearch bi;
			finalsortted[r][x] = bi.binary(array3, count3, n, 0, (count3 - 1), 0);
			x = x + 1;

			MySearch in;
			finalsortted[r][x] = in.interpolation(array3, count3, n, 0, count3);
			x = x + 1;

			MySearch ju;
			finalsortted[r][x] = ju.jump(array3, count3, n);
			if (x == 4)
			{
				n = n2;
				x = x + 1;
			}
			else if (x == 9)
			{
				n = n3;
				x = x + 1;
			}
			else if (x == 14)
			{
				n = n4;
				x = x + 1;
			}


		}
	}

	ifstream text4;
	text4.open("Set4.txt");
	if (text4.fail())
	{
		cout << "There is an error in open the file set4\n\n\n\n";
	}

	else
	{
		int n1, n2, n3, n4;
		cin >> n1 >> n2 >> n3 >> n4;
		int count4 = 0;
		int a;
		text4 >> a;
		while (text4.good())
		{
			count4 = count4 + 1;
			text4 >> a;
		}
		text4.close();
		text4.open("Set4.txt");
		int *array4 = new int[count4];
		int *array44 = new int[count4];
		int i = 0;
		int b;
		text4 >> b;
		while (text4.good())
		{
			text4 >> b;
			array4[i] = b;

			i = i + 1;
		}

		for (int i = 0; i < count4; i++)
		{
			array44[i] = array4[i];
		}

		sort(array4, count4);

		int n = n1;
		int r = 3;
		int x = 0;
		for (x; x < 20;)
		{

			MySearch liu;
			finalsortted[r][x] = liu.linear(array44, count4, n);
			x = x + 1;

			MySearch lis;
			finalsortted[r][x] = lis.linear(array4, count4, n);
			x = x + 1;

			MySearch bi;
			finalsortted[r][x] = bi.binary(array4, count4, n, 0, (count4 - 1), 0);
			x = x + 1;

			MySearch in;
			finalsortted[r][x] = in.interpolation(array4, count4, n, 0, count4);
			x = x + 1;

			MySearch ju;
			finalsortted[r][x] = ju.jump(array4, count4, n);
			if (x == 4)
			{
				n = n2;
				x = x + 1;
			}
			else if (x == 9)
			{
				n = n3;
				x = x + 1;
			}
			else if (x == 14)
			{
				n = n4;
				x = x + 1;
			}


		}
	}

	ifstream text5;
	text5.open("Set5.txt");
	if (text5.fail())
	{
		cout << "There is an error in open the file set5\n\n\n\n";
	}

	else
	{
		int n1, n2, n3, n4;
		cin >> n1 >> n2 >> n3 >> n4;
		int count5 = 0;
		int a;
		text5 >> a;
		while (text5.good())
		{
			count5 = count5 + 1;
			text5 >> a;
		}
		text5.close();
		text5.open("Set5.txt");
		int *array5 = new int[count5];
		int *array55 = new int[count5];
		int i = 0;
		int b;
		text5 >> b;
		while (text5.good())
		{
			text5 >> b;
			array5[i] = b;
			i = i + 1;
		}

		for (int i = 0; i < count5; i++)
		{
			array55[i] = array5[i];
		}

		sort(array5, count5);

		int n = n1;
		int r = 4;
		int x = 0;
		for (x; x < 20;)
		{

			MySearch liu;
			finalsortted[r][x] = liu.linear(array55, count5, n);
			x = x + 1;

			MySearch lis;
			finalsortted[r][x] = lis.linear(array5, count5, n);
			x = x + 1;

			MySearch bi;
			finalsortted[r][x] = bi.binary(array5, count5, n, 0, (count5 - 1), 0);
			x = x + 1;

			MySearch in;
			finalsortted[r][x] = in.interpolation(array5, count5, n, 0, count5);
			x = x + 1;

			MySearch ju;
			finalsortted[r][x] = ju.jump(array5, count5, n);
			if (x == 4)
			{
				n = n2;
				x = x + 1;
			}
			else if (x == 9)
			{
				n = n3;
				x = x + 1;
			}
			else if (x == 14)
			{
				n = n4;
				x = x + 1;
			}


		}

	}

}




int main()
{
		file();

		cout << "\n\n\n\n\n\n\n\tLinear Search\tLinear Search\tBinary Search\tInterpolation\tJump Search\n\t(unsorted set)\t(sorted set)\t\t\tsearch\n\t  a  b  c  d\t  a  b  c  d\t  a  b  c  d\t  a  b  c  d\t  a  b  c  d\n\n";
		
		for (int r = 0; r < 5; r++)
		{
			int x = 0;
			cout << "set" << r+1 <<"\t";
			
			int c = 0;

			t:
			for ( c ; c < 20;)
			{
				
				if (c < 20)
				{
					cout << finalsortted[r][c] << " ";
				}
				
				if (c == 19)
				{
					goto g;
				}

				c = c + 5;

				if (c > 19)
				{
					c = x+1;
					x = x + 1;
					goto t;
				}
			}
			g:
			cout << endl;

		}

		/*for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				cout << finalsortted[i][j]<<" ";
			}
			cout << endl;
		}*/
	system("pause");
	return 0;
}