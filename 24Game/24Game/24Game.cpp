#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int n1 = 0;
int n2 = 0;
double nums[4];
double nu[10];
double r[10];
char  op[10];
char _op[] = { '+', '-', '*', '/' };
bool calc24(double *num, int n);
double operation(double f1, double f2, char c);

int main()
{
	system("color f1");
	string filename = "24Game.in";
	ifstream filein;
	ofstream fileout("24Game.txt");
	filein.open(filename);
	while (true)
	{
		//get the filename
		cout << "Enter the source text: ";
		getline(cin, filename);
		filein.open(filename);
		if (!filein){
			cout << "Unable to open that file. Try again.\n";
			continue;
		}
		break;
	}
	char ch[20];
	char snu[10][4];
	bool flag1, flag2;//1--check the input 2--check whether there is an answer

	while (!filein.eof())
	{
		//transfer char array to double array
		flag1 = true;
		filein.getline(ch, 20);
		char*tmp = ch;
		if (!*tmp)	continue;
		for (int i = 0; i<4; i++)
		{
			switch (*tmp)
			{
			case 'J':	nums[i] = 11; break;
			case 'Q':	nums[i] = 12; break;
			case 'K':	nums[i] = 13; break;
			case '1':
			{
						if (*(tmp + 1) == '0')
						{
							nums[i] = 10;
							tmp++;
						}
						else
							nums[i] = 1;
			}
				break;
			case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':		nums[i] = *tmp - '0'; break;
			default:	nums[i] = -1; flag1 = false;
			}
			tmp += 2;
		}

		for (int i = 0; i<4; i++)	cout << nums[i] << " ";
		cout << "			";

		//check the input
		for (int i = 0; i<4; i++)
		{
			if (nums[i]<1 || nums[i]>13) flag1 = false;
		}
		if (!flag1)
		{
			cout << "WRONG FORMAT" << endl;
			fileout << "WRONG FORMAT" << endl;
			continue;
		}

		//recursive calculation
		flag2 = calc24(nums, 4);

		//transfer number to char
		for (int i = 0; i<6; i++)
		{
			snu[i][0] = '0';
			snu[i][1] = ' ';
			snu[i][2] = '\0';
			if (nu[i]<10 && nu[i]>0)
				snu[i][0] = nu[i] + '0';
			else if (nu[i] == 10)
			{
				snu[i][0] = '1';
				snu[i][1] = '0';
				snu[i][2] = ' ';
				snu[i][3] = '\0';
			}
			else if (nu[i] == 11)
				snu[i][0] = 'J';
			else if (nu[i] == 12)
				snu[i][0] = 'Q';
			else if (nu[i] == 13)
				snu[i][0] = 'K';
		}

		//file output
		if (flag2)
		{
			if ((r[0] == nu[4] && r[1] == nu[5]) || (r[0] == nu[5] && r[1] == nu[4]))
			{
				switch (op[2])
				{
				case '+':
					cout << snu[0] << op[0] << ' ' << snu[1] << op[2] << ' ' << snu[2] << op[1] << ' ' << snu[3] << "= 24 " << endl;
					fileout << snu[0] << op[0] << ' ' << snu[1] << op[2] << ' ' << snu[2] << op[1] << ' ' << snu[3] << "= 24 " << endl;
					break;
				case '-':
					if (r[0]>r[1])
					{
						cout << snu[0] << op[0] << ' ' << snu[1] << op[2] << ' ';
						fileout << snu[0] << op[0] << ' ' << snu[1] << op[2] << ' ';
						if (op[1] == '+' || op[1] == '-')
						{
							cout << "( " << snu[2] << op[1] << ' ' << snu[3] << ") " << "= 24 " << endl;
							fileout << "( " << snu[2] << op[1] << ' ' << snu[3] << ") " << "= 24 " << endl;
						}
						else
						{
							cout << snu[2] << op[1] << ' ' << snu[3] << "= 24 " << endl;
							fileout << snu[2] << op[1] << ' ' << snu[3] << "= 24 " << endl;
						}
					}
					else
					{
						cout << snu[2] << op[1] << ' ' << snu[3] << op[2] << ' ';
						fileout << snu[2] << op[1] << ' ' << snu[3] << op[2] << ' ';
						if (op[0] == '+' || op[0] == '-')
						{
							cout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") " << "= 24 " << endl;
							fileout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") " << "= 24 " << endl;
						}
						else
						{
							cout << snu[0] << op[0] << ' ' << snu[1] << "= 24 " << endl;
							fileout << snu[0] << op[0] << ' ' << snu[1] << "= 24 " << endl;
						}
					}
					break;
				case '*':
					if (op[0] == '+' || op[0] == '-')
					{
						cout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
						fileout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
					}
					else
					{
						cout << snu[0] << op[0] << ' ' << snu[1];
						fileout << snu[0] << op[0] << ' ' << snu[1];
					}
					cout << op[2] << ' ';
					fileout << op[2] << ' ';
					if (op[1] == '+' || op[1] == '-')
					{
						cout << "( " << snu[2] << op[1] << ' ' << snu[3] << ") " << "= 24 " << endl;
						fileout << "( " << snu[2] << op[1] << ' ' << snu[3] << ") " << "= 24 " << endl;
					}
					else
					{
						cout << snu[2] << op[1] << ' ' << snu[3] << "= 24 " << endl;
						fileout << snu[2] << op[1] << ' ' << snu[3] << "= 24 " << endl;
					}
					break;
				case '/':
					if (r[0]>r[1])
					{
						if (op[0] == '+' || op[0] == '-')
						{
							cout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
							fileout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
						}
						else
						{
							cout << snu[0] << op[0] << ' ' << snu[1];
							fileout << snu[0] << op[0] << ' ' << snu[1];
						}
						cout << op[2] << ' ' << "( " << snu[2] << op[1] << ' ' << snu[3] << ") " << "= 24 " << endl;
						fileout << op[2] << ' ' << "( " << snu[2] << op[1] << ' ' << snu[3] << ") " << "= 24 " << endl;
					}
					else
					{
						if (op[1] == '+' || op[1] == '-')
						{
							cout << "( " << snu[2] << op[1] << ' ' << snu[3] << ") ";
							fileout << "( " << snu[2] << op[1] << ' ' << snu[3] << ") ";
						}
						else
						{
							cout << snu[2] << op[1] << ' ' << snu[3];
							fileout << snu[2] << op[1] << ' ' << snu[3];
						}
						cout << op[2] << ' ' << "( " << snu[0] << op[0] << ' ' << snu[1] << ") " << "= 24 " << endl;
						fileout << op[2] << ' ' << "( " << snu[0] << op[0] << ' ' << snu[1] << ") " << "= 24 " << endl;
					}
					break;
				}
			}
			else
			{
				if (r[1] == nu[5])
				{
					cout << snu[4] << op[2] << ' ';
					fileout << snu[4] << op[2] << ' ';
					if (op[2] == '+' || ((op[2] == '-' || op[2] == '*') && (op[1] == '*' || op[1] == '/')))
					{
						if (r[0] == nu[3])
						{
							cout << snu[2] << op[1] << ' ';
							fileout << snu[2] << op[1] << ' ';
							if (op[1] == '+' || ((op[1] == '-' || op[1] == '*') && (op[0] == '*' || op[0] == '/')))
							{
								cout << snu[0] << op[0] << ' ' << snu[1] << "= 24 " << endl;
								fileout << snu[0] << op[0] << ' ' << snu[1] << "= 24 " << endl;
							}
							else
							{
								cout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") " << "= 24 " << endl;
								fileout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") " << "= 24 " << endl;
							}
						}
						else
						{
							if (op[1] == '+' || op[1] == '-' || ((op[1] == '*' || op[1] == '/') && (op[0] == '*' || op[0] == '/')))
							{
								cout << snu[0] << op[0] << ' ' << snu[1];
								fileout << snu[0] << op[0] << ' ' << snu[1];
							}
							else
							{
								cout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
								fileout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
							}
							cout << op[1] << ' ' << snu[3] << "= 24 " << endl;
							fileout << op[1] << ' ' << snu[3] << "= 24 " << endl;
						}
					}
					else
					{
						cout << "( ";
						fileout << "( ";
						if (r[0] == nu[3])
						{
							cout << snu[2] << op[1] << ' ';
							fileout << snu[2] << op[1] << ' ';
							if (op[1] == '+' || ((op[1] == '-' || op[1] == '*') && (op[0] == '*' || op[0] == '/')))
							{
								cout << snu[0] << op[0] << ' ' << snu[1];
								fileout << snu[0] << op[0] << ' ' << snu[1];
							}
							else
							{
								cout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
								fileout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
							}
						}
						else
						{
							if (op[1] == '+' || op[1] == '-' || ((op[1] == '*' || op[1] == '/') && (op[0] == '*' || op[0] == '/')))
							{
								cout << snu[0] << op[0] << ' ' << snu[1];
								fileout << snu[0] << op[0] << ' ' << snu[1];
							}
							else
							{
								cout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
								fileout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
							}
							cout << op[1] << ' ' << snu[3];
							fileout << op[1] << ' ' << snu[3];
						}
						cout << ") " << "= 24 " << endl;
						fileout << ") " << "= 24 " << endl;
					}
				}
				else
				{
					if ((op[2] == '+' || op[2] == '-') || ((op[2] == '*' || op[2] == '/') && (op[1] == '*' || op[1] == '/')))
					{
						if (r[0] == nu[3])
						{
							cout << snu[2] << op[1] << ' ';
							fileout << snu[2] << op[1] << ' ';
							if (op[1] == '+' || ((op[1] == '-' || op[1] == '*') && (op[0] == '*' || op[0] == '/')))
							{
								cout << snu[0] << op[0] << ' ' << snu[1];
								fileout << snu[0] << op[0] << ' ' << snu[1];
							}
							else
							{
								cout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
								fileout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
							}
						}
						else
						{
							if (op[1] == '+' || op[1] == '-' || ((op[1] == '*' || op[1] == '/') && (op[0] == '*' || op[0] == '/')))
							{
								cout << snu[0] << op[0] << ' ' << snu[1];
								fileout << snu[0] << op[0] << ' ' << snu[1];
							}
							else
							{
								cout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
								fileout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
							}
							cout << op[1] << ' ' << snu[3];
							fileout << op[1] << ' ' << snu[3];
						}
					}
					else
					{
						cout << "( ";
						fileout << "( ";
						if (r[0] == nu[3])
						{
							cout << snu[2] << op[1] << ' ';
							fileout << snu[2] << op[1] << ' ';
							if (op[1] == '+' || ((op[1] == '-' || op[1] == '*') && (op[0] == '*' || op[0] == '/')))
							{
								cout << snu[0] << op[0] << ' ' << snu[1];
								fileout << snu[0] << op[0] << ' ' << snu[1];
							}
							else
							{
								cout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
								fileout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
							}
						}
						else
						{
							if (op[1] == '+' || op[1] == '-' || ((op[1] == '*' || op[1] == '/') && (op[0] == '*' || op[0] == '/')))
							{
								cout << snu[0] << op[0] << ' ' << snu[1];
								fileout << snu[0] << op[0] << ' ' << snu[1];
							}
							else
							{
								cout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
								fileout << "( " << snu[0] << op[0] << ' ' << snu[1] << ") ";
							}
							cout << op[1] << ' ' << snu[3];
							fileout << op[1] << ' ' << snu[3];
						}
						cout << ") ";
						fileout << ") ";
					}
					cout << op[2] << ' ' << snu[5] << "= 24 " << endl;
					fileout << op[2] << ' ' << snu[5] << "= 24 " << endl;
				}
			}
		}
		else
		{
			cout << "NO ANSWER" << endl;
			fileout << "NO ANSWER" << endl;
		}
	}
	filein.close();
	fileout.close();
	cout << endl << "Calculation Completed!" << endl << endl;
	system("pause");
}

