//Header files
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

int mecount = 0;
int qucount = 0;
class MySortStrings 
{
public:
	vector<string>set;
	void selection(string array[],int count);
	void insertion(string array[],int count);
	void bubble(string array[],int count);

	void me(vector<string>&set, vector<string>&left, vector<string>&right);
	void merge(vector<string>&set);

	//int partition(vector<string>&set, int start, int end);
	//void quicksort(vector<string>&set, int start, int end);
	
	/*void me(string*array, int s, int e,int count)
	{
		int mid = (s + e) / 2;

		int i = s;
		int j = mid + 1;
		int k = s;

		string *temp = new string[count];
		while ((i <= mid) && (j <= e))
		{
			if (array[i] < array[j])
			{
				temp[k++] = array[i++];
			}
			else
			{
				temp[k++] = array[j++];
			}
		}
		while (i <= mid)
		{
			temp[k++] = array[i++];
			for (int i = s; i <= e; i++)
			{
				array[i] = temp[i];
			}
		}
	}
	void merge(string array[], int count, int s, int e)
	{
		if (s >= e)
		{
			return;
		}
		int mid = (s + e) / 2;
		merge(array,count, s, mid);
		merge(array, count,mid + 1, e);

	}*/

	int partition(string array[], int start, int end,int count5)
	{
		
		int p, l, r;
		p = start;
		l = start + 1;
		r = end;
		count5 =count5+ 3;

		while (l < r)
		{
			while ((array[l] <= array[p]) && l < end)
			{
				l = l + 1;
				count5 = count5 + 1;
			}
			while (array[r]<array[p] && r>start)
			{
				r--;
				count5 = count5 + 1;
			}
			if (l < r)
			{
				swap(array[r], array[l]);
				count5 = count5 + 1;
			}
			if (r != p)
			{
				swap(array[r], array[p]);
				count5 = count5 + 1;
			}
			return r;
		}
	}
	void quicksort(string array[], int start, int end, int count)
	{
		int count5 = 0;
		int p;
		count5 = count5 + 1;
		if (start < end)
		{
			p = partition(array, start, end,count5);
			count5 = count5 + 1;
			quicksort(array, start, p - 1, count);
			count5 = count5 + 1;
			quicksort(array, p + 1, end, count);
			count5 = count5 + 1;
			
		}
		
		cout << "Quicksort count = "<<count5;
		
	}

};

void MySortStrings::selection(string array[], int count)
{
	int count1 = 0;
	for (int i = 0; i < count; i++)
	{
		int min = i;
		count1 = count1 + 1;
		for (int j = i+1; j < count; j++)
		{
			count1 = count1 + 1;
			if (array[j] < array[min])
			{
				min = j ;
				count1 = count1 + 1;
			}

			
		}

		swap(array[i], array[min]);
		count1 = count1 + 1;
	}
	
	cout << "\tSelection Sort Count = "<<count1<<endl;
}

void MySortStrings::insertion(string array[],int count) 
{
	int count2=0;
	for (int i = 1; i < count; i++)
	{
			int j = i;
			count2 = count2 + 1;
			while (j-1>=0)
			{
				if (array[j] < array[j - 1])
				{
					swap(array[j], array[j - 1]);

					count2 = count2 + 1;
				}
				j = j - 1;
				count2 = count2 + 1;
				
			}
	}

	cout << "\tInsertion Sort Count = "<< count2<<endl;
}

void MySortStrings::bubble(string array[], int count)
{
	int count3 = 0;
	for (int i = 0; i < count-1; i++)
	{
		for (int j = count - 1; j > i; j--)
		{
			if (array[j] < array[j - 1])
			{
				count3 = count3 + 1;
				swap(array[j], array[j - 1]);
			}
			count3 = count3 + 1;
		}
	}
	
	cout <<"\tBubble Sort Count = "<< count3<<endl;

}

void MySortStrings::me(vector<string>&left, vector<string>&right, vector<string>&set)
{
	mecount = mecount + 1;
	int lengthl = left.size();
	int lengthr = right.size();
	mecount =mecount + 2;
	int i = 0;
	int j = 0;
	int k = 0;
	mecount =mecount+ 3;

	while (i < lengthl && j < lengthr)
	{
		mecount = mecount + 1;
		if (left[i] <= right[j])
		{
			set[k] = left[i];
			mecount = mecount + 1;
			k = k + 1;
			i = i + 1;
			mecount =mecount+ 2;
		}
		else
		{
			set[k] = right[j];
			mecount = mecount + 1;
			k = k + 1;
			j = j + 1;
			mecount = mecount + 3;

		}
	}
	while (i < lengthl)
	{
		set[k] = left[i];
		k = k + 1;
		i = i + 1;
		mecount = mecount + 3;
	}
	while (i < lengthr)
	{
		set[k] = left[j];
		k = k + 1;
		j = j + 1;
		mecount = mecount + 3;
	}

}

void MySortStrings::merge(vector<string>&set)
{
	mecount=mecount+1;
	int length = set.size();
	if (length < 2)
	{
		return;
	}
	int mid = length / 2; 
	mecount=mecount+1;
	vector<string>left;
	vector<string>right;
	mecount = mecount + 2;
	for (int i = 0; i < mid; i++)
	{
		left.push_back(set[i]);
		mecount = mecount + 1;
	}
	for (int i = mid; i < length; i++)
	{
		right.push_back(set[i]);
	}
	merge(left);
	merge(right);
	me(left, right, set);
}


int main()
{
	ifstream file;

	file.open("Words.txt");

	if (file.fail())
	{
		cout << "There is an error in open the file\n\n\n\n";
	}

	else
	{
		int count = 0;
		string a;
		file >> a;
		while (file.good())
		{
			count=count+1;
			file >> a;
		}
		file.close();
		file.open("Words.txt");
		string *array = new string[count];

		int i = 0;
		string b;
		file >> b;
		while (file.good())
		{
			file >> b;
			array[i] = b;
			i = i + 1;
		}

		MySortStrings se;
		se.selection(array, count);
		
		MySortStrings in;
		in.insertion(array, count);

		MySortStrings bu;
		bu.bubble(array, count);

		MySortStrings mer;
		mer.merge(mer.set);
		cout << "\tMerge Sort Count = " << mecount << endl;
		
		MySortStrings qu;
		qu.merge(mer.set);
	}

	system("pause");
	return 0;
}