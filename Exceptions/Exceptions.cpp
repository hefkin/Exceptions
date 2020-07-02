#include <iostream>
#include <ctime>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename T> T new1(int n, T* a, int o)
{
	cout << "Введите элементы массива:" << endl;
	{
		for (int i = 0; i < n; i++)
		{
			while (!(cin >> a[i]) || (cin.peek() != '\n'))
			{
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Некоректные данные, попробуйте снова" << endl;
			}
		}
	}
	system("cls");
	cout << endl << "Массив: " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
	cout << endl;
	return *a;
}

template <typename T> T new2(int n, T* a, int o)
{
	cout << "Введите элементы массива:" << endl;
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
	}
	system("cls");
	cout << endl << "Массив: " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
	cout << endl;
	return *a;
}

template <typename T> T sum(T* a, int n)
{

	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			sum = sum + a[i];
		}

	}
	cout << "___________________________________________________________________________" << endl << endl;
	cout << "Сумма положительных элементов = " << sum << endl;
	return sum;
}

template <typename T> T print(int n, T* a)
{
	int i, iN = 0, iE = 0, imax = 0, imin = 0;
	float max = 0, min = 10000, multi = 1;
	for (i = 0; i < n; i++)
	{
		if (fabs(a[i]) > fabs(max))
		{
			max = a[i];
			imax = i;
		}
		if (fabs(a[i]) < fabs(min))
		{
			min = a[i];
			imin = i;
		}
	}
	cout << "___________________________________________________________________________" << endl << endl;
	cout << "Максимальный по модулю элемент = " << max << endl;
	cout << "Минимальный по модулю элемент = " << min << endl;
	if (imax > imin)
	{
		iN = imin;
		iE = imax;
	}
	else
	{
		iN = imax;
		iE = imin;
	}
	for (i = iN + 1; i < iE; i++)
		multi = multi * a[i];
	cout << "___________________________________________________________________________" << endl << endl;
	cout << "Произведение элементов между минимальным и максимальным по модулю = " << multi << endl;
	return multi;
}

template <typename T> T sort(T* a, int n)
{
	cout << "___________________________________________________________________________" << endl << endl;
	cout << "Отсортированный массив по возрастанию: " << endl << endl;
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
	cout << endl << "___________________________________________________________________________";
	return *a;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int n, o;

	for (;;)
	{
		try
		{
			cout << "================================================\n";
			cout << "Попытка ввода элементов массива\n";
			cout << "================================================\n\n";
			cout << "Кол-во элементов массива: ";

			while (!(cin >> n) || (cin.peek() != '\n'))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Ошибка! Введите цифру, а не букву!" << endl;
			}

			if (0 > n)
				throw runtime_error("Ошибка! Введите число элементов массива в виде неотрицательной цифры!");

			cout << "\n================================================\n";
			cout << "Элементы массива успешно введены!" << endl;
			cout << "================================================\n";
			system("pause");
			system("cls");
			break;
		}
		catch (const std::exception & ex)
		{
			cout << ex.what() << endl;
		}
	}
	for (;;)
	{
		try
		{
			cout << "================================================\n";
			cout << "Тип элементов\n";
			cout << "================================================\n";
			cout << "1 int\n";
			cout << "2 double\n";
			cout << "3 float\n";
			cout << "4 char\n\n";

			while (!(cin >> o) || (cin.peek() != '\n'))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Ошибка! Введите цифру, а не букву!" << endl;
			}

			if (0 > o)
				throw runtime_error("Ошибка! Введите число из меню!");
			cout << "\n================================================\n";
			cout << "Тип данных успешно выбран\n";
			cout << "================================================\n";
			system("pause");
			system("cls");
			break;
		}
		catch (const std::exception & ex)
		{
			cout << ex.what() << endl;
		}
	}

	if ((o > 4) || (o < 1))
	{
		cout << "Некоректные данные" << endl;
		exit(0);
	}
	if (o == 1)
	{
		int* a;
		a = new int[n];
		new1<int>(n, a, o);
		float temp = 0;
		for (int i = 0; i < n; i++)
		{
			temp = temp + a[i] - int(a[i]);
		}
		if (temp == 0)
		{

			sum<int>(a, n);
			print<int>(n, a);
			sort<int>(a, n);
		}
		else
		{
			cout << "Некоректные данные" << endl;
			exit(1);
		}

		delete[] a;
	}
	else if (o == 2)
	{
		double* a;
		a = new double[n];
		new1<double>(n, a, o);
		sum<double>(a, n);
		print<double>(n, a);
		sort<double>(a, n);
		delete[] a;
	}
	else if (o == 3)
	{
		float* a;
		a = new float[n];
		new1<float>(n, a, o);
		sum<float>(a, n);
		print<float>(n, a);
		sort<float>(a, n);
		delete[] a;
	}
	else if (o == 4)
	{
		char* a;
		a = new char[n];
		new2<char>(n, a, o);
		sort<char>(a, n);
		delete[] a;
	}
	return 0;
}