double operation(double f1, double f2, char c)
{
	double f;
	switch (c)
	{
	case '+':
		f = f1 + f2;
		break;
	case '-':
		f = f1 - f2;
		break;
	case '*':
		f = f1 * f2;
		break;
	case '/':
		f = f1 / f2;
		break;
	}
	nu[n1++] = f1;
	nu[n1++] = f2;
	op[n2] = c;
	r[n2++] = f;
	return f;
}

bool calc24(double *num, int n)
{
	bool flag = false;
	if (n == 1)
	{
		if (fabs(num[0] - 24.0) < 0.0001)
			return true;
		else
			return false;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == i)
			{
				continue;
			}
			double f1 = num[i];
			double f2 = num[j];
			char *p = _op;
			for (int k = 1; k <= 4; k++, p++)
			{
				if ('/' == *p && fabs(f2) < 0.0001)
				{
					continue;
				}
				if ('-' == *p && f1<f2)
				{
					continue;
				}
				double f = operation(f1, f2, *p);
				double *pnew = new double[n - 1];
				if (!pnew)
				{
					return flag;
				}
				pnew[0] = f;
				for (int i1 = 1, i2 = 0; i1 < n - 1; i1++)
				{
					while (i2 == i || i2 == j)
					{
						i2++;
					}
					pnew[i1] = num[i2++];
				}
				flag = calc24(pnew, n - 1);
				n2--;
				n1 -= 2;
				delete pnew;
				if (flag) return true;
			}
		}
	}
	return flag;
}